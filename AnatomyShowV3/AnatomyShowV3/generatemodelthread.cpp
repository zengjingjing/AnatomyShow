#include "generatemodelthread.h"

#include "webgl-loader/bounds.h"
#include "webgl-loader/compress.h"
#include "webgl-loader/mesh.h"
#include "webgl-loader/optimize.h"
#include "webgl-loader/stream.h"

extern QString assembledOBJFileName;

GenerateModelThread::GenerateModelThread(QObject *parent,QMap<QString,QStringList> anatomy,QStringList materialList,QStringList layerList,QStringList meshNameList,QStringList idList)
	: QThread(parent)
{
	this->anatomy=anatomy;
	this->materialList=materialList;
	this->layerList=layerList;
	this->meshNameList=meshNameList;
	this->idList=idList;
}

GenerateModelThread::~GenerateModelThread()
{

}


void GenerateModelThread::run()
{
	//(1)先将所有mesh assemble起来
	AssembleMesh();

	//(2)压缩OBJ，并且生成JS文件	
	CompressAndGenerateJS();

	//(3)生成JSON文件
	GenerateJSONFile();
	emit signalGenerateDone();
	exec();
}

void GenerateModelThread::AssembleMesh()
{
	ofstream outfile(assembledOBJFileName.toStdString().c_str());
	ifstream infile;
	char ch;
	int vertex[4];
	int preVexNum=0;
	int preNormalNum=0;
	int countOfVertex=0;
	int countOfNormal=0;
	string str;
	string str_type;
	int i;
	outfile<<"mtllib web\\models\\human\\human.mtl"<<endl;
	for(i=0;i<meshNameList.count();i++)
	{
		infile.open(meshNameList[i].toStdString().c_str());	
		preVexNum+=countOfVertex;
		preNormalNum+=countOfNormal;
		countOfVertex=0;
		countOfNormal=0;
		string name=meshNameList[i].toStdString();
		int pos=name.find_last_of('/');
		name.erase(0,pos+1);
		pos=name.find('.');
		name=name.substr(0,pos);
		outfile<<"g "<<name<<endl;
		outfile<<"usemtl "<<materialList[i].toStdString()<<endl;
		while(!infile.eof())
		{
			str_type="";
			infile>>str_type;
			if(str_type=="v")
			{
				outfile<<"v";
				getline(infile,str);
				outfile<<str<<endl;
				countOfVertex++;
				continue;
			}
			else if(str_type=="vn")
			{
				outfile<<"vn";
				getline(infile,str);
				outfile<<str<<endl;
				countOfNormal++;
				continue;
			}
			else if(str_type=="f")
			{
				outfile<<"f ";
				//infile.get();
				getline(infile,str);
				int indexOfFirstBlank=str.find_first_of(' ');
				str.erase(0,indexOfFirstBlank+1);
				while(str.find(' ')!=string::npos)
				{
					int index=str.find(' ');
					string temp_str=str.substr(0,index);
					if(temp_str.find('/')!=string::npos)
					{
						int index2=temp_str.find('/');
						string temp2=temp_str.substr(0,index2);
						outfile<<atoi(temp_str.c_str())+preVexNum<<"//";
						temp_str.erase(0,index2+2);
						outfile<<atoi(temp_str.c_str())+preNormalNum<<" ";
					}
					str.erase(0,index+1);
				}
				if(!str.empty())
				{
					if(str.find('/')!=string::npos)
					{
						int index2=str.find('/');
						string temp2=str.substr(0,index2);
						outfile<<atoi(str.c_str())+preVexNum<<"//";
						str.erase(0,index2+2);
						outfile<<atoi(str.c_str())+preNormalNum<<" ";
					}
				}
				outfile<<endl;
				continue;
			}
			else
			{
				getline(infile,str);
			}
		}
		infile.close();
	}
	outfile.close();
}


void GenerateModelThread::CompressAndGenerateJS()
{
	string utf8Name=assembledOBJFileName.toStdString();
	int pos=utf8Name.find_last_of('\\');
	utf8Name.erase(0,pos+1);
	pos=utf8Name.find('.');
	utf8Name=utf8Name.substr(0,pos);
	string jsName=utf8Name+".js";
	jsName="web\\models\\human\\"+jsName;
	FILE *jsfile=fopen(jsName.c_str(),"w");

	if(jsfile==NULL)
	{
		qDebug()<<"open failed";
	}
	FILE* fp = fopen(assembledOBJFileName.toStdString().c_str(), "r");
	WavefrontObjFile obj(fp);
	fclose(fp);
	qDebug()<<StripLeadingDir(assembledOBJFileName.toStdString().c_str());
	fprintf(jsfile,"MODELS[\'%s\'] = {\n",StripLeadingDir(assembledOBJFileName.toStdString().c_str()));
	//puts("  materials: {");
	fputs("  materials: {\n",jsfile);

	const MaterialList& materials = obj.materials();
	for (size_t i = 0; i < materials.size(); ++i) {

		materials[i].DumpJson(jsfile);
		if(i<materials.size()-1)
			fprintf(jsfile,",");
	}
	// puts("  },");
	fputs("  },\n",jsfile);
	const MaterialBatches& batches = obj.material_batches();

	// Pass 1: compute bounds.
	webgl_loader::Bounds bounds;
	bounds.Clear();
	for (MaterialBatches::const_iterator iter = batches.begin();
		iter != batches.end(); ++iter) {
			const DrawBatch& draw_batch = iter->second;
			bounds.Enclose(draw_batch.draw_mesh().attribs);
	}
	webgl_loader::BoundsParams bounds_params = 
		webgl_loader::BoundsParams::FromBounds(bounds);
	fprintf(jsfile,"  decodeParams: ");

	bounds_params.DumpJson(jsfile);

	fputs("  urls: {\n",jsfile);
	std::vector<char> utf8;
	webgl_loader::VectorSink sink(&utf8);
	// Pass 2: quantize, optimize, compress, report.
	for (MaterialBatches::const_iterator iter = batches.begin();
		iter != batches.end(); ++iter) {
			size_t offset = 0;
			utf8.clear();
			const DrawMesh& draw_mesh = iter->second.draw_mesh();
			if (draw_mesh.indices.empty()) continue;

			QuantizedAttribList quantized_attribs;
			webgl_loader::AttribsToQuantizedAttribs(draw_mesh.attribs, bounds_params,
				&quantized_attribs);
			VertexOptimizer vertex_optimizer(quantized_attribs);
			const std::vector<GroupStart>& group_starts = iter->second.group_starts();
			WebGLMeshList webgl_meshes;
			std::vector<size_t> group_lengths;
			for (size_t i = 1; i < group_starts.size(); ++i) {
				const size_t here = group_starts[i-1].offset;
				const size_t length = group_starts[i].offset - here;
				group_lengths.push_back(length);
				vertex_optimizer.AddTriangles(&draw_mesh.indices[here], length,
					&webgl_meshes);
			}
			const size_t here = group_starts.back().offset;
			const size_t length = draw_mesh.indices.size() - here;
			const bool divisible_by_3 = length % 3 == 0;
			CHECK(divisible_by_3);
			group_lengths.push_back(length);
			vertex_optimizer.AddTriangles(&draw_mesh.indices[here], length,
				&webgl_meshes);

			std::vector<std::string> material;
			std::vector<size_t> attrib_start, attrib_length, index_start, index_length;
			for (size_t i = 0; i < webgl_meshes.size(); ++i) {
				const size_t num_attribs = webgl_meshes[i].attribs.size();
				const size_t num_indices = webgl_meshes[i].indices.size();
				const bool kBadSizes = num_attribs % 8 || num_indices % 3;
				CHECK(!kBadSizes);
				webgl_loader::CompressQuantizedAttribsToUtf8(webgl_meshes[i].attribs, 
					&sink);
				webgl_loader::CompressIndicesToUtf8(webgl_meshes[i].indices, &sink);
				material.push_back(iter->first);
				attrib_start.push_back(offset);
				attrib_length.push_back(num_attribs / 8);
				index_start.push_back(offset + num_attribs);
				index_length.push_back(num_indices / 3);
				offset += num_attribs + num_indices;
			}
			const uint32 hash = SimpleHash(&utf8[0], utf8.size());
			char buf[9] = { '\0' };
			ToHex(hash, buf);
			// TODO: this needs to handle paths.
			string strUTF8Name=utf8Name+".utf8";
			std::string out_fn = std::string(buf) + "." + strUTF8Name;

			string out="web\\models\\human\\"+out_fn;
			FILE* out_fp = fopen(out.c_str(), "wb");
			fprintf(jsfile,"    \'%s\': [\n", out_fn.c_str());
			size_t group_index = 0;
			for (size_t i = 0; i < webgl_meshes.size(); ++i) {
				fprintf(jsfile,"      { material: \'%s\',\n"
					"        attribRange: [" PRIuS ", " PRIuS "],\n"
					"        indexRange: [" PRIuS ", " PRIuS "],\n"
					"        bboxes: " PRIuS ",\n"
					"        names: [",
					material[i].c_str(),
					attrib_start[i], attrib_length[i],
					index_start[i], index_length[i],
					offset);
				std::vector<size_t> buffered_lengths;
				size_t group_start = 0;
				while (group_index < group_lengths.size()) {
					fprintf(jsfile,"\'%s\', ",
						obj.LineToGroup(group_starts[group_index].group_line).c_str());
					const size_t group_length = group_lengths[group_index];
					const size_t next_start = group_start + group_length;
					const size_t webgl_index_length = webgl_meshes[i].indices.size();
					// TODO: bbox info is better placed at the head of the file,
					// perhaps transposed. Also, when a group gets split between
					// batches, the bbox gets stored twice.
					webgl_loader::CompressAABBToUtf8(group_starts[group_index].bounds,
						bounds_params, &sink);
					offset += 6;
					if (next_start < webgl_index_length) {
						buffered_lengths.push_back(group_length);
						group_start = next_start;
						++group_index;
					} else {
						const size_t fits = webgl_index_length - group_start;
						buffered_lengths.push_back(fits);
						group_start = 0;
						group_lengths[group_index] -= fits;
						break;
					}
				}
				fprintf(jsfile,"],\n        lengths: [");
				for (size_t k = 0; k < buffered_lengths.size(); ++k) {
					fprintf(jsfile,PRIuS ", ", buffered_lengths[k]);
				}
				fputs("],\n      },\n",jsfile);
			}
			fwrite(&utf8[0], 1, utf8.size(), out_fp);
			fclose(out_fp);
			fputs("    ],\n",jsfile);
	}
	fputs("  }\n};\n",jsfile);
	fclose(jsfile);

}

void GenerateModelThread::GenerateJSONFile()
{
	QMap<QString,QString> nameMap;
	nameMap.insert("10","skin_layer");
	nameMap.insert("11","muscle_layer");
	nameMap.insert("12","bone_layer");
	nameMap.insert("13","organ_layer");
	nameMap.insert("14","nerve_layer");
	nameMap.insert("15","artery_layer");
	ofstream jsonFile("web\\models\\human\\entity_metadata.json");
	jsonFile<<"{"<<endl;
	//生成"layers"字段
	jsonFile<<"\"layers\":[";
	int length=layerList.count();
	int i;
	for(i=0;i<length;i++)
	{

		jsonFile<<layerList[i].toStdString();
		if(i<length-1)
			jsonFile<<",";
	}
	jsonFile<<"],"<<endl;
	//生成"dag"字段
	jsonFile<<"\"dag\":[";
	for(i=0;i<length;i++)
	{
		jsonFile<<"["<<layerList[i].toStdString()<<",[";
		int lengthOfLeaf=anatomy[layerList[i]].count();
		int j;
		for(j=0;j<lengthOfLeaf;j++)
		{
			jsonFile<<anatomy[layerList[i]][j].toStdString();
			if(j<lengthOfLeaf-1)
				jsonFile<<",";
		}
		jsonFile<<"]]";
		jsonFile<<",";
	}
	//处理[1,[14,12,13,11,10]]
	jsonFile<<"[1,[";
	for(i=0;i<length;i++)
	{

		jsonFile<<layerList[i].toStdString();
		if(i<length-1)
			jsonFile<<",";
	}
	jsonFile<<"]]],"<<endl;

	//生成"symmetries"字段
	jsonFile<<"\"symmetries\":[],"<<endl;

	//生成"names"字段
	jsonFile<<"\"names\":"<<endl;
	jsonFile<<"[";	
	for(i=0;i<length;i++)
	{
		jsonFile<<"["<<layerList[i].toStdString()<<",\""<<nameMap[layerList[i]].toStdString()<<"\"],";
	}

	for(i=0;i<meshNameList.length();i++)
	{
		string name=meshNameList[i].toStdString();
		int pos=name.find_last_of('/');
		name.erase(0,pos+1);
		pos=name.find('.');
		name=name.substr(0,pos);
		jsonFile<<"["<<idList[i].toStdString()<<",\""<<name<<"\"]";
		if(i<meshNameList.length()-1)
			jsonFile<<",";
		jsonFile<<endl;
	}
	jsonFile<<"],"<<endl;


	//生成"leafs"字段
	jsonFile<<"\"leafs\":"<<endl;
	jsonFile<<"[";	
	for(i=0;i<meshNameList.length();i++)
	{
		string name=meshNameList[i].toStdString();
		int pos=name.find_last_of('/');
		name.erase(0,pos+1);
		pos=name.find('.');
		name=name.substr(0,pos);
		jsonFile<<"["<<idList[i].toStdString()<<",\""<<name<<"\"]";
		if(i<meshNameList.length()-1)
			jsonFile<<",";
		jsonFile<<endl;
	}
	jsonFile<<"],"<<endl;

	//生成"hidden"字段
	jsonFile<<"\"hidden\":[1,";
	for(i=0;i<length;i++)
	{
		jsonFile<<layerList[i].toStdString();
		if(i<length-1)
			jsonFile<<",";
	}
	jsonFile<<"],"<<endl;


	//生成"nodes"字段
	jsonFile<<"\"nodes\":"<<endl;
	jsonFile<<"[[1,\"human\"],";	
	for(i=0;i<length;i++)
	{
		jsonFile<<"["<<layerList[i].toStdString()<<",\""<<nameMap[layerList[i]].toStdString()<<"\"]";
		if(i<length-1)
			jsonFile<<",";
	}
	jsonFile<<"],"<<endl;

	//生成"sublayers"字段
	jsonFile<<"\"sublayers\":[]"<<endl;
	jsonFile<<"}";
	jsonFile.close();
}