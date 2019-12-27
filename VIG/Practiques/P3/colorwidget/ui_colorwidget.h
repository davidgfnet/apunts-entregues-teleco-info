/********************************************************************************
** Form generated from reading UI file 'colorwidget.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORWIDGET_H
#define UI_COLORWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorWidget
{
public:
    QSlider *sliderRed;
    QLabel *label;
    QLabel *label_2;
    QSlider *sliderGreen;
    QLabel *label_3;
    QSlider *sliderBlue;

    void setupUi(QWidget *ColorWidget)
    {
        if (ColorWidget->objectName().isEmpty())
            ColorWidget->setObjectName(QString::fromUtf8("ColorWidget"));
        ColorWidget->resize(239, 88);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorWidget->sizePolicy().hasHeightForWidth());
        ColorWidget->setSizePolicy(sizePolicy);
        sliderRed = new QSlider(ColorWidget);
        sliderRed->setObjectName(QString::fromUtf8("sliderRed"));
        sliderRed->setGeometry(QRect(60, 10, 171, 20));
        sliderRed->setMaximum(255);
        sliderRed->setOrientation(Qt::Horizontal);
        label = new QLabel(ColorWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 66, 17));
        label_2 = new QLabel(ColorWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 66, 27));
        sliderGreen = new QSlider(ColorWidget);
        sliderGreen->setObjectName(QString::fromUtf8("sliderGreen"));
        sliderGreen->setGeometry(QRect(60, 30, 171, 30));
        sliderGreen->setMaximum(255);
        sliderGreen->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(ColorWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 66, 17));
        sliderBlue = new QSlider(ColorWidget);
        sliderBlue->setObjectName(QString::fromUtf8("sliderBlue"));
        sliderBlue->setGeometry(QRect(60, 60, 171, 20));
        sliderBlue->setMaximum(255);
        sliderBlue->setOrientation(Qt::Horizontal);

        retranslateUi(ColorWidget);
        QObject::connect(sliderRed, SIGNAL(valueChanged(int)), ColorWidget, SLOT(changedRed(int)));
        QObject::connect(sliderGreen, SIGNAL(valueChanged(int)), ColorWidget, SLOT(changedGreen(int)));
        QObject::connect(sliderBlue, SIGNAL(valueChanged(int)), ColorWidget, SLOT(changedBlue(int)));

        QMetaObject::connectSlotsByName(ColorWidget);
    } // setupUi

    void retranslateUi(QWidget *ColorWidget)
    {
        ColorWidget->setWindowTitle(QApplication::translate("ColorWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ColorWidget", "Red:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ColorWidget", "Green:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ColorWidget", "Blue:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ColorWidget: public Ui_ColorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORWIDGET_H
