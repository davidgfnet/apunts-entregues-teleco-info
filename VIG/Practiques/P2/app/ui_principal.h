/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Principal
{
public:
    QHBoxLayout *horizontalLayout_2;
    GLWidget *gLWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonLoadObject;
    QPushButton *buttonAutoZoom;
    QPushButton *buttonResetCamera;
    QCheckBox *cbWireframe;
    QCheckBox *mostraBB;
    QCheckBox *cbOrtogonal;
    QCheckBox *checkPlantaAlcat;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *Principal)
    {
        if (Principal->objectName().isEmpty())
            Principal->setObjectName(QString::fromUtf8("Principal"));
        Principal->resize(644, 420);
        horizontalLayout_2 = new QHBoxLayout(Principal);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gLWidget = new GLWidget(Principal);
        gLWidget->setObjectName(QString::fromUtf8("gLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gLWidget->sizePolicy().hasHeightForWidth());
        gLWidget->setSizePolicy(sizePolicy);
        gLWidget->setMinimumSize(QSize(400, 400));

        horizontalLayout_2->addWidget(gLWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        buttonLoadObject = new QPushButton(Principal);
        buttonLoadObject->setObjectName(QString::fromUtf8("buttonLoadObject"));

        verticalLayout->addWidget(buttonLoadObject);

        buttonAutoZoom = new QPushButton(Principal);
        buttonAutoZoom->setObjectName(QString::fromUtf8("buttonAutoZoom"));

        verticalLayout->addWidget(buttonAutoZoom);

        buttonResetCamera = new QPushButton(Principal);
        buttonResetCamera->setObjectName(QString::fromUtf8("buttonResetCamera"));

        verticalLayout->addWidget(buttonResetCamera);

        cbWireframe = new QCheckBox(Principal);
        cbWireframe->setObjectName(QString::fromUtf8("cbWireframe"));

        verticalLayout->addWidget(cbWireframe);

        mostraBB = new QCheckBox(Principal);
        mostraBB->setObjectName(QString::fromUtf8("mostraBB"));

        verticalLayout->addWidget(mostraBB);

        cbOrtogonal = new QCheckBox(Principal);
        cbOrtogonal->setObjectName(QString::fromUtf8("cbOrtogonal"));

        verticalLayout->addWidget(cbOrtogonal);

        checkPlantaAlcat = new QCheckBox(Principal);
        checkPlantaAlcat->setObjectName(QString::fromUtf8("checkPlantaAlcat"));

        verticalLayout->addWidget(checkPlantaAlcat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Principal);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Principal);
        QObject::connect(buttonLoadObject, SIGNAL(clicked()), gLWidget, SLOT(LoadObject()));
        QObject::connect(pushButton, SIGNAL(clicked()), Principal, SLOT(close()));
        QObject::connect(buttonResetCamera, SIGNAL(clicked()), gLWidget, SLOT(ResetCamera()));
        QObject::connect(cbWireframe, SIGNAL(toggled(bool)), gLWidget, SLOT(setWireframe(bool)));
        QObject::connect(mostraBB, SIGNAL(toggled(bool)), gLWidget, SLOT(setBBRender(bool)));
        QObject::connect(buttonAutoZoom, SIGNAL(clicked()), gLWidget, SLOT(AutoZoom()));
        QObject::connect(cbOrtogonal, SIGNAL(toggled(bool)), gLWidget, SLOT(OrthoView(bool)));
        QObject::connect(checkPlantaAlcat, SIGNAL(toggled(bool)), gLWidget, SLOT(Toogle3D(bool)));

        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QWidget *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "Principal", 0, QApplication::UnicodeUTF8));
        buttonLoadObject->setText(QApplication::translate("Principal", "Load Object", 0, QApplication::UnicodeUTF8));
        buttonAutoZoom->setText(QApplication::translate("Principal", "Auto zoom", 0, QApplication::UnicodeUTF8));
        buttonResetCamera->setText(QApplication::translate("Principal", "ResetCamera", 0, QApplication::UnicodeUTF8));
        cbWireframe->setText(QApplication::translate("Principal", "Wireframe", 0, QApplication::UnicodeUTF8));
        mostraBB->setText(QApplication::translate("Principal", "Mostra Bounding Box", 0, QApplication::UnicodeUTF8));
        cbOrtogonal->setText(QApplication::translate("Principal", "Vista ortogonal", 0, QApplication::UnicodeUTF8));
        checkPlantaAlcat->setText(QApplication::translate("Principal", "Planta i al\303\247at", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Principal", "&Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
