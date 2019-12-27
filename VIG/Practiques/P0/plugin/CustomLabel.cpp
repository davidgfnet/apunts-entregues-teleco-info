
#include "CustomLabel.h"
#include <iostream>

CustomLabel::CustomLabel(const QString& text, QWidget *parent) :QLabel(text,parent) {}

void CustomLabel::clear() {
	this->setText(QString(""));
}


void CustomLabel::addRed() {
	if (this->text().length() >= 10) this->setText(QString(""));
	this->setText(this->text()+QString("R"));
}

void CustomLabel::addBlue() {
	if (this->text().length() >= 10) this->setText(QString(""));
	this->setText(this->text()+QString("B"));
}

void CustomLabel::addGreen() {
	if (this->text().length() >= 10) this->setText(QString(""));
	this->setText(this->text()+QString("G"));
}

void CustomLabel::addYellow() {
	if (this->text().length() >= 10) this->setText(QString(""));
	this->setText(this->text()+QString("Y"));
}


