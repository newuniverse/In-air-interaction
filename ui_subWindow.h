/********************************************************************************
** Form generated from reading UI file 'subWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWINDOW_H
#define UI_SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_SubWindow
{
public:
    QVTKWidget *subWidget;

    void setupUi(QWidget *SubWindow)
    {
        if (SubWindow->objectName().isEmpty())
            SubWindow->setObjectName(QString::fromUtf8("SubWindow"));
        SubWindow->resize(400, 300);
        subWidget = new QVTKWidget(SubWindow);
        subWidget->setObjectName(QString::fromUtf8("subWidget"));
        subWidget->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(SubWindow);

        QMetaObject::connectSlotsByName(SubWindow);
    } // setupUi

    void retranslateUi(QWidget *SubWindow)
    {
        SubWindow->setWindowTitle(QApplication::translate("SubWindow", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubWindow: public Ui_SubWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
