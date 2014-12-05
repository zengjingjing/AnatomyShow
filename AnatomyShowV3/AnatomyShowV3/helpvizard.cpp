#include "helpvizard.h"

extern int maxWindowHeight;
extern int maxWindowWidth;

HelpVizard::HelpVizard(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	resize(maxWindowWidth * 0.8, maxWindowHeight * 0.8);
	move(maxWindowWidth * 0.2 + 20, 20);
	setWindowFlags(Qt::FramelessWindowHint);
	this->update();
}

HelpVizard::~HelpVizard()
{

}
