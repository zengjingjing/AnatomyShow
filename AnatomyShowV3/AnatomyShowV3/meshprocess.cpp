#include "meshprocess.h"

extern int maxWindowHeight;
extern int maxWindowWidth;

typedef OpenMesh::TriMesh_ArrayKernelT<>  MyMesh;
//在显示windowMeshProcess的时候，如果是"从mesh process开始"操作的，那么就显示“打开source mesh”button,然后打开mesh,应该把mesh再拷贝到D:\test\input目录下，还没有做
//如果是从最开始做，那么一显示窗口，就要把上一步的mesh显示出来
extern QString  sourceDICOMDirectory;;

MeshProcess::MeshProcess(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	resize(maxWindowWidth * 0.8, maxWindowHeight * 0.8);
	move(maxWindowWidth * 0.2 + 20, 20);
	setWindowFlags(Qt::FramelessWindowHint);
	hide();
	ui.btnOpenSourceMesh->hide();
	pixOfNextStepEnable.load(":/MyImages/images/nextenable.png");
	pixOfNextStepDisable.load(":/MyImages/images/nextdisable.png");
	//	ui.btnSaveMesh->resize(pix.size());
	//	ui.btnSaveMesh->setIcon(pix);
	//	ui.btnSaveMesh->setIconSize(pix.size());
//	ui.btnNextStep->resize(pixOfNextStepEnable.size());
//	ui.btnNextStep->setIconSize(pixOfNextStepEnable.size());
//	ui.btnNextStep->setIcon(pixOfNextStepDisable);
	this->processed=false;
	this->ShowVTKWindow();

	 renderer =vtkSmartPointer<vtkRenderer>::New();	

	ui.btnNextStep->setEnabled(false);

}

MeshProcess::~MeshProcess()
{

}


void MeshProcess::ShowVTKWindow()
{
		ui.vtkDestMesh->GetRenderWindow()->Render();
		ui.vtkSourceMesh->GetRenderWindow()->Render();
}


void MeshProcess::OpenSourceMesh()
{
	this->sourceMeshName = QFileDialog::getOpenFileName(this,  tr("open mesh"), "");
	if(sourceMeshName.isEmpty())return ;
	ReadOBJAndShow(ui.vtkSourceMesh,this->sourceMeshName);

}


void MeshProcess::ShowMesh()
{
	//	renderer->Clear();
	//QString str="D:\\appshow\\NewDICOM";
	vtkSmartPointer<vtkImageData> volume = vtkSmartPointer<vtkImageData>::New();
	vtkSmartPointer<vtkDICOMImageReader> reader=vtkSmartPointer<vtkDICOMImageReader>::New();
	//reader->SetDirectoryName(this->destDICOMDirectory.toStdString().c_str());
	reader->SetDirectoryName(sourceDICOMDirectory.toStdString().c_str());
	reader->Update();
	//	volume->DeepCopy(reader->GetOutput());
	vtkSmartPointer<vtkMarchingCubes> surface =  vtkSmartPointer<vtkMarchingCubes>::New();
	//surface->SetInput(volume);
	surface->SetInput(reader->GetOutput());
	surface->ComputeNormalsOn();
	surface->SetValue(0, 10);
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(surface->GetOutputPort());
	mapper->ScalarVisibilityOff();
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	renderer->AddActor(actor);
	ui.vtkSourceMesh->GetRenderWindow()->AddRenderer(renderer);
	ui.vtkSourceMesh->GetRenderWindow()->Render();
	ui.vtkDestMesh->GetRenderWindow()->Render();
}


void MeshProcess::StartMeshProcess()
{
	
	if(!ui.btnOpenSourceMesh->isVisible())
	//首先保存原始mesh
{
	vtkSmartPointer<vtkOBJExporter>  write=vtkSmartPointer<vtkOBJExporter>::New();
	this->sourceMeshName="sourecemesh.obj";
	write->SetFilePrefix("sourcemesh");
	write->SetRenderWindow(ui.vtkSourceMesh->GetRenderWindow());
	write->Write();
}
	QString processOption=ui.cbMeshProcess->currentText();
	//如果进行的是laplace smoothing
	if(processOption=="Laplace smoothing")
	{
		this->smoothCount=ui.leSmoothCount->text().toInt();
	/*	QString cmd="C:\\Users\\zengjing\\Desktop\\regcmd.exe 10 ";
		cmd+="D:\\test\\input 1 ";
		cmd+="D:\\test\\output ";
		cmd+=QString::number(smoothCount);
		qDebug()<<"cmd=="<<cmd;
		system(cmd.toStdString().c_str());
		MeshRecoveryWithNormal("D:\\test\\input\\1.obj","D:\\test\\output\\1.obj");*/
		laplaceSmooth(this->smoothCount,this->sourceMeshName.toStdString().c_str(),"destmesh.obj");
		ReadOBJAndShow(ui.vtkDestMesh,"destmesh.obj");
	}
	else
	{

	}
	processed=true;
	ui.btnNextStep->setEnabled(true);

}

//本函数其实是在平滑后的mesh中使用原始mesh的法向量
/*void MeshProcess::MeshRecoveryWithNormal(string source,string dest)
{
	ifstream sourceFile(source.c_str());
	ifstream destFile(source.c_str());
	ofstream newFile("D:\\test\\output\\1_new.obj");
	string type;
	string str;
	string str2;
	while(!destFile.eof())
	{
		destFile>>type;
		if(type=="v")
		{
			newFile<<type;
			getline(destFile,str);
			newFile<<str<<endl;
		}
	}

	while(!sourceFile.eof())
	{
		sourceFile>>type;
		if(type=="vn")
		{
			newFile<<type;
			getline(sourceFile,str);
			newFile<<str<<endl;
		}
		if(type=="f")
		{
			newFile<<type;
			getline(sourceFile,str);
			newFile<<str<<endl;
		}

	}
	sourceFile.close();
	destFile.close();
	newFile.close();

}*/

void MeshProcess::ReadOBJAndShow(QVTKWidget* vtkShow,QString meshName)
{
	
	
//	vtkShow->GetRenderWindow()->RemoveRenderer(vtkShow->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
	//renderer->Clear();
//	renderer->GetActors();
	vtkSmartPointer<vtkOBJReader> reader =vtkSmartPointer<vtkOBJReader>::New();
	reader->SetFileName(meshName.toStdString().c_str());
	reader->Update();
	// Visualize
	vtkSmartPointer<vtkPolyDataMapper> mapper =vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(reader->GetOutputPort());
	vtkSmartPointer<vtkActor> actor =vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	
	vtkShow->GetRenderWindow()->AddRenderer(renderer);
	renderer->Clear();
	renderer->AddActor(actor);
	vtkShow->GetRenderWindow()->Render();
}


void MeshProcess::SaveMesh()
{
	if(ui.btnOpenSourceMesh->isVisible())
	{
		QMessageBox::information(NULL, "information", "you don't need to save!");
		return ;
	}
	QString destMeshPath = QFileDialog::getSaveFileName(this,  tr("save mesh"), "", tr("OBJ Files"));
	if(processed==false)
		QFile::copy("sourcemesh.obj",destMeshPath);
	else
		QFile::copy("destmesh.obj",destMeshPath);
}

void MeshProcess::NextStep()
{
	emit signalNextStep(3);
}

void MeshProcess::PrevStep()
{
	QMessageBox message(QMessageBox::Warning,"Information","sure to save current mesh!!!",QMessageBox::Yes|QMessageBox::No,NULL);  
	//message.show();
	if (message.exec()==QMessageBox::Yes)  
	{  
		emit signalPrevStep();
	}  
	else  
	{  
		return ;
	}  



}


void MeshProcess::ShowAddMeshButton()
{
	ui.btnOpenSourceMesh->show();
}


bool MeshProcess::laplaceSmooth(int smoothCount,QString sourceMesh,QString destMesh)
{
	MyMesh  mesh;
	OpenMesh::IO::Options ropt;
	OpenMesh::IO::Options wopt;
	wopt+=OpenMesh::IO::Options::VertexNormal;

	// read mesh from stdin
	if ( ! OpenMesh::IO::read_mesh(mesh, sourceMesh.toStdString().c_str(),ropt) )
	{
		std::cerr << "Error: Cannot read mesh" << std::endl;
		return false;
	}


	// this vector stores the computed centers of gravity
	std::vector<MyMesh::Point>  cogs;
	std::vector<MyMesh::Point>::iterator cog_it;
	cogs.reserve(mesh.n_vertices());


	// smoothing mesh argv[1] times
	MyMesh::VertexIter          v_it, v_end(mesh.vertices_end());
	MyMesh::VertexVertexIter    vv_it;
	MyMesh::Point               cog;
	MyMesh::Scalar              valence;

	int i;
	for (i=0; i < smoothCount; ++i)
	{
		cogs.clear();
		for (v_it=mesh.vertices_begin(); v_it!=v_end; ++v_it)
		{
			cog[0] = cog[1] = cog[2] = valence = 0.0;

			for (vv_it=mesh.vv_iter( v_it ); vv_it; ++vv_it)
			{
				cog += mesh.point( vv_it );
				++valence;
			}

			cogs.push_back(cog / valence);
		}

		for (v_it=mesh.vertices_begin(), cog_it=cogs.begin(); 
			v_it!=v_end; ++v_it, ++cog_it)
			if ( !mesh.is_boundary( v_it ) )
				mesh.set_point( v_it, *cog_it );
	}

	//cal the normal
	mesh.request_vertex_normals();
	mesh.request_face_normals();
	mesh.update_normals();

	// write mesh to stdout
	if ( ! OpenMesh::IO::write_mesh(mesh, destMesh.toStdString().c_str(),wopt) )
	{
		cerr << "Error: cannot write mesh"<<endl;
		return false;
	}
	return true;
}