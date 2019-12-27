#ifndef _Scene_H_
#define _Scene_H_
#include "objecte.h"
#include "matrix.h"
#include "model.h"
#include <QtOpenGL/qgl.h>


#define PICK_BUFFER_SIZE 1024

class GLWidget;

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
  bool moving_obj;
  bool material_obj;
  bool scale_obj;
  bool rotate_obj;
  int scale_axis;
  vector <int> selection_vector;
  vector <Point> last_positions;
  float l0_alcada;
  float colors_llums[2][4];

  void DrawScene(bool picking = false);
  void SetLights(Vector cam = Vector(0,0,0));
  Point last_pos;
  bool culling,ztest;
  GLWidget * glwidget;

  void GoodPosition(int obj);

  GLdouble mview[2][16];
  GLdouble mproj[2][16];
  
 public:
  static MaterialLib matlib;	  // col·lecció de materials
  static bool bbrender;
  static unsigned int name_counter;

  Scene();

  void Init(GLWidget * w);
  void construirBase();
  void Render(bool picking = false);
  void LoadObject(std::string);
  bool MovingMouse(int x, int y, int vpw, int vph);
  Vector UnprojectPoint(int x, int y, int vp_w, int vp_h);
  bool DoPicking(int cursorx, int cursory);
  void FixPosition();
  bool CheckFixPosition();
  void CancelSelection();
  void GetObjMaterial(float matcolors[13]);
  void SetObjMaterial(float *);
  void SetObjMaterialApply();
  void SetObjMaterialRevert();
  void LightUpdate(float* col,float* alt);
  void ToogleMove();
  void EditMaterial();
  void DeleteObj();
  void Scale(int s);
  void Rotate();

  void LoadScene(std::string);
  void SaveScene(std::string);
  void DisableObj();
  void EnableObj();

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
  void ToogleCulling(bool);
  void ToogleZtest(bool);

};

#endif

