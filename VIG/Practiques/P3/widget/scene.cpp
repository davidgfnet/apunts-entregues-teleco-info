#include "scene.h"
#include "matrix.h"
#include "float.h"
#include <math.h>
#include <GL/glu.h>

MaterialLib Scene::matlib;
bool  Scene::bbrender;

const float AuxVPSize = 10.0f;

Scene::Scene()
{
  zoom = 10;
  hangle = vangle = 0;
  wireframe = false;
  ratio = 1;
  fovy = 45;
  Scene::bbrender = false;
  orthoview = false;
  center = Vector(0,0,0);
  cam_pos = Vector(0,0,0);
  vista3d = true;
  selected_obj = ~0;
  l0_alcada = 10;
  colors_llums = {{1,1,1,1},{1,1,1,1}};
  culling = ztest = true;
}

void Scene::NoSelection() {
  // Comprovar que no estigui solapant-se amb altres objectes
  if (selected_obj < 0) return;
  for (unsigned int i = 1; i < lobjectes.size(); i++) {
    if (i == selected_obj) continue;
    bool c1 = lobjectes[selected_obj].collideBox(lmodels,lobjectes[i].getTransformedBBPoints(lmodels));
    bool c2 = lobjectes[i].collideBox(lmodels,lobjectes[selected_obj].getTransformedBBPoints(lmodels));
    if (c1 and c2) return; // Estan col·lisionant!
  }
  selected_obj = ~0;
}

void Scene::CancelSelection() {
  if (selected_obj == ~0) return;
  lobjectes[selected_obj].setPosition(last_pos);
  selected_obj = ~0;
}

void Scene::Init()
{
  construirBase ();
  ResetCamera();
}

void Scene::Toogle3D(bool a) {
  vista3d = not a;
}

void Scene::construirBase ()
{
  Model b("Base");

  // Construim el poligon base
  Vertex v1(Point(-5,0,-5));
  Vertex v2(Point(-5,0,5));
  Vertex v3(Point(5,0,5));
  Vertex v4(Point(5,0,-5));
  b.vertices.push_back(v1);
  b.vertices.push_back(v2);
  b.vertices.push_back(v3);
  b.vertices.push_back(v4);

  Face face(0,1,2,3);
  face.normal = Vector(0,1,0);
  face.material = 0;
  b.faces.push_back(face);
  b.updateBoundingBox();

  lmodels.push_back(b);
  Objecte oref("Base", 0, Point(0,0,0), 1, 0);
  lobjectes.push_back(oref);
}

void Scene::SetLights(Vector cam) {
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_NORMALIZE);

  // Light 0
  {
    float pos[4] = {0,l0_alcada,0,1};
    float ambient[4] = {colors_llums[0][0]*0.05f,
                        colors_llums[0][1]*0.05f,
                        colors_llums[0][2]*0.05f,
                        colors_llums[0][3]*0.05f };
    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    glLightfv(GL_LIGHT0,GL_DIFFUSE, colors_llums[0]);
    glLightfv(GL_LIGHT0,GL_SPECULAR,colors_llums[0]);
    glLightfv(GL_LIGHT0,GL_AMBIENT, ambient);
  }


  // Light 1
  {
    float pos[4] = {cam.x,cam.y,cam.z,1};
    float ambient[4] = {colors_llums[1][0]*0.05f,
                        colors_llums[1][1]*0.05f,
                        colors_llums[1][2]*0.05f,
                        colors_llums[1][3]*0.05f };
    glLightfv(GL_LIGHT1,GL_POSITION,pos);
    glLightfv(GL_LIGHT1,GL_DIFFUSE, colors_llums[1]);
    glLightfv(GL_LIGHT1,GL_SPECULAR,colors_llums[1]);
    glLightfv(GL_LIGHT1,GL_AMBIENT, ambient);
  }
}

void Scene::Render(bool picking) {
  if (culling) glEnable(GL_CULL_FACE);
  else glDisable(GL_CULL_FACE);

  if (ztest) glEnable(GL_DEPTH_TEST);
  else glDisable(GL_DEPTH_TEST);

  if (wireframe) glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  else glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

  glDisable(GL_LIGHTING);

  if (not vista3d) {
    float ratio = 0.5f*vw/vh;
    glEnable(GL_SCISSOR_TEST);
    glViewport(vw/2,0,vw/2,vh);
    glScissor(vw/2,0,vw/2,vh);
    if (picking) glClearColor(0,0,0,0);
    else glClearColor(0.4f,0.4f,0.1f,0);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-AuxVPSize*ratio,AuxVPSize*ratio,AuxVPSize,-AuxVPSize,-50,50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(180, 0,0,1);

    if (not picking) SetLights();
    DrawScene(picking);    

    glViewport(0,0,vw/2,vh);
    glScissor(0,0,vw/2,vh);
    if (picking) glClearColor(0,0,0,0);
    else glClearColor(0.4f,0.1f,0.4f,0);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-AuxVPSize*ratio,AuxVPSize*ratio,AuxVPSize,-AuxVPSize,-50,50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(90, 1,0,0);

    if (not picking) SetLights();
    DrawScene(picking);

  }else{
    int viewport[4] = {0,0,vw,vh};
    glViewport(0,0,vw,vh);
    glDisable(GL_SCISSOR_TEST);
    if (picking) glClearColor(0,0,0,0);
    else glClearColor(0.4f,0.4f,0.4f,0);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    // Cal pintar tots els objectes de l'escena que es troben al vector
    cam_pos = Vector(zoom*cos(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f),
          	    zoom*sin(vangle*M_PI/180.0f),
	              zoom*sin(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f));

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if (orthoview) {
      float wid = zoom*tan((fovy/2)*M_PI/180.0f);
      float r = vh/vw;
      glOrtho(-wid,wid,-wid*r,wid*r,0,100);
    }else{
      gluPerspective(fovy, vw/vh, 0.2f, 100.0f);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    viewm = LookAtMatrix(cam_pos+center,center,Vector(0,1,0));
    glLoadMatrixf(&viewm.m.mat[0][0]);

    if (not picking) SetLights(cam_pos+center);
    DrawScene(picking);
  }
}

void Scene::LoadObject(std::string file)
{
  // Search if the model is already in use by (maybe) another object
  int model_index = -1;
  for (unsigned int i = 0; i < lmodels.size(); i++) {
    if (lmodels[i].getName() == file) {
      model_index = i;
      break;
    }
  }

  if (model_index == -1) {
    Model mod (file);
    mod.readObj(file.c_str(),Scene::matlib);
    lmodels.push_back(mod);
    model_index = lmodels.size()-1;
  }
  Box bb = lmodels[model_index].boundingBox();
  float max = floatmax(bb.maxb.z - bb.minb.z,bb.maxb.x - bb.minb.x);
  
  Objecte obj(file, model_index, Point(0,0,0),1.0f/max,90);
  lobjectes.push_back(obj);
  selected_obj = lobjectes.size()-1;
}

void Scene::UpdateZoom(float z) {
  zoom = zoom + z;
  if (zoom < 1) zoom = 1;
  if (zoom > 500) zoom = 500;
}

void Scene::UpdateHAngle(int a) {
  hangle = (hangle+a+360)%360;
}

void Scene::UpdateVAngle(int a) {
  vangle += a;
}

void Scene::setWireframe(bool w) {
  wireframe = w;
}
void Scene::ResetCamera() {
  hangle = 30;
  vangle = 75;
  zoom = 10;

  cam_pos = Vector(zoom*cos(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f),
        	    zoom*sin(vangle*M_PI/180.0f),
	            zoom*sin(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f));

  center = Vector(0,0,0);
  for (int i = 0; i < lobjectes.size(); i++) {
    center += lobjectes[i].getPosition();
  }
  center = (1.0f/lobjectes.size())*center;

  AutoZoom();
}
void Scene::setViewport(float w,float h) {
  vw = w; vh = h;
  ratio = w/h;
}
void Scene::AutoZoom() {

if (orthoview) {
  Render(); // Actualitza escene i les matrius!
  // Versió per a càmeres ortogonals, projecció sobre near plane
  // Agafem 6 punts per cada objecte (els de la seva BB), els transformem a
  // l'espai de vista (càmera sobre 0 mirant a -Z) i els projectem
  // sobre el pla Z = 0. Trobem els màxims/mínims de X i Y.
  float minx=FLT_MAX,maxx=FLT_MIN,miny=FLT_MAX,maxy=FLT_MIN;
  for (unsigned int i = 0; i < lobjectes.size(); i++) {
    vector <Point> points = lobjectes[i].getTransformedBBPoints(lmodels);
    for (unsigned int j = 0; j < points.size(); j++) {
      points[j] = viewm*points[j];
      points[j].z = 0; // Projecció
      if (points[j].x < minx) minx = points[j].x;
      if (points[j].y < miny) miny = points[j].y;

      if (points[j].x > maxx) maxx = points[j].x;
      if (points[j].y > maxy) maxy = points[j].y;
    }
  }
  // Busquem la dimensio del rectangle
  float ry = fabs(maxy);
  if (ry < fabs(miny)) ry = fabs(miny);
  float rx = fabs(maxx);
  if (rx < fabs(minx)) rx = fabs(minx);

  float ratio = vw/vh;
  if (rx < ry*ratio) rx = ry*ratio;

  float fov = this->fovy*M_PI/180.0f;
  float d = rx/tan(fov/2);
  zoom = d;
  Render();

}else{
  // Aproximem el frustum per un con (que està a dins, pitjor cas més petit possible)
  // Calculem en quin punt de la recta sobre la que pot estar la càmera 
  // l'angle format per punt, càmera i center és igual a l'apertura del con
  // Ho fem per a tots els vèrtexs i triem el punt més llunyà
  Vector dir = cam_pos; dir.normalize();
  float k = 1;
  float fovy = this->fovy*M_PI/180.0f;
  float fovx = 2*atan(tan(fovy/2)/ratio);
  // Triem la apertura més petita!
  float apertura = fovy; if (fovy > fovx) apertura = fovx;
  apertura = apertura/2;
  // donat que aillar k no és trivial:
  // (cos^-1 aper)^2 = (punt*dir-k)^2/(punt*punt+k^2-2*k*dir)
  // El que farem serà triar zoom = 1 i anar augmentant-lo
  // calculant el que s'ha de tirar enrere tirant sempre a la baixa
  // No fem gaires iteracions. Així ho fem el màxim ajustat possible
  for (unsigned int i = 0; i < lobjectes.size(); i++) {
    vector <Point> points = lobjectes[i].getTransformedBBPoints(lmodels);
    for (unsigned int j = 0; j < points.size(); j++) {
      Vector po = points[j];
      float angle, back;
      do {
        angle = acos(-((po-k*dir)*dir)/((po-k*dir).length()));
        back = k*sin(angle-apertura); // Aproximem la distància enrere pel sinus
        if (back < 1.0f) back = 1.0f;
        if (angle > apertura) k+=back;
      } while(angle > apertura);
    }
  }

  zoom = k;
  Render();
}

}

// Posiciona l'objecte a la posició esmentada.
// Cal calcular l'offset, ja que hem de situar el centre
// de la base de la bounding box
bool Scene::SetLastObjectPosition(Vector pos) {
  if (selected_obj > 0)
    lobjectes[selected_obj].setPosition(pos);
  else return false;
  return true;
}
bool Scene::SetLastObjectRotation(int inc) {
  if (selected_obj > 0)
    lobjectes[selected_obj].setOrientation(lobjectes[selected_obj].getOrientation()+inc*10.0f);
  else return false;
  return true;
}

void Scene::OrthoView(bool a) {
  orthoview = a;
}

void Scene::DoPan(float x, float y) {

  // Fem servir el far plane com a mida,
  // en el cas de la ortho és exacte, en perspectiva depèn
  // de la distància (del pla on ens moguem per a fer el pan,
  // en aquest cas el far, que abarca més)
  float wid = zoom*tan((fovy/2)*M_PI/180.0f);
  float r = vh/vw;
  x = x*(wid*2)/vw;
  y = y*(wid*r*2)/(0.5f*vh);

  Vector dir = cam_pos;
  Vector up = Vector(0,1,0);
  Vector side = up^dir;
  up = dir^side;
  side.normalize();
  up.normalize();
  side = -x*side;
  up = y*up;
  center = center + up + side;
  cam_pos = Vector(zoom*cos(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f),
        	    zoom*sin(vangle*M_PI/180.0f),
	            zoom*sin(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f));  
}

void Scene::DrawScene(bool picking) {
  if (not picking) {
    glBegin(GL_LINES);
    glNormal3f(0,1,0);
    glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
    glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
    glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z
    glEnd();
  }
  if (picking) {
    for (unsigned int i = 0; i < lobjectes.size(); i++) {
      lobjectes[i].Render(lmodels,i == selected_obj,i);
    }
  }else{
    for (unsigned int i = 0; i < lobjectes.size(); i++) {
      lobjectes[i].Render(lmodels,i == selected_obj,-1);
    }
  }
  
}

bool Scene::DoPicking(int cursorx, int cursory) {
  if (selected_obj >= 0) return false; // Already picking
  this->cursorx = cursorx;
  this->cursory = cursory;

  Render(true);
  unsigned char pixelval[3];
  glReadPixels(cursorx,cursory,1,1,GL_RGB,GL_UNSIGNED_BYTE,pixelval);

  selected_obj = (pixelval[0]<<16) | (pixelval[1]<<8) | pixelval[2];
  if (selected_obj != ~0) last_pos = lobjectes[selected_obj].getPosition();

  if (selected_obj == 0) selected_obj = ~0; // Ignorar el pla
  if (selected_obj < 0 or selected_obj > lobjectes.size()) selected_obj = ~0;

  return (selected_obj != ~0);
}

void Scene::GetObjMaterial(float matcolors[13]) {
  if (selected_obj > 0)
    lobjectes[selected_obj].GetMaterial(matcolors);
}

void Scene::SetObjMaterial(float * m) {
  if (selected_obj > 0)
    lobjectes[selected_obj].SetMaterial(m);
}

void Scene::LightUpdate(float* col,float* alt) {
  memcpy(colors_llums,col,sizeof(float)*2*4);
  l0_alcada = *alt;
}

void Scene::ToogleCulling(bool a) {
  culling = a;
}

void Scene::ToogleZtest(bool a) {
  ztest = a;
}


