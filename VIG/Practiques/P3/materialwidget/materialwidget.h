#ifndef MaterialWidget_H
#define MaterialWidget_H

#include <QWidget>

namespace Ui {
    class MaterialWidget;
}

class MaterialWidget : public QWidget {
    Q_OBJECT
public:
    MaterialWidget(QWidget *parent = 0);
    ~MaterialWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MaterialWidget *ui;
    float materials[13];
    float old_materials[13];
    int curr_val;

public slots:
    void MakeInvisible(float *);
    void MakeVisible(float ar, float ag, float ab,
                     float dr, float dg, float db,
                     float sr, float sg, float sb,
                     float s);
    void ValuesUpdated();
    void ComboChanged(int);
    void Aplica();
    void Revert();

signals:
    void MaterialChange(float *);
};

#endif // PRINCIPAL_H
