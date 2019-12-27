#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include "point.h"
using namespace std;

// Matrix: representa una matriu de 4x4
class Matrix
{
 public:
  Matrix(); // Crea la matriu identitat
  Matrix(const float * ptr); // Crea d'un array

  // atributs
  union {
    float mat[4][4];
    float mat2[16];
  } m;
};


// Operacions bàsiques entre matrius i vectors
Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator* (float f, const Matrix&);
Vector operator* (const Matrix&,const Vector&);


Matrix TranslateMatrix(Vector t);
Matrix MatrixRotationY(const float angle);
Matrix LookAtMatrix(Vector eye, Vector center, Vector upv);

#endif

