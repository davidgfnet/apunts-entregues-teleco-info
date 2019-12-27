#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
using namespace std;

class Vector;
class Point;

static inline float floatmax(float a, float b) {
  if (a > b) return a;
  return b;
}

// Point - permet representar un punt a l'espai
class Point
{
 public:
  Point(float px=0., float py=0., float pz=0.);
  Point(const Vector &);

  // atributs
  float x, y, z;	// coordenades del punt
};

// Vector - permet representar un vector de l'espai
class Vector
{
 public:
  Vector (float vx=0., float vy=0., float vz=0.);
  Vector(const Point &p);
  
  float  operator[](int i) const;
  float& operator[](int i); 
  
  float length() const; // modul del vector
  float squaredLength() const; // modul al quadrat
  
  void normalize();
  
  // atributs
  float x, y, z;	// components del vector
};


// Operacions bàsiques entre punts i vectors

// P+Q
Point   operator+(const Point&, const Point&);
Point&  operator+=(Point&, const Point&);

// P-Q
Vector operator-(const Point&, const Point&);

// P+v
Point  operator+(const Point&, const Vector &v);
Point& operator+=(Point&, const Vector &v);

// P-v 
Point  operator-(const Point&, const Vector&);
Point& operator-=(Point&, const Vector &v);

// v+u
Vector   operator+(const Vector&, const Vector&);
Vector&  operator+=(Vector&, const Vector&);

// v-u
Vector operator-(const Vector&, const Vector&);
Vector& operator-=(Vector&, const Vector &v);

// aP
Point operator* (const Point&, float f);
Point operator* (float f, const Point&);

// P/a
Point operator/ (const Point&, float f);
Point&operator/=(Point&, float f);

// av
Vector operator* (const Vector&, float f);
Vector operator* (float f, const Vector&);

// Producte escalar!
float operator* (const Vector&, const Vector&);
Vector operator^ (const Vector&, const Vector&);

// v/a
Vector operator/ (const Vector&, float f);
Vector&operator/=(Vector&, float f);


// escriptura
ostream& operator<< (ostream &os, const Point &p);
ostream& operator<< (ostream &os, const Vector &p);

class Plane
{
 public:
  Plane (float a = 0.0f, float b = 0.0f, float c = 0.0f, float d = 0.0f);
  Plane (Point p1, Point p2, Point p3);
  //Plane (Point normal, Point planepoint);
  
  float a,b,c,d;
}; 

float PointPlaneDist(Plane p, Point po);
ostream& operator<< (ostream &os, const Plane &p);

#endif
