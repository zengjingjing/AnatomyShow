/********************************************************************************
** Form generated from reading UI file 'anatomydefine.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANATOMYDEFINE_H
#define UI_ANATOMYDEFINE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AnatomyDefine
{
public:
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QListWidget *lwSkin;
    QPushButton *btnSkinAdd;
    QPushButton *btnSkinSub;
    QListWidget *lwMuscle;
    QListWidget *lwBone;
    QListWidget *lwOrgan;
    QListWidget *lwArtery;
    QListWidget *lwNerve;
    QPushButton *btnMuscleSub;
    QPushButton *btnMuscleAdd;
    QPushButton *btnBoneAdd;
    QPushButton *btnBoneSub;
    QPushButton *btnOrganSub;
    QPushButton *btnOrganAdd;
    QPushButton *btnNerveSub;
    QPushButton *btnNerveAdd;
    QPushButton *btnArteryAdd;
    QPushButton *btnArterySub;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *btnGenerateModel;
    QProgressBar *progressBar;
    QLabel *lblShowMsg;

    void setupUi(QDialog *AnatomyDefine)
    {
        if (AnatomyDefine->objectName().isEmpty())
            AnatomyDefine->setObjectName(QString::fromUtf8("AnatomyDefine"));
        AnatomyDefine->resize(750, 550);
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(204, 232, 207, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(160, 160, 160, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        AnatomyDefine->setPalette(palette);
        line = new QFrame(AnatomyDefine);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(200, 10, 20, 241));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(AnatomyDefine);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(480, 10, 20, 241));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(AnatomyDefine);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(200, 270, 20, 221));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(AnatomyDefine);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(480, 270, 20, 231));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(AnatomyDefine);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 250, 721, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        lwSkin = new QListWidget(AnatomyDefine);
        lwSkin->setObjectName(QString::fromUtf8("lwSkin"));
        lwSkin->setGeometry(QRect(0, 40, 191, 151));
        btnSkinAdd = new QPushButton(AnatomyDefine);
        btnSkinAdd->setObjectName(QString::fromUtf8("btnSkinAdd"));
        btnSkinAdd->setGeometry(QRect(0, 200, 35, 35));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MyImages/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSkinAdd->setIcon(icon);
        btnSkinAdd->setIconSize(QSize(35, 35));
        btnSkinSub = new QPushButton(AnatomyDefine);
        btnSkinSub->setObjectName(QString::fromUtf8("btnSkinSub"));
        btnSkinSub->setGeometry(QRect(40, 200, 35, 35));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MyImages/images/sub.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSkinSub->setIcon(icon1);
        btnSkinSub->setIconSize(QSize(35, 35));
        lwMuscle = new QListWidget(AnatomyDefine);
        lwMuscle->setObjectName(QString::fromUtf8("lwMuscle"));
        lwMuscle->setGeometry(QRect(220, 40, 191, 151));
        lwBone = new QListWidget(AnatomyDefine);
        lwBone->setObjectName(QString::fromUtf8("lwBone"));
        lwBone->setGeometry(QRect(490, 40, 191, 151));
        lwOrgan = new QListWidget(AnatomyDefine);
        lwOrgan->setObjectName(QString::fromUtf8("lwOrgan"));
        lwOrgan->setGeometry(QRect(0, 300, 191, 151));
        lwArtery = new QListWidget(AnatomyDefine);
        lwArtery->setObjectName(QString::fromUtf8("lwArtery"));
        lwArtery->setGeometry(QRect(490, 300, 191, 151));
        lwNerve = new QListWidget(AnatomyDefine);
        lwNerve->setObjectName(QString::fromUtf8("lwNerve"));
        lwNerve->setGeometry(QRect(230, 300, 191, 151));
        btnMuscleSub = new QPushButton(AnatomyDefine);
        btnMuscleSub->setObjectName(QString::fromUtf8("btnMuscleSub"));
        btnMuscleSub->setGeometry(QRect(270, 200, 35, 35));
        btnMuscleSub->setIcon(icon1);
        btnMuscleSub->setIconSize(QSize(35, 35));
        btnMuscleAdd = new QPushButton(AnatomyDefine);
        btnMuscleAdd->setObjectName(QString::fromUtf8("btnMuscleAdd"));
        btnMuscleAdd->setGeometry(QRect(230, 200, 35, 35));
        btnMuscleAdd->setIcon(icon);
        btnMuscleAdd->setIconSize(QSize(35, 35));
        btnBoneAdd = new QPushButton(AnatomyDefine);
        btnBoneAdd->setObjectName(QString::fromUtf8("btnBoneAdd"));
        btnBoneAdd->setGeometry(QRect(500, 200, 35, 35));
        btnBoneAdd->setIcon(icon);
        btnBoneAdd->setIconSize(QSize(35, 35));
        btnBoneSub = new QPushButton(AnatomyDefine);
        btnBoneSub->setObjectName(QString::fromUtf8("btnBoneSub"));
        btnBoneSub->setGeometry(QRect(540, 200, 35, 35));
        btnBoneSub->setIcon(icon1);
        btnBoneSub->setIconSize(QSize(35, 35));
        btnOrganSub = new QPushButton(AnatomyDefine);
        btnOrganSub->setObjectName(QString::fromUtf8("btnOrganSub"));
        btnOrganSub->setGeometry(QRect(50, 460, 35, 35));
        btnOrganSub->setIcon(icon1);
        btnOrganSub->setIconSize(QSize(35, 35));
        btnOrganAdd = new QPushButton(AnatomyDefine);
        btnOrganAdd->setObjectName(QString::fromUtf8("btnOrganAdd"));
        btnOrganAdd->setGeometry(QRect(10, 460, 35, 35));
        btnOrganAdd->setIcon(icon);
        btnOrganAdd->setIconSize(QSize(35, 35));
        btnNerveSub = new QPushButton(AnatomyDefine);
        btnNerveSub->setObjectName(QString::fromUtf8("btnNerveSub"));
        btnNerveSub->setGeometry(QRect(270, 460, 35, 35));
        btnNerveSub->setIcon(icon1);
        btnNerveSub->setIconSize(QSize(35, 35));
        btnNerveAdd = new QPushButton(AnatomyDefine);
        btnNerveAdd->setObjectName(QString::fromUtf8("btnNerveAdd"));
        btnNerveAdd->setGeometry(QRect(230, 460, 35, 35));
        btnNerveAdd->setIcon(icon);
        btnNerveAdd->setIconSize(QSize(35, 35));
        btnArteryAdd = new QPushButton(AnatomyDefine);
        btnArteryAdd->setObjectName(QString::fromUtf8("btnArteryAdd"));
        btnArteryAdd->setGeometry(QRect(500, 460, 35, 35));
        btnArteryAdd->setIcon(icon);
        btnArteryAdd->setIconSize(QSize(35, 35));
        btnArterySub = new QPushButton(AnatomyDefine);
        btnArterySub->setObjectName(QString::fromUtf8("btnArterySub"));
        btnArterySub->setGeometry(QRect(540, 460, 35, 35));
        btnArterySub->setIcon(icon1);
        btnArterySub->setIconSize(QSize(35, 35));
        label = new QLabel(AnatomyDefine);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 54, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(AnatomyDefine);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 10, 71, 21));
        label_2->setFont(font);
        label_3 = new QLabel(AnatomyDefine);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(510, 10, 71, 20));
        label_3->setFont(font);
        label_4 = new QLabel(AnatomyDefine);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 260, 54, 31));
        label_4->setFont(font);
        label_5 = new QLabel(AnatomyDefine);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 260, 54, 31));
        label_5->setFont(font);
        label_6 = new QLabel(AnatomyDefine);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 270, 61, 21));
        label_6->setFont(font);
        btnGenerateModel = new QPushButton(AnatomyDefine);
        btnGenerateModel->setObjectName(QString::fromUtf8("btnGenerateModel"));
        btnGenerateModel->setGeometry(QRect(200, 510, 111, 31));
        btnGenerateModel->setFont(font);
        progressBar = new QProgressBar(AnatomyDefine);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 520, 171, 23));
        progressBar->setValue(24);
        lblShowMsg = new QLabel(AnatomyDefine);
        lblShowMsg->setObjectName(QString::fromUtf8("lblShowMsg"));
        lblShowMsg->setGeometry(QRect(330, 515, 411, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lblShowMsg->setPalette(palette1);
        lblShowMsg->setFont(font);

        retranslateUi(AnatomyDefine);
        QObject::connect(btnSkinAdd, SIGNAL(clicked()), AnatomyDefine, SLOT(SkinAdd()));
        QObject::connect(btnSkinSub, SIGNAL(clicked()), AnatomyDefine, SLOT(SkinSub()));
        QObject::connect(btnMuscleAdd, SIGNAL(clicked()), AnatomyDefine, SLOT(MuscleAdd()));
        QObject::connect(btnMuscleSub, SIGNAL(clicked()), AnatomyDefine, SLOT(MuscleSub()));
        QObject::connect(btnBoneAdd, SIGNAL(clicked()), AnatomyDefine, SLOT(BoneAdd()));
        QObject::connect(btnBoneSub, SIGNAL(clicked()), AnatomyDefine, SLOT(BoneSub()));
        QObject::connect(btnOrganAdd, SIGNAL(clicked()), AnatomyDefine, SLOT(OrganAdd()));
        QObject::connect(btnOrganSub, SIGNAL(clicked()), AnatomyDefine, SLOT(OrganSub()));
        QObject::connect(btnNerveAdd, SIGNAL(clicked()), AnatomyDefine, SLOT(NerveAdd()));
        QObject::connect(btnNerveSub, SIGNAL(clicked()), AnatomyDefine, SLOT(NerveSub()));
        QObject::connect(btnArteryAdd, SIGNAL(clicked()), AnatomyDefine, SLOT(ArteryAdd()));
        QObject::connect(btnArterySub, SIGNAL(clicked()), AnatomyDefine, SLOT(ArterySub()));
        QObject::connect(btnGenerateModel, SIGNAL(clicked()), AnatomyDefine, SLOT(GenerateModel()));

        QMetaObject::connectSlotsByName(AnatomyDefine);
    } // setupUi

    void retranslateUi(QDialog *AnatomyDefine)
    {
        AnatomyDefine->setWindowTitle(QApplication::translate("AnatomyDefine", "AnatomyDefine", 0, QApplication::UnicodeUTF8));
        btnSkinAdd->setText(QString());
        btnSkinSub->setText(QString());
        btnMuscleSub->setText(QString());
        btnMuscleAdd->setText(QString());
        btnBoneAdd->setText(QString());
        btnBoneSub->setText(QString());
        btnOrganSub->setText(QString());
        btnOrganAdd->setText(QString());
        btnNerveSub->setText(QString());
        btnNerveAdd->setText(QString());
        btnArteryAdd->setText(QString());
        btnArterySub->setText(QString());
        label->setText(QApplication::translate("AnatomyDefine", "\347\232\256\350\202\244\345\261\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AnatomyDefine", "\350\202\214\350\202\211\345\261\202", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AnatomyDefine", "\351\252\250\351\252\274\345\261\202", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AnatomyDefine", "\345\231\250\345\256\230\345\261\202", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AnatomyDefine", "\347\245\236\347\273\217\345\261\202", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AnatomyDefine", "\350\241\200\347\256\241\345\261\202", 0, QApplication::UnicodeUTF8));
        btnGenerateModel->setText(QApplication::translate("AnatomyDefine", "\347\224\237\346\210\220\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
        lblShowMsg->setText(QApplication::translate("AnatomyDefine", "\347\216\260\345\234\250\345\217\257\344\273\245\350\247\202\347\234\213\346\250\241\345\236\213\344\272\206\357\274\201\347\202\271\345\207\273\345\267\246\350\276\271\342\200\234anatomy\342\200\235 \346\230\276\347\244\272\345\215\263\345\217\257\357\274\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnatomyDefine: public Ui_AnatomyDefine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANATOMYDEFINE_H
