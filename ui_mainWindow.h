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
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
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
    QSpinBox *windowNumSpinBox_2;
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
        label_8->raise();
        parallaxSlider->raise();
        setting2 = new QWidget();
        setting2->setObjectName(QString::fromUtf8("setting2"));
        setting2->setGeometry(QRect(0, 0, 400, 626));
        verticalLayout_15 = new QVBoxLayout(setting2);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        leapActivateButton = new QPushButton(setting2);
        leapActivateButton->setObjectName(QString::fromUtf8("leapActivateButton"));
        leapActivateButton->setMinimumSize(QSize(150, 32));

        verticalLayout_15->addWidget(leapActivateButton);

        scrollArea_2 = new QScrollArea(setting2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(350, 400));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 374, 566));
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

        windowNumSpinBox_2 = new QSpinBox(centralwidget);
        windowNumSpinBox_2->setObjectName(QString::fromUtf8("windowNumSpinBox_2"));
        windowNumSpinBox_2->setGeometry(QRect(560, 730, 53, 24));
        windowNumSpinBox_2->setWrapping(false);
        windowNumSpinBox_2->setReadOnly(false);
        windowNumSpinBox_2->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        windowNumSpinBox_2->setKeyboardTracking(true);
        windowNumSpinBox_2->setMinimum(1);
        windowNumSpinBox_2->setMaximum(11);
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

        toolBox->setCurrentIndex(0);


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
