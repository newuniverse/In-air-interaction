/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen_File;
    QAction *actionOpen_Config;
    QAction *actionSave_Scene;
    QAction *actionSave_config;
    QAction *actionNew_gesture;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_37;
    QToolBox *toolBox;
    QWidget *setting1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_4;
    QSlider *parallaxSlider;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_42;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *widthLineEdit;
    QHBoxLayout *horizontalLayout_41;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *heightLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *windowNumSpinBox;
    QPushButton *createWindowButton;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_40;
    QLabel *label_40;
    QLabel *label_48;
    QDoubleSpinBox *x1SpinBox;
    QLabel *label_49;
    QDoubleSpinBox *y1SpinBox;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_41;
    QLabel *label_50;
    QDoubleSpinBox *x2SpinBox;
    QLabel *label_53;
    QDoubleSpinBox *y2SpinBox;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_42;
    QLabel *label_51;
    QDoubleSpinBox *x3SpinBox;
    QLabel *label_54;
    QDoubleSpinBox *y3SpinBox;
    QHBoxLayout *horizontalLayout_45;
    QLabel *label_47;
    QLabel *label_52;
    QDoubleSpinBox *x4SpinBox;
    QLabel *label_55;
    QDoubleSpinBox *y4SpinBox;
    QHBoxLayout *horizontalLayout_46;
    QLabel *label_39;
    QSpinBox *windowIndexSpinBox;
    QPushButton *setKeystoneButton;
    QPushButton *saveKeystoneButton;
    QWidget *setting2;
    QVBoxLayout *verticalLayout_15;
    QPushButton *leapActivateButton;
    QPushButton *robotActivateButton;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_16;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QLineEdit *j1d;
    QLineEdit *j1a;
    QLineEdit *j1alpha;
    QDoubleSpinBox *j1theta;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_17;
    QLineEdit *j2d;
    QLineEdit *j2a;
    QLineEdit *j2alpha;
    QDoubleSpinBox *j2theta;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_18;
    QLineEdit *j3d;
    QLineEdit *j3a;
    QLineEdit *j3alpha;
    QDoubleSpinBox *j3theta;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_19;
    QLineEdit *j4d;
    QLineEdit *j4a;
    QLineEdit *j4alpha;
    QDoubleSpinBox *j4theta;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_20;
    QLineEdit *j5d;
    QLineEdit *j5a;
    QLineEdit *j5alpha;
    QDoubleSpinBox *j5theta;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_21;
    QLineEdit *j6d;
    QLineEdit *j6a;
    QLineEdit *j6alpha;
    QDoubleSpinBox *j6theta;
    QWidget *setting3;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_38;
    QSlider *numFrameSlider;
    QSpinBox *numFrameSpinBox;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_39;
    QSlider *numFrameSlider_2;
    QSpinBox *numFrameSpinBox_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *newGestureNameLineEdit;
    QPushButton *recordGestureButton;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *gestureNameBox;
    QPushButton *gestureSelectButton;
    QTextBrowser *gestureEditBrowzer;
    QWidget *setting4;
    QVBoxLayout *verticalLayout_17;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QVTKWidget *vtkChart1;
    QVTKWidget *vtkChart2;
    QLabel *label_7;
    QLabel *label_38;
    QVTKWidget *qvtkWidget;
    QSpacerItem *horizontalSpacer_5;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1333, 800);
        MainWindow->setMinimumSize(QSize(1330, 800));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        actionOpen_Config = new QAction(MainWindow);
        actionOpen_Config->setObjectName(QString::fromUtf8("actionOpen_Config"));
        actionSave_Scene = new QAction(MainWindow);
        actionSave_Scene->setObjectName(QString::fromUtf8("actionSave_Scene"));
        actionSave_config = new QAction(MainWindow);
        actionSave_config->setObjectName(QString::fromUtf8("actionSave_config"));
        actionNew_gesture = new QAction(MainWindow);
        actionNew_gesture->setObjectName(QString::fromUtf8("actionNew_gesture"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 1, 1275, 752));
        horizontalLayout_37 = new QHBoxLayout(layoutWidget);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        horizontalLayout_37->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(layoutWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(400, 730));
        setting1 = new QWidget();
        setting1->setObjectName(QString::fromUtf8("setting1"));
        setting1->setGeometry(QRect(0, 0, 400, 626));
        verticalLayout = new QVBoxLayout(setting1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_8 = new QLabel(setting1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        parallaxSlider = new QSlider(setting1);
        parallaxSlider->setObjectName(QString::fromUtf8("parallaxSlider"));
        parallaxSlider->setMinimum(0);
        parallaxSlider->setMaximum(100);
        parallaxSlider->setSingleStep(5);
        parallaxSlider->setValue(50);
        parallaxSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(parallaxSlider);


        verticalLayout->addLayout(horizontalLayout_2);

        label_15 = new QLabel(setting1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout->addWidget(label_15);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        label_2 = new QLabel(setting1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_42->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_42->addItem(horizontalSpacer_2);

        widthLineEdit = new QLineEdit(setting1);
        widthLineEdit->setObjectName(QString::fromUtf8("widthLineEdit"));

        horizontalLayout_42->addWidget(widthLineEdit);


        verticalLayout->addLayout(horizontalLayout_42);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        label_3 = new QLabel(setting1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_41->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_3);

        heightLineEdit = new QLineEdit(setting1);
        heightLineEdit->setObjectName(QString::fromUtf8("heightLineEdit"));

        horizontalLayout_41->addWidget(heightLineEdit);


        verticalLayout->addLayout(horizontalLayout_41);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(setting1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        windowNumSpinBox = new QSpinBox(setting1);
        windowNumSpinBox->setObjectName(QString::fromUtf8("windowNumSpinBox"));
        windowNumSpinBox->setWrapping(false);
        windowNumSpinBox->setReadOnly(false);
        windowNumSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        windowNumSpinBox->setKeyboardTracking(true);
        windowNumSpinBox->setMinimum(1);
        windowNumSpinBox->setMaximum(11);

        horizontalLayout->addWidget(windowNumSpinBox);

        createWindowButton = new QPushButton(setting1);
        createWindowButton->setObjectName(QString::fromUtf8("createWindowButton"));
        createWindowButton->setCheckable(true);

        horizontalLayout->addWidget(createWindowButton);


        verticalLayout->addLayout(horizontalLayout);

        label_4 = new QLabel(setting1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        label_40 = new QLabel(setting1);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        horizontalLayout_40->addWidget(label_40);

        label_48 = new QLabel(setting1);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        horizontalLayout_40->addWidget(label_48);

        x1SpinBox = new QDoubleSpinBox(setting1);
        x1SpinBox->setObjectName(QString::fromUtf8("x1SpinBox"));
        x1SpinBox->setMinimum(-2);
        x1SpinBox->setMaximum(2);
        x1SpinBox->setSingleStep(0.01);
        x1SpinBox->setValue(1);

        horizontalLayout_40->addWidget(x1SpinBox);

        label_49 = new QLabel(setting1);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        horizontalLayout_40->addWidget(label_49);

        y1SpinBox = new QDoubleSpinBox(setting1);
        y1SpinBox->setObjectName(QString::fromUtf8("y1SpinBox"));
        y1SpinBox->setDecimals(2);
        y1SpinBox->setMinimum(-2);
        y1SpinBox->setMaximum(2);
        y1SpinBox->setSingleStep(0.01);
        y1SpinBox->setValue(1);

        horizontalLayout_40->addWidget(y1SpinBox);


        verticalLayout->addLayout(horizontalLayout_40);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        label_41 = new QLabel(setting1);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        horizontalLayout_43->addWidget(label_41);

        label_50 = new QLabel(setting1);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        horizontalLayout_43->addWidget(label_50);

        x2SpinBox = new QDoubleSpinBox(setting1);
        x2SpinBox->setObjectName(QString::fromUtf8("x2SpinBox"));
        x2SpinBox->setMinimum(-2);
        x2SpinBox->setMaximum(2);
        x2SpinBox->setSingleStep(0.01);
        x2SpinBox->setValue(-1);

        horizontalLayout_43->addWidget(x2SpinBox);

        label_53 = new QLabel(setting1);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        horizontalLayout_43->addWidget(label_53);

        y2SpinBox = new QDoubleSpinBox(setting1);
        y2SpinBox->setObjectName(QString::fromUtf8("y2SpinBox"));
        y2SpinBox->setMinimum(-2);
        y2SpinBox->setMaximum(2);
        y2SpinBox->setSingleStep(0.01);
        y2SpinBox->setValue(1);

        horizontalLayout_43->addWidget(y2SpinBox);


        verticalLayout->addLayout(horizontalLayout_43);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        label_42 = new QLabel(setting1);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_44->addWidget(label_42);

        label_51 = new QLabel(setting1);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        horizontalLayout_44->addWidget(label_51);

        x3SpinBox = new QDoubleSpinBox(setting1);
        x3SpinBox->setObjectName(QString::fromUtf8("x3SpinBox"));
        x3SpinBox->setMinimum(-2);
        x3SpinBox->setMaximum(2);
        x3SpinBox->setSingleStep(0.01);
        x3SpinBox->setValue(-1);

        horizontalLayout_44->addWidget(x3SpinBox);

        label_54 = new QLabel(setting1);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        horizontalLayout_44->addWidget(label_54);

        y3SpinBox = new QDoubleSpinBox(setting1);
        y3SpinBox->setObjectName(QString::fromUtf8("y3SpinBox"));
        y3SpinBox->setMinimum(-2);
        y3SpinBox->setMaximum(2);
        y3SpinBox->setSingleStep(0.01);
        y3SpinBox->setValue(-1);

        horizontalLayout_44->addWidget(y3SpinBox);


        verticalLayout->addLayout(horizontalLayout_44);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        label_47 = new QLabel(setting1);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        horizontalLayout_45->addWidget(label_47);

        label_52 = new QLabel(setting1);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        horizontalLayout_45->addWidget(label_52);

        x4SpinBox = new QDoubleSpinBox(setting1);
        x4SpinBox->setObjectName(QString::fromUtf8("x4SpinBox"));
        x4SpinBox->setMinimum(-2);
        x4SpinBox->setMaximum(2);
        x4SpinBox->setSingleStep(0.01);
        x4SpinBox->setValue(1);

        horizontalLayout_45->addWidget(x4SpinBox);

        label_55 = new QLabel(setting1);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        horizontalLayout_45->addWidget(label_55);

        y4SpinBox = new QDoubleSpinBox(setting1);
        y4SpinBox->setObjectName(QString::fromUtf8("y4SpinBox"));
        y4SpinBox->setMinimum(-2);
        y4SpinBox->setMaximum(2);
        y4SpinBox->setSingleStep(0.01);
        y4SpinBox->setValue(-1);

        horizontalLayout_45->addWidget(y4SpinBox);


        verticalLayout->addLayout(horizontalLayout_45);

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        label_39 = new QLabel(setting1);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        horizontalLayout_46->addWidget(label_39);

        windowIndexSpinBox = new QSpinBox(setting1);
        windowIndexSpinBox->setObjectName(QString::fromUtf8("windowIndexSpinBox"));
        windowIndexSpinBox->setMinimum(1);
        windowIndexSpinBox->setMaximum(11);

        horizontalLayout_46->addWidget(windowIndexSpinBox);

        setKeystoneButton = new QPushButton(setting1);
        setKeystoneButton->setObjectName(QString::fromUtf8("setKeystoneButton"));

        horizontalLayout_46->addWidget(setKeystoneButton);


        verticalLayout->addLayout(horizontalLayout_46);

        saveKeystoneButton = new QPushButton(setting1);
        saveKeystoneButton->setObjectName(QString::fromUtf8("saveKeystoneButton"));

        verticalLayout->addWidget(saveKeystoneButton);

        toolBox->addItem(setting1, QString::fromUtf8("Output Setting"));
        saveKeystoneButton->raise();
        label_4->raise();
        label_15->raise();
        setting2 = new QWidget();
        setting2->setObjectName(QString::fromUtf8("setting2"));
        setting2->setGeometry(QRect(0, 0, 400, 626));
        verticalLayout_15 = new QVBoxLayout(setting2);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        leapActivateButton = new QPushButton(setting2);
        leapActivateButton->setObjectName(QString::fromUtf8("leapActivateButton"));
        leapActivateButton->setMinimumSize(QSize(150, 32));

        verticalLayout_15->addWidget(leapActivateButton);

        robotActivateButton = new QPushButton(setting2);
        robotActivateButton->setObjectName(QString::fromUtf8("robotActivateButton"));
        robotActivateButton->setCheckable(false);

        verticalLayout_15->addWidget(robotActivateButton);

        scrollArea_2 = new QScrollArea(setting2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(350, 400));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 374, 532));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_9 = new QLabel(scrollAreaWidgetContents_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_16 = new QLabel(scrollAreaWidgetContents_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_3->addWidget(label_16);

        label_11 = new QLabel(scrollAreaWidgetContents_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_3->addWidget(label_11);

        label_12 = new QLabel(scrollAreaWidgetContents_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);

        label_13 = new QLabel(scrollAreaWidgetContents_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13);

        label_14 = new QLabel(scrollAreaWidgetContents_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_3->addWidget(label_14);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_10 = new QLabel(scrollAreaWidgetContents_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_6->addWidget(label_10);

        j1d = new QLineEdit(scrollAreaWidgetContents_2);
        j1d->setObjectName(QString::fromUtf8("j1d"));

        horizontalLayout_6->addWidget(j1d);

        j1a = new QLineEdit(scrollAreaWidgetContents_2);
        j1a->setObjectName(QString::fromUtf8("j1a"));

        horizontalLayout_6->addWidget(j1a);

        j1alpha = new QLineEdit(scrollAreaWidgetContents_2);
        j1alpha->setObjectName(QString::fromUtf8("j1alpha"));

        horizontalLayout_6->addWidget(j1alpha);

        j1theta = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        j1theta->setObjectName(QString::fromUtf8("j1theta"));
        j1theta->setMinimum(-90);
        j1theta->setMaximum(90.99);

        horizontalLayout_6->addWidget(j1theta);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_17 = new QLabel(scrollAreaWidgetContents_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_7->addWidget(label_17);

        j2d = new QLineEdit(scrollAreaWidgetContents_2);
        j2d->setObjectName(QString::fromUtf8("j2d"));

        horizontalLayout_7->addWidget(j2d);

        j2a = new QLineEdit(scrollAreaWidgetContents_2);
        j2a->setObjectName(QString::fromUtf8("j2a"));

        horizontalLayout_7->addWidget(j2a);

        j2alpha = new QLineEdit(scrollAreaWidgetContents_2);
        j2alpha->setObjectName(QString::fromUtf8("j2alpha"));

        horizontalLayout_7->addWidget(j2alpha);

        j2theta = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        j2theta->setObjectName(QString::fromUtf8("j2theta"));
        j2theta->setMinimum(-90);
        j2theta->setMaximum(90.99);

        horizontalLayout_7->addWidget(j2theta);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_18 = new QLabel(scrollAreaWidgetContents_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_8->addWidget(label_18);

        j3d = new QLineEdit(scrollAreaWidgetContents_2);
        j3d->setObjectName(QString::fromUtf8("j3d"));

        horizontalLayout_8->addWidget(j3d);

        j3a = new QLineEdit(scrollAreaWidgetContents_2);
        j3a->setObjectName(QString::fromUtf8("j3a"));

        horizontalLayout_8->addWidget(j3a);

        j3alpha = new QLineEdit(scrollAreaWidgetContents_2);
        j3alpha->setObjectName(QString::fromUtf8("j3alpha"));

        horizontalLayout_8->addWidget(j3alpha);

        j3theta = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        j3theta->setObjectName(QString::fromUtf8("j3theta"));
        j3theta->setMinimum(-90);
        j3theta->setMaximum(90.99);

        horizontalLayout_8->addWidget(j3theta);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_19 = new QLabel(scrollAreaWidgetContents_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_9->addWidget(label_19);

        j4d = new QLineEdit(scrollAreaWidgetContents_2);
        j4d->setObjectName(QString::fromUtf8("j4d"));

        horizontalLayout_9->addWidget(j4d);

        j4a = new QLineEdit(scrollAreaWidgetContents_2);
        j4a->setObjectName(QString::fromUtf8("j4a"));

        horizontalLayout_9->addWidget(j4a);

        j4alpha = new QLineEdit(scrollAreaWidgetContents_2);
        j4alpha->setObjectName(QString::fromUtf8("j4alpha"));

        horizontalLayout_9->addWidget(j4alpha);

        j4theta = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        j4theta->setObjectName(QString::fromUtf8("j4theta"));
        j4theta->setMinimum(-90);
        j4theta->setMaximum(90.99);

        horizontalLayout_9->addWidget(j4theta);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_20 = new QLabel(scrollAreaWidgetContents_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_10->addWidget(label_20);

        j5d = new QLineEdit(scrollAreaWidgetContents_2);
        j5d->setObjectName(QString::fromUtf8("j5d"));

        horizontalLayout_10->addWidget(j5d);

        j5a = new QLineEdit(scrollAreaWidgetContents_2);
        j5a->setObjectName(QString::fromUtf8("j5a"));

        horizontalLayout_10->addWidget(j5a);

        j5alpha = new QLineEdit(scrollAreaWidgetContents_2);
        j5alpha->setObjectName(QString::fromUtf8("j5alpha"));

        horizontalLayout_10->addWidget(j5alpha);

        j5theta = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        j5theta->setObjectName(QString::fromUtf8("j5theta"));
        j5theta->setMinimum(-90);
        j5theta->setMaximum(90.99);

        horizontalLayout_10->addWidget(j5theta);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_21 = new QLabel(scrollAreaWidgetContents_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_11->addWidget(label_21);

        j6d = new QLineEdit(scrollAreaWidgetContents_2);
        j6d->setObjectName(QString::fromUtf8("j6d"));

        horizontalLayout_11->addWidget(j6d);

        j6a = new QLineEdit(scrollAreaWidgetContents_2);
        j6a->setObjectName(QString::fromUtf8("j6a"));

        horizontalLayout_11->addWidget(j6a);

        j6alpha = new QLineEdit(scrollAreaWidgetContents_2);
        j6alpha->setObjectName(QString::fromUtf8("j6alpha"));

        horizontalLayout_11->addWidget(j6alpha);

        j6theta = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        j6theta->setObjectName(QString::fromUtf8("j6theta"));
        j6theta->setMinimum(-90);
        j6theta->setMaximum(90.99);

        horizontalLayout_11->addWidget(j6theta);


        verticalLayout_2->addLayout(horizontalLayout_11);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_15->addWidget(scrollArea_2);

        toolBox->addItem(setting2, QString::fromUtf8("Input Setting"));
        setting3 = new QWidget();
        setting3->setObjectName(QString::fromUtf8("setting3"));
        setting3->setGeometry(QRect(0, 0, 404, 626));
        verticalLayout_16 = new QVBoxLayout(setting3);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        label_5 = new QLabel(setting3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_16->addWidget(label_5);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        numFrameSlider = new QSlider(setting3);
        numFrameSlider->setObjectName(QString::fromUtf8("numFrameSlider"));
        numFrameSlider->setMinimum(5);
        numFrameSlider->setMaximum(25);
        numFrameSlider->setOrientation(Qt::Horizontal);
        numFrameSlider->setTickPosition(QSlider::TicksAbove);

        horizontalLayout_38->addWidget(numFrameSlider);

        numFrameSpinBox = new QSpinBox(setting3);
        numFrameSpinBox->setObjectName(QString::fromUtf8("numFrameSpinBox"));
        numFrameSpinBox->setMinimum(5);
        numFrameSpinBox->setMaximum(25);

        horizontalLayout_38->addWidget(numFrameSpinBox);


        verticalLayout_16->addLayout(horizontalLayout_38);

        label_6 = new QLabel(setting3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_16->addWidget(label_6);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        numFrameSlider_2 = new QSlider(setting3);
        numFrameSlider_2->setObjectName(QString::fromUtf8("numFrameSlider_2"));
        numFrameSlider_2->setMinimum(5);
        numFrameSlider_2->setMaximum(55);
        numFrameSlider_2->setOrientation(Qt::Horizontal);
        numFrameSlider_2->setTickPosition(QSlider::TicksAbove);

        horizontalLayout_39->addWidget(numFrameSlider_2);

        numFrameSpinBox_2 = new QSpinBox(setting3);
        numFrameSpinBox_2->setObjectName(QString::fromUtf8("numFrameSpinBox_2"));
        numFrameSpinBox_2->setMinimum(5);
        numFrameSpinBox_2->setMaximum(55);

        horizontalLayout_39->addWidget(numFrameSpinBox_2);


        verticalLayout_16->addLayout(horizontalLayout_39);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        newGestureNameLineEdit = new QLineEdit(setting3);
        newGestureNameLineEdit->setObjectName(QString::fromUtf8("newGestureNameLineEdit"));
        newGestureNameLineEdit->setMinimumSize(QSize(200, 26));

        horizontalLayout_5->addWidget(newGestureNameLineEdit);

        recordGestureButton = new QPushButton(setting3);
        recordGestureButton->setObjectName(QString::fromUtf8("recordGestureButton"));

        horizontalLayout_5->addWidget(recordGestureButton);


        verticalLayout_16->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gestureNameBox = new QComboBox(setting3);
        gestureNameBox->setObjectName(QString::fromUtf8("gestureNameBox"));
        gestureNameBox->setMinimumSize(QSize(300, 26));

        horizontalLayout_4->addWidget(gestureNameBox);

        gestureSelectButton = new QPushButton(setting3);
        gestureSelectButton->setObjectName(QString::fromUtf8("gestureSelectButton"));
        gestureSelectButton->setMinimumSize(QSize(70, 32));

        horizontalLayout_4->addWidget(gestureSelectButton);


        verticalLayout_16->addLayout(horizontalLayout_4);

        gestureEditBrowzer = new QTextBrowser(setting3);
        gestureEditBrowzer->setObjectName(QString::fromUtf8("gestureEditBrowzer"));

        verticalLayout_16->addWidget(gestureEditBrowzer);

        toolBox->addItem(setting3, QString::fromUtf8("Gesture Setting"));
        setting4 = new QWidget();
        setting4->setObjectName(QString::fromUtf8("setting4"));
        setting4->setGeometry(QRect(0, 0, 400, 626));
        verticalLayout_17 = new QVBoxLayout(setting4);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        scrollArea_4 = new QScrollArea(setting4);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 374, 600));
        vtkChart1 = new QVTKWidget(scrollAreaWidgetContents_4);
        vtkChart1->setObjectName(QString::fromUtf8("vtkChart1"));
        vtkChart1->setGeometry(QRect(10, 40, 350, 161));
        vtkChart2 = new QVTKWidget(scrollAreaWidgetContents_4);
        vtkChart2->setObjectName(QString::fromUtf8("vtkChart2"));
        vtkChart2->setGeometry(QRect(10, 260, 351, 241));
        label_7 = new QLabel(scrollAreaWidgetContents_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 10, 56, 16));
        label_38 = new QLabel(scrollAreaWidgetContents_4);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(10, 220, 56, 16));
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_17->addWidget(scrollArea_4);

        toolBox->addItem(setting4, QString::fromUtf8("Resoning Setting"));

        horizontalLayout_37->addWidget(toolBox);

        qvtkWidget = new QVTKWidget(layoutWidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy);
        qvtkWidget->setMinimumSize(QSize(840, 750));

        horizontalLayout_37->addWidget(qvtkWidget);

        horizontalSpacer_5 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_37->addItem(horizontalSpacer_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1333, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(widthLineEdit);
        label_3->setBuddy(heightLineEdit);
        label->setBuddy(windowNumSpinBox);
#endif // QT_NO_SHORTCUT

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionOpen_Config);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Scene);
        menuFile->addAction(actionSave_config);
        menuEdit->addAction(actionNew_gesture);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open file", 0, QApplication::UnicodeUTF8));
        actionOpen_Config->setText(QApplication::translate("MainWindow", "Open config", 0, QApplication::UnicodeUTF8));
        actionSave_Scene->setText(QApplication::translate("MainWindow", "Save scene", 0, QApplication::UnicodeUTF8));
        actionSave_config->setText(QApplication::translate("MainWindow", "Save config", 0, QApplication::UnicodeUTF8));
        actionNew_gesture->setText(QApplication::translate("MainWindow", "New gesture", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Parallax:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Windows:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Width:  ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Height:", 0, QApplication::UnicodeUTF8));
        heightLineEdit->setText(QString());
        label->setText(QApplication::translate("MainWindow", "&Total:", 0, QApplication::UnicodeUTF8));
        createWindowButton->setText(QApplication::translate("MainWindow", "&Create", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Keystones:", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MainWindow", "1:", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("MainWindow", "x:", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("MainWindow", "y:", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MainWindow", "2:", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("MainWindow", "x:", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("MainWindow", "y:", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("MainWindow", "3:", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("MainWindow", "x:", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("MainWindow", "y:", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("MainWindow", "4:", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("MainWindow", "x:", 0, QApplication::UnicodeUTF8));
        label_55->setText(QApplication::translate("MainWindow", "y:", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MainWindow", "Window number:", 0, QApplication::UnicodeUTF8));
        setKeystoneButton->setText(QApplication::translate("MainWindow", "&Set", 0, QApplication::UnicodeUTF8));
        saveKeystoneButton->setText(QApplication::translate("MainWindow", "Save keystone config", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(setting1), QApplication::translate("MainWindow", "Output Setting", 0, QApplication::UnicodeUTF8));
        leapActivateButton->setText(QApplication::translate("MainWindow", "Enable Leap Motion", 0, QApplication::UnicodeUTF8));
        robotActivateButton->setText(QApplication::translate("MainWindow", "Enable Manipulator", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Joints: DH", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", " parameter:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "d", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "a", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "alpha", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "theta", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "1:", 0, QApplication::UnicodeUTF8));
        j1d->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        j1a->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        j1alpha->setText(QApplication::translate("MainWindow", "90", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "2:", 0, QApplication::UnicodeUTF8));
        j2d->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        j2a->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        j2alpha->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "3:", 0, QApplication::UnicodeUTF8));
        j3d->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        j3a->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        j3alpha->setText(QApplication::translate("MainWindow", "90", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "4:", 0, QApplication::UnicodeUTF8));
        j4d->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        j4a->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        j4alpha->setText(QApplication::translate("MainWindow", "90", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "5:", 0, QApplication::UnicodeUTF8));
        j5d->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        j5a->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        j5alpha->setText(QApplication::translate("MainWindow", "90", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "6:", 0, QApplication::UnicodeUTF8));
        j6d->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        j6a->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        j6alpha->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(setting2), QApplication::translate("MainWindow", "Input Setting", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Number of input gesture frames (sparse):", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Number of recording gesture frames (dense):", 0, QApplication::UnicodeUTF8));
        recordGestureButton->setText(QApplication::translate("MainWindow", "Record New Gesture", 0, QApplication::UnicodeUTF8));
        gestureSelectButton->setText(QApplication::translate("MainWindow", "Select", 0, QApplication::UnicodeUTF8));
        gestureEditBrowzer->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.Lucida Grande UI'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(setting3), QApplication::translate("MainWindow", "Gesture Setting", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Chart 1:", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "Chart 2:", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(setting4), QApplication::translate("MainWindow", "Resoning Setting", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
