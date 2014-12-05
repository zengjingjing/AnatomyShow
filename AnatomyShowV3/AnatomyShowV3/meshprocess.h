#ifndef MESHPROCESS_H
#define MESHPROCESS_H

#include <QDialog>
#include "ui_meshprocess.h"
#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <QVTKWidget.h>
#include <vtkImageShiftScale.h>
#include <vtkImageData.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkMarchingCubes.h>
#include <vtkPolyDataMapper.h>
#include <vtkOBJExporter.h>
#include <QFileDialog>
#include <string>
#include <vtkOBJReader.h>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <vtkRendererCollection.h>
#include <iostream>
#include <vector>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
using namespace std;
class MeshProcess : public QDialog
{
	Q_OBJECT

public:
	MeshProcess(QWidget *parent = 0);
	~MeshProcess();
	void ShowVTKWindow();
	void ShowMesh();
	void ReadOBJAndShow(QVTKWidget* vtkShow,QString meshName);
	void MeshRecoveryWithNormal(string source,string dest);
	void ShowAddMeshButton();
	bool laplaceSmooth(int smoothCount,QString sourceMesh,QString destMesh);
	public slots:
		void OpenSourceMesh();
		//void GetDestDICOMDirectory(QString);
		void StartMeshProcess();
		void SaveMesh();
		void NextStep();
		void PrevStep();

private:
	Ui::MeshProcess ui;
	int smoothCount;
	QString destDICOMDirectory;
	QString sourceMeshName;
	QPixmap pixOfNextStepEnable;
	QPixmap pixOfNextStepDisable;
	bool processed;
	vtkSmartPointer<vtkRenderer> renderer;
signals:
	void signalNextStep(int);
	void signalPrevStep();

};

#endif // MESHPROCESS_H
