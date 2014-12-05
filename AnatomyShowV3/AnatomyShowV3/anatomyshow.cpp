#include "anatomyshow.h"

extern int flagCurrentToolbar;
extern int maxWindowHeight;
extern int maxWindowWidth;

AnatomyShow::AnatomyShow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//move(200,100);
	//flagCurrentToolbar=1 ��ͼ��ָʼ
	//flagCurrentToolbar=2 ��mesh����ʼ
	//flagCurrentToolbar=3 �ӽṹ���忪ʼ
	//setWindowFlags(Qt::WindowMinMaxButtonsHint|Qt::MSWindowsFixedSizeDialogHint );
	// setWindowState(Qt::WindowMaximized);
	// setWindowState(Qt::WindowFullScreen );
	setWindowTitle("�������ѧ3D͸����ʾ");
	setWindowIcon(QIcon(":/MyImages/images/anatomy.jpg"));
	QRect rect=QApplication::desktop()->availableGeometry();
	maxWindowHeight=rect.height();
	maxWindowWidth=rect.width();
	this->resize(maxWindowWidth,maxWindowHeight);
	setWindowFlags(Qt::WindowMinMaxButtonsHint|Qt::MSWindowsFixedSizeDialogHint );

	//�������������������ߵ�1/5��
	buttonWidth = maxWindowWidth * 0.2 * 0.7;
	buttonHeight = maxWindowHeight * 0.1;
	buttonshiftX = maxWindowHeight * 0.2 * 0.15;
	buttonshiftY = buttonHeight * 0.4;
	labelShiftX=(buttonWidth - buttonHeight) / 2 + buttonshiftX;

	//load and adjust img size
	imgBlackArrow.load(":/MyImages/images/arrowdown.png");
	imgGrayArrow.load(":/MyImages/images/arrowdown2.png");	
	imgBlackArrow.scaled(buttonHeight, buttonHeight);
	imgGrayArrow.scaled(buttonHeight, buttonHeight);

	this->windowAnatomyDefine=NULL;
	this->windowImageSegmentation=NULL;
	this->windowMeshProcess=NULL;

	ui.txtWizard->setTextColor(QColor(255,0,0));
	ui.txtWizard->setStyleSheet("font-size : 15px");
	
	//create 4 windows
	this->windowAnatomyDefine=new AnatomyDefine(this);
	this->windowImageSegmentation=new ImageSegmentation(this);
	this->windowMeshProcess=new MeshProcess(this);
	this->windowHelpVizard=new HelpVizard(this);

	connect(windowImageSegmentation,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowMeshProcess,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowAnatomyDefine,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));

	//ShowLeftToturial(1,1);
	AlignWindow();
	HideAll();
	windowHelpVizard->show();
}

AnatomyShow::~AnatomyShow()
{

}

//���ӡ�ͼ��ָ��ʼ����ʱ����ʾ��ߵ�Toturial������button����ʾ
//flagCurrentToolbar=1 ��ͼ��ָʼ
//flagCurrentToolbar=2 ��mesh����ʼ
//flagCurrentToolbar=3 �ӽṹ���忪ʼ


//processStep=1 ��ǰ����Ϊͼ��ָֻ�С�ͼ��ָ���Ե��������buttonΪ�ң��Դ�����
//processStep=2 ��ǰ����Ϊmesh����
//processStep=3 ��ǰ����Ϊ�ṹ����
//processStep=4 ��ǰ����Ϊ��ʾ
void AnatomyShow::ShowLeftToturial(int flagCurrentToolbar,int processStep)
{
	ui.btnAnatomyDefine->setVisible(true);
	ui.btnImageSegmentation->setVisible(true);
	ui.btnMeshProcess->setVisible(true);
	ui.btnAnatomyShow->setVisible(true);
	//���������������"����"
	if(processStep==1)
	{
		ui.txtWizard->clear();
		ui.txtWizard->setPlainText("                                ͼ��ָ�          ");
		ui.txtWizard->append("���ܣ��ָ�ԭʼDICOM���õ�ֻ�����ض���λ����DICOM");
		ui.txtWizard->append("����ָ����������ȵõ����������λ��ģ�ͣ�mesh����������֮����ʾ����3d͸��Ч���������Ҫ�ָ�ͷ­����ô���Ƚ����������ɨ��DICOM�����һ�������ڣ��ٽ�����ͷ­������ͼ������ڶ�����������ٵ�����ָ��ť��������ɷָ�ָ�ʱ���ͼƬ�϶࣬����Ҫ�ȴ�һ��ʱ�䣬���Եȡ�");
	}
	else if(processStep==2)
	{
		ui.txtWizard->clear();
		ui.txtWizard->setPlainText("                               mesh����          ");
		ui.txtWizard->append("���ܣ���ԭʼmesh���д���");
		ui.txtWizard->append("����ָ����������ѡ����Ҫ�Ĵ���ʽ������lapace smoothing�Լ�ƽ�����������������Եõ������۵�mesh");
		ui.txtWizard->append("PS:Ŀǰ�汾����ֻ�ṩ��ƽ���������������и���Ĵ���ʽ��ѡ��");

	}
	else if(processStep==3)
	{
		ui.txtWizard->clear();
		ui.txtWizard->setPlainText("                               ����ṹ����         ");
		ui.txtWizard->append("���ܣ������轫���û��Զ��������3D�ṹ");
		ui.txtWizard->append("����ָ����������Ѿ������������λ��mesh,��ô��������Щmesh��Ӧ�ķ�������ӡ������ڡ������㡱�����ڣ��������ͷ­�����ǡ��ŹǵȲ�λ��mesh�������û����Щmesh���뷵�ص�һ�����в���");
	}
	else
	{

	}




	if(flagCurrentToolbar==1)
	{
		ui.lblShowFirstStep->show();
		ui.lblShowSecondStep->show();
		ui.lblShowThirdStep->show();
		if(processStep==1)
		{
			ui.btnImageSegmentation->setEnabled(true);
			ui.btnMeshProcess->setEnabled(false);
			ui.btnAnatomyDefine->setEnabled(false);
			ui.btnAnatomyShow->setEnabled(false);

			ui.lblShowFirstStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowSecondStep->setPixmap(QPixmap::fromImage(imgGrayArrow));
			ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgGrayArrow));


		}
		else if(processStep==2)
		{
			ui.btnImageSegmentation->setEnabled(true);
			ui.btnMeshProcess->setEnabled(true);
			ui.btnAnatomyDefine->setEnabled(false);
			ui.btnAnatomyShow->setEnabled(false);

			ui.lblShowFirstStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowSecondStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgGrayArrow));
		}
		else if(processStep==3)
		{
			ui.btnImageSegmentation->setEnabled(true);
			ui.btnMeshProcess->setEnabled(true);
			ui.btnAnatomyDefine->setEnabled(true);
			ui.btnAnatomyShow->setEnabled(false);

			ui.lblShowFirstStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowSecondStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
		}
		else
		{
			ui.btnImageSegmentation->setEnabled(true);
			ui.btnMeshProcess->setEnabled(true);
			ui.btnAnatomyDefine->setEnabled(true);
			ui.btnAnatomyShow->setEnabled(true);

			ui.lblShowFirstStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowSecondStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
		}
	}
	else if(flagCurrentToolbar==2)
	{
		//����Ǵӵڶ�����ʼ����ô��һ����button����ʾ
		ui.btnImageSegmentation->setVisible(false);
		ui.lblShowSecondStep->show();
		ui.lblShowThirdStep->show();
		if(processStep==2)
		{
			ui.btnMeshProcess->setEnabled(true);
			ui.btnAnatomyDefine->setEnabled(false);
			ui.btnAnatomyShow->setEnabled(false);
			ui.lblShowSecondStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgGrayArrow));
		}
		else if(processStep==3)
		{
			ui.btnMeshProcess->setEnabled(true);
			ui.btnAnatomyDefine->setEnabled(true);
			ui.btnAnatomyShow->setEnabled(false);
		
			ui.lblShowSecondStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
		}
		else
		{
			ui.btnMeshProcess->setEnabled(true);
			ui.btnAnatomyDefine->setEnabled(true);
			ui.btnAnatomyShow->setEnabled(true);
			ui.lblShowSecondStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
			ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
		}

	}
	else
	{
		ui.lblShowThirdStep->show();
		ui.btnImageSegmentation->setVisible(false);
		ui.btnMeshProcess->setVisible(false);
		if(processStep==3)
		{
			ui.btnAnatomyDefine->setEnabled(true);
			ui.btnAnatomyShow->setEnabled(false);
			ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
		}
		else
		{
			ui.btnAnatomyDefine->setEnabled(true);
			ui.btnAnatomyShow->setEnabled(true);
			ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
		}
	}
}

//���ӡ�mesh������ʼ����ʱ����ʾ��ߵ�Toturial��ֻ��ʾ3��button
//processStep=1 ��ǰ����Ϊmesh����
//processStep=2 ��ǰ����Ϊ�ṹ����
//processStep=3 ��ǰ����Ϊ��ʾ
/*void AnatomyShow::ShowToturialWhenProcessFromMesh(int flagCurrentToolbar,int processStep)
{

}*/

//���ӡ�anatomy���塱��ʼ����ʱ����ʾ��ߵ�Toturial��ֻ��ʾ���ṹ���塱�͡���ʾ������button
//processStep=1 ��ǰ����Ϊ�ṹ����
//processStep=2 ��ǰ����Ϊ��ʾ
/*void AnatomyShow::ShowToturialWhenProcessFromAnatomyDefine(int flagCurrentToolbar,int processStep)
{

}*/

//���toolbar�ϵġ���Anatomy���忪ʼ������ʾ��������Լ��ұ�anatomy�����Ӧ�Ľ���
void AnatomyShow::ToolbarProcessFromAnatomyClicked()
{
	flagCurrentToolbar=3;
	if(windowMeshProcess!=NULL)
		delete windowMeshProcess;	
	windowMeshProcess=new MeshProcess(this);
	if(windowImageSegmentation!=NULL)
		delete windowImageSegmentation;	
	windowImageSegmentation=new ImageSegmentation(this);
	if(windowAnatomyDefine!=NULL)
		delete windowAnatomyDefine;	
	windowAnatomyDefine=new AnatomyDefine(this);
	this->windowHelpVizard->hide();
	this->windowAnatomyDefine->show();
	
	this->windowMeshProcess->hide();
	this->windowImageSegmentation->hide();



	ui.lblShowFirstStep->hide();
	ui.lblShowSecondStep->hide();
	ui.lblShowThirdStep->show();
	ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgBlackArrow));

	AdjustLeft(3);
	ShowLeftToturial(3,3);
	ui.txtWizard->show();
	ui.line->show();
	
	connect(windowImageSegmentation,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowMeshProcess,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowAnatomyDefine,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	//	connect(windowImageSegmentation,SIGNAL(signalMeshPath(QString)),this,SLOT(GetCurrentMeshPath(QString)));
	//connect(windowImageSegmentation,SIGNAL(signalDestDICOMDirectory(QString)),windowMeshProcess,SLOT(GetDestDICOMDirectory(QString)));

}

//���toolbar�ϵġ���ͼ��ָʼ������ʾ��������Լ�ͼ��ָ��Ӧ�Ľ���
void AnatomyShow::ToolbarProcessFromImageClicked()
{
	
	flagCurrentToolbar=1;
	if(windowMeshProcess!=NULL)
		delete windowMeshProcess;
	windowMeshProcess=new MeshProcess(this);
	if(windowImageSegmentation!=NULL)
		delete windowImageSegmentation;
	windowImageSegmentation=new ImageSegmentation(this);
	if(windowAnatomyDefine!=NULL)
		delete windowAnatomyDefine;
	windowAnatomyDefine=new AnatomyDefine(this);
	this->windowHelpVizard->hide();
	this->windowAnatomyDefine->hide();
	this->windowMeshProcess->hide();
	this->windowImageSegmentation->show();
	windowImageSegmentation->ShowVTKWindow();


	ui.lblShowFirstStep->show();
	ui.lblShowSecondStep->show();
	ui.lblShowThirdStep->show();

	ui.lblShowFirstStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
	ui.lblShowSecondStep->setPixmap(QPixmap::fromImage(imgGrayArrow));
	ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgGrayArrow));

	AdjustLeft(1);
	ShowLeftToturial(1,1);
	ui.txtWizard->show();
	ui.line->show();

	connect(windowImageSegmentation,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowMeshProcess,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowAnatomyDefine,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	//	connect(windowImageSegmentation,SIGNAL(signalMeshPath(QString)),this,SLOT(GetCurrentMeshPath(QString)));
//	connect(windowImageSegmentation,SIGNAL(signalDestDICOMDirectory(QString)),windowMeshProcess,SLOT(GetDestDICOMDirectory(QString)));
	connect(windowMeshProcess,SIGNAL(signalPrevStep()),this,SLOT(ShowPrevStep()));
}

//���toolbar�ϵġ���mesh����ʼ������ʾ��������Լ�mesh�����Ӧ�Ľ���
void AnatomyShow::ToolbarProcessFromMeshClicked()
{
	flagCurrentToolbar=2;
	if(windowMeshProcess!=NULL)
		delete windowMeshProcess;	
	windowMeshProcess=new MeshProcess(this);
	if(windowImageSegmentation!=NULL)
		delete windowImageSegmentation;	
	windowImageSegmentation=new ImageSegmentation(this);
	if(windowAnatomyDefine!=NULL)
		delete windowAnatomyDefine;	
	windowAnatomyDefine=new AnatomyDefine(this);
	this->windowHelpVizard->hide();
	this->windowAnatomyDefine->hide();
	this->windowImageSegmentation->hide();
	this->windowMeshProcess->show();
	this->windowMeshProcess->ShowAddMeshButton();


	ui.lblShowFirstStep->hide();
	ui.lblShowSecondStep->show();
	ui.lblShowThirdStep->show();

	ui.lblShowSecondStep->setPixmap(QPixmap::fromImage(imgBlackArrow));
	ui.lblShowThirdStep->setPixmap(QPixmap::fromImage(imgGrayArrow));
	
	AdjustLeft(2);
	ShowLeftToturial(2,2);
	ui.txtWizard->show();
	ui.line->show();
	
	connect(windowImageSegmentation,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowMeshProcess,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowAnatomyDefine,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	//	connect(windowImageSegmentation,SIGNAL(signalMeshPath(QString)),this,SLOT(GetCurrentMeshPath(QString)));
	//connect(windowImageSegmentation,SIGNAL(signalDestDICOMDirectory(QString)),windowMeshProcess,SLOT(GetDestDICOMDirectory(QString)));

}

//���toturial�еġ�ͼ��ָ���
void AnatomyShow::ImageSegmentationClicked()
{
	this->windowAnatomyDefine->hide();
	this->windowHelpVizard->hide();
	
	this->windowMeshProcess->hide();
	this->windowImageSegmentation->show();
	this->windowImageSegmentation->ShowVTKWindow();

}

void AnatomyShow::MeshProcessClicked()
{
	this->windowAnatomyDefine->hide();
	this->windowHelpVizard->hide();
	this->windowImageSegmentation->hide();
	this->windowMeshProcess->show();

	this->windowMeshProcess->ShowVTKWindow();
	
	
}

void AnatomyShow::AnatomyDefineClicked()
{	
	
	this->windowHelpVizard->hide();
	this->windowImageSegmentation->hide();
	this->windowMeshProcess->hide();
	this->windowAnatomyDefine->show();
}


void AnatomyShow::AnatomyShowClicked()
{
	QString cmd="\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\" localhost";
	qDebug()<<cmd;
	system(cmd.toStdString().c_str());

}

void AnatomyShow::ShowNextStep(int processStep)
{
	ShowLeftToturial(flagCurrentToolbar,processStep);
	if(processStep==2)
	{
		
		windowAnatomyDefine->hide();
		windowImageSegmentation->hide();
		windowMeshProcess->show();
	//	windowMeshProcess->ShowVTKWindow();
		windowMeshProcess->ShowMesh();
	}
	else if(processStep==3)
	{
		windowMeshProcess->hide();
		windowImageSegmentation->hide();
		windowAnatomyDefine->show();
		

	}
	//�����4����ô����ʾ���������
	else
	{

	}

}

void AnatomyShow::HideAll()
{
	ui.btnAnatomyDefine->hide();
	ui.btnAnatomyShow->hide();
	ui.btnImageSegmentation->hide();
	ui.btnMeshProcess->hide();
	ui.lblShowFirstStep->hide();
	ui.lblShowSecondStep->hide();
	ui.lblShowThirdStep->hide();
	ui.txtWizard->hide();
	ui.line->hide();
}


void AnatomyShow::ShowPrevStep()
{
	
	
	ShowLeftToturial(flagCurrentToolbar,1);
	if(windowMeshProcess!=NULL)
		delete windowMeshProcess;
	windowMeshProcess=new MeshProcess(this);
	if(windowImageSegmentation!=NULL)
		delete windowImageSegmentation;
	windowImageSegmentation=new ImageSegmentation(this);
	if(windowAnatomyDefine!=NULL)
		delete windowAnatomyDefine;
	windowAnatomyDefine=new AnatomyDefine(this);
	connect(windowImageSegmentation,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowMeshProcess,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	connect(windowAnatomyDefine,SIGNAL(signalNextStep(int)),this,SLOT(ShowNextStep(int)));
	//	connect(windowImageSegmentation,SIGNAL(signalMeshPath(QString)),this,SLOT(GetCurrentMeshPath(QString)));
	connect(windowImageSegmentation,SIGNAL(signalDestDICOMDirectory(QString)),windowMeshProcess,SLOT(GetDestDICOMDirectory(QString)));
	windowMeshProcess->hide();
	windowAnatomyDefine->hide();
	windowImageSegmentation->show();
}


void AnatomyShow::AlignWindow()
{
	//align button
	ui.btnImageSegmentation->resize(buttonWidth, buttonHeight);
	ui.btnMeshProcess->resize(buttonWidth, buttonHeight);
	ui.btnAnatomyDefine->resize(buttonWidth, buttonHeight);
	ui.btnAnatomyShow->resize(buttonWidth, buttonHeight);
	ui.btnImageSegmentation->move(buttonshiftX, buttonshiftY);	
	ui.btnMeshProcess->move(buttonshiftX, buttonshiftY + 2 * buttonHeight);	
	ui.btnAnatomyDefine->move(buttonshiftX, buttonshiftY + 4 * buttonHeight);	
	ui.btnAnatomyShow->move(buttonshiftX, buttonshiftY + 6 * buttonHeight);

	//align arrow label 

	ui.lblShowFirstStep->resize(buttonHeight, buttonHeight);
	ui.lblShowSecondStep->resize(buttonHeight, buttonHeight);
	ui.lblShowThirdStep->resize(buttonHeight, buttonHeight);
	ui.lblShowFirstStep->move(labelShiftX, buttonshiftY + 1 * buttonHeight);
	ui.lblShowSecondStep->move(labelShiftX, buttonshiftY + 3 * buttonHeight);
	ui.lblShowThirdStep->move(labelShiftX, buttonshiftY + 5 * buttonHeight);

	//align text
	int textHeight = maxWindowHeight * 0.2 - 20;
	int textWidth =  maxWindowWidth * 0.8;
	ui.txtWizard->resize(textWidth, textHeight);
	ui.txtWizard->move(maxWindowWidth * 0.2, 20 + maxWindowHeight * 0.8);

	//align line
	ui.line->resize(1, maxWindowHeight - 20);
	ui.line->move(maxWindowWidth * 0.2, 20);


}



void AnatomyShow::AdjustLeft(int start)
{
	if (start == 1)
	{
		ui.btnImageSegmentation->move(buttonshiftX, buttonshiftY);	
		ui.btnMeshProcess->move(buttonshiftX, buttonshiftY + 2 * buttonHeight);	
		ui.btnAnatomyDefine->move(buttonshiftX, buttonshiftY + 4 * buttonHeight);	
		ui.btnAnatomyShow->move(buttonshiftX, buttonshiftY + 6 * buttonHeight);

		ui.lblShowFirstStep->move(labelShiftX, buttonshiftY + 1 * buttonHeight);
		ui.lblShowSecondStep->move(labelShiftX, buttonshiftY + 3 * buttonHeight);
		ui.lblShowThirdStep->move(labelShiftX, buttonshiftY + 5 * buttonHeight);

	}
	else if (start == 2)
	{
		ui.btnMeshProcess->move(buttonshiftX, buttonshiftY + 1 * buttonHeight);	
		ui.btnAnatomyDefine->move(buttonshiftX, buttonshiftY + 3 * buttonHeight);	
		ui.btnAnatomyShow->move(buttonshiftX, buttonshiftY + 5 * buttonHeight);

		ui.lblShowSecondStep->move(labelShiftX, buttonshiftY + 2 * buttonHeight);
		ui.lblShowThirdStep->move(labelShiftX, buttonshiftY + 4 * buttonHeight);
	}
	else
	{
		ui.btnAnatomyDefine->move(buttonshiftX, buttonshiftY + 2 * buttonHeight);	
		ui.btnAnatomyShow->move(buttonshiftX, buttonshiftY + 4 * buttonHeight);

		ui.lblShowThirdStep->move(labelShiftX, buttonshiftY + 3 * buttonHeight);
	}
}