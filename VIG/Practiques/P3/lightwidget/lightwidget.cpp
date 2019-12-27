
#include <iostream>
#include <QComboBox>
#include "lightwidget.h"
#include "colorwidget.h"
#include "ui_lightwidget.h"

LightWidget::LightWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LightWidget)
{
    ui->setupUi(this);
    curr_l = 0;
    colors = {{1,1,1,1},{1,1,1,1}};
    ComboChanged(0);
}

LightWidget::~LightWidget()
{
    delete ui;
}

void LightWidget::changeEvent(QEvent *e)
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

void LightWidget::ValuesUpdated() {
  ui->colorwidget->GetValues(&colors[curr_l][0],&colors[curr_l][1],&colors[curr_l][2]);
  al = ui->sliderLlum->value();
  emit(LightChange((float*)colors,&al));
}

void LightWidget::ComboChanged(int v) {
  curr_l = v;
  ui->colorwidget->SetValues(colors[curr_l][0],colors[curr_l][1],colors[curr_l][2]);
}

void LightWidget::GetValues(float * colors[2][4], float * alcada) {
   memcpy(colors,this->colors,sizeof(float)*4*2);
   *alcada = ui->sliderLlum->value();
}



