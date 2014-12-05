#ifndef IMAGEPROCESSTHREAD_H
#define IMAGEPROCESSTHREAD_H
 #undef UNICODE
#include <QThread>
#include <QDebug>
#include <QDir>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <string>
#include <list>
#include <windows.h>
using namespace std;
class ImageProcessThread : public QThread
{
	Q_OBJECT

public:
	ImageProcessThread(QObject *parent);
	~ImageProcessThread();
	void CheckIfInPolyOneContour(ofstream &outfile,int num1,float *arr1X,float* arr1Y);//�������ֻ��һ������ôɨ������ͼ��������ڶ�����ڣ���ô�����
	void CheckIfInPolyTwoContour(ofstream &outfile,int num1,int num2,float *arr1X,float* arr1Y,float *arr2X,float* arr2Y);//�������������
	int Pnpoly(int nvert, float *vertx, float *verty, float testx, float testy);
	void PreProcess(IplImage * img);//��ԭʼͼ�����Ԥ�������������ú�ɫ��ʾ�����������ú�ɫ��ʾ
	public slots:
		//void ImageProcess(QString,QString,QString);
		void ImageProcess();
protected:
	void run();

private:
//	QString sourceDICOMDirectory;
//	QString bmpDirectory;
//	QString destDICOMDirectory;
	QString outputContourInfoFileName;
signals:
	void signalImageProcessDone();
	void signalOBJCompressDone();
	
};

#endif // IMAGEPROCESSTHREAD_H
