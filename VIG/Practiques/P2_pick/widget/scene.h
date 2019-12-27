#ifndef _Scene_H_
#define _Scene_H_
#include "objecte.h"
#include "matrix.h"
#include "model.h"
#include <QtOpenGL/qgl.h>

#define PICK_BUFFER_SIZE 1024

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
  bool orthoview,vista3d;
  int cursorx,cursory;
  int selected_obj;

  void DrawScene();
  unsigned int pickBuffer[PICK_BUFFER_SIZE];
  
 public:
  static MaterialLib matlib;	  // col·lecció de materials
  static bool bbrender;
  static unsigned int name_counter;

  Scene();

  void Init();
  void construirBase();
  void Render(bool pickmat = false);
  void LoadObject(std::string);
  bool SetLastObjectPosition(Vector pos);
  bool SetLastObjectRotation(int inc);
  bool DoPicking(int cursorx, int cursory);
  void NoSelection();

  void DoPan(float x, float y);
  void UpdateZoom(float);
  void UpdateHAngle(int);
  void UpdateVAngle(int);
  void setWireframe(bool);
  void ResetCamera();
  void setViewport(float,float);
  void AutoZoom();
  void OrthoView(bool);
  void Toogle3D(bool);
};

#endif

