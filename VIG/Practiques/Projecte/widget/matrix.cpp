
#include <iostream>
#include <math.h>
#include "point.h"
#include "matrix.h"

using namespace std;

Matrix::Matrix() {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      m.mat[i][j] = (i==j);
}

Matrix::Matrix(const float * ptr) {
  for (int i = 0; i < 16; i++)
    m.mat2[i] = ptr[i];
}

Matrix   operator+(const Matrix& a, const Matrix& b) {
  Matrix ret;
  for (int i = 0; i < 16; i++)
    ret.m.mat2[i] = a.m.mat2[i] + b.m.mat2[i];
  return ret;
}

Matrix   operator-(const Matrix& a, const Matrix& b) {
  Matrix ret;
  for (int i = 0; i < 16; i++)
    ret.m.mat2[i] = a.m.mat2[i] - b.m.mat2[i];
  return ret;
}

Matrix operator* (float f, const Matrix& m) {
  Matrix ret;
  for (int i = 0; i < 16; i++)
    ret.m.mat2[i] =f*m.m.mat2[i];
  return ret;
}

Matrix   operator*(const Matrix& a, const Matrix& b) {
  Matrix ret;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      ret.m.mat[i][j] = a.m.mat[i][0]*b.m.mat[0][j]+
                        a.m.mat[i][1]*b.m.mat[1][j]+
                        a.m.mat[i][2]*b.m.mat[2][j]+
                        a.m.mat[i][3]*b.m.mat[3][j];
  return ret;
}

// Transforma un vector donada una matriu
Vector operator* (const Matrix& m,const Vector& v) {
  Vector ret;
  ret.x = m.m.mat[0][0]*v.x + m.m.mat[1][0]*v.y + m.m.mat[2][0]*v.z + m.m.mat[3][0];
  ret.y = m.m.mat[0][1]*v.x + m.m.mat[1][1]*v.y + m.m.mat[2][1]*v.z + m.m.mat[3][1];
  ret.z = m.m.mat[0][2]*v.x + m.m.mat[1][2]*v.y + m.m.mat[2][2]*v.z + m.m.mat[3][2];
  return ret;
}

// Crea una matriu de rotació al voltant de l'eix Y
Matrix MatrixRotationY(const float angle) {
  Matrix ret;
  ret.m.mat[0][0] = cos(angle);
  ret.m.mat[2][2] = cos(angle);

  ret.m.mat[2][0] = sin(angle);
  ret.m.mat[0][2] =-sin(angle);
  return ret;
}

Matrix TranslateMatrix(Vector t) {
  Matrix ret;
  ret.m.mat[3][0] = t.x;
  ret.m.mat[3][1] = t.y;
  ret.m.mat[3][2] = t.z;
  return ret;
}

static void _normalize(float v[3]) {
  float r;
  r=sqrtf(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
  if (r==0.0f) return;

  v[0]/=r; v[1]/=r; v[2]/=r;
}

static void _cross(float v1[3], float v2[3], float result[3]) {
  result[0] = v1[1]*v2[2] - v1[2]*v2[1];
  result[1] = v1[2]*v2[0] - v1[0]*v2[2];
  result[2] = v1[0]*v2[1] - v1[1]*v2[0];
}


Matrix LookAtMatrix(Vector eye, Vector center, Vector upv) {
  float forward[3], side[3], up[3];
  float m[4][4];

  forward[0] = center.x - eye.x;
  forward[1] = center.y - eye.y;
  forward[2] = center.z - eye.z;
  up[0] = upv.x; up[1] = upv.y; up[2] = upv.z;

  _normalize(forward);
  _cross(forward, up, side);
  _normalize(side);
  _cross(side, forward, up);

  m[0][3] = 0; m[1][3] = 0; m[2][3] = 0;
  m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
  m[0][0] = side[0]; m[1][0] = side[1]; m[2][0] = side[2];
  m[0][1] = up[0]; m[1][1] = up[1]; m[2][1] = up[2];
  m[0][2] = -forward[0]; m[1][2] = -forward[1]; m[2][2] = -forward[2];

  Matrix res = TranslateMatrix(Vector(-eye.x, -eye.y, -eye.z))*Matrix(&m[0][0]);

  return res;
}

