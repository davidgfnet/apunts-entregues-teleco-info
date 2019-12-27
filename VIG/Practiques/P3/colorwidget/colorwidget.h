#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QWidget>

namespace Ui {
    class ColorWidget;
}

class ColorWidget : public QWidget {
    Q_OBJECT
public:
    ColorWidget(QWidget *parent = 0);
    ~ColorWidget();

    void GetValues(float * r, float * g, float * b);
    void SetValues(float r, float g, float b);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ColorWidget *ui;
    int r,g,b;

private slots:
    void changedRed(int);
    void changedGreen(int);
    void changedBlue(int);

signals:
    void valueChanged();
};

#endif // PRINCIPAL_H
