/********************************************************************************
** Form generated from reading UI file 'anatomyshow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANATOMYSHOW_H
#define UI_ANATOMYSHOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnatomyShowClass
{
public:
    QAction *actProcessImageSegmentation;
    QAction *actProcessFromMesh;
    QAction *actFromAnatomyDefine;
    QWidget *centralWidget;
    QFrame *line;
    QTextEdit *txtWizard;
    QPushButton *btnImageSegmentation;
    QPushButton *btnMeshProcess;
    QPushButton *btnAnatomyDefine;
    QPushButton *btnAnatomyShow;
    QLabel *lblShowFirstStep;
    QLabel *lblShowSecondStep;
    QLabel *lblShowThirdStep;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *AnatomyShowClass)
    {
        if (AnatomyShowClass->objectName().isEmpty())
            AnatomyShowClass->setObjectName(QString::fromUtf8("AnatomyShowClass"));
        AnatomyShowClass->resize(1000, 700);
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
        AnatomyShowClass->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font.setPointSize(14);
        AnatomyShowClass->setFont(font);
        actProcessImageSegmentation = new QAction(AnatomyShowClass);
        actProcessImageSegmentation->setObjectName(QString::fromUtf8("actProcessImageSegmentation"));
        actProcessFromMesh = new QAction(AnatomyShowClass);
        actProcessFromMesh->setObjectName(QString::fromUtf8("actProcessFromMesh"));
        actFromAnatomyDefine = new QAction(AnatomyShowClass);
        actFromAnatomyDefine->setObjectName(QString::fromUtf8("actFromAnatomyDefine"));
        centralWidget = new QWidget(AnatomyShowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(200, 0, 20, 680));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        txtWizard = new QTextEdit(centralWidget);
        txtWizard->setObjectName(QString::fromUtf8("txtWizard"));
        txtWizard->setGeometry(QRect(218, 560, 781, 120));
        QPalette palette1;
        QBrush brush2(QColor(227, 227, 227, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        txtWizard->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        txtWizard->setFont(font1);
        txtWizard->setReadOnly(true);
        btnImageSegmentation = new QPushButton(centralWidget);
        btnImageSegmentation->setObjectName(QString::fromUtf8("btnImageSegmentation"));
        btnImageSegmentation->setGeometry(QRect(20, 45, 160, 70));
        QPalette palette2;
        QBrush brush3(QColor(140, 140, 140, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btnImageSegmentation->setPalette(palette2);
        QFont font2;
        font2.setPointSize(14);
        btnImageSegmentation->setFont(font2);
        btnMeshProcess = new QPushButton(centralWidget);
        btnMeshProcess->setObjectName(QString::fromUtf8("btnMeshProcess"));
        btnMeshProcess->setGeometry(QRect(20, 205, 160, 68));
        btnMeshProcess->setFont(font2);
        btnAnatomyDefine = new QPushButton(centralWidget);
        btnAnatomyDefine->setObjectName(QString::fromUtf8("btnAnatomyDefine"));
        btnAnatomyDefine->setGeometry(QRect(20, 372, 160, 68));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        btnAnatomyDefine->setPalette(palette3);
        btnAnatomyDefine->setFont(font2);
        btnAnatomyShow = new QPushButton(centralWidget);
        btnAnatomyShow->setObjectName(QString::fromUtf8("btnAnatomyShow"));
        btnAnatomyShow->setGeometry(QRect(20, 508, 160, 68));
        btnAnatomyShow->setFont(font2);
        lblShowFirstStep = new QLabel(centralWidget);
        lblShowFirstStep->setObjectName(QString::fromUtf8("lblShowFirstStep"));
        lblShowFirstStep->setGeometry(QRect(70, 120, 70, 70));
        lblShowSecondStep = new QLabel(centralWidget);
        lblShowSecondStep->setObjectName(QString::fromUtf8("lblShowSecondStep"));
        lblShowSecondStep->setGeometry(QRect(60, 310, 70, 68));
        lblShowThirdStep = new QLabel(centralWidget);
        lblShowThirdStep->setObjectName(QString::fromUtf8("lblShowThirdStep"));
        lblShowThirdStep->setGeometry(QRect(60, 440, 70, 68));
        AnatomyShowClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(AnatomyShowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AnatomyShowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actProcessImageSegmentation);
        mainToolBar->addAction(actProcessFromMesh);
        mainToolBar->addAction(actFromAnatomyDefine);

        retranslateUi(AnatomyShowClass);
        QObject::connect(actProcessFromMesh, SIGNAL(triggered()), AnatomyShowClass, SLOT(ToolbarProcessFromMeshClicked()));
        QObject::connect(actFromAnatomyDefine, SIGNAL(triggered()), AnatomyShowClass, SLOT(ToolbarProcessFromAnatomyClicked()));
        QObject::connect(actProcessImageSegmentation, SIGNAL(triggered()), AnatomyShowClass, SLOT(ToolbarProcessFromImageClicked()));
        QObject::connect(btnMeshProcess, SIGNAL(clicked()), AnatomyShowClass, SLOT(MeshProcessClicked()));
        QObject::connect(btnImageSegmentation, SIGNAL(clicked()), AnatomyShowClass, SLOT(ImageSegmentationClicked()));
        QObject::connect(btnAnatomyDefine, SIGNAL(clicked()), AnatomyShowClass, SLOT(AnatomyDefineClicked()));
        QObject::connect(btnAnatomyShow, SIGNAL(clicked()), AnatomyShowClass, SLOT(AnatomyShowClicked()));

        QMetaObject::connectSlotsByName(AnatomyShowClass);
    } // setupUi

    void retranslateUi(QMainWindow *AnatomyShowClass)
    {
        AnatomyShowClass->setWindowTitle(QApplication::translate("AnatomyShowClass", "AnatomyShow", 0, QApplication::UnicodeUTF8));
        actProcessImageSegmentation->setText(QApplication::translate("AnatomyShowClass", "\344\273\216\345\233\276\345\203\217\345\210\206\345\211\262\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        actProcessFromMesh->setText(QApplication::translate("AnatomyShowClass", "\344\273\216mesh\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        actFromAnatomyDefine->setText(QApplication::translate("AnatomyShowClass", "\344\273\216\344\272\272\344\275\223\347\273\223\346\236\204\345\256\232\344\271\211\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        btnImageSegmentation->setText(QApplication::translate("AnatomyShowClass", "\345\233\276\345\203\217\345\210\206\345\211\262", 0, QApplication::UnicodeUTF8));
        btnMeshProcess->setText(QApplication::translate("AnatomyShowClass", "mesh\345\244\204\347\220\206", 0, QApplication::UnicodeUTF8));
        btnAnatomyDefine->setText(QApplication::translate("AnatomyShowClass", "anatomy\345\256\232\344\271\211", 0, QApplication::UnicodeUTF8));
        btnAnatomyShow->setText(QApplication::translate("AnatomyShowClass", "anatomy \346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        lblShowFirstStep->setText(QApplication::translate("AnatomyShowClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        lblShowSecondStep->setText(QApplication::translate("AnatomyShowClass", "TextLabel", 0, QApplication::UnicodeUTF8));
        lblShowThirdStep->setText(QApplication::translate("AnatomyShowClass", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnatomyShowClass: public Ui_AnatomyShowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANATOMYSHOW_H
