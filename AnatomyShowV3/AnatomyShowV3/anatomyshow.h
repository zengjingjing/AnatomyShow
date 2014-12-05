#ifndef ANATOMYSHOW_H
#define ANATOMYSHOW_H

#include <QtGui/QMainWindow>
#include <QRect>
#include <QDesktopWidget>
#include <QImage>
#include "ui_anatomyshow.h"
#include "imagesegmentation.h"
#include "meshprocess.h"
#include "anatomydefine.h"
#include "helpvizard.h"

class AnatomyShow : public QMainWindow
{
	Q_OBJECT

public:
	AnatomyShow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AnatomyShow();
	
		void ShowLeftToturial(int flagCurrentToolbar,int processStep);
		void HideAll();
		void AlignWindow();
		void AdjustLeft(int start);//start=1 从“图像分割”开始； =2 从“mesh处理”开始； =3 从“定义”开始
		//void ShowToturialWhenProcessFromMesh(int flagCurrentToolbar,int processStep);
		//void ShowToturialWhenProcessFromAnatomyDefine(int flagCurrentToolbar,int processStep);
	public slots:
		void ToolbarProcessFromImageClicked();
		void ToolbarProcessFromMeshClicked();
		void ToolbarProcessFromAnatomyClicked();
		void ImageSegmentationClicked();
		void MeshProcessClicked();
		void AnatomyDefineClicked();
		void AnatomyShowClicked();
		void ShowNextStep(int);
		void ShowPrevStep();

private:
	Ui::AnatomyShowClass ui;
	ImageSegmentation * windowImageSegmentation;
	MeshProcess *windowMeshProcess;
	AnatomyDefine *windowAnatomyDefine;
	HelpVizard * windowHelpVizard;

	QImage imgBlackArrow;//黑色箭头,enable
	QImage imgGrayArrow;//灰色箭头,disable

	//int maxWindowWidth;
	//int maxWindowHeight;
	int dockWindowSize;
	int labelShiftX;

	//left button size and shift
	int buttonWidth;
	int buttonHeight;
	int buttonshiftX;
	int buttonshiftY;
};

#endif // ANATOMYSHOW_H
