#include "SPH.h"
#include <QPushButton>
#include <QThread>

SPH::SPH(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect_Buttons();
}

void SPH::connect_Buttons()
{
	timer.start(20);
	// Konfigurowanie przyciskow.
	connect(&timer, SIGNAL(timeout()), ui.widget, SLOT(updateGL()));
	connect(&timer, SIGNAL(timeout()), this, SLOT(change_Labels()));
	connect(ui.pushButton, SIGNAL(released()), this, SLOT(close()));
	connect(ui.pushButton_2, SIGNAL(released()), ui.widget, SLOT(add_Particle()));
	connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), ui.widget, SLOT(change_gValue(int)));
}

void SPH::change_Labels()
{
	ui.label_2->setNum(ui.widget->particles_Number());
	ui.label_8->setNum(ui.widget->m_Value());
	ui.label_7->setNum(ui.widget->g_Value());
}
