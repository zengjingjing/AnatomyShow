#include "anatomyshow.h"
#include <QtGui/QApplication>
#include <QTextCodec>
#include <QDebug>
#include <QRect>
#include <QDesktopWidget>
QString sourceDICOMDirectory;
QString bmpDirectory;
QString destDICOMDirectory;
QString assembledOBJFileName="web\\models\\human\\human.obj";
int flagCurrentToolbar;
int maxWindowWidth;
int maxWindowHeight;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec *codec = QTextCodec::codecForName("GBK");//ַי¿צ1
	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	//QRect rect=QApplication::desktop()->availableGeometry();
	//qDebug()<<"rect=="<<rect.width()<<" "<<rect.height();
	AnatomyShow w;
	w.show();
	//w.showMaximized();
	return a.exec();
}
