#ifndef GENERATEMODELTHREAD_H
#define GENERATEMODELTHREAD_H

#include <QThread>
#include<QDebug>
#include <QStringList>
#include <fstream>
#include <string>
#include <QMap>
using namespace std;
class GenerateModelThread : public QThread
{
	Q_OBJECT

public:
	GenerateModelThread(QObject *parent,QMap<QString,QStringList> anatomy,QStringList materialList,QStringList layerList,QStringList meshNameList,QStringList idList);
	~GenerateModelThread();
	void AssembleMesh();
	void CompressAndGenerateJS();
	void GenerateJSONFile();
protected:
	void run();

private:
	QMap<QString,QStringList> anatomy;
	QStringList materialList;
	QStringList layerList;
	QStringList meshNameList;
	QStringList idList;
signals:
	void signalGenerateDone();
	
};

#endif // GENERATEMODELTHREAD_H
