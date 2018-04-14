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
    unsigned nx,
    unsigned ny,
    unsigned nz
)
{
    printf("VOXEL\n");
    double*** out = malloc(nx * sizeof(double**));
    for(unsigned i=0; i<nx; i++){
        out[i] = malloc(ny * sizeof(double*));
        for(unsigned j=0; j<ny ; j++){
            out[i][j] = malloc(nz * sizeof(double));
            for(unsigned k=0; k<nz; k++){
                out[i][j][k] = 
                  (*f)(xmin + (xmax-xmin)*i/(nx-1), 
                       ymin + (ymax-ymin)*j/(ny-1), 
                       zmin + (zmax-zmin)*k/(nz-1)); 
            }
        }
    }
    return out;
}
