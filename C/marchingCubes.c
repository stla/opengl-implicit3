#ifndef __HEADER__
#define __HEADER__
#include "marchingCubes.h"
#endif
#include <math.h>   // for floor - compile with flag -lm


unsigned** faceType(double** M, unsigned m, unsigned n, double level, double max){
    unsigned** L = levelMatrix(M, m, n, level, level<max);
    unsigned** minorMat = minorMatrix(L,m,n,m-1,n-1);
    unsigned** sminorMat2 = scaleMinorMatrix(2,L,m,n,0,m-1);
    unsigned** sminorMat4 = scaleMinorMatrix(4,L,m,n,0,0);
    unsigned** sminorMat8 = scaleMinorMatrix(8,L,m,n,n-1,0);
    unsigned** sum1 = matricialSum(minorMat, sminorMat2, m-1, n-1);
    unsigned** sum2 = matricialSum(sminorMat4, sminorMat8, m-1, n-1);
    unsigned** out = matricialSum(sum1, sum2, m-1, n-1);
    freeMatrix(L,m);
    freeMatrix(sminorMat2,m-1);
    freeMatrix(sminorMat4,m-1);
    freeMatrix(sminorMat8,m-1);
    freeMatrix(sum1,m-1);
    freeMatrix(sum2,m-1);
    return out; 
}

unsigned** levCells(double*** A, unsigned nx, unsigned ny, unsigned nz, double level, double max, 
                    unsigned* nrow){
    unsigned* cells[nz-1];
    unsigned* types[nz-1];
    unsigned** bottomTypes = faceType(toMatrix(A, nx, ny, 0), nx, ny, level, max);
    unsigned totallength = 0;
    unsigned lengths[nz-1];
    for(unsigned k=0; k<nz-1; k++){
        unsigned** topTypes = faceType(toMatrix(A, nx, ny, k+1), nx, ny, level, max);
        unsigned** cellTypes = 
            matricialSum(bottomTypes, scaleMatrix(16, topTypes, nx-1, ny-1), nx-1, ny-1);
        unsigned length;
        unsigned** goodcells01 = whichIndicesAndItems(cellTypes, nx-1, ny-1, &length);
        cells[k] = malloc(length * sizeof(unsigned));
        types[k] = malloc(length * sizeof(unsigned));
        for(unsigned l=0; l<length; l++){
            cells[k][l] = goodcells01[0][l] + (nx-1)*(ny-1)*k + 1;
            types[k][l] = goodcells01[1][l];
        }
        freeMatrix(bottomTypes, nx-1);
        unsigned** bottomTypes = copyMatrix(topTypes, nx-1, ny-1);
        freeMatrix(topTypes, nx-1);
        lengths[k] = length;
        totallength += length;
        freeMatrix(cellTypes, nx-1);
        freeMatrix(goodcells01, 2);
    }
    unsigned** out = malloc(4 * sizeof(unsigned*));
    out[0] = malloc(totallength * sizeof(unsigned));
    out[1] = malloc(totallength * sizeof(unsigned));
    out[2] = malloc(totallength * sizeof(unsigned));
    out[3] = malloc(totallength * sizeof(unsigned));
    unsigned count=0;
    for(unsigned k=0; k<nz-1; k++){
        for(unsigned l=0; l<lengths[k]; l++){
            out[0][count] = (cells[k][l]-1) % (nx-1) + 1;
            out[1][count] = ((cells[k][l]-1) / (nx-1)) % (ny-1) + 1;
            out[2][count] = (cells[k][l]-1) / ((nx-1) * (ny-1)) + 1;
            out[3][count] = types[k][l];
            count++;  
        }
    }
    *nrow = totallength;
    return out;
}

unsigned** GetBasic1(unsigned* R, unsigned nR, unsigned** vivjvk, unsigned n){ // n = nrow(vivjvk) - not used ?
  unsigned** indexPtr = malloc(8 * sizeof(unsigned*));
  for(unsigned i=0; i<8; i++){
      indexPtr[i] = malloc(3 * sizeof(unsigned));
      for(unsigned j=0; j<3; j++){
          indexPtr[i][j] = indexArray[i][j];
      }
  }
  unsigned** cube1 = malloc(nR * sizeof(unsigned*));
  for(unsigned i=0; i<nR; i++){
      cube1[i] = malloc(3 * sizeof(unsigned));
      for(unsigned j=0; j<3; j++){
          cube1[i][j] = vivjvk[R[i]][j];
      }
  }
  unsigned** k1 = kro1(indexPtr, 8, 3, nR);
  displayMatrix_u(k1, 8*nR, 3);
  unsigned** k2 = kro2(cube1, nR, 3, 8);
  displayMatrix_u(k2, 8*nR, 3);
  unsigned** cubeco = matricialSum(k1, k2, 8*nR, 3);
  displayMatrix_u(cubeco, 8*nR, 3);
  free(indexPtr); free(cube1); free(k1); free(k2);
  return cubeco;
}

double* GetBasic2(double*** A, double level, unsigned* R, unsigned nR, unsigned** vivjvk){
    unsigned** cubeco = GetBasic1(R, nR, vivjvk, 999); // 999 useless ?
    double* values = malloc((8*nR+1)*sizeof(double));
    for(unsigned i=0; i<8*nR; i++){
        values[i] = A[cubeco[i][0]-1][cubeco[i][1]-1][cubeco[i][2]-1] - level;
    }
    values[8*nR] = 0;
    free(cubeco);
    return values;
}

unsigned* get_tcase(unsigned* types, unsigned nrow){
    unsigned* out = malloc(nrow * sizeof(unsigned));
    for(unsigned i=0; i<nrow; i++){
        out[i] = CaseRotationFlip[types[i]][0]-1;
    }
    return out;
} 

unsigned* getR(unsigned* tcase, unsigned nrow, unsigned* nR){
    unsigned* out = malloc(nrow * sizeof(unsigned));
    *nR=0;
    for(unsigned i=0; i<nrow; i++){
        if(tcase[i]==1 || tcase[i]==2 || tcase[i]==5 || tcase[i]==8 || tcase[i]==9 || tcase[i]==11 || tcase[i]==14){
            out[*nR] = i;
            (*nR)++;
        }
    }
    return(out);
}

double** LambdaMu(double* x1, unsigned n){
    double** lambdamu = malloc(2 * sizeof(double*));
    lambdamu[0] = malloc(n * sizeof(double));
    lambdamu[1] = malloc(n * sizeof(double));
    for(unsigned i=0; i<n; i++){
        lambdamu[0][i] = floor(x1[i]/9);
        lambdamu[1][i] = 1 - lambdamu[0][i];
    }
    return lambdamu;
}

double* average(double** lambdamu, double* w1, double* w2, unsigned n){
    double* lambda = lambdamu[0]; double* mu = lambdamu[1];
    double* out = malloc(n * sizeof(double));
    for(unsigned i=0; i<n; i++){
        out[i] =  mu[i]*w1[i] + lambda[i]*w2[i];
    }
    return out;
}

double* average7(double** lambdamu, double* w, unsigned n){
    double* lambda = lambdamu[0]; double* mu = lambdamu[1];
    double* out = malloc(n * sizeof(double));
    for(unsigned i=0; i<n; i++){
        out[i] =  mu[i]*w[i] + lambda[i];
    }
    return out;    
}

double* average8(double** lambdamu, double* w, unsigned n){
    double* lambda = lambdamu[0]; double* mu = lambdamu[1];
    double* out = malloc(n * sizeof(double));
    for(unsigned i=0; i<n; i++){
        out[i] =  mu[i]*w[i] - lambda[i];
    }
    return out;    
}

double** GetPoints(unsigned** cubeco, double* values, unsigned* p1, unsigned* x1, unsigned* x2, unsigned n){
    unsigned* p1x1 = malloc(n * sizeof(unsigned));
    unsigned* p1x2 = malloc(n * sizeof(unsigned));
    double* xx1 = malloc(n * sizeof(double));
    for(unsigned i=0; i<n; i++){
        p1x1[i] = p1[i] + x1[i];
        p1x2[i] = p1[i] + x2[i];
        xx1[i] = (double) x1[i];
    }
    double** lambdamu = LambdaMu(xx1, n);
    double v1[n]; double w1[n];
    double v2[n]; double w2[n];
    double v3[n]; double w3[n];
    double v4[n]; double w4[n];
    double v5[n]; double w5[n];
    double v6[n]; double w6[n];
    double v7[n]; double v8[n];
    for(unsigned i=0; i<n; i++){
        v1[i] = (double) cubeco[p1x1[i]-2][0];
        w1[i] = (double) cubeco[p1[i]-1][0];
        v2[i] = (double) cubeco[p1x2[i]-2][0];
        w2[i] = (double) cubeco[p1[i]][0];
        v3[i] = (double) cubeco[p1x1[i]-2][1];
        w3[i] = (double) cubeco[p1[i]][1];
        v4[i] = (double) cubeco[p1x2[i]-2][1];
        w4[i] = (double) cubeco[p1[i]+1][1];
        v5[i] = (double) cubeco[p1x1[i]-2][2];
        w5[i] = (double) cubeco[p1[i]][2];
        v6[i] = (double) cubeco[p1x2[i]-2][2];
        w6[i] = (double) cubeco[p1[i]+4][2];
        v7[i] = values[p1x1[i]-2];
        v8[i] = values[p1x2[i]-2];
    }
    free(p1x1);
    free(p1x2);
    double** out = malloc(8 * sizeof(double*));
    out[0] = average(lambdamu, v1, w1, n); 
    out[1] = average(lambdamu, v2, w2, n); 
    out[2] = average(lambdamu, v3, w3, n); 
    out[3] = average(lambdamu, v4, w4, n); 
    out[4] = average(lambdamu, v5, w5, n); 
    out[5] = average(lambdamu, v6, w6, n);
    out[6] = average7(lambdamu, v7, n);
    out[7] = average8(lambdamu, v8, n); 
    free(lambdamu);
    return(out);
}

double** CalPoints(double** points, unsigned n){
    double* x1 = points[0];
    double* x2 = points[1];
    double* y1 = points[2];
    double* y2 = points[3];
    double* z1 = points[4];
    double* z2 = points[5];
    double* v1 = points[6];
    double* v2 = points[7];
    double* x = malloc(n * sizeof(double));
    double* y = malloc(n * sizeof(double));
    double* z = malloc(n * sizeof(double));
    for(unsigned i=0; i<n; i++){
        double s = v1[i]/(v1[i]-v2[i]);
        x[i] = x1[i] + s*(x2[i]-x1[i]);
        y[i] = y1[i] + s*(y2[i]-y1[i]);
        z[i] = z1[i] + s*(z2[i]-z1[i]);
    }
    double** out = malloc(3 * sizeof(double*));
    out[0] = x; out[1] = y; out[2] = z;
    // free(x);free(y);free(z); NON
    return(out);
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

double** computeContour3d(
    double*** voxel, 
    unsigned nx, unsigned ny, unsigned nz, 
    double max, 
    double level)
{
    unsigned nrow;
    unsigned** ijkt = levCells(voxel, nx, ny, nz, level, max, &nrow); 
    unsigned* tcase = get_tcase(ijkt[3], nrow);
    unsigned nR;
    unsigned* R = getR(tcase, nrow, &nR);
    if(nR == 0){
        return 0;
    }else{
        unsigned** vivjvk = malloc(nrow * sizeof(unsigned*));
        for(unsigned i=0; i<nrow; i++){
            vivjvk[i] = malloc(3 * sizeof(unsigned));
            for(unsigned j=0; j<3; j++){
                vivjvk[i][j] = ijkt[j][i];
            }
        }
        unsigned** cubeco = GetBasic1(R, nR, vivjvk, 99999999);
        double* values = GetBasic2(voxel, level, R, nR, vivjvk);
        unsigned* p1 = malloc(nR * sizeof(unsigned));
        for(unsigned i=0; i<nR; i++){
            p1[i] = i*8 + 1; // -1 ou pas ?
        }
        unsigned* vt = ijkt[3];
        unsigned* cases = malloc(nR * sizeof(unsigned));
        for(unsigned i=0; i<nR; i++){
            cases[i] = vt[R[i]]-1; // -1 ou pas ?
        }
        unsigned edgeslengths[nR];
        unsigned totalLength = 0;
        for(unsigned i=0; i<nR; i++){
            edgeslengths[i] = edgesLengths[cases[i]];
            totalLength += edgeslengths[i];
        }
        unsigned* p1rep = replicate(p1, edgeslengths, nR);
        unsigned edges[totalLength];
        unsigned edgeiter = 0;
        for(unsigned i=0; i<nR; i++){
            for(unsigned j=0; j<edgeslengths[i]; j++){
                edges[edgeiter] = Edges[cases[i]][j];
                edgeiter++;
            }
        }
        unsigned* x1 = malloc(totalLength * sizeof(unsigned));
        for(unsigned i=0; i<totalLength; i++){
            x1[i] = EdgePoints[edges[i]-1][1];
        }
        unsigned* x2 = malloc(totalLength * sizeof(unsigned));
        for(unsigned i=0; i<totalLength; i++){
            x2[i] = EdgePoints[edges[i]-1][2];
        }
        double** points = GetPoints(cubeco, values, p1rep, x1, x2, totalLength);
        double** triangles = CalPoints(points, totalLength);
        freeMatrix_d(points,8); 
        free(x1); free(x2);
        freeMatrix(ijkt,4); 
        freeMatrix(cubeco,3); 
        free(tcase); free(R);
        freeMatrix(vivjvk,3); 
        return triangles;
    }

}
