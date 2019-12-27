#ifndef _COLOR_H_
#define _COLOR_H_

#include <iostream>
using namespace std;

class Color
{
 public:
  Color(float red=0., float green=0., float blue=0., float alfa=1.);

  // atributs
  float r,g,b,a ;	// components RGB del color
};

class ColorI
{
 public:
  ColorI(unsigned char red=0, unsigned char green=0, unsigned char blue=0, unsigned char alfa=1);

  // atributs
  unsigned char r,g,b,a ;	// components RGB del color
};

ostream& operator<< (ostream &os, const Color &c);

#endif
