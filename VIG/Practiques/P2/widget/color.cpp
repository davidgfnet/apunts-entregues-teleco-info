#include "color.h"

Color::Color(float red, float green, float blue, float alfa) 
: r(red), g(green), b(blue), a(alfa) 
{}

ColorI::ColorI(unsigned char red, unsigned char green, unsigned char blue, unsigned char alfa) 
: r(red), g(green), b(blue), a(alfa) 
{}


ostream& operator<< (ostream &os, const Color &c) 
{
  os << c.r << ", " << c.g << ", " << c.b << ", " << c.a << endl;
  return os;
}

