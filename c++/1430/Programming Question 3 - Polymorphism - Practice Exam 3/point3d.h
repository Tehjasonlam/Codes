#ifndef POINT3D_H
#define POINT3D_H

#include "point2d.h"

class Point3D : public Point2D // use the virtual qualifier when needed 
{
   public:
      virtual int getDimension() const {return 3;};
      double getZ() const {return z;}
      void setZ(double z) {this->z = z;}
   private:
      double z = 0;
};

#endif