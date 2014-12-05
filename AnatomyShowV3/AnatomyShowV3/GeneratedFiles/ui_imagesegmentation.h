/********************************************************************************
** Form generated from reading UI file 'imagesegmentation.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESEGMENTATION_H
#define UI_IMAGESEGMENTATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ImageSegmentation
{
public:
    QSlider *sliderSourceDICOM;
    QSlider *sliderBMP;
    QSlider *sliderDestDICOM;
    QPushButton *btnOpenSourceDICOM;
    QPushButton *btnOpenBMP;
    QPushButton *btnSegmentation;
    QPushButton *btnNextStep;
    QProgressBar *progressBar;
    QFrame *frame;
    QVTKWidget *vtkSourceDICOM;
    QFrame *frame_2;
    QLabel *lblShowBMP;
    QFrame *frame_3;
    QVTKWidget *vtkDestDICOM;
    QLabel *label;

    void setupUi(QDialog *ImageSegmentation)
    {
        if (ImageSegmentation->objectName().isEmpty())
            ImageSegmentation->setObjectName(QString::fromUtf8("ImageSegmentation"));
        ImageSegmentation->resize(750, 550);
        QPalette palette;
        QBrush brush(QColor(204, 232, 207, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(160, 160, 160, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ImageSegmentation->setPalette(palette);
        sliderSourceDICOM = new QSlider(ImageSegmentation);
        sliderSourceDICOM->setObjectName(QString::fromUtf8("sliderSourceDICOM"));
        sliderSourceDICOM->setGeometry(QRect(30, 470, 160, 19));
        sliderSourceDICOM->setOrientation(Qt::Horizontal);
        sliderBMP = new QSlider(ImageSegmentation);
        sliderBMP->setObjectName(QString::fromUtf8("sliderBMP"));
        sliderBMP->setGeometry(QRect(240, 470, 160, 19));
        sliderBMP->setOrientation(Qt::Horizontal);
        sliderDestDICOM = new QSlider(ImageSegmentation);
        sliderDestDICOM->setObjectName(QString::fromUtf8("sliderDestDICOM"));
        sliderDestDICOM->setGeometry(QRect(550, 470, 160, 19));
        sliderDestDICOM->setOrientation(Qt::Horizontal);
        btnOpenSourceDICOM = new QPushButton(ImageSegmentation);
        btnOpenSourceDICOM->setObjectName(QString::fromUtf8("btnOpenSourceDICOM"));
        btnOpenSourceDICOM->setGeometry(QRect(50, 30, 121, 41));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        btnOpenSourceDICOM->setPalette(palette1);
        QFont font;
        font.setPointSize(11);
        btnOpenSourceDICOM->setFont(font);
        btnOpenBMP = new QPushButton(ImageSegmentation);
        btnOpenBMP->setObjectName(QString::fromUtf8("btnOpenBMP"));
        btnOpenBMP->setGeometry(QRect(280, 30, 121, 41));
        btnOpenBMP->setFont(font);
        btnSegmentation = new QPushButton(ImageSegmentation);
        btnSegmentation->setObjectName(QString::fromUtf8("btnSegmentation"));
        btnSegmentation->setGeometry(QRect(440, 230, 81, 51));
        btnNextStep = new QPushButton(ImageSegmentation);
        btnNextStep->setObjectName(QString::fromUtf8("btnNextStep"));
        btnNextStep->setGeometry(QRect(310, 490, 81, 51));
        btnNextStep->setFont(font);
        progressBar = new QProgressBar(ImageSegmentation);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 520, 261, 23));
        progressBar->setValue(24);
        frame = new QFrame(ImageSegmentation);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 100, 200, 340));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        frame->setPalette(palette2);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(5);
        frame->setMidLineWidth(1);
        vtkSourceDICOM = new QVTKWidget(frame);
        vtkSourceDICOM->setObjectName(QString::fromUtf8("vtkSourceDICOM"));
        vtkSourceDICOM->setGeometry(QRect(13, 13, 180, 320));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        vtkSourceDICOM->setPalette(palette3);
        frame_2 = new QFrame(ImageSegmentation);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(220, 100, 200, 340));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        frame_2->setPalette(palette4);
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(5);
        frame_2->setMidLineWidth(1);
        lblShowBMP = new QLabel(frame_2);
        lblShowBMP->setObjectName(QString::fromUtf8("lblShowBMP"));
        lblShowBMP->setGeometry(QRect(10, 10, 180, 320));
        frame_3 = new QFrame(ImageSegmentation);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(540, 100, 200, 340));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        frame_3->setPalette(palette5);
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Sunken);
        frame_3->setLineWidth(5);
        frame_3->setMidLineWidth(1);
        vtkDestDICOM = new QVTKWidget(frame_3);
        vtkDestDICOM->setObjectName(QString::fromUtf8("vtkDestDICOM"));
        vtkDestDICOM->setGeometry(QRect(13, 13, 180, 320));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        vtkDestDICOM->setPalette(palette6);
        label = new QLabel(ImageSegmentation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 260, 24, 24));
        label->setPixmap(QPixmap(QString::fromUtf8(":/MyImages/images/add.png")));

        retranslateUi(ImageSegmentation);
        QObject::connect(btnOpenBMP, SIGNAL(clicked()), ImageSegmentation, SLOT(OpenBMP()));
        QObject::connect(btnOpenSourceDICOM, SIGNAL(clicked()), ImageSegmentation, SLOT(OpenSourceDICOM()));
        QObject::connect(btnSegmentation, SIGNAL(clicked()), ImageSegmentation, SLOT(StartSegmentation()));
        QObject::connect(btnNextStep, SIGNAL(clicked()), ImageSegmentation, SLOT(NextStep()));
        QObject::connect(sliderSourceDICOM, SIGNAL(sliderMoved(int)), ImageSegmentation, SLOT(SliderShowSourceDICOM(int)));
        QObject::connect(sliderBMP, SIGNAL(sliderMoved(int)), ImageSegmentation, SLOT(SliderShowBMP(int)));
        QObject::connect(sliderDestDICOM, SIGNAL(sliderMoved(int)), ImageSegmentation, SLOT(SliderShowDestDICOM(int)));

        QMetaObject::connectSlotsByName(ImageSegmentation);
    } // setupUi

    void retranslateUi(QDialog *ImageSegmentation)
    {
        ImageSegmentation->setWindowTitle(QApplication::translate("ImageSegmentation", "ImageSegmentation", 0, QApplication::UnicodeUTF8));
        btnOpenSourceDICOM->setText(QApplication::translate("ImageSegmentation", "\346\211\223\345\274\200\345\216\237\345\247\213DICOM", 0, QApplication::UnicodeUTF8));
        btnOpenBMP->setText(QApplication::translate("ImageSegmentation", "\346\211\223\345\274\200\345\257\271\345\272\224\350\275\256\345\273\223", 0, QApplication::UnicodeUTF8));
        btnSegmentation->setText(QString());
        btnNextStep->setText(QApplication::translate("ImageSegmentation", "\344\270\213\344\270\200\346\255\245", 0, QApplication::UnicodeUTF8));
        lblShowBMP->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageSegmentation: public Ui_ImageSegmentation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESEGMENTATION_H
