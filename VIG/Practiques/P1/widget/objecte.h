#ifndef _OBJECTE_H_
#define _OBJECTE_H_
#include <vector>
#include <stdio.h>
#include "point.h"
#include "model.h"
#include "box.h"


using namespace std;

class Objecte
{
 protected:
  std::string nom;
  int model;   // identificador del model
  Point pos;    // posicio sobre el terra
  float scale;	   // mida en unitats
  float orientation;  //orientació respecte Y

 public:
  Objecte(std::string nom, int idmod, Point p, float scl, float ori);
  ~Objecte(void);

  void Render(std::vector<Model> &);
  std::string getNom();
  int getModelId();
  Point getPosition();
  float getScale();
  float getOrientation();

  void setPosition(Point p);
  void setOrientation(float ori);

  Box getBB(std::vector<Model> &) const;
  Box getTransformedBB(std::vector<Model> &) const;

};

#endif
