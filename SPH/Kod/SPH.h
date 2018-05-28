#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SPH.h"
#include <QTimer>

class SPH : public QMainWindow
{
	Q_OBJECT
public:
	SPH(QWidget *parent = Q_NULLPTR);
	void connect_Buttons();
public slots:
	void change_Labels();
private:
	Ui::SPHClass ui;
	// Timer sluzacy do aktualizacji.
	QTimer timer;
};

