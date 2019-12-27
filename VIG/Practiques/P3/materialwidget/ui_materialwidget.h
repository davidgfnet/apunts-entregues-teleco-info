/********************************************************************************
** Form generated from reading UI file 'materialwidget.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALWIDGET_H
#define UI_MATERIALWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>
#include "colorwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MaterialWidget
{
public:
    QComboBox *comboBox;
    ColorWidget *colorwidget;
    QPushButton *buttonAplicar;
    QPushButton *buttonReiniciar;
    QSlider *shininessSlider;

    void setupUi(QWidget *MaterialWidget)
    {
        if (MaterialWidget->objectName().isEmpty())
            MaterialWidget->setObjectName(QString::fromUtf8("MaterialWidget"));
        MaterialWidget->resize(241, 199);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MaterialWidget->sizePolicy().hasHeightForWidth());
        MaterialWidget->setSizePolicy(sizePolicy);
        comboBox = new QComboBox(MaterialWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 221, 27));
        colorwidget = new ColorWidget(MaterialWidget);
        colorwidget->setObjectName(QString::fromUtf8("colorwidget"));
        colorwidget->setGeometry(QRect(0, 45, 240, 240));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(colorwidget->sizePolicy().hasHeightForWidth());
        colorwidget->setSizePolicy(sizePolicy1);
        colorwidget->setMinimumSize(QSize(240, 240));
        buttonAplicar = new QPushButton(MaterialWidget);
        buttonAplicar->setObjectName(QString::fromUtf8("buttonAplicar"));
        buttonAplicar->setGeometry(QRect(10, 160, 101, 27));
        buttonReiniciar = new QPushButton(MaterialWidget);
        buttonReiniciar->setObjectName(QString::fromUtf8("buttonReiniciar"));
        buttonReiniciar->setGeometry(QRect(130, 160, 98, 27));
        shininessSlider = new QSlider(MaterialWidget);
        shininessSlider->setObjectName(QString::fromUtf8("shininessSlider"));
        shininessSlider->setGeometry(QRect(10, 130, 221, 19));
        shininessSlider->setMaximum(128);
        shininessSlider->setOrientation(Qt::Horizontal);

        retranslateUi(MaterialWidget);
        QObject::connect(buttonAplicar, SIGNAL(clicked()), MaterialWidget, SLOT(Aplica()));
        QObject::connect(shininessSlider, SIGNAL(valueChanged(int)), MaterialWidget, SLOT(ValuesUpdated()));
        QObject::connect(buttonReiniciar, SIGNAL(clicked()), MaterialWidget, SLOT(Revert()));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), MaterialWidget, SLOT(ComboChanged(int)));
        QObject::connect(colorwidget, SIGNAL(valueChanged()), MaterialWidget, SLOT(ValuesUpdated()));

        QMetaObject::connectSlotsByName(MaterialWidget);
    } // setupUi

    void retranslateUi(QWidget *MaterialWidget)
    {
        MaterialWidget->setWindowTitle(QApplication::translate("MaterialWidget", "Form", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MaterialWidget", "Ambient", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MaterialWidget", "DIffuse", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MaterialWidget", "Specular", 0, QApplication::UnicodeUTF8)
        );
        buttonAplicar->setText(QApplication::translate("MaterialWidget", "Aplicar", 0, QApplication::UnicodeUTF8));
        buttonReiniciar->setText(QApplication::translate("MaterialWidget", "Reiniciar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MaterialWidget: public Ui_MaterialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALWIDGET_H
