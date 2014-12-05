#ifndef HELPVIZARD_H
#define HELPVIZARD_H

#include <QDialog>
#include "ui_helpvizard.h"

class HelpVizard : public QDialog
{
	Q_OBJECT

public:
	HelpVizard(QWidget *parent = 0);
	~HelpVizard();

private:
	Ui::HelpVizard ui;
};

#endif // HELPVIZARD_H
