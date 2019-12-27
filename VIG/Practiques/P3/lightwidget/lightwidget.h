#ifndef LightWidget_H
#define LightWidget_H

#include <QWidget>

namespace Ui {
    class LightWidget;
}

class LightWidget : public QWidget {
    Q_OBJECT
public:
    LightWidget(QWidget *parent = 0);
    ~LightWidget();

    void GetValues(float * colors[2][4], float * alcada);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::LightWidget *ui;
    float colors[2][4];
    float al;
    int curr_l;

public slots:
    void ValuesUpdated();
    void ComboChanged(int);

signals:
    void LightChange(float *,float *);
};

#endif // PRINCIPAL_H
