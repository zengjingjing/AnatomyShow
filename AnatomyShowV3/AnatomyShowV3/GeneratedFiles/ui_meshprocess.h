/********************************************************************************
** Form generated from reading UI file 'meshprocess.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHPROCESS_H
#define UI_MESHPROCESS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MeshProcess
{
public:
    QComboBox *cbMeshProcess;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *leSmoothCount;
    QPushButton *btnStartProcess;
    QPushButton *btnOpenSourceMesh;
    QPushButton *btnSaveMesh;
    QPushButton *btnNextStep;
    QFrame *frame;
    QVTKWidget *vtkSourceMesh;
    QFrame *frame_2;
    QVTKWidget *vtkDestMesh;
    QPushButton *btnPrevStep;

    void setupUi(QDialog *MeshProcess)
    {
        if (MeshProcess->objectName().isEmpty())
            MeshProcess->setObjectName(QString::fromUtf8("MeshProcess"));
        MeshProcess->resize(750, 550);
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
        MeshProcess->setPalette(palette);
        cbMeshProcess = new QComboBox(MeshProcess);
        cbMeshProcess->setObjectName(QString::fromUtf8("cbMeshProcess"));
        cbMeshProcess->setGeometry(QRect(310, 230, 131, 22));
        QFont font;
        font.setPointSize(9);
        cbMeshProcess->setFont(font);
        label = new QLabel(MeshProcess);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 230, 81, 21));
        label_2 = new QLabel(MeshProcess);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 260, 81, 20));
        leSmoothCount = new QLineEdit(MeshProcess);
        leSmoothCount->setObjectName(QString::fromUtf8("leSmoothCount"));
        leSmoothCount->setGeometry(QRect(310, 260, 131, 20));
        btnStartProcess = new QPushButton(MeshProcess);
        btnStartProcess->setObjectName(QString::fromUtf8("btnStartProcess"));
        btnStartProcess->setGeometry(QRect(310, 300, 161, 60));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MyImages/images/starthandle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStartProcess->setIcon(icon);
        btnStartProcess->setIconSize(QSize(160, 60));
        btnOpenSourceMesh = new QPushButton(MeshProcess);
        btnOpenSourceMesh->setObjectName(QString::fromUtf8("btnOpenSourceMesh"));
        btnOpenSourceMesh->setGeometry(QRect(40, 20, 131, 50));
        QFont font1;
        font1.setPointSize(11);
        btnOpenSourceMesh->setFont(font1);
        btnSaveMesh = new QPushButton(MeshProcess);
        btnSaveMesh->setObjectName(QString::fromUtf8("btnSaveMesh"));
        btnSaveMesh->setGeometry(QRect(550, 480, 90, 50));
        btnSaveMesh->setFont(font1);
        btnSaveMesh->setIconSize(QSize(70, 70));
        btnNextStep = new QPushButton(MeshProcess);
        btnNextStep->setObjectName(QString::fromUtf8("btnNextStep"));
        btnNextStep->setGeometry(QRect(390, 480, 90, 50));
        btnNextStep->setFont(font1);
        frame = new QFrame(MeshProcess);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 70, 220, 380));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        frame->setPalette(palette1);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(5);
        frame->setMidLineWidth(1);
        vtkSourceMesh = new QVTKWidget(frame);
        vtkSourceMesh->setObjectName(QString::fromUtf8("vtkSourceMesh"));
        vtkSourceMesh->setGeometry(QRect(13, 13, 200, 360));
        frame_2 = new QFrame(MeshProcess);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(480, 70, 220, 380));
        QPalette palette2;
        QBrush brush3(QColor(4, 4, 4, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        frame_2->setPalette(palette2);
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(5);
        frame_2->setMidLineWidth(1);
        vtkDestMesh = new QVTKWidget(frame_2);
        vtkDestMesh->setObjectName(QString::fromUtf8("vtkDestMesh"));
        vtkDestMesh->setGeometry(QRect(13, 13, 200, 360));
        btnPrevStep = new QPushButton(MeshProcess);
        btnPrevStep->setObjectName(QString::fromUtf8("btnPrevStep"));
        btnPrevStep->setGeometry(QRect(0, 480, 321, 50));
        btnPrevStep->setFont(font1);

        retranslateUi(MeshProcess);
        QObject::connect(btnOpenSourceMesh, SIGNAL(clicked()), MeshProcess, SLOT(OpenSourceMesh()));
        QObject::connect(btnStartProcess, SIGNAL(clicked()), MeshProcess, SLOT(StartMeshProcess()));
        QObject::connect(btnSaveMesh, SIGNAL(clicked()), MeshProcess, SLOT(SaveMesh()));
        QObject::connect(btnNextStep, SIGNAL(clicked()), MeshProcess, SLOT(NextStep()));
        QObject::connect(btnPrevStep, SIGNAL(clicked()), MeshProcess, SLOT(PrevStep()));

        QMetaObject::connectSlotsByName(MeshProcess);
    } // setupUi

    void retranslateUi(QDialog *MeshProcess)
    {
        MeshProcess->setWindowTitle(QApplication::translate("MeshProcess", "MeshProcess", 0, QApplication::UnicodeUTF8));
        cbMeshProcess->clear();
        cbMeshProcess->insertItems(0, QStringList()
         << QApplication::translate("MeshProcess", "Laplace smoothing", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MeshProcess", "\351\200\211\346\213\251\345\244\204\347\220\206\346\226\271\345\274\217\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MeshProcess", "\351\200\211\346\213\251\345\271\263\346\273\221\346\254\241\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        btnStartProcess->setText(QString());
        btnOpenSourceMesh->setText(QApplication::translate("MeshProcess", "\346\211\223\345\274\200\345\216\237\345\247\213Mesh", 0, QApplication::UnicodeUTF8));
        btnSaveMesh->setText(QApplication::translate("MeshProcess", "\344\277\235\345\255\230mesh", 0, QApplication::UnicodeUTF8));
        btnNextStep->setText(QApplication::translate("MeshProcess", "\344\270\213\344\270\200\346\255\245", 0, QApplication::UnicodeUTF8));
        btnPrevStep->setText(QApplication::translate("MeshProcess", "\350\277\230\346\234\211\351\203\250\344\275\215\351\234\200\350\246\201\345\210\206\345\211\262\357\274\237\344\270\215\350\246\201\347\264\247\357\274\214\350\277\224\345\233\236\344\270\212\344\270\200\346\255\245\357\274\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MeshProcess: public Ui_MeshProcess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHPROCESS_H
