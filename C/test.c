#ifndef __HEADER__
#define __HEADER__
#include "marchingCubes.h"
#endif

double f(double x, double y, double z){
    return x*x + y*y + z*z;
}


int main(){
    unsigned n = 150;
    double*** vxl = voxel(&f, -2, 2, -2, 2, -2, 2, n, n, n);
    printf("vxl done\n");
    size_t ntriangles;
    double** contour = computeContour3d(vxl, n, n, n, 12, 1, &ntriangles);
    freeArray(vxl, n, n);
    printf("nrows: %u\n", ntriangles);
    return 0;
}


