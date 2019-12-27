#include "glwidget.h"
#include <math.h>

#define ZOOM_SENSIBILITY 0.15f
#define ZOOM_SENSIBILITY_WHEEL 0.1f

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
  this->setMouseTracking(true);
  this->setFocusPolicy(Qt::StrongFocus);
  this->grabKeyboard();
  scene.ResetCamera();
}

GLWidget::~GLWidget() {
  this->releaseKeyboard();
}

void GLWidget::initializeGL()
{
  glClearColor(0.4f, 0.4f, 0.8f, 1.0f);
  glEnable(GL_DEPTH_TEST);
  scene.Init(this);
}
void GLWidget::resizeGL (int width, int height)
{
  vp_w = width;
  vp_h = height;
  scene.setViewport(vp_w,vp_h);
  glViewport (0, 0, width, height);
}

void GLWidget::paintGL( void )
{
  // dibuixar eixos aplicacio
  glDisable(GL_LIGHTING);

  scene.Render();
}

void GLWidget::mousePressEvent( QMouseEvent *e) {
  xClick = e->x();
  yClick = e->y();

  if (e->button()&Qt::RightButton) {
    if (scene.CheckFixPosition()) {
      scene.FixPosition();
      updateGL();
    }
  }

  if (e->button()&Qt::LeftButton &&
      ! (e->modifiers()&(Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
  {
    // Fem rotació!
    DoingInteractive = ROTATE;
  }
  else if (e->button()&Qt::LeftButton &&  e->modifiers() &Qt::ShiftModifier)
  {
    DoingInteractive = ZOOM;
  }
  else if (e->button()&Qt::LeftButton &&  e->modifiers() &Qt::ControlModifier)
  {
      DoingInteractive = PAN;
  }
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
  switch (e->key())
  {
    case Qt::Key_F:
        scene.setWireframe(true);
        updateGL();
        break;
    case Qt::Key_S:
        scene.setWireframe(false);
        updateGL();
        break;
    case Qt::Key_Escape:
        scene.CancelSelection();
        updateGL();
        break;
    case Qt::Key_M:
        scene.ToogleMove();
        updateGL();
        break;
    case Qt::Key_R:
        scene.Rotate();
        updateGL();
        break;
    case Qt::Key_D:
        scene.Rotate();
        updateGL();
        break;
    default: e->ignore();
  }
}

void GLWidget::mouseReleaseEvent( QMouseEvent * e) {
  // Mirem si l'usuari selecciona alguna cosa
  if (e->button()&Qt::LeftButton) {
    if (scene.DoPicking(e->x(),vp_h-e->y())) {
      updateGL();
    }
  }

  DoingInteractive = NONE;
}

void GLWidget::wheelEvent(QWheelEvent *event) {
  float numDeg = event->delta();
  scene.UpdateZoom(ZOOM_SENSIBILITY_WHEEL*numDeg);
  updateGL();
}

void GLWidget::mouseMoveEvent(QMouseEvent *e)
{
  // Aqui cal que es calculi i s'apliqui la rotaci, el zoom o el pan
  // com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotacio
    int hangle = 360*float(e->x()-xClick)/vp_w;
    int vangle = -180*float(e->y()-yClick)/vp_h;
    scene.UpdateHAngle(hangle);
    scene.UpdateVAngle(vangle);
    this->updateGL();
  }
  else if (DoingInteractive == ZOOM)
  {
    float y = e->y()-yClick;
    scene.UpdateZoom(ZOOM_SENSIBILITY*y);
    this->updateGL();
  }
  else if (DoingInteractive==PAN)
  {
    float x = e->x()-xClick;
    float y = e->y()-yClick;
  	scene.DoPan(x,y);
    this->updateGL();
  }
  
//  Vector punt = this->UnprojectPoint(e->x(),e->y());
//  if (scene.MovingMouse(punt,float(e->x())/float(vp_w)-0.5f,float(vp_h-e->y())/float(vp_h)-0.5f))
//    this->updateGL();

  if (scene.MovingMouse(e->x(),e->y(),vp_w,vp_h))
    this->updateGL();


  xClick = e->x();
  yClick = e->y();
}

void GLWidget::LoadObject()
{
  QString model = QFileDialog::getOpenFileName(this, tr("Open File"), "../data", tr("Objectes (*.obj)"));
  if (model != "") {
    scene.LoadObject(model.toStdString());
  }
  this->updateGL();
}

void GLWidget::setBBRender(bool a) {
  Scene::bbrender = a;
  this->updateGL();
}

void GLWidget::setWireframe(bool wf) {
  scene.setWireframe(wf);
  this->updateGL();
}
void GLWidget::AutoZoom() {
  scene.AutoZoom();
  this->updateGL();
}

void GLWidget::ResetCamera() {
  scene.ResetCamera();
  this->updateGL();
}
void GLWidget::OrthoView(bool a) {
  scene.OrthoView(a);
  this->updateGL();
}

void GLWidget::Toogle3D(bool a) {
  scene.Toogle3D(a);
  this->updateGL();
}

Vector GLWidget::UnprojectPoint(int x, int y) {
  // Cal obtenir la coordenada 3D del punt al que estem. Donat que la funció
  // de projecció no és bijectiva (R³ -> R²) existeixen infinits punts que
  // compleixen l'equació. Trobarem dos punts (qualsevols) i farem una recta.
  // Aleshores podem tribar el punt fent intersecció entre recta i pla (o
  // triangle si s'escau).

  y = vp_h - y;  // Conversió a coordenades de OGL

  GLdouble pos1[3],pos2[3];
  GLdouble mmodel[16]; GLdouble mproj[16];
  GLint viewp[4];
  glGetDoublev(GL_MODELVIEW_MATRIX,mmodel);
  glGetDoublev(GL_PROJECTION_MATRIX,mproj);
  viewp[0] = 0; viewp[1] = 0; viewp[2] = vp_w; viewp[3] = vp_h;
  gluUnProject(x,y,-1,mmodel,mproj,viewp,&pos1[0],&pos1[1],&pos1[2]);
  gluUnProject(x,y, 1,mmodel,mproj,viewp,&pos2[0],&pos2[1],&pos2[2]);

  // Projectem sobre el pla XZ
  Vector p1(pos1[0],pos1[1],pos1[2]);
  Vector p2(pos2[0],pos2[1],pos2[2]);
  Vector dir = p2-p1;
  // Tenim p1 + dir*k = (x,0,z), d'on treballant sobre Y tenim
  // p1.y + dir.y*k = 0 --> k = -p1.y/dir.y
  // Coneguda k trobem x i z
  float k = -p1.y/dir.y;
  Vector punt = p1 + dir*k;
  return punt;
}

void GLWidget::UpdateMaterial(float * mat) {
  scene.SetObjMaterial(mat);
  updateGL();
}

void GLWidget::MaterialApply() {
  scene.SetObjMaterialApply();
  emit(HideMaterialWidget());
  updateGL();
}

void GLWidget::MaterialRevert() {
  scene.SetObjMaterialRevert();
  emit(HideMaterialWidget());
  updateGL();
}

void GLWidget::LightUpdate(float* col,float* alt) {
  scene.LightUpdate(col,alt);
  updateGL();
}

void GLWidget::ToogleCulling(bool a) {
  scene.ToogleCulling(a);
  updateGL();
}

void GLWidget::ToogleZtest(bool a) {
  scene.ToogleZtest(a);
  updateGL();
}

#define ADD_OBJ(a) \
  scene.LoadObject(a); \
  this->updateGL();


void GLWidget::addCube() {
  ADD_OBJ("./../models/cub.obj")
}

void GLWidget::addPyramid() {
  ADD_OBJ("./../models/pyramid.obj")
}

void GLWidget::addDoor() {
  ADD_OBJ("./../models/door.obj")
}

void GLWidget::addWindow() {
  ADD_OBJ("./../models/window.obj")
}

void GLWidget::addPrisma() {
  ADD_OBJ("./../models/prisma.obj")
}

void GLWidget::MoveTool() {
  scene.ToogleMove();
  updateGL();
}

void GLWidget::EditMaterial() {
  float materials[13];
  scene.GetObjMaterial(materials);
  emit(ShowMaterialWidget(materials[0],materials[1],materials[2],
                          materials[4],materials[5],materials[6],
                          materials[8],materials[9],materials[10],materials[12]));
  scene.EditMaterial();
  updateGL();
}

void GLWidget::DeleteObj() {
  scene.DeleteObj();
  updateGL();
}

void GLWidget::XScale() {
  scene.Scale(0);
  updateGL();
}

void GLWidget::YScale() {
  scene.Scale(1);
  updateGL();
}

void GLWidget::ZScale() {
  scene.Scale(2);
  updateGL();
}

void GLWidget::RotateObj() {
  scene.Rotate();
  updateGL();
}

void GLWidget::SaveScene() {
  QString fitxer = QFileDialog::getSaveFileName(this, tr("Open File"), "../data", tr("Objectes (*.obj)"));
  if (fitxer != "") {
    scene.SaveScene(fitxer.toStdString());
  }
}

void GLWidget::LoadScene() {
  QString fitxer = QFileDialog::getOpenFileName(this, tr("Open File"), "../data", tr("Escenes (*.txt)"));
  if (fitxer != "") {
    scene.LoadScene(fitxer.toStdString());
  }
  updateGL();
}

void GLWidget::DisableObj() {
  scene.DisableObj();
  updateGL();
}

void GLWidget::EnableObj() {
  scene.EnableObj();
  updateGL();
}

