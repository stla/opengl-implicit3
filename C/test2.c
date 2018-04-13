#ifndef __HEADER__
#define __HEADER__
#include "marchingCubes.h"
#endif

// Goursat
double f(double x, double y, double z){
  double x2=x*x; double y2=y*y; double z2=z*z;
  double x4=x2*x2; double y4=y2*y2; double z4=z2*z2;
  double x2y2z2 = x2+y2+z2;

  return x4 + y4 + z4 - 0.27*x2y2z2*x2y2z2 - 0.5*x2y2z2;
}


int main(){
    unsigned n = 101;
    double*** vxl = voxel(&f, -2.5, 2.5, -2.5, 2.5, -2.5, 2.5, n, n, n);
    printf("vxl done\n");
    size_t ntriangles;
    double** contour = computeContour3d(vxl, n, n, n, 10000, 2, &ntriangles);
    printf("nrows: %u\n", ntriangles);
    freeArray(vxl, n, n);
    return 0;
}


