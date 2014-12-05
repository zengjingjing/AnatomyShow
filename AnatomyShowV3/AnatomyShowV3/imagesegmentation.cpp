#include "imagesegmentation.h"


extern QString sourceDICOMDirectory;
extern QString bmpDirectory;
extern QString destDICOMDirectory;
extern int maxWindowHeight;
extern int maxWindowWidth;

ImageSegmentation::ImageSegmentation(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	resize(maxWindowWidth * 0.8, maxWindowHeight * 0.8);
	move(maxWindowWidth * 0.2 + 20, 20);
	setWindowFlags(Qt::FramelessWindowHint);
	hide();
	ui.progressBar->setRange(0,0);
	ui.progressBar->hide();

	this->pixOfSegmentationDisable.load(":/MyImages/images/segmentation2.png");
	this->pixOfSegmentationEnable.load(":/MyImages/images/segmentation.png");
	ui.btnSegmentation->resize(pixOfSegmentationEnable.size());
	ui.btnSegmentation->setIcon(pixOfSegmentationEnable);
	ui.btnSegmentation->setIconSize(pixOfSegmentationDisable.size());


	 ui.btnNextStep->setEnabled(false);
	 viewSourceDICOM=vtkSmartPointer<vtkImageViewer2>::New();
	 viewDestDICOM=vtkSmartPointer<vtkImageViewer2>::New();
	 viewBMP=vtkSmartPointer<vtkImageViewer2>::New();
	 this->ShowVTKWindow();
	 ui.sliderSourceDICOM->setEnabled(false);
	 ui.sliderDestDICOM->setEnabled(false);
	 ui.sliderBMP->setEnabled(false);

}

ImageSegmentation::~ImageSegmentation()
{

}


//下面4个是点击界面上4个button的响应函数
void ImageSegmentation::OpenSourceDICOM()
{
	
	sourceDICOMDirectory = QFileDialog::getExistingDirectory(this,tr("open DICOM Directory"),QDir::currentPath(),QFileDialog::ShowDirsOnly);
	qDebug()<<sourceDICOMDirectory;
	int mMinSliderX;
	int mMaxSliderX;
	if(sourceDICOMDirectory.isEmpty())return ;
	vtkSmartPointer<vtkDICOMImageReader> reader=vtkSmartPointer<vtkDICOMImageReader>::New();

	reader->SetDirectoryName(sourceDICOMDirectory.toStdString().c_str());
	reader->Update();
	viewSourceDICOM->SetInputConnection(reader->GetOutputPort());
	mMinSliderX = viewSourceDICOM->GetSliceMin();
	mMaxSliderX = viewSourceDICOM->GetSliceMax();
	ui.sliderSourceDICOM->setMinimum(mMinSliderX);
	ui.sliderSourceDICOM->setMaximum(mMaxSliderX);
	viewSourceDICOM->SetRenderWindow(ui.vtkSourceDICOM->GetRenderWindow());
	viewSourceDICOM->Render();
	ui.vtkSourceDICOM->GetRenderWindow()->Render();
	ui.sliderSourceDICOM->setEnabled(true);
}

//这里读取BMP采用的是xx.bmp的格式，前面两位数字，如果以后BMP命名有3位数字，那么要改一下。以后还要把批量重命名加进去
void ImageSegmentation::OpenBMP()
{
	bmpDirectory = QFileDialog::getExistingDirectory(this,tr("open BMP Directory"),QDir::currentPath(),QFileDialog::ShowDirsOnly);
	qDebug()<<bmpDirectory;
	if(bmpDirectory.isEmpty())return ;
	QDir dir(bmpDirectory);
	dir.setFilter(QDir::Files);
	dir.setSorting(QDir::Time| QDir::Reversed);

	list = dir.entryInfoList();
	int count=list.count();
	ui.sliderBMP->setMinimum(1);
	ui.sliderBMP->setMaximum(count);
	QPixmap pix(list.at(0).filePath());
	ui.lblShowBMP->setPixmap(pix.scaled(180,320));
	ui.sliderBMP->setEnabled(true);
}


void ImageSegmentation::NextStep()
{
	emit signalNextStep(2);
	//emit signalDestDICOMDirectory(destDICOMDirectory);
}


void ImageSegmentation::StartSegmentation()
{
	if(sourceDICOMDirectory.isEmpty() || bmpDirectory.isEmpty())
	{
		QMessageBox::warning(NULL, "warning", "Sure to open DICOM and BMP!!!"); 
		return ;
	}

	ui.progressBar->show();
	int index=sourceDICOMDirectory.toStdString().find_last_of('\\');
	string temp1=sourceDICOMDirectory.toStdString().substr(0,index);
	string temp2=sourceDICOMDirectory.toStdString().erase(0,index+1);
	temp2="\\New"+temp2;
	temp2=temp1+temp2;
	destDICOMDirectory=QString::fromStdString(temp2);	
	ui.btnSegmentation->setEnabled(false);
	ui.btnSegmentation->setIcon(pixOfSegmentationDisable);
	
	this->processThread=new ImageProcessThread(this);
//	connect(this,SIGNAL(signalImageProcess(QString,QString,QString)),processThread,SLOT(ImageProcess(QString,QString,QString)));
	//connect(this,SIGNAL(signalImageProcess()),processThread,SLOT(ImageProcess()));
	connect(processThread,SIGNAL(signalImageProcessDone()),this,SLOT(ImageProcessDone()));
	processThread->start();
//	emit signalImageProcess(this->sourceDICOMDirectory,this->destDICOMDirectory,this->bmpDirectory);
	//signalImageProcess();

}


//滑动滚动条，显示图像序列，下面3个都是滑动滚动条的响应函数
void ImageSegmentation::SliderShowSourceDICOM(int position)
{
	viewSourceDICOM->SetSlice(position);
	viewSourceDICOM->Render();
}

void ImageSegmentation::SliderShowBMP(int position)
{
	QString str=list.at(position-1).filePath();
	QPixmap pix(str);
	ui.lblShowBMP->setPixmap(pix.scaled(180,320));
}

void ImageSegmentation::SliderShowDestDICOM(int position)
{
	viewDestDICOM->SetSlice(position);
	viewDestDICOM->Render();
}


void ImageSegmentation::ShowDestDICOM()
{
	int mMinSliderX;
	int mMaxSliderX;
	vtkSmartPointer<vtkDICOMImageReader> reader=vtkSmartPointer<vtkDICOMImageReader>::New();
	reader->SetDirectoryName(destDICOMDirectory.toStdString().c_str());
	reader->Update();
	viewDestDICOM->SetInputConnection(reader->GetOutputPort());
	mMinSliderX = viewDestDICOM->GetSliceMin();
	mMaxSliderX = viewDestDICOM->GetSliceMax();
	ui.sliderDestDICOM->setMinimum(mMinSliderX);
	ui.sliderDestDICOM->setMaximum(mMaxSliderX);
	viewDestDICOM->SetRenderWindow(ui.vtkDestDICOM->GetRenderWindow());
	viewDestDICOM->Render();
	ui.vtkDestDICOM->GetRenderWindow()->Render();
}


void ImageSegmentation::ImageProcessDone()
{
	ui.progressBar->hide();
	ui.btnSegmentation->setEnabled(true);
	ui.btnNextStep->setEnabled(true);
	ui.btnSegmentation->setIcon(pixOfSegmentationEnable);
	QMessageBox::information(NULL, "information", "process done....");
	ShowDestDICOM();
	ui.sliderDestDICOM->setEnabled(true);
	ui.btnNextStep->setEnabled(true);
	if(processThread->isRunning())
	{
		processThread->terminate();
		delete processThread;
	}
	

}



void ImageSegmentation::ShowVTKWindow()
{
	ui.vtkDestDICOM->GetRenderWindow()->Render();
	ui.vtkSourceDICOM->GetRenderWindow()->Render();
}
