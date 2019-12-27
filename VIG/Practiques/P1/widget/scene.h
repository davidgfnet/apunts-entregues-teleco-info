#ifndef _Scene_H_
#define _Scene_H_
#include "objecte.h"
#include "matrix.h"
#include "model.h"
#include <QtOpenGL/qgl.h>


class Scene
{
 private:
	
  // Tindrem un vector amb els models geomètrics dels objectes geomètrics
  // i un altre amb instàncies seves (instàncies o referències a objectes).
  std::vector<Model> lmodels;
  std::vector<Objecte> lobjectes;
  float zoom;
  int hangle,vangle;
  bool wireframe;
  float ratio;
  Vector cam_pos, center;
  Matrix viewm;
  float fovy;
  float vh,vw;
  bool orthoview;
  
 public:
  static MaterialLib matlib;	  // col·lecció de materials
  static bool bbrender;

  Scene();

  void Init();
  void construirBase();
  void Render();
  void LoadObject(std::string);
  void SetLastObjectPosition(Vector pos);
  void SetLastObjectRotation(int inc);

  void DoPan(float x, float y);
  void UpdateZoom(float);
  void UpdateHAngle(int);
  void UpdateVAngle(int);
  void setWireframe(bool);
  void ResetCamera();
  void setViewport(float,float);
  void AutoZoom();
  void OrthoView(bool);
};

#endif

