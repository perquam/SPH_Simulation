#include <QtWidgets/QApplication>
#include <QWidget>
#include <QMainWindow>
#include "SPH.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SPH window;
	window.show();
	return a.exec();
}
