
#include <math.h>
#include "objecte.h"
#include "box.h"
#include <QtOpenGL/qgl.h>
#include "scene.h"
#include "matrix.h"

Objecte::Objecte(std::string n, int mod, Point p, float scl, float ori):
  nom(n), model(mod), pos(p), scale(scl), orientation(ori)
{}

Objecte::~Objecte(void)
{}

void Objecte::Render(std::vector<Model> &lmodels)
{
  // Cal pintar la geometria de l'objecte transformada de la forma adequada
  Box b = lmodels[model].boundingBox();
  Point mid = b.getCenter();
  mid.y = b.minb.y; // A la base de la caixa!

  glPushMatrix();
  glTranslatef(pos.x,pos.y,pos.z);
  glRotatef(orientation,0,1,0);
  glScalef(scale,scale,scale);
  glTranslatef(-mid.x,-mid.y,-mid.z);
  
  lmodels[model].Render();

  if (Scene::bbrender) {
    b.Render();
  }
  glPopMatrix();
}

std::string Objecte::getNom()
{
  return nom;
}

int Objecte::getModelId()
{
  return model;
}

Point Objecte::getPosition()
{
   return pos;
}

void Objecte::setPosition(Point p) {
  pos = p;
}

float Objecte::getScale() {
   return scale;
}

float Objecte::getOrientation() {
   return orientation;
}
void Objecte::setOrientation(float ori) {
  orientation = ori;
}

Box Objecte::getBB(std::vector<Model> &ml) const {
  return ml[model].boundingBox();
}

Box Objecte::getTransformedBB(std::vector<Model> &ml) const {
  Box b = ml[model].boundingBox();
  Point mid = b.getCenter();
  mid.y = b.minb.y; // A la base de la caixa!

  Matrix rot = MatrixRotationY(orientation*M_PI/180.0f);
  b.minb -= mid;
  b.maxb -= mid;
  b.minb = scale*b.minb;
  b.maxb = scale*b.maxb;
  b.minb = rot*b.minb;
  b.maxb = rot*b.maxb;
  b.minb += pos;
  b.maxb += pos;
  return b;
}



