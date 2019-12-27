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
  float sx,sy,sz;	   // mida en unitats
  float osx,osy,osz;   // mida en unitats
  float orientation;  //orientació respecte Y
  float oorientation;  //orientació respecte Y
  bool enable;

 public:
  Objecte(std::string nom, int idmod, Point p, float scl, float ori);
  Objecte(std::string serialdata);
  ~Objecte(void);

  void Render(std::vector<Model> &, bool selected = false, int index_color = -1);
  std::string getNom();
  int getModelId();
  Point getPosition();
  float getScale(int axis);
  float getOrientation();

  void setPosition(Point p);
  void setOrientation(float ori, bool def);
  void RevertOrientation();
  void setEnable(bool);

  std::string Serialize();

  Box getBB(std::vector<Model> &) const;
  std::vector <Point> getTransformedBBPoints(std::vector<Model> &) const;
  bool collideBox(std::vector<Model> &, std::vector <Point> );
  void GetMaterial(float matcolors[13]);
  void SetMaterial(float *, bool def);
  void RevertMaterial();
  void setScale(int axis, float scale, bool def);
  void revertScale();

  private:
    float materials[13];
    float oldmaterials[13];
};

#endif
