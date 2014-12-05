#include "anatomyshow.h"

extern int flagCurrentToolbar;
extern int maxWindowHeight;
extern int maxWindowWidth;

AnatomyShow::AnatomyShow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//move(200,100);
	//flagCurrentToolbar=1 从图像分割开始
	//flagCurrentToolbar=2 从mesh处理开始
	//flagCurrentToolbar=3 从结构定义开始
	//setWindowFlags(Qt::WindowMinMaxButtonsHint|Qt::MSWindowsFixedSizeDialogHint );
	// setWindowState(Qt::WindowMaximized);
	// setWindowState(Qt::WindowFullScreen );
	setWindowTitle("人体解剖学3D透视显示");
	setWindowIcon(QIcon(":/MyImages/images/anatomy.jpg"));
	QRect rect=QApplication::desktop()->availableGeometry();
	maxWindowHeight=rect.height();
	maxWindowWidth=rect.width();
	this->resize(maxWindowWidth,maxWindowHeight);
	setWindowFlags(Qt::WindowMinMaxButtonsHint|Qt::MSWindowsFixedSizeDialogHint );

	//左边栏，在整个窗口左边的1/5内
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

//当从“图像分割”开始处理时，显示左边的Toturial，所有button都显示
//flagCurrentToolbar=1 从图像分割开始
//flagCurrentToolbar=2 从mesh处理开始
//flagCurrentToolbar=3 从结构定义开始


//processStep=1 当前步骤为图像分割，只有“图像分割”可以点击，其他button为灰，以此类推
//processStep=2 当前步骤为mesh处理
//processStep=3 当前步骤为结构定义
//processStep=4 当前步骤为显示
void AnatomyShow::ShowLeftToturial(int flagCurrentToolbar,int processStep)
{
	ui.btnAnatomyDefine->setVisible(true);
	ui.btnImageSegmentation->setVisible(true);
	ui.btnMeshProcess->setVisible(true);
	ui.btnAnatomyShow->setVisible(true);
	//处理主界面下面的"帮助"
	if(processStep==1)
	{
		ui.txtWizard->clear();
		ui.txtWizard->setPlainText("                                图像分割          ");
		ui.txtWizard->append("功能：分割原始DICOM，得到只含有特定部位的新DICOM");
		ui.txtWizard->append("操作指导：你必须先得到人体各个部位的模型（mesh），才能在之后显示人体3d透视效果。如果你要分割头颅，那么请先将整个人体的扫描DICOM输入第一个方框内，再将标有头颅轮廓的图像输入第二个方框。最后再点击“分割”按钮，即可完成分割。分割时如果图片较多，则需要等待一段时间，请稍等～");
	}
	else if(processStep==2)
	{
		ui.txtWizard->clear();
		ui.txtWizard->setPlainText("                               mesh处理          ");
		ui.txtWizard->append("功能：将原始mesh进行处理");
		ui.txtWizard->append("操作指导：您可以选择需要的处理方式，比如lapace smoothing以及平滑次数，这样您可以得到更美观的mesh");
		ui.txtWizard->append("PS:目前版本程序只提供了平滑操作，后续会有更多的处理方式供选择～");

	}
	else if(processStep==3)
	{
		ui.txtWizard->clear();
		ui.txtWizard->setPlainText("                               人体结构定义         ");
		ui.txtWizard->append("功能：本步骤将由用户自定义人体的3D结构");
		ui.txtWizard->append("操作指导：如果你已经有人体各个部位的mesh,那么可以在这些mesh对应的方框内添加。比如在“骨骼层”方框内，可以添加头颅、锁骨、髋骨等部位的mesh。如果还没有这些mesh，请返回第一步进行操作");
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
		//如果是从第二步开始，那么第一步的button不显示
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

//当从“mesh处理”开始处理时，显示左边的Toturial，只显示3个button
//processStep=1 当前步骤为mesh处理
//processStep=2 当前步骤为结构定义
//processStep=3 当前步骤为显示
/*void AnatomyShow::ShowToturialWhenProcessFromMesh(int flagCurrentToolbar,int processStep)
{

}*/

//当从“anatomy定义”开始处理时，显示左边的Toturial，只显示“结构定义”和“显示”两个button
//processStep=1 当前步骤为结构定义
//processStep=2 当前步骤为显示
/*void AnatomyShow::ShowToturialWhenProcessFromAnatomyDefine(int flagCurrentToolbar,int processStep)
{

}*/

//点击toolbar上的“从Anatomy定义开始”，显示左边栏，以及右边anatomy定义对应的界面
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

//点击toolbar上的“从图像分割开始”，显示左边栏，以及图像分割对应的界面
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

//点击toolbar上的“从mesh处理开始”，显示左边栏，以及mesh处理对应的界面
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

//左边toturial中的“图像分割”点击
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
	//如果是4，那么就显示浏览器窗口
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