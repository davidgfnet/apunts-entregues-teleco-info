#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    ui->materialwidget->setVisible(false);


  ui->addCube->setFlat(true);
  ui->addCube->setAutoFillBackground(true);
  ui->addCube->setStyleSheet("background-image:url(../imatges/cub.jpg)");

  ui->addPrisma->setFlat(true);
  ui->addPrisma->setAutoFillBackground(true);
  ui->addPrisma->setStyleSheet("background-image:url(../imatges/prisma.jpg)");

  ui->addPyramid->setFlat(true);
  ui->addPyramid->setAutoFillBackground(true);
  ui->addPyramid->setStyleSheet("background-image:url(../imatges/pyramid.jpg)");

  ui->addWindow->setFlat(true);
  ui->addWindow->setAutoFillBackground(true);
  ui->addWindow->setStyleSheet("background-image:url(../imatges/window.jpg)");

  ui->addDoor->setFlat(true);
  ui->addDoor->setAutoFillBackground(true);
  ui->addDoor->setStyleSheet("background-image:url(../imatges/door.jpg)");

  ui->buttonMove->setFlat(true);
  ui->buttonMove->setAutoFillBackground(true);
  ui->buttonMove->setStyleSheet("background-image:url(../imatges/move.png); background-repeat: none; background-position: center center;");

  ui->buttonMaterial->setFlat(true);
  ui->buttonMaterial->setAutoFillBackground(true);
  ui->buttonMaterial->setStyleSheet("background-image:url(../imatges/material.png); background-repeat: none; background-position: center center;");

  ui->buttonDelete->setFlat(true);
  ui->buttonDelete->setAutoFillBackground(true);
  ui->buttonDelete->setStyleSheet("background-image:url(../imatges/del.png); background-repeat: none; background-position: center center;");

  ui->butResetCamera->setFlat(true);
  ui->butResetCamera->setAutoFillBackground(true);
  ui->butResetCamera->setStyleSheet("background-image:url(../imatges/reset.png); background-repeat: none; background-position: center center;");

  ui->butAutoZoom->setFlat(true);
  ui->butAutoZoom->setAutoFillBackground(true);
  ui->butAutoZoom->setStyleSheet("background-image:url(../imatges/zoom.png); background-repeat: none; background-position: center center;");

  ui->butSave->setFlat(true);
  ui->butSave->setAutoFillBackground(true);
  ui->butSave->setStyleSheet("background-image:url(../imatges/save.png); background-repeat: none; background-position: center center;");

  ui->butLoad->setFlat(true);
  ui->butLoad->setAutoFillBackground(true);
  ui->butLoad->setStyleSheet("background-image:url(../imatges/open.png); background-repeat: none; background-position: center center;");

  ui->buttonDisable->setFlat(true);
  ui->buttonDisable->setAutoFillBackground(true);
  ui->buttonDisable->setStyleSheet("background-image:url(../imatges/disable.png); background-repeat: none; background-position: center center;");

  ui->buttonEnable->setFlat(true);
  ui->buttonEnable->setAutoFillBackground(true);
  ui->buttonEnable->setStyleSheet("background-image:url(../imatges/enable.png); background-repeat: none; background-position: center center;");

  ui->buttonRotate->setFlat(true);
  ui->buttonRotate->setAutoFillBackground(true);
  ui->buttonRotate->setStyleSheet("background-image:url(../imatges/rotate.png); background-repeat: none; background-position: center center;");
}

Principal::~Principal()
{
    delete ui;
}

void Principal::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

