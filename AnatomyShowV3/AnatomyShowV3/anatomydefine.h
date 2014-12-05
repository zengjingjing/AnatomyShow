#ifndef ANATOMYDEFINE_H
#define ANATOMYDEFINE_H

#include <QDialog>
#include "ui_anatomydefine.h"
#include <QFileDialog>
#include <fstream>
#include <string>
#include <QStringList>
#include <QMap>
#include <QList>
#include <QDebug>
#include <sstream>  
#include "generatemodelthread.h"
using namespace std;
typedef struct OBJ
{
	QString objName;
	QString objId;

}OBJ;
class AnatomyDefine : public QDialog
{
	Q_OBJECT

public:
	AnatomyDefine(QWidget *parent = 0);
	~AnatomyDefine();
	void HandleUIData();
	void EraseModelJS();//修改script中的model.js，主要是修改numLayers
	public slots:
		void SkinAdd();
		void SkinSub();
		void MuscleAdd();
		void MuscleSub();
		void BoneAdd();
		void BoneSub();
		void OrganAdd();
		void OrganSub();
		void NerveAdd();
		void NerveSub();
		void ArteryAdd();
		void ArterySub();
		void GenerateModel();
		void GenerateDone();
		
private:
	Ui::AnatomyDefine ui;
	QMap<QString,QStringList> anatomy;
	QStringList materialList;
	QStringList layerList;
	QStringList meshNameList;
	QStringList idList;
	GenerateModelThread * generate_thread;
	int numLayers;


signals:
	void signalNextStep(int);

};

#endif // ANATOMYDEFINE_H
