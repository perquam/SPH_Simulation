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
	// Przycisk sluzacy do dodawania czastek.
	connect(&timer, SIGNAL(timeout()), ui.widget, SLOT(updateGL()));
	connect(&timer, SIGNAL(timeout()), this, SLOT(change_Labels()));
	connect(ui.pushButton, SIGNAL(released()), this, SLOT(close()));
	connect(ui.pushButton_2, SIGNAL(released()), ui.widget, SLOT(add_Particle()));
	connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), ui.widget, SLOT(change_gValue(int)));
	connect(ui.horizontalSlider_3, SIGNAL(valueChanged(int)), ui.widget, SLOT(change_Pos(int)));
	connect(ui.horizontalSlider_4, SIGNAL(valueChanged(int)), ui.widget, SLOT(change_Mass(int)));
	connect(ui.horizontalSlider_2, SIGNAL(valueChanged(int)), ui.widget, SLOT(change_ParticleSize(int)));
	connect(ui.horizontalSlider_5, SIGNAL(valueChanged(int)), ui.widget, SLOT(change_VISC(int)));
}

void SPH::change_Labels()
{
	ui.label_2->setNum(ui.widget->particles_Number());
	ui.label_8->setNum(ui.widget->m_Value());
	ui.label_7->setNum(ui.widget->g_Value());
	ui.label_10->setNum(ui.widget->p_Value());
	ui.label_13->setNum(ui.widget->particleSize_Value());
	ui.label_2->setNum(ui.widget->particles_Number());
	ui.label_5->setNum(ui.widget->VISC_Value());
}
