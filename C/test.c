#ifndef __HEADER__
#define __HEADER__
#include "marchingCubes.h"
#endif

double f(double x, double y, double z){
    return x*x + y*y + z*z;
}

int main(){
    double*** vxl = voxel(&f, -2, 2, -2, 2, -2, 2, 5);
    unsigned ntriangles;
    double** contour = computeContour3d(vxl, 5, 5, 5, 12, 1, &ntriangles);
    printf("nrows: %u", ntriangles);
    return 0;
}


