
#include <math.h>
#include "objecte.h"
#include "box.h"
#include <QtOpenGL/qgl.h>
#include "scene.h"
#include "matrix.h"

const Vector minbound(-5,-1,-5);
const Vector maxbound(5,1,5);

Objecte::Objecte(std::string n, int mod, Point p, float scl, float ori):
  nom(n), model(mod), pos(p), scale(scl), orientation(ori)
{
}

Objecte::~Objecte(void)
{}

void Objecte::Render(std::vector<Model> &lmodels, bool selected, int index_color)
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
  
  // Fem us només dels 4 bits de major pes
  // Ja que si fem us de 16 bits de profunditat de color
  // (portàtil) elimina els 3 o 2 bits de menor pes
  // Màxim 64 IDs diferents
  if (index_color >= 0) {
    ColorI col;
    col.b = (index_color%256);
    col.g = ((index_color>>8)%256);
    col.r = ((index_color>>16)%256);
    lmodels[model].Render(true,col);
  }else{
    lmodels[model].Render();
  }

  if (selected) {
    b.Render(1,0,0);
  }else if (Scene::bbrender) {
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
  if (p.x > maxbound.x or p.x < minbound.x or p.z > maxbound.z or p.z < minbound.z) return;
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

std::vector <Point> Objecte::getTransformedBBPoints(std::vector<Model> &ml) const {
  Box b = ml[model].boundingBox();
  Point mid = b.getCenter();
  mid.y = b.minb.y; // A la base de la caixa!
  Matrix rot = MatrixRotationY(orientation*M_PI/180.0f);

  std::vector <Point> ret = b.getPoints();
  for (unsigned int i = 0; i < ret.size(); i++) {
    ret[i] -= mid;
    ret[i] = scale*ret[i];
    ret[i] = rot*ret[i];
    ret[i] += pos;
  }
  return ret;
}

bool Objecte::collideBox(std::vector<Model> & mod, std::vector <Point> testpoints) {
  
  std::vector<Point> points = getTransformedBBPoints(mod);
  std::vector<Plane> vec;

  // Regla del sacacorxus ;)
  vec.push_back(Plane(points[2],points[3],points[7]));  // TOP
  vec.push_back(Plane(points[5],points[1],points[0]));  // BOTTOM

  vec.push_back(Plane(points[5],points[4],points[6]));
  vec.push_back(Plane(points[0],points[2],points[6]));

  vec.push_back(Plane(points[5],points[7],points[3]));
  vec.push_back(Plane(points[2],points[0],points[1]));

  for (int i = 0; i < vec.size(); i++) {
    bool allout = true;
    for (int j = 0; j < testpoints.size(); j++) {
      if (PointPlaneDist(vec[i],testpoints[j]) < 0) {
        allout = false;
        break;
      }
    }
    if (allout) return false;  // No collision for sure!
  }
  return true; // It might be a false positive, need to check the other box!
}



