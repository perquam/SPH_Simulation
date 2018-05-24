/********************************************************************************
** Form generated from reading UI file 'SPH.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPH_H
#define UI_SPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SPHClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_6;
    QLabel *label_9;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_7;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    GLWidget *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SPHClass)
    {
        if (SPHClass->objectName().isEmpty())
            SPHClass->setObjectName(QStringLiteral("SPHClass"));
        SPHClass->resize(612, 414);
        centralWidget = new QWidget(SPHClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_9, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_6->addWidget(pushButton_2, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 4, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_7->addWidget(label_2, 1, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_7->addWidget(label_5, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_7->addWidget(label, 1, 0, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_7->addWidget(label_7, 2, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_7->addWidget(label_6, 3, 0, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_7->addWidget(label_8, 3, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_7, 3, 0, 1, 1);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMinimum(-20);
        horizontalSlider->setMaximum(20);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(10);
        horizontalSlider->setValue(10);
        horizontalSlider->setSliderPosition(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(horizontalSlider, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_6, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_2);

        widget = new GLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(widget);

        SPHClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SPHClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 612, 21));
        SPHClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SPHClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SPHClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SPHClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SPHClass->setStatusBar(statusBar);

        retranslateUi(SPHClass);
        QObject::connect(pushButton, SIGNAL(released()), SPHClass, SLOT(close()));

        QMetaObject::connectSlotsByName(SPHClass);
    } // setupUi

    void retranslateUi(QMainWindow *SPHClass)
    {
        SPHClass->setWindowTitle(QApplication::translate("SPHClass", "SPH", nullptr));
        label_9->setText(QApplication::translate("SPHClass", "Zmie\305\204 g:", nullptr));
        pushButton_2->setText(QApplication::translate("SPHClass", "Dodaj cz\304\205stk\304\231", nullptr));
        label_2->setText(QString());
        label_5->setText(QApplication::translate("SPHClass", "g:", nullptr));
        label->setText(QApplication::translate("SPHClass", "Cz\304\205stek:", nullptr));
        label_7->setText(QString());
        label_6->setText(QApplication::translate("SPHClass", "m:", nullptr));
        label_8->setText(QString());
        pushButton->setText(QApplication::translate("SPHClass", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SPHClass: public Ui_SPHClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPH_H
