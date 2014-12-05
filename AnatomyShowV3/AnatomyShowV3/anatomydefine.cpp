#include "anatomydefine.h"

extern int maxWindowHeight;
extern int maxWindowWidth;

AnatomyDefine::AnatomyDefine(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	resize(maxWindowWidth * 0.8, maxWindowHeight * 0.8);
	move(maxWindowWidth * 0.2 + 20, 20);
	setWindowFlags(Qt::FramelessWindowHint);
	hide();
	ui.progressBar->setRange(0,0);
	ui.progressBar->hide();
	ui.lblShowMsg->hide();
	this->numLayers=0;
	qDebug()<<"define=="<<this->width()<<" "<<this->height();
}

AnatomyDefine::~AnatomyDefine()
{

}


void AnatomyDefine::SkinAdd()
{
	QString str = QFileDialog::getOpenFileName(this,  tr("open Skin obj"), "");
	ui.lwSkin->addItem(str);

}

void AnatomyDefine::SkinSub()
{
	ui.lwSkin->takeItem(ui.lwSkin->currentRow());  
}

void AnatomyDefine::MuscleAdd()
{
	QString str = QFileDialog::getOpenFileName(this,  tr("open Muscle obj"), "");
	ui.lwMuscle->addItem(str);
}

void AnatomyDefine::MuscleSub()
{
	ui.lwMuscle->takeItem(ui.lwMuscle->currentRow());  
}

void AnatomyDefine::BoneAdd()
{
	QString str = QFileDialog::getOpenFileName(this,  tr("open Bone obj"), "");
	ui.lwBone->addItem(str);
}

void AnatomyDefine::BoneSub()
{
	ui.lwBone->takeItem(ui.lwBone->currentRow());  
}

void AnatomyDefine::OrganAdd()
{
	QString str = QFileDialog::getOpenFileName(this,  tr("open Organ obj"), "");
	ui.lwOrgan->addItem(str);
}

void AnatomyDefine::OrganSub()
{
	ui.lwOrgan->takeItem(ui.lwOrgan->currentRow()); 
}

void AnatomyDefine::NerveAdd()
{
	QString str = QFileDialog::getOpenFileName(this,  tr("open Nerve obj"), "");
	ui.lwNerve->addItem(str);
}

void AnatomyDefine::NerveSub()
{
	ui.lwNerve->takeItem(ui.lwNerve->currentRow()); 
}

void AnatomyDefine::ArteryAdd()
{
	QString str = QFileDialog::getOpenFileName(this,  tr("open Artery obj"), "");
	ui.lwArtery->addItem(str);
}

void AnatomyDefine::ArterySub()
{
	ui.lwArtery->takeItem(ui.lwNerve->currentRow()); 
}


void AnatomyDefine::GenerateModel()
{
	ui.progressBar->show();
	
	HandleUIData();
	EraseModelJS();
	this->generate_thread=new GenerateModelThread(this,anatomy,materialList,layerList,meshNameList,idList);
	connect(generate_thread,SIGNAL(signalGenerateDone()),this,SLOT(GenerateDone()));
	generate_thread->start();
}



void AnatomyDefine::GenerateDone()
{
	ui.progressBar->hide();
	if(generate_thread->isRunning())
	{
		generate_thread->terminate();
		delete generate_thread;
	}
	ui.lblShowMsg->show();
	emit signalNextStep(4);
}


void AnatomyDefine::HandleUIData()
{
	int i;
	if(ui.lwSkin->count()>0)
	{
		this->layerList.append("10");
		int count=0;
		QStringList tempIDList;
		for(i=0;i<ui.lwSkin->count();i++)
		{
			QString str=ui.lwSkin->item(i)->text();
			QString id=QString::number(100+count);		
			this->meshNameList.append(str);
			tempIDList.append(id);
			this->idList.append(id);
			this->materialList.append("skin");
			count++;
		}
		anatomy["10"]=tempIDList;
		numLayers++;

	}
	if(ui.lwMuscle->count()>0)
	{
		this->layerList.append("11");
		int count=0;
		QStringList tempIDList;
		for(i=0;i<ui.lwMuscle->count();i++)
		{
			QString str=ui.lwMuscle->item(i)->text();
			QString id=QString::number(110+count);	

			this->meshNameList.append(str);
			tempIDList.append(id);
					this->idList.append(id);
			this->materialList.append("muscle");
			count++;
		}
		anatomy["11"]=tempIDList;
		numLayers++;

	}
	if(ui.lwBone->count()>0)
	{
		this->layerList.append("12");
		int count=0;
		QStringList tempIDList;
		for(i=0;i<ui.lwBone->count();i++)
		{
			QString str=ui.lwBone->item(i)->text();
			QString id=QString::number(120+count);	

			this->meshNameList.append(str);
			tempIDList.append(id);
			this->idList.append(id);
			this->materialList.append("bone");
			count++;
		}
		anatomy["12"]=tempIDList;
		numLayers++;

	}
	if(ui.lwOrgan->count()>0)
	{
		this->layerList.append("13");
		int count=0;
		QStringList tempIDList;
		for(i=0;i<ui.lwOrgan->count();i++)
		{
			QString str=ui.lwOrgan->item(i)->text();
			QString id=QString::number(130+count);		
			this->meshNameList.append(str);
			this->idList.append(id);
			tempIDList.append(id);
			this->materialList.append("organ");
			count++;
		}
		anatomy["13"]=tempIDList;
		numLayers++;
	}

	if(ui.lwNerve->count()>0)
	{
		this->layerList.append("14");
		int count=0;
		QStringList tempIDList;
		for(i=0;i<ui.lwNerve->count();i++)
		{
			QString str=ui.lwNerve->item(i)->text();
			QString id=QString::number(140+count);	
			this->meshNameList.append(str);
			tempIDList.append(id);
			this->idList.append(id);
			this->materialList.append("nerve");
			count++;
		}
		anatomy["14"]=tempIDList;
		numLayers++;
	}
	if(ui.lwArtery->count()>0)
	{
		this->layerList.append("15");
		int count=0;
		QStringList tempIDList;
		for(i=0;i<ui.lwArtery->count();i++)
		{
			QString str=ui.lwArtery->item(i)->text();
			QString id=QString::number(150+count);	
			this->meshNameList.append(str);
			tempIDList.append(id);
			this->idList.append(id);
			this->materialList.append("artery");
			count++;
		}
		anatomy["15"]=tempIDList;
		numLayers++;
	}	
}

void AnatomyDefine::EraseModelJS()
{
	ifstream infile("web\\scripts\\models.js");
	stringstream buffer;  
	buffer << infile.rdbuf();  
	string contents(buffer.str()); 
	int index=contents.find("numLayers",0);
	index+=11;
	contents.erase(index,1);
	string temp=QString::number(numLayers).toStdString();
	contents.insert(index,temp);
	infile.close();
	ofstream outfile("web\\scripts\\models.js");
	outfile<<contents;
	outfile.close();
	
	
}