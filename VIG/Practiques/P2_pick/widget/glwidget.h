#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFileDialog>
#include "point.h"
#include "scene.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    virtual ~GLWidget();

protected:
    void initializeGL ();

    void paintGL ();
    void resizeGL (int width, int height);
    Vector UnprojectPoint(int x, int y);

    virtual void mousePressEvent (QMouseEvent *e);
    virtual void mouseReleaseEvent (QMouseEvent *e);
    virtual void mouseMoveEvent (QMouseEvent *e);
    virtual void keyPressEvent (QKeyEvent *event);
    virtual void wheelEvent(QWheelEvent *event);

    double dist, anterior, posterior, radi, angleX, angleY, anglecam, ra;
    Point VRP;
    Scene scene;
    int vp_h,vp_w;

    typedef  enum {NONE, ROTATE, ZOOM, PAN} InteractiveAction;
    InteractiveAction DoingInteractive;

    int   xClick, yClick;
    bool coloca_obj;

 public slots:
     void LoadObject ();
     void setBBRender(bool);
     void setWireframe(bool);
     void ResetCamera();
     void AutoZoom();
     void OrthoView(bool);
     void Toogle3D(bool);
};

#endif

