#ifndef __HEADER__
#define __HEADER__
#include "marchingCubes.h"
#endif

void displayMatrix_u(unsigned** M, unsigned nx, unsigned ny){
    for(unsigned i=0; i<nx; i++){
        for(unsigned j=0; j<ny; j++){
            printf("M[%u][%u]=%u ", i, j, M[i][j]);
        }
        printf("\n");
    }
}

void displayMatrix(double** M, unsigned nx, unsigned ny){
    for(unsigned i=0; i<nx; i++){
        for(unsigned j=0; j<ny; j++){
            printf("M[%u][%u]=%f ", i, j, M[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix_u(unsigned** M, unsigned nx){
    for(unsigned i=0; i<nx; i++){
        free(M[i]);
    }
    free(M);
}

void freeMatrix_s(size_t** M, size_t nx){
    for(size_t i=0; i<nx; i++){
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

size_t** minorMatrix(size_t** M, unsigned m, unsigned n, unsigned row, unsigned col){
    size_t** out = malloc((m-1) * sizeof(size_t*));
    for(unsigned i=0; i<(m-1); i++){
        out[i] = malloc((n-1) * sizeof(size_t));
        unsigned ii = i<row ? i : i+1;
        for(unsigned j=0; j<(n-1); j++){
            unsigned jj = j<col ? j : j+1;
            out[i][j] = M[ii][jj];
        }
    }
    return out;
}

size_t** scaleMatrix(size_t k, size_t** M, unsigned m, unsigned n){
    size_t** out = malloc(m * sizeof(size_t*));
    for(unsigned i=0; i<m; i++){
        out[i] = malloc(n * sizeof(size_t));
        for(unsigned j=0; j<n; j++){
            out[i][j] = k * M[i][j];
        }
    }
    return out;
}

size_t** scaleMinorMatrix(size_t k, size_t** M, unsigned m, unsigned n, unsigned row, unsigned col){
    size_t** minorMat = minorMatrix(M,m,n,row,col);
    size_t** out = scaleMatrix(k, minorMat, m-1, n-1);
    freeMatrix_s(minorMat, m-1);
    return out;
}

size_t** matricialSum(size_t** M1, size_t** M2, size_t m, unsigned n){
    size_t** out = malloc(m * sizeof(size_t*));
    for(size_t i=0; i<m; i++){
        out[i] = malloc(n * sizeof(size_t));
        for(unsigned j=0; j<n; j++){
            out[i][j] = M1[i][j] + M2[i][j];
        }
    }
    return out;
}

size_t** levelMatrix(double** M, unsigned m, unsigned n, double level, unsigned strict){
    size_t** out = malloc(m * sizeof(size_t*));
    for(unsigned i=0; i<m; i++){
        out[i] = malloc(n * sizeof(size_t));
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

unsigned** whichIndicesAndItems(size_t** M, unsigned m, unsigned n, unsigned* outlength){
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
    // printf("k: %u\n", k);
    return out;
}

// not used
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

size_t** kro1(size_t** M, unsigned nx, unsigned ny, size_t n){
    size_t** out = malloc((nx*n+1) * sizeof(size_t*));
    for(size_t i=0; i<nx*n; i++){
        out[i] = malloc(ny * sizeof(size_t));
        for(unsigned j=0; j<ny; j++){
            out[i][j] = M[i%nx][j];
        }
    }
    out[nx*n] = malloc(ny * sizeof(size_t));
    for(unsigned j=0; j<ny; j++){
        out[nx*n][j] = 0;
    }
    return out;
}

size_t** kro2(size_t** M, size_t nx, unsigned ny, unsigned n){
    size_t** out = malloc((nx*n+1) * sizeof(size_t*));
//    unsigned* replicates = malloc((nx*n+1) * sizeof(unsigned));
    unsigned* replicates = malloc((nx*n) * sizeof(unsigned));
    unsigned count = 0;
    for(size_t i=0; i<nx; i++){
        for(unsigned m=0; m<n; m++){
            replicates[count] = i;
            count++;
        }
    }
    for(size_t i=0; i<nx*n; i++){
        out[i] = malloc(ny * sizeof(size_t));
        for(unsigned j=0; j<ny; j++){
            out[i][j] = M[replicates[i]][j];
        }
    }
    free(replicates);
    out[nx*n] = malloc(ny * sizeof(size_t));
    for(unsigned j=0; j<ny; j++){
        out[nx*n][j] = 0;
    }
    return out;
}

size_t* replicate(size_t* x, unsigned* counts, size_t n){
    unsigned total = 0;
    for(size_t i=0; i<n; i++){
        total += counts[i];
    }
    size_t* out = malloc(total * sizeof(size_t));
    unsigned count = 0;
    for(size_t i=0; i<n; i++){
        for(unsigned j=0; j<counts[i]; j++){
            out[count] = x[i];
            count++;
        }
    }
    return out;
}

/* for special cases */
// concatenate rows of a jagged array
int* unlist(int (*jagged[])[], unsigned* jaggedsizes, unsigned* rows, unsigned nrows, unsigned* outlength){
  unsigned count = 0;
  for(unsigned i=0; i<nrows; i++){
    count += jaggedsizes[rows[i]];
  }
  *outlength = count;
  unsigned* out = malloc(count * sizeof(unsigned));
  count = 0;
  for(unsigned i=0; i<nrows; i++){
    for(unsigned j=0; j<jaggedsizes[rows[i]]; j++){
      out[count] = (*jagged[rows[i]])[j];
      count++;
    }
  }
  return out;
}

unsigned* unlist_u(unsigned (*jagged[])[], unsigned* jaggedsizes, unsigned* rows, unsigned nrows, unsigned* outlength){
  unsigned count = 0;
  for(unsigned i=0; i<nrows; i++){
    count += jaggedsizes[rows[i]];
  }
  *outlength = count;
  unsigned* out = malloc(count * sizeof(unsigned));
  count = 0;
  for(unsigned i=0; i<nrows; i++){
    for(unsigned j=0; j<jaggedsizes[rows[i]]; j++){
      out[count] = (*jagged[rows[i]])[j];
      count++;
    }
  }
  return out;
}

unsigned upow(unsigned base, unsigned exp){
    unsigned result = 1;
    while(exp){
        if(exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

unsigned* FacesNo7(int* faces, size_t* p1, double* values, size_t l, unsigned j){
    unsigned* index = malloc(l * sizeof(unsigned));
    for(size_t i=0; i<l; i++){
      unsigned f = abs(faces[i])-1;
      unsigned e1 = FacePoints[f][1];
      unsigned e2 = FacePoints[f][2];
      unsigned e3 = FacePoints[f][3];
      unsigned e4 = FacePoints[f][4];
      size_t p = p1[i]-2;
      double A = values[p+e1];
      double B = values[p+e2];
      double C = values[p+e3];
      double D = values[p+e4];
      int temp = faces[i]>0 ? 1 : -1;
      temp *= (A*B-C*D>0 ? 1 : -1);
      index[i] = temp == 1 ? upow(2,j-1) : 0;
    }
    return(index);
}

unsigned* Faces7(int* faces, size_t* p1, double* values, size_t l, unsigned j){
  unsigned* index = malloc(l * sizeof(unsigned));
  for(size_t i=0; i<l; i++){
    size_t p = p1[i] - 1;
    double A0 = values[p];
    double B0 = values[p+3];
    double C0 = values[p+2];
    double D0 = values[p+1];
    double A1 = values[p+4];
    double B1 = values[p+7];
    double C1 = values[p+6];
    double D1 = values[p+5];
    double a = (A1 - A0) * (C1 - C0) - (B1 - B0) * (D1 - D0);
    double b = C0 * (A1 - A0) + A0 * (C1 - C0) - D0 * (B1 - B0) - B0 * (D1 - D0);
    double c = A0 * C0 - B0 * D0;
    double tmax = -b/(2 * a);
    double maximum = a * tmax*tmax + b * tmax + c;
    maximum = isnan(maximum) ? -1 : maximum;
    printf("maximum: %f\n", maximum);
    unsigned cond1 = a<0 ? 1 : 0;
    unsigned cond2 = tmax>0 ? 1 : 0;
    unsigned cond3 = tmax<1 ? 1 : 0;
    unsigned cond4 = maximum>0 ? 1 : 0;
    unsigned totalcond = cond1*cond2*cond3*cond4;
    int temp = faces[i]>0 ? 1 : -1;
    temp *= (totalcond == 1 ? 1 : -1);
    index[i] = temp == 1 ? upow(2,j-1) : 0;
  }
  return index;
}

// matrix(M, ncol=ncol, byrow=TRUE)
unsigned** vector2matrix(unsigned* M, unsigned lengthM, unsigned ncol){
  unsigned nrow = lengthM/ncol;
  unsigned** out = malloc(nrow * sizeof(unsigned*));
  for(unsigned i=0; i<nrow; i++){
    out[i] = malloc(ncol * sizeof(unsigned));
    for(unsigned j=0; j<ncol; j++){
      out[i][j] = M[i*ncol+j];
    }
  }
  return out;
}

// cbind(matrix, vector, vector) - not tested
unsigned** cbind(unsigned** M, size_t* v1, unsigned* v2, unsigned nrow, unsigned ncol){
    unsigned** out = malloc(nrow * sizeof(unsigned*));
    for(unsigned i=0; i<nrow; i++){
      out[i] = malloc((ncol+2) * sizeof(unsigned));
      for(unsigned j=0; j<ncol; j++){
        out[i][j] = M[i][j];
      }
      out[i][ncol] = v1[i];
      out[i][ncol+1] = v2[i];
    }
    return out;
}

unsigned** subsetMatrix(unsigned** M, unsigned* rows, unsigned* cols, unsigned nrows, unsigned ncols){
  unsigned** out = malloc(nrows * sizeof(unsigned*));
  for(unsigned i=0; i<nrows; i++){
    out[i] = malloc(ncols * sizeof(unsigned));
    for(unsigned j=0; j<ncols; j++){
      out[i][j] = M[rows[i]][cols[j]];
    }
  }
  return out;
}

// not tested
unsigned* whichEqual(unsigned* v, unsigned x, unsigned lv, unsigned* outlength){
  short* flag = malloc(lv * sizeof(short));
  unsigned count = 0;
  for(unsigned i=0; i<lv; i++){
    if(v[i]==x){
      flag[i] = 1;
      count++;
    }else{
      flag[i] = 0;
    }
  }
  *outlength = count;
  unsigned* out = malloc(count * sizeof(unsigned));
  count = 0;
  for(unsigned i=0; i<lv; i++){
    if(flag[i]){
      out[count] = i;
      count++;
    }
  }
  free(flag);
  return(out);
}

unsigned* matrix2vector(unsigned** M, unsigned nrow, unsigned ncol){
  unsigned* out = malloc(nrow*ncol * sizeof(unsigned));
  for(size_t i=0; i<nrow; i++){
    for(size_t j=0; j<ncol; j++){
        out[i*ncol + j] = M[i][j];
    }
  }
  return out;
}

unsigned* matrix2vectorMinusFirstColumn(unsigned** M, unsigned nrow, unsigned ncol){
  unsigned* out = malloc(nrow*(ncol-1) * sizeof(unsigned));
  for(size_t i=0; i<nrow; i++){
    for(size_t j=1; j<ncol; j++){
        out[i*(ncol-1) + j-1] = M[i][j];
    }
  }
  return out;
}

size_t* repeach(size_t* x, unsigned times, size_t n){
    size_t* out = malloc(n*times * sizeof(size_t));
    unsigned count = 0;
    for(size_t i=0; i<n; i++){
        for(unsigned j=0; j<times; j++){
            out[count] = x[i];
            count++;
        }
    }
    return out;
}

// not used
unsigned* replicatex(unsigned x, unsigned times){
  unsigned* out = malloc(times * sizeof(unsigned));
  for(unsigned i=0; i<times; i++){
    out[i] = x;
  }
  return out;
}

int* jthColumn(int* M, unsigned lengthM, unsigned ncol, unsigned j){
  unsigned nrow = lengthM/ncol;
  int* out = malloc(nrow * sizeof(unsigned));
  for(unsigned i=0; i<nrow; i++){
    out[i] = M[i*ncol+j];
  }
  return out;
}

double** transpose(double** M, size_t nrow, size_t ncol){
  double** out = malloc(ncol * sizeof(double*));
  for(size_t i=0; i<ncol; i++){
    out[i] = malloc(nrow * sizeof(double));
    for(size_t j=0; j<nrow; j++){
      out[i][j] = M[j][i];
    }
  }
  return out;
}

unsigned* vectorialSum(unsigned* v1, unsigned* v2, unsigned l){
  unsigned* out = malloc(l * sizeof(unsigned));
  for(unsigned i=0; i<l; i++){
    out[i] = v1[i] + v2[i];
  }
  return out;
}
