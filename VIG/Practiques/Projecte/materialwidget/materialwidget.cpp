
#include <iostream>
#include <QComboBox>
#include "materialwidget.h"
#include "ui_materialwidget.h"

MaterialWidget::MaterialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaterialWidget)
{
    ui->setupUi(this);
    curr_val = 0;
}

MaterialWidget::~MaterialWidget()
{
    delete ui;
}

void MaterialWidget::changeEvent(QEvent *e)
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

void MaterialWidget::MakeInvisible() {
    this->setVisible(false);
}

void MaterialWidget::MakeVisible(float ar, float ag, float ab,
                                 float dr, float dg, float db,
                                 float sr, float sg, float sb, float s) {

    materials[0] = ar; materials[1] = ag; materials[2] = ab;  materials[3] = 1;
    materials[4] = dr; materials[5] = dg; materials[6] = db;  materials[7] = 1;
    materials[8] = sr; materials[9] = sg; materials[10] = sb; materials[11] = 1;
    materials[12] = s;
    ui->comboBox->setCurrentIndex(0);
    ComboChanged(0);

    this->setVisible(true);
}

void MaterialWidget::ValuesUpdated() {
    int offset = curr_val*4;
    ui->colorwidget->GetValues(&materials[offset+0],&materials[offset+1],&materials[offset+2]);
    materials[offset+3] = 1;
    materials[12] = (float(ui->shininessSlider->value()));

    emit(MaterialChange(materials));
}

void MaterialWidget::ComboChanged(int v) {
    curr_val = v;
    ui->colorwidget->SetValues(materials[curr_val*4+0],materials[curr_val*4+1],materials[curr_val*4+2]);
}

void MaterialWidget::Aplica() {
  emit(MaterialApply());
}

void MaterialWidget::Revert() {
  emit(MaterialRevert());
}


