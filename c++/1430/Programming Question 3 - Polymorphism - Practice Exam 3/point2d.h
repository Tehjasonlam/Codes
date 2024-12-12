#ifndef POINT2D_H
#define POINT2D_H

#include "point1d.h"

class Point2D : public Point1D // use the virtual qualifier when needed
{
   public:
      virtual int getDimension() const {return 2;};
      Double getY() const {return y;}
      void setY(double y) { this->y = y;}
   private:
      double y = 0;
};

#endif