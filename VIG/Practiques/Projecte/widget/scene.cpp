#include "scene.h"
#include "matrix.h"
#include "float.h"
#include "glwidget.h"
#include <math.h>
#include <GL/glu.h>
#include <fstream>
#include <sstream>

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
  moving_obj = false;
  material_obj = false;
  scale_obj = false;
  rotate_obj = false;
  l0_alcada = 10;
  colors_llums[0][0]=colors_llums[0][1]=colors_llums[0][2]=colors_llums[0][3]=0.3f;
  colors_llums[1][0]=colors_llums[1][1]=colors_llums[1][2]=colors_llums[1][3]=0.3f;
  culling = ztest = true;
  glwidget = NULL;

}

bool Scene::CheckFixPosition() {
  // Comprovar que no estigui solapant-se amb altres objectes
  for (unsigned int j = 0; j < selection_vector.size(); j++) {
    int selected_obj = selection_vector[j];
    for (unsigned int i = 1; i < lobjectes.size(); i++) {
      if (i == (unsigned int)selected_obj) continue;
      bool c1 = lobjectes[selected_obj].collideBox(lmodels,lobjectes[i].getTransformedBBPoints(lmodels));
      bool c2 = lobjectes[i].collideBox(lmodels,lobjectes[selected_obj].getTransformedBBPoints(lmodels));
      if (c1 and c2) return false; // Estan col·lisionant!
    }
  }
  return true;
}

void Scene::FixPosition() {
  moving_obj = false;
  scale_obj = false;
  rotate_obj = false;
  last_positions.clear();
  for (unsigned int i = 0; i < selection_vector.size(); i++) {
    last_positions.push_back(lobjectes[selection_vector[i]].getPosition());
    float sx,sy,sz;
    sx = lobjectes[selection_vector[i]].getScale(0);
    sy = lobjectes[selection_vector[i]].getScale(1);
    sz = lobjectes[selection_vector[i]].getScale(2);
    lobjectes[selection_vector[i]].setScale(0,sx,true);
    lobjectes[selection_vector[i]].setScale(1,sy,true);
    lobjectes[selection_vector[i]].setScale(2,sz,true);
    float o = lobjectes[selection_vector[i]].getOrientation();
    lobjectes[selection_vector[i]].setOrientation(o,true);
  }
}

void Scene::CancelSelection() {
  // Cancela la operació actual o bé la selecció!
  if (moving_obj) {
    for (unsigned int i = 0; i < selection_vector.size(); i++) {
      lobjectes[selection_vector[i]].setPosition(last_positions[i]);
    }
    moving_obj = false;
  }else if (material_obj) {
    if (glwidget!=NULL)
      glwidget->MaterialRevert();
    material_obj = false;
  }else if (scale_obj) {
    for (unsigned int i = 0; i < selection_vector.size(); i++) {
      lobjectes[selection_vector[i]].revertScale();
    }
    scale_obj = false;
  }else if (rotate_obj) {
    for (unsigned int i = 0; i < selection_vector.size(); i++) {
      lobjectes[selection_vector[i]].setPosition(last_positions[i]);
      lobjectes[selection_vector[i]].RevertOrientation();
    }
    rotate_obj = false;
  }else{
    last_positions.clear();
    selection_vector.clear();
  }
}

void Scene::Init(GLWidget * w)
{
  construirBase ();
  ResetCamera();
  glwidget = w;
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

  // Preload models!
  #define MODELLOAD(file) \
    { Model mod (file); \
      mod.readObj(file,Scene::matlib); \
      lmodels.push_back(mod); }
  MODELLOAD("./../models/cub.obj")
  MODELLOAD("./../models/door.obj")
  MODELLOAD("./../models/prisma.obj")
  MODELLOAD("./../models/pyramid.obj")
  MODELLOAD("./../models/window.obj")
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

  if (wireframe and not picking) glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
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

    glGetDoublev(GL_MODELVIEW_MATRIX,mview[1]);
    glGetDoublev(GL_PROJECTION_MATRIX,mproj[1]);

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

    glGetDoublev(GL_MODELVIEW_MATRIX,mview[0]);
    glGetDoublev(GL_PROJECTION_MATRIX,mproj[0]);

    if (not picking) SetLights();
    DrawScene(picking);

  }else{
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

    glGetDoublev(GL_MODELVIEW_MATRIX,mview[0]);
    glGetDoublev(GL_PROJECTION_MATRIX,mproj[0]);

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
//  Box bb = lmodels[model_index].boundingBox();
//  float max = floatmax(bb.maxb.z - bb.minb.z,bb.maxb.x - bb.minb.x);
//  Objecte obj(file, model_index, Point(0,0,0),1.0f/max,90);

  Objecte obj(file, model_index, Point(0,0,0),1.0f,90);
  lobjectes.push_back(obj);
  GoodPosition(lobjectes.size()-1);

  selection_vector.push_back(lobjectes.size()-1);
  last_positions.push_back(lobjectes.back().getPosition());
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
  vangle = 25;
  zoom = 10;

  cam_pos = Vector(zoom*cos(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f),
        	    zoom*sin(vangle*M_PI/180.0f),
	            zoom*sin(hangle*M_PI/180.0f)*cos(vangle*M_PI/180.0f));

  center = Vector(0,0,0);
  for (unsigned int i = 0; i < lobjectes.size(); i++) {
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

void Scene::GoodPosition(int obj) {
  bool goodpos = false;
  while (not goodpos) {
    goodpos = true;
    for (unsigned int i = 1; i < lobjectes.size(); i++) {
      if (i == (unsigned int)obj) continue;
      bool c1 = lobjectes[obj].collideBox(lmodels,lobjectes[i].getTransformedBBPoints(lmodels));
      bool c2 = lobjectes[i].collideBox(lmodels,lobjectes[obj].getTransformedBBPoints(lmodels));
      if (c1 and c2) {
        float h = 0.001f+lobjectes[i].getTransformedBBPoints(lmodels)[2].y;
        Point pos = lobjectes[obj].getPosition();
        lobjectes[obj].setPosition(Point(pos.x,h,pos.z));
        goodpos = false;
        break; // Estan col·lisionant!
      }
    }
  }
}

Vector Scene::UnprojectPoint(int x, int y, int vp_w, int vp_h) {
  bool verticalproj = false;
  if (not vista3d) {
    x = 2*x;
  }
  y = vp_h - y;  // Conversió a coordenades de OGL

  GLdouble pos1[3],pos2[3];
  GLdouble * mmodel, * mproj;
  if (vista3d or x < vp_w) {
    mmodel = this->mview[0];
    mproj = this->mproj[0];
  }else{
    verticalproj = true;
    x = x-vp_w;
    mmodel = this->mview[1];
    mproj = this->mproj[1];
  }
  GLint viewp[4];
  viewp[0] = 0; viewp[1] = 0; viewp[2] = vp_w; viewp[3] = vp_h;
  gluUnProject(x,y,-1,mmodel,mproj,viewp,&pos1[0],&pos1[1],&pos1[2]);
  gluUnProject(x,y, 1,mmodel,mproj,viewp,&pos2[0],&pos2[1],&pos2[2]);

  Vector p1(pos1[0],pos1[1],pos1[2]);
  Vector p2(pos2[0],pos2[1],pos2[2]);
  Vector dir = p2-p1;

  float k;
  if (verticalproj) {
    // Projectem sobre el pla XY (Z=0)
    // Tenim p1 + dir*k = (x,y,0), d'on treballant sobre Y tenim
    k = -p1.z/dir.z;
  }else{
    // Projectem sobre el pla XZ
    // Tenim p1 + dir*k = (x,0,z), d'on treballant sobre Y tenim
    // p1.y + dir.y*k = 0 --> k = -p1.y/dir.y
    // Coneguda k trobem x i z
    k = -p1.y/dir.y;
  }
  Vector punt = p1 + dir*k;
  return punt;

}

// Posiciona l'objecte a la posició esmentada.
// Cal calcular l'offset, ja que hem de situar el centre
// de la base de la bounding box
bool Scene::MovingMouse(int x, int y, int vpw, int vph) {
  Vector pos = UnprojectPoint(x,y,vpw,vph);
  Point c;
  if (last_positions.size() > 0) {
    c = last_positions[0];
    for (unsigned int i = 1; i < last_positions.size(); i++) {
      //c+= last_positions[i];
      c.x += last_positions[i].x;
      c.z += last_positions[i].z;
      c.y = fmin(c.y,last_positions[i].y);
    }
    c.x = (1.0f/last_positions.size())*c.x;
    c.z = (1.0f/last_positions.size())*c.z;
  }

  if (moving_obj) {
    // Calculem el centroide
    for (unsigned int i = 0; i < selection_vector.size(); i++) {
      lobjectes[selection_vector[i]].setPosition(last_positions[i]-c+pos);
      GoodPosition(selection_vector[i]);
    }
    return selection_vector.size()!=0;
  }
  else if (scale_obj) {
    for (unsigned int i = 0; i < selection_vector.size(); i++) {
      lobjectes[selection_vector[i]].setScale(scale_axis,(y+0.5f)*7.0f,false);
    }
    return true;
  }
  else if (rotate_obj) {
    c.y = 0;
    float angle = x*360.0f*2.0f/180.0f*M_PI;
    for (unsigned int i = 0; i < selection_vector.size(); i++) {
      Point rvec = last_positions[i]-c;
      Point rvec2;
      rvec2.x = rvec.x*cos(angle) + rvec.z*sin(angle);
      rvec2.z = -rvec.x*sin(angle) + rvec.z*cos(angle);
      rvec2.y = 0;
      lobjectes[selection_vector[i]].setOrientation(angle*180.0f/M_PI,false);
      lobjectes[selection_vector[i]].setPosition(rvec2+c);
    }
    return true;
  }

  return false;
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

bool vector_contains (vector <int> & vec, int val) {
  for (unsigned int i = 0; i < vec.size(); i++)
    if (vec[i] == val) return true;
  return false;
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
      lobjectes[i].Render(lmodels,false,i);
    }
  }else{
    for (unsigned int i = 0; i < lobjectes.size(); i++) {
      lobjectes[i].Render(lmodels,vector_contains(selection_vector,i),-1);
    }
  }
  
}

bool Scene::DoPicking(int cursorx, int cursory) {
  if (moving_obj or material_obj or scale_obj) return false;

  int selected_obj = -1;
  this->cursorx = cursorx;
  this->cursory = cursory;

  Render(true);
  unsigned char pixelval[3];
  glReadPixels(cursorx,cursory,1,1,GL_RGB,GL_UNSIGNED_BYTE,pixelval);

  selected_obj = (pixelval[0]<<16) | (pixelval[1]<<8) | pixelval[2];
  if (selected_obj < 0 or selected_obj >= (int)lobjectes.size()) {
    selected_obj = -1;
    cout << "Selected an object out of range!!!" << endl;
  }
  if (selected_obj == 0) selected_obj = -1; // Ignorar el pla
  if (selected_obj != -1) {
    // Afegim l'objecte a la selecció SI NO HO ESTÀ!
    if (vector_contains(selection_vector,selected_obj)) {
      unsigned int pos;
      for (pos = 0; pos < selection_vector.size(); pos++) 
        if (selection_vector[pos] == selected_obj) break;

      selection_vector.erase(selection_vector.begin()+pos);
      last_positions.erase(last_positions.begin()+pos);
    }else{
      selection_vector.push_back(selected_obj);
      last_positions.push_back(lobjectes[selected_obj].getPosition());
    }
  }

  return (selected_obj != -1);
}

// Retorna el material del primer objecte
void Scene::GetObjMaterial(float matcolors[13]) {
  if (selection_vector.size() != 0) {
    lobjectes[selection_vector[0]].GetMaterial(matcolors);
  }
}

void Scene::SetObjMaterial(float * m) {
  for (unsigned int i = 0; i < selection_vector.size(); i++)
    lobjectes[selection_vector[i]].SetMaterial(m,false);
}

void Scene::SetObjMaterialApply() {
  for (unsigned int i = 0; i < selection_vector.size(); i++) {
    float m[13];
    lobjectes[selection_vector[i]].GetMaterial(m);
    lobjectes[selection_vector[i]].SetMaterial(m,true);
  }
  material_obj = false;
}

void Scene::SetObjMaterialRevert() {
  for (unsigned int i = 0; i < selection_vector.size(); i++)
    lobjectes[selection_vector[i]].RevertMaterial();
  material_obj = false;
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

#define CHECK_TOOL \
  if (rotate_obj or scale_obj or material_obj or moving_obj or selection_vector.size() == 0) return;

void Scene::ToogleMove() {
  CHECK_TOOL
  moving_obj = true;
}

void Scene::EditMaterial() {
  CHECK_TOOL
  material_obj = true;
}

void Scene::DeleteObj() {
  CHECK_TOOL

  std::vector<Objecte> newvector;
  
  for (unsigned int i = 0; i < lobjectes.size(); i++) {
    if (not vector_contains(selection_vector,i)) {
      newvector.push_back(lobjectes[i]);
    }
  }
  lobjectes = newvector;

  selection_vector.clear();
  last_positions.clear();
}

void Scene::Scale(int s) {
  CHECK_TOOL
  scale_obj = true;
  scale_axis = s;
}

void Scene::Rotate() {
  CHECK_TOOL
  rotate_obj = true;
}

void Scene::DisableObj() {
  CHECK_TOOL
  for (unsigned int i = 0; i < selection_vector.size(); i++)
    lobjectes[selection_vector[i]].setEnable(false);

  selection_vector.clear();
  last_positions.clear();
}

void Scene::EnableObj() {
  CHECK_TOOL
  for (unsigned int i = 0; i < lobjectes.size(); i++)
    lobjectes[i].setEnable(true);
}

void Scene::LoadScene(std::string file) {
  if (rotate_obj or scale_obj or material_obj or moving_obj) return;
  std::ifstream fd(file.c_str(),std::ios::in);
  while (not fd.eof()) {
    char buffer[2048];
    fd.getline(buffer,sizeof(buffer));
    std::string file(buffer);

    std::istringstream line;
    line.clear(); line.str(file);
    std::string obj; line >> obj;
    if (obj == "OBJECT") {
      Objecte ob(file);
      lobjectes.push_back(ob);
      GoodPosition(lobjectes.size()-1);
    }
  }
}

void Scene::SaveScene(std::string file) {
  CHECK_TOOL
  std::ofstream fd(file.c_str(),std::ios::out);
  for (unsigned int i = 1; i < lobjectes.size(); i++) {
    std::string data = lobjectes[i].Serialize();
    fd << data << std::endl;
  }
  fd.close();
}



