/********************************************************************************
** Form generated from reading UI file 'helpvizard.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPVIZARD_H
#define UI_HELPVIZARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HelpVizard
{
public:
    QLabel *label;

    void setupUi(QDialog *HelpVizard)
    {
        if (HelpVizard->objectName().isEmpty())
            HelpVizard->setObjectName(QString::fromUtf8("HelpVizard"));
        HelpVizard->resize(1000, 670);
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
        HelpVizard->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MyImages/images/toturial.png"), QSize(), QIcon::Normal, QIcon::Off);
        HelpVizard->setWindowIcon(icon);
        label = new QLabel(HelpVizard);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 70, 717, 549));
        label->setPixmap(QPixmap(QString::fromUtf8(":/MyImages/images/toturial.png")));

        retranslateUi(HelpVizard);

        QMetaObject::connectSlotsByName(HelpVizard);
    } // setupUi

    void retranslateUi(QDialog *HelpVizard)
    {
        HelpVizard->setWindowTitle(QApplication::translate("HelpVizard", "HelpVizard", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HelpVizard: public Ui_HelpVizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPVIZARD_H
