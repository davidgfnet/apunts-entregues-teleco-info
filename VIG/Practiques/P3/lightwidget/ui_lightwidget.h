/********************************************************************************
** Form generated from reading UI file 'lightwidget.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTWIDGET_H
#define UI_LIGHTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QWidget>
#include "colorwidget.h"

QT_BEGIN_NAMESPACE

class Ui_LightWidget
{
public:
    QComboBox *comboBox;
    ColorWidget *colorwidget;
    QSlider *sliderLlum;
    QLabel *label;

    void setupUi(QWidget *LightWidget)
    {
        if (LightWidget->objectName().isEmpty())
            LightWidget->setObjectName(QString::fromUtf8("LightWidget"));
        LightWidget->resize(240, 165);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LightWidget->sizePolicy().hasHeightForWidth());
        LightWidget->setSizePolicy(sizePolicy);
        comboBox = new QComboBox(LightWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 221, 27));
        colorwidget = new ColorWidget(LightWidget);
        colorwidget->setObjectName(QString::fromUtf8("colorwidget"));
        colorwidget->setGeometry(QRect(0, 45, 240, 88));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(colorwidget->sizePolicy().hasHeightForWidth());
        colorwidget->setSizePolicy(sizePolicy1);
        colorwidget->setMinimumSize(QSize(240, 88));
        sliderLlum = new QSlider(LightWidget);
        sliderLlum->setObjectName(QString::fromUtf8("sliderLlum"));
        sliderLlum->setGeometry(QRect(69, 140, 161, 20));
        sliderLlum->setMinimum(1);
        sliderLlum->setMaximum(30);
        sliderLlum->setOrientation(Qt::Horizontal);
        label = new QLabel(LightWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 140, 66, 17));

        retranslateUi(LightWidget);
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), LightWidget, SLOT(ComboChanged(int)));
        QObject::connect(colorwidget, SIGNAL(valueChanged()), LightWidget, SLOT(ValuesUpdated()));
        QObject::connect(sliderLlum, SIGNAL(valueChanged(int)), LightWidget, SLOT(ValuesUpdated()));

        QMetaObject::connectSlotsByName(LightWidget);
    } // setupUi

    void retranslateUi(QWidget *LightWidget)
    {
        LightWidget->setWindowTitle(QApplication::translate("LightWidget", "Form", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("LightWidget", "Light 0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LightWidget", "Light 1", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("LightWidget", "Al\303\247ada", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LightWidget: public Ui_LightWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTWIDGET_H
