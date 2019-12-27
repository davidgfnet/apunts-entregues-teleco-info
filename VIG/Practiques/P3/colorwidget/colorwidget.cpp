#include "colorwidget.h"
#include "ui_colorwidget.h"

ColorWidget::ColorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorWidget)
{
    ui->setupUi(this);
    r = g = b = 0;
}

ColorWidget::~ColorWidget()
{
    delete ui;
}

void ColorWidget::changeEvent(QEvent *e)
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

void ColorWidget::GetValues(float * r, float * g, float * b) {
   *r = float(this->r)/255.0f;
   *g = float(this->g)/255.0f;
   *b = float(this->b)/255.0f;
}

void ColorWidget::SetValues(float r, float g, float b) {
   this->r = r*255.0f;
   this->g = g*255.0f;
   this->b = b*255.0f;
   this->findChild<QSlider *>("sliderRed")->setValue(this->r);
   this->findChild<QSlider *>("sliderGreen")->setValue(this->g);
   this->findChild<QSlider *>("sliderBlue")->setValue(this->b);
}

void ColorWidget::changedRed(int val) {
   r = val;
   emit(valueChanged());
}

void ColorWidget::changedGreen(int val) {
   g = val;
   emit(valueChanged());
}

void ColorWidget::changedBlue(int val) {
   b = val;
   emit(valueChanged());
}


