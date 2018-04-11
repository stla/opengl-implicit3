#ifndef __HEADER__
#define __HEADER__
#include "marchingCubes.h"
#endif

void freeMatrix_u(unsigned** M, unsigned nx){
    for(unsigned i=0; i<nx; i++){
        free(M[i]);
    }
    free(M);
}

void freeMatrix_d(double** M, unsigned nx){
    for(unsigned i=0; i<nx; i++){
        free(M[i]);
    }
    free(M);
}

unsigned** copyMatrix(unsigned** M, unsigned nx, unsigned ny){
    unsigned** MM = malloc(nx * sizeof(unsigned*));
    for(unsigned i=0; i<nx; i++){
        MM[i] = malloc(ny * sizeof(unsigned));
        for(unsigned j=0; j<ny; j++){
            MM[i][j] = M[i][j];
        }
    }
    return MM;
}

unsigned** minorMatrix(unsigned** M, unsigned m, unsigned n, unsigned row, unsigned col){
    unsigned** out = malloc((m-1) * sizeof(unsigned*));
    for(unsigned i=0; i<(m-1); i++){
        out[i] = malloc((n-1) * sizeof(unsigned));
        unsigned ii = i<row ? i : i+1;
        for(unsigned j=0; j<(n-1); j++){
            unsigned jj = j<col ? j : j+1;
            out[i][j] = M[ii][jj];
        }
    }
    return out;
}

unsigned** scaleMatrix(unsigned k, unsigned** M, unsigned m, unsigned n){
    unsigned** out = malloc(m * sizeof(unsigned*));
    for(unsigned i=0; i<m; i++){
        out[i] = malloc(n * sizeof(unsigned));
        for(unsigned j=0; j<n; j++){
            out[i][j] = k * M[i][j];
        }
    }
    return out;
}

unsigned** scaleMinorMatrix(unsigned k, unsigned** M, unsigned m, unsigned n, unsigned row, unsigned col){
    unsigned** minorMat = minorMatrix(M,m,n,row,col);
    unsigned** out = scaleMatrix(k, minorMat, m-1, n-1);
    freeMatrix_u(minorMat, m-1);
    return out;
}

unsigned** matricialSum(unsigned** M1, unsigned** M2, unsigned m, unsigned n){
    unsigned** out = malloc(m * sizeof(unsigned*));
    for(unsigned i=0; i<m; i++){
        out[i] = malloc(n * sizeof(unsigned));
        for(unsigned j=0; j<n; j++){
            out[i][j] = M1[i][j] + M2[i][j];
        }
    }
    return out;
}

unsigned** levelMatrix(double** M, unsigned m, unsigned n, double level, unsigned strict){
    unsigned** out = malloc(m * sizeof(unsigned*));
    for(unsigned i=0; i<m; i++){
        out[i] = malloc(n * sizeof(unsigned));
        for(unsigned j=0; j<n; j++){
            out[i][j] = (strict ? (M[i][j] > level) : (M[i][j] >= level)) ? 1 : 0;
        }
    }
    return out;    
}

double** toMatrix(double*** A, unsigned m, unsigned n, unsigned k){
    double** out = malloc(m * sizeof(double*));
    for(unsigned i=0; i<m; i++){
        out[i] = malloc(n * sizeof(double));
        for(unsigned j=0; j<n; j++){
            out[i][j] = A[i][j][k];
        }
    }
    return out;    
}

unsigned** whichIndicesAndItems(unsigned** M, unsigned m, unsigned n, unsigned* outlength){
    unsigned** out = malloc(2 * sizeof(unsigned*));
    out[0] = malloc(m*n * sizeof(unsigned));
    out[1] = malloc(m*n * sizeof(unsigned));
    unsigned k=0;
    unsigned ij=0;
    for(unsigned j=0; j<n; j++){
        for(unsigned i=0; i<m; i++){
            if(M[i][j]>0 && M[i][j]<255){
                out[0][k] = ij;
                out[1][k] = M[i][j];
                k++;
            }
            ij++;
        }
    }
    *outlength = k;
    return out;
}

double*** fun2array(double f(unsigned,unsigned,unsigned), unsigned nx, unsigned ny, unsigned nz){
    double*** out = malloc(nx * sizeof(double**));
    for(unsigned i=0; i<nx; i++){
        out[i] = malloc(ny * sizeof(double*));
        for(unsigned j=0; j<ny; j++){
            out[i][j] = malloc(nz * sizeof(double));
            for(unsigned k=0; k<nz; k++){
                out[i][j][k] = f(i,j,k);
            }
        }
    }
    return out;
}

void freeArray(double*** A, unsigned nx, unsigned ny){
    for(unsigned i=0; i<nx; i++){
        for(unsigned j=0; j<ny; j++){
            free(A[i][j]);
        }
        free(A[i]);
    }
    free(A);
}

unsigned** kro1(unsigned** M, unsigned nx, unsigned ny, unsigned n){
    unsigned** out = malloc((nx*n+1) * sizeof(unsigned*));
    for(unsigned i=0; i<nx*n; i++){
        out[i] = malloc(ny * sizeof(unsigned));
        for(unsigned j=0; j<ny; j++){
            out[i][j] = M[i%nx][j];
        }
    }
    out[nx*n] = malloc(ny * sizeof(unsigned));
    for(unsigned j=0; j<ny; j++){
        out[nx*n][j] = 0;
    }
    return out;
}

unsigned** kro2(unsigned** M, unsigned nx, unsigned ny, unsigned n){
    unsigned** out = malloc((nx*n+1) * sizeof(unsigned*));
    unsigned replicates[nx*n+1];
    unsigned count = 0;
    for(unsigned i=0; i<nx; i++){
        for(unsigned m=0; m<n; m++){
            replicates[count] = i;
            count++;
        }
    }
    for(unsigned i=0; i<nx*n; i++){
        out[i] = malloc(ny * sizeof(unsigned));
        for(unsigned j=0; j<ny; j++){
            out[i][j] = M[replicates[i]][j];
        }
    }
    out[nx*n] = malloc(ny * sizeof(unsigned));
    for(unsigned j=0; j<ny; j++){
        out[nx*n][j] = 0;
    }
    return out;
}

unsigned* replicate(unsigned* x, unsigned* counts, unsigned n){
    unsigned total = 0;
    for(unsigned i=0; i<n; i++){
        total += counts[i];
    }
    unsigned* out = malloc(total * sizeof(unsigned));
    unsigned count = 0;
    for(unsigned i=0; i<n; i++){
        for(unsigned j=0; j<counts[i]; j++){
            out[count] = x[i];
            count++;
        }
    }
    return out;
}
