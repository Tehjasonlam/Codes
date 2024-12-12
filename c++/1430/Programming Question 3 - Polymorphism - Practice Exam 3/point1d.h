#ifndef POINT1D_H
#define POINT1D_H

#include "point.h"

class Point1D : public Point // use the virtual qualifier when needed
{
   public:
      virtual int getDimension() const {return 1;};
      double getX() const {return x;}
      void setX(double x) {this->x = x;}
   private:
      double x = 0;
};

#endif