#include "point1d.h"
#include "point2d.h"
#include "point3d.h"

void read(Point* points[], int n) 
{
   string line;
   int i = 0;
   while (getline(cin, line)) 
   {
      bool findX = line.find('x') != string::npos;
      bool findY = line.find('y') != string::npos;
      bool findZ = line.find('z') != string::npos;
      
      if (findX && findY && findZ) 
         points[i] = new Point3D;
      else if (findX && findY) 
         points[i] = new Point2D;
      else if (findX) 
         points[i] = new Point1D;
      i++;
   }
}

void print(Point* points[], int n)
{
   int count[3] = {0};
   for (int i = 0; i < n; ++i)
      ++count[points[i]->getDimension() - 1];
   cout << "#1D = " << count[0] << ", #2D = " << count[1] << ", #3D = " << count[2];
}

// Do not modify the main function

int main(int argc, char **argv)
{
    switch (argv[1][0])
    {
        case '1':   
        {
               Point* points[7];
               read(points,7);
               print(points,7);
	            for(int i =0; i < 7 ;i++)
               {
                  if(points[i]!=nullptr)
                     delete points[i];
               }  
               break;
        }
        case '2':
        {
            Point* points[4];
            read(points,4);
            print(points,4);
            for(int i =0; i < 4 ;i++)
            {
               if(points[i]!=nullptr)
                  delete points[i];
            }
            break;
        }
    }
    return 0;
}

