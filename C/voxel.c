#ifndef __HEADER__
#define __HEADER__
#include "marchingCubes.h"
#endif

double*** voxel(
    double (*f)(double, double, double),
    double xmin,
    double xmax,
    double ymin,
    double ymax,
    double zmin,
    double zmax,
    unsigned n
)
{
    double*** out = malloc(n * sizeof(double**));
    for(unsigned i=0; i<n; i++){
        out[i] = malloc(n * sizeof(double*));
        for(unsigned j=0; j<n ; j++){
            out[i][j] = malloc(n * sizeof(double));
            for(unsigned k=0; k<n; k++){
                out[i][j][k] = 
                  (*f)(xmin + (xmax-xmin)*i/(n-1), ymin + (ymax-ymin)*j/(n-1), zmin + (zmax-zmin)*k/(n-1)); 
            }
        }
    }
    return out;
}
