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
		void AdjustLeft(int start);//start=1 �ӡ�ͼ��ָ��ʼ�� =2 �ӡ�mesh������ʼ�� =3 �ӡ����塱��ʼ
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

	QImage imgBlackArrow;//��ɫ��ͷ,enable
	QImage imgGrayArrow;//��ɫ��ͷ,disable

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
