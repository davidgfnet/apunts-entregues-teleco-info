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
}

void Scene::Init()
{
  construirBase ();
  ResetCamera();
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

void Scene::Render() {
//  glEnable(GL_CULL_FACE);
  if (wireframe) glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  else glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

  float ratio = vw/vh;
  glEnable(GL_SCISSOR_TEST);
  glViewport(vw/2,vh/2,vw/2,vh/2);
  glScissor(vw/2,vh/2,vw/2,vh/2);
  glClearColor(0.4f,0.4f,0.1f,0);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-AuxVPSize*ratio,AuxVPSize*ratio,AuxVPSize,-AuxVPSize,-50,50);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef(180, 0,0,1);
  
  glBegin(GL_LINES);
  glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
  glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
  glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z
  glEnd();
  for (unsigned int i = 0; i < lobjectes.size(); i++) {
    lobjectes[i].Render(lmodels);
  }

  glViewport(0,vh/2,vw/2,vh/2);
  glScissor(0,vh/2,vw/2,vh/2);
  glClearColor(0.4f,0.1f,0.4f,0);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-AuxVPSize*ratio,AuxVPSize*ratio,AuxVPSize,-AuxVPSize,-50,50);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef(90, 1,0,0);
  glBegin(GL_LINES);
  glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
  glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
  glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z
  glEnd();
  for (unsigned int i = 0; i < lobjectes.size(); i++) {
    lobjectes[i].Render(lmodels);
  }

  glViewport(0,0,vw,vh/2);
  glScissor(0,0,vw,vh/2);
  glClearColor(0.4f,0.4f,0.4f,0);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  // Cal pintar tots els objectes de l'escena que es troben al vector
  cam_pos = Vector(zoom*cos(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f),
        	    zoom*sin(vangle*M_PI/180.0f),
	            zoom*sin(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  if (orthoview) {
    float wid = zoom*tan((fovy/2)*M_PI/180.0f);
    float r = 0.5f*vh/vw;
    glOrtho(-wid,wid,-wid*r,wid*r,0,100);
  }else{
    gluPerspective(fovy, 2*vw/vh, 0.2f, 100.0f);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  viewm = LookAtMatrix(cam_pos+center,center,Vector(0,1,0));
  glLoadMatrixf(&viewm.m.mat[0][0]);

  glBegin(GL_LINES);
  glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
  glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
  glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z
  glEnd();
  for (unsigned int i = 0; i < lobjectes.size(); i++) {
    lobjectes[i].Render(lmodels);
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
    Box bb = lobjectes[i].getTransformedBB(lmodels);
    vector <Point> points = bb.getPoints();
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

  float ratio = 2*vw/vh;
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
    Box bb = lobjectes[i].getTransformedBB(lmodels);
    vector <Point> points = bb.getPoints();
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
void Scene::SetLastObjectPosition(Vector pos) {
  if (lobjectes.size() > 0)
    lobjectes[lobjectes.size()-1].setPosition(pos);
}
void Scene::SetLastObjectRotation(int inc) {
  if (lobjectes.size() > 0)
    lobjectes[lobjectes.size()-1].setOrientation(lobjectes[lobjectes.size()-1].getOrientation()+inc*10.0f);
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
  float r = 0.5f*vh/vw;
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


