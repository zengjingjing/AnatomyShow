#include "imageprocessthread.h"
typedef struct Point
{
	int x;
	int y;
}Point;

#define  WIDTH 512
#define HEIGHT 512
#define SLICE_NUM 201
//#define  WIDTH 416
//#define HEIGHT 286
//#define SLICE_NUM 118
#define UPSAMLING 1
CvSeq* contours[2] = {0,0};
extern QString sourceDICOMDirectory;
extern QString destDICOMDirectory;
extern QString bmpDirectory;

ImageProcessThread::ImageProcessThread(QObject *parent)
	: QThread(parent)
{
	this->outputContourInfoFileName="D:\\lab\\mywork\\leg\\ContourInfo.txt";
}

ImageProcessThread::~ImageProcessThread()
{

}
void ImageProcessThread::run()
{
	//ImageProcess(sourceDICOMDirectory,destDICOMDirectory,bmpDirectory);
	ImageProcess();
	exec();
}

void ImageProcessThread::ImageProcess()
{
	//	this->sourceDICOMDirectory=sourceDICOMDirectory;
	//	this->bmpDirectory=bmpDirectory;
	//	this->destDICOMDirectory=destDICOMDirectory;
	//在DICOM路径下创建以New开头的新文件夹

	QDir().mkdir(destDICOMDirectory);
	// load and set up the image in a window
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	list<string> myList;
	string fileName;
	string inputBMPdir=bmpDirectory.toStdString()+"\\";
	//ofstream outfile("D:\\lab\\mywork\\leg\\ContourInfo.txt");
	ofstream outfile(outputContourInfoFileName.toStdString());

	string temp_str=inputBMPdir;
	temp_str=temp_str+"*.BMP";
	//hFind = FindFirstFile("D:\\lab\\mywork\\leg\\BMP\\*.bmp", &FindFileData);
	//cout<<temp_str<<endl;
	hFind = FindFirstFile(temp_str.c_str(), &FindFileData);
	//hFind = FindFirstFile(L"D:\\lab\\mywork\\leg\\BMP\\", &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE) 
	{

		printf ("FindFirstFile failed (%d)\n", GetLastError());
		return ;
	} 
	else 
	{
		fileName=FindFileData.cFileName;
		myList.push_back(fileName);


	}
	while (FindNextFile(hFind, &FindFileData) != 0)
	{
		fileName=FindFileData.cFileName;
		//cout<<fileName<<endl;
		myList.push_back(fileName);
	}
	FindClose(hFind);
	//cout<<"file count="<<myList.size()<<endl;
	string prefix=inputBMPdir;
	//string prefix="D:\\lab\\mywork\\leg\\BMP\\";
	while(!myList.empty())
	{

		IplImage * img[2],*greyimg[2],*testimg[2],*tempImg;
		CvMemStorage* storage[2];
		bool flag=false;
		string fileName2;
		fileName=myList.front();
		myList.pop_front();
		/*if(fileName.find('-')!=string::npos)
		{
		fileName2=myList.front();
		myList.pop_front();
		flag=true;
		}*/
		//找到目前读取的BMP文件的文件名，提取出里面的数字，输出到文件中
		string tempStr=fileName;
		int indexOfDot=tempStr.find('.');
		tempStr=tempStr.substr(0,indexOfDot);	
		outfile<<tempStr<<endl;
		float * arrX[2],*arrY[2];
		int i;

		//如果某个切片有多张图对应的轮廓
		if(flag==false)
		{
			fileName=prefix+fileName;
			//降采样
			tempImg=cvLoadImage(fileName.c_str());
			CvSize size=cvSize(tempImg->width/UPSAMLING,tempImg->height/UPSAMLING);
			img[0] =cvCreateImage(size,tempImg->depth,tempImg->nChannels);
			cvResize(tempImg,img[0]);
			//	img[0]=cvLoadImage(fileName.c_str());
			//cvSaveImage("D:\\1.bmp",img[0]);
			//对图像进行预处理
			PreProcess(img[0]);
			//	cvSaveImage("D:\\2.bmp",img[0]);
			greyimg[0] = cvCreateImage(cvGetSize(img[0]), IPL_DEPTH_8U, 1);
			testimg[0] = cvCreateImage(cvGetSize(img[0]), IPL_DEPTH_8U, 1);

			cvCvtColor(img[0], greyimg[0], CV_BGR2GRAY);  
			cvConvertImage(img[0], testimg[0]);

			storage[0] = cvCreateMemStorage(0);

			int numOfContour=cvFindContours(testimg[0], storage[0], &contours[0], sizeof(CvContour),CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
			//cvDrawContours(img[0], contours[0],CV_RGB(0,0,255), cvScalarAll(255), 100);
			//cvSaveImage("D:\\new.bmp",img[0]);
			cout<<"numOfContour=="<<numOfContour<<endl;
			//cout<<contours[0]->total<<endl;
			//如果某张图有多条轮廓，那么就找出轮廓最大的一条来
			if(numOfContour>1)
			{
				CvSeq* temp=contours[0];
				int maxTotal=-1;
				int maxIndex=-1;
				for(i=0;i<numOfContour;i++)
				{
					if(temp->total>maxTotal)
					{
						maxTotal=temp->total;
						maxIndex=i;
					}
					temp=temp->h_next;

				}
				//cout<<"最大轮廓点数："<<maxIndex<<endl;
				while(maxIndex--)
					contours[0]=contours[0]->h_next;


			}
			arrX[0]=new float[contours[0]->total];
			arrY[0]=new float[contours[0]->total];
			CvPoint * tempPoint;
			//	outfile<<contours[0]->total<<endl;
			for(i=0;i<contours[0]->total;i++)
			{
				tempPoint=(CvPoint*)cvGetSeqElem(contours[0],i);
				arrX[0][i]=tempPoint->x;
				arrY[0][i]=tempPoint->y;
				//outfile<<tempPoint->x<<" "<<tempPoint->y<<endl;
			}
			//outfile<<contours[0]->total<<endl;
			CheckIfInPolyOneContour(outfile,contours[0]->total,arrX[0],arrY[0]);
		}
		else
		{
			fileName=prefix+fileName;
			fileName2=prefix+fileName2;
			tempImg=cvLoadImage(fileName.c_str());
			CvSize size=cvSize(tempImg->width/4,tempImg->height/4);
			img[0] =cvCreateImage(size,tempImg->depth,tempImg->nChannels);
			cvResize(tempImg,img[0]);
			tempImg=cvLoadImage(fileName2.c_str());
			img[1] =cvCreateImage(size,tempImg->depth,tempImg->nChannels);
			cvResize(tempImg,img[1]);
			//	img[0]=cvLoadImage(fileName.c_str());
			//	img[1]=cvLoadImage(fileName2.c_str());
			PreProcess(img[0]);
			PreProcess(img[1]);
			greyimg[0] = cvCreateImage(cvGetSize(img[0]), IPL_DEPTH_8U, 1);
			testimg[0] = cvCreateImage(cvGetSize(img[0]), IPL_DEPTH_8U, 1);
			greyimg[1] = cvCreateImage(cvGetSize(img[1]), IPL_DEPTH_8U, 1);
			testimg[1] = cvCreateImage(cvGetSize(img[1]), IPL_DEPTH_8U, 1);
			cvCvtColor(img[0], greyimg[0], CV_BGR2GRAY);  
			cvConvertImage(img[0], testimg[0]);
			cvCvtColor(img[1], greyimg[1], CV_BGR2GRAY);  
			cvConvertImage(img[1], testimg[1]);
			storage[0] = cvCreateMemStorage(0);
			storage[1] = cvCreateMemStorage(0);
			int numOfContour1=cvFindContours(testimg[0], storage[0], &contours[0], sizeof(CvContour),CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
			int numOfContour2=cvFindContours(testimg[1], storage[1], &contours[1], sizeof(CvContour),CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
			//cvDrawContours(img, contours[0],CV_RGB(255,0,0), cvScalarAll(255), 100);
			cout<<numOfContour1<<" "<<numOfContour2<<endl;
			cout<<contours[0]->total<<endl;
			//如果某张图有多条轮廓，那么就找出轮廓最大的一条来
			if(numOfContour1>1)
			{
				CvSeq* temp=contours[0];
				int maxTotal=-1;
				int maxIndex=-1;
				for(i=0;i<numOfContour1;i++)
				{
					if(temp->total>maxTotal)
					{
						maxTotal=temp->total;
						maxIndex=i;
					}
					temp=temp->h_next;

				}
				cout<<"最大轮廓点数："<<maxIndex<<endl;
				while(maxIndex--)
					contours[0]=contours[0]->h_next;


			}
			if(numOfContour2>1)
			{
				CvSeq* temp=contours[1];
				int maxTotal=-1;
				int maxIndex=-1;
				for(i=0;i<numOfContour2;i++)
				{
					if(temp->total>maxTotal)
					{
						maxTotal=temp->total;
						maxIndex=i;
					}
					temp=temp->h_next;

				}
				cout<<"最大轮廓点数："<<maxIndex<<endl;
				while(maxIndex--)
					contours[1]=contours[1]->h_next;


			}
			arrX[0]=new float[contours[0]->total];
			arrY[0]=new float[contours[0]->total];
			arrX[1]=new float[contours[1]->total];
			arrY[1]=new float[contours[1]->total];
			CvPoint * tempPoint;
			for(i=0;i<contours[0]->total;i++)
			{
				tempPoint=(CvPoint*)cvGetSeqElem(contours[0],i);
				arrX[0][i]=tempPoint->x;
				arrY[0][i]=tempPoint->y;
			}
			for(i=0;i<contours[1]->total;i++)
			{
				tempPoint=(CvPoint*)cvGetSeqElem(contours[1],i);
				arrX[1][i]=tempPoint->x;
				arrY[1][i]=tempPoint->y;
			}
			//outfile<<contours[0]->total<<endl;
			CheckIfInPolyTwoContour(outfile,contours[0]->total,contours[1]->total,arrX[0],arrY[0],arrX[1],arrY[1]);
		}


		cvReleaseMemStorage( &storage[0]);
		cvReleaseImage(&img[0]);
		cvReleaseImage(&greyimg[0]);
		cvReleaseImage(&tempImg);
		if(flag==true)
		{
			cvReleaseMemStorage( &storage[1]);
			cvReleaseImage(&img[1]);
			cvReleaseImage(&greyimg[1]);

		}

	}
	//ui.lblShowMessage->setText("generate point info done....");
	//QMessageBox::information(NULL, "information", "generate point info done....");
	outfile.close();
	QString cmd="C:\\Users\\zengjing\\Desktop\\ChangeDICOM.exe ";
	cmd+=this->outputContourInfoFileName;
	cmd+=" ";
	cmd+=sourceDICOMDirectory+"\\";
	cmd+=" ";
	cmd+=destDICOMDirectory+"\\";
	cmd+=" ";
	cmd+=QString::number(WIDTH);
	cmd+=" ";
	cmd+=QString::number(HEIGHT);
	cmd+=" ";
	cmd+=QString::number(SLICE_NUM);

	//sprintf(cmd,"C:\Users\zengjing\Desktop\ChangeDICOM.exe %s %s %s %d %d %d",this->outputContourInfoFileName.toStdString(),this->sourceDICOMDir.toStdString(),this->destDICOMDir.toStdString(),WIDTH,HEIGHT,SLICE_NUM);
	qDebug()<<"cmd=="<<cmd<<endl;
	system(cmd.toStdString().c_str());
	emit signalImageProcessDone();
}



int ImageProcessThread::Pnpoly(int nvert, float *vertx, float *verty, float testx, float testy)
{
	int i, j, c = 0;
	for (i = 0, j = nvert-1; i < nvert; j = i++) {
		if ( ((verty[i]>testy) != (verty[j]>testy)) &&
			(testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
			c = !c;
	}
	return c;
}

void ImageProcessThread::CheckIfInPolyOneContour(ofstream &outfile,int num,float *arr1X,float* arr1Y)
{
	int i,j;
	int count=0;
	list<Point> pointList;
	Point pTemp;
	for(i=0;i<HEIGHT;i++)
		for(j=0;j<WIDTH;j++)
		{
			if(Pnpoly(num,arr1X,arr1Y,j,i)!=0)
			{
				//outfile<<j<<" "<<i<<endl;
				pTemp.x=j;
				pTemp.y=i;
				pointList.push_back(pTemp);
				//outfile<<1<<endl;
				count++;
			}

		}
		outfile<<count<<endl;
		while(!pointList.empty())
		{

			outfile<<pointList.front().x<<" "<<pointList.front().y<<endl;
			pointList.pop_front();
		}
		//	cout<<count<<endl;
}


void ImageProcessThread::CheckIfInPolyTwoContour(ofstream &outfile,int num1,int num2,float *arr1X,float* arr1Y,float *arr2X,float* arr2Y)
{
	int i,j;
	int count=0;
	list<Point> pointList;
	Point pTemp;
	for(i=0;i<HEIGHT;i++)
		for(j=0;j<WIDTH;j++)
		{
			if(Pnpoly(num1,arr1X,arr1Y,j,i)!=0 ||Pnpoly(num2,arr2X,arr2Y,j,i)!=0)
			{
				//	outfile<<j<<" "<<i<<endl;
				pTemp.x=j;
				pTemp.y=i;
				pointList.push_back(pTemp);
				count++;

			}

		}
		outfile<<count<<endl;
		while(!pointList.empty())
		{

			outfile<<pointList.front().x<<" "<<pointList.front().y<<endl;
			pointList.pop_front();
		}
}



void ImageProcessThread::PreProcess(IplImage * img)
{
	int x,y;
	for(  y=0; y<img->height; y++ ) 
	{ 
		uchar* ptr = (uchar*) ( img->imageData + y * img->widthStep ); 
		for(  x=0; x<img->width; x++ )
		{ 
			//if(ptr[3*x+0]==255)
			if(ptr[3*x+0]==255 && ptr[3*x+1]!=255 && ptr[3*x+2]!=255)
			{
				ptr[3*x+2] = 255; //Set red to max (BGR format)
				ptr[3*x+1] =255; //Set red to max (BGR format)
				ptr[3*x+0] = 255; //Set red to max (BGR format)

			}
			else
			{
				ptr[3*x+2] = 0; //Set red to max (BGR format)
				ptr[3*x+1] =0; //Set red to max (BGR format)
				ptr[3*x+0] = 0; //Set red to max (BGR format)
			}
		}
	}
}

