#ifndef IMAGESEGMENTATION_H
#define IMAGESEGMENTATION_H
#include <QDialog>
#include "ui_imagesegmentation.h"
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkBMPReader.h>
#include <QVTKWidget.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QPixmap>
#include <QDebug>
#include<QPixmap>
#include "imageprocessthread.h"
using namespace std;
class ImageSegmentation : public QDialog
{
	Q_OBJECT

public:
	ImageSegmentation(QWidget *parent = 0);
	~ImageSegmentation();
	void ShowVTKWindow();
	void ShowDestDICOM();
public slots:
	void OpenSourceDICOM();
	void OpenBMP();
	void StartSegmentation();
	void NextStep();
	void SliderShowSourceDICOM(int position);
	void SliderShowBMP(int position);
	void SliderShowDestDICOM(int position);
	void ImageProcessDone();
	
signals:
//	void signalImageProcess(QString,QString,QString);
//	void signalImageProcess();
	void signalNextStep(int);
	//void signalDestDICOMDirectory(QString);

private:
	Ui::ImageSegmentation ui;

	vtkSmartPointer<vtkImageViewer2> viewSourceDICOM;
	vtkSmartPointer<vtkImageViewer2> viewDestDICOM;
	vtkSmartPointer<vtkImageViewer2> viewBMP;
//	QString outputContourInfoFileName;
	ImageProcessThread * processThread;
	QFileInfoList list;

	QPixmap pixOfSegmentationEnable;
	QPixmap pixOfSegmentationDisable;

};

#endif // IMAGESEGMENTATION_H
