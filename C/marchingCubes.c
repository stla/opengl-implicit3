#ifndef __HEADER__
#define __HEADER__
#include "marchingCubes.h"
#endif
#include <math.h>   // for floor - compile with flag -lm

size_t** faceType(double** M, unsigned m, unsigned n, double level, double max){
    size_t** L = levelMatrix(M, m, n, level, level<max);
    size_t** minorMat = minorMatrix(L,m,n,m-1,n-1);
    size_t** sminorMat2 = scaleMinorMatrix(2,L,m,n,0,n-1);
    size_t** sminorMat4 = scaleMinorMatrix(4,L,m,n,0,0);
    size_t** sminorMat8 = scaleMinorMatrix(8,L,m,n,m-1,0);
    size_t** sum1 = matricialSum(minorMat, sminorMat2, m-1, n-1);
    size_t** sum2 = matricialSum(sminorMat4, sminorMat8, m-1, n-1);
    size_t** out = matricialSum(sum1, sum2, m-1, n-1);
    freeMatrix_s(L,m);
    freeMatrix_s(sminorMat2,m-1);
    freeMatrix_s(sminorMat4,m-1);
    freeMatrix_s(sminorMat8,m-1);
    freeMatrix_s(sum1,m-1);
    freeMatrix_s(sum2,m-1);
    return out;
}

unsigned** levCells(double*** A, unsigned nx, unsigned ny, unsigned nz, double level, double max,
                    size_t* outnrow){
    // //printf("nz: %u\n", nz);
    // unsigned* cells[nz-1];
    // unsigned* types[nz-1];
    unsigned** cells = malloc((nz-1) * sizeof(unsigned*));
    unsigned** types = malloc((nz-1) * sizeof(unsigned*));
    // //printf("slice 0:\n");
    // displayMatrix(toMatrix(A, nx, ny, 0), nx, ny);
    size_t** bottomTypes = faceType(toMatrix(A, nx, ny, 0), nx, ny, level, max);
    // //printf("bottomTypes:\n");
    // displayMatrix_u(bottomTypes, nx-1, ny-1);
    size_t totallength = 0;
    unsigned lengths[nz-1];
    for(unsigned k=0; k<nz-1; k++){
        size_t** topTypes = faceType(toMatrix(A, nx, ny, k+1), nx, ny, level, max);
        // //printf("topTypes:\n");
        // displayMatrix_u(topTypes, nx-1, ny-1);
        size_t** cellTypes =
            matricialSum(bottomTypes, scaleMatrix(16, topTypes, nx-1, ny-1), nx-1, ny-1);
        // //printf("cellTypes:\n");
        // displayMatrix_u(cellTypes, nx-1, ny-1);
        unsigned length;
        unsigned** goodcells01 = whichIndicesAndItems(cellTypes, nx-1, ny-1, &length);
        cells[k] = malloc(length * sizeof(unsigned));
        types[k] = malloc(length * sizeof(unsigned));
        for(unsigned l=0; l<length; l++){
            cells[k][l] = goodcells01[0][l] + (nx-1)*(ny-1)*k + 1;
            types[k][l] = goodcells01[1][l];
        }
        bottomTypes = topTypes;
        // freeMatrix_u(bottomTypes, nx-1);
        // unsigned** bottomTypes = copyMatrix(topTypes, nx-1, ny-1);
        lengths[k] = length;
        totallength += (size_t) length;
        //freeMatrix_s(topTypes, nx-1);
        freeMatrix_s(cellTypes, nx-1);
        freeMatrix_u(goodcells01, 2);
    }
    unsigned** out = malloc(4 * sizeof(unsigned*));
    out[0] = malloc(totallength * sizeof(unsigned));
    out[1] = malloc(totallength * sizeof(unsigned));
    out[2] = malloc(totallength * sizeof(unsigned));
    out[3] = malloc(totallength * sizeof(unsigned));
    size_t count=0;
    for(unsigned k=0; k<nz-1; k++){
        for(unsigned l=0; l<lengths[k]; l++){
            unsigned c = cells[k][l]-1;
            out[0][count] = c % (nx-1) + 1;
            out[1][count] = (c / (nx-1)) % (ny-1) + 1;
            out[2][count] = c / ((nx-1) * (ny-1)) + 1;
            out[3][count] = types[k][l];
            count++;
        }
    }
    freeMatrix_u(cells, nz-1);
    freeMatrix_u(types, nz-1);
    *outnrow = totallength;
    return out;
}

size_t** GetBasic1(unsigned* R, size_t nR, size_t** vivjvk, unsigned n){ // n = nrow(vivjvk) - not used ?
  size_t** indexPtr = malloc(8 * sizeof(size_t*));
  for(unsigned i=0; i<8; i++){
      indexPtr[i] = malloc(3 * sizeof(size_t));
      for(unsigned j=0; j<3; j++){
          indexPtr[i][j] = indexArray[i][j];
      }
  }
  printf("GB1 - indexPtr done\n");
  size_t** cube1 = malloc(nR * sizeof(size_t*));
  for(size_t i=0; i<nR; i++){
      cube1[i] = malloc(3 * sizeof(size_t));
      size_t* vivjvkRi = vivjvk[R[i]];
      for(unsigned j=0; j<3; j++){
          cube1[i][j] = vivjvkRi[j];
      }
  }
  printf("GB1 - cube1 done\n");
  size_t** k1 = kro1(indexPtr, 8, 3, nR);
  printf("GB1 - k1 done\n");
  size_t** k2 = kro2(cube1, nR, 3, 8); // PROBLèME ICI
  printf("GB1 - k2 done\n");
  size_t** cubeco = matricialSum(k1, k2, 8*nR, 3);
  printf("GB1 - cubeco done\n");
  freeMatrix_s(indexPtr,8);
  freeMatrix_s(cube1,nR);
  freeMatrix_s(k1,24);
  freeMatrix_s(k2,8*nR);
  return cubeco;
}

// double* GetBasic2(double*** A, double level, unsigned* R, size_t nR, size_t** vivjvk){
//     size_t** cubeco = GetBasic1(R, nR, vivjvk, 999); // 999 useless ?
//     double* values = malloc((8*nR+1)*sizeof(double));
//     for(size_t i=0; i<8*nR; i++){
//         values[i] = A[cubeco[i][0]-1][cubeco[i][1]-1][cubeco[i][2]-1] - level;
//     }
//     values[8*nR] = 0;
//     freeMatrix_s(cubeco, 8*nR);
//     return values;
// }

double* GetBasic2prime(double*** A, double level, size_t** cubeco, size_t nR){
//    size_t** cubeco = GetBasic1(R, nR, vivjvk, 999); // 999 useless ?
    double* values = malloc((8*nR+1)*sizeof(double));
    for(size_t i=0; i<8*nR; i++){
        values[i] = A[cubeco[i][0]-1][cubeco[i][1]-1][cubeco[i][2]-1] - level;
    }
    values[8*nR] = 0;
//    freeMatrix_s(cubeco, 8*nR);
    return values;
}

unsigned* get_tcase(unsigned* types, size_t nrow){
    unsigned CRF[256] =
    {1, 2, 2, 3, 2, 4, 3, 6, 2, 3, 4, 6, 3, 6, 6, 9, 2, 3, 4, 6,
     5, 7, 7, 12, 4, 6, 8, 10, 7, 15, 13, 6, 2, 4, 3, 6, 4, 8, 6,
     10, 5, 7, 7, 15, 7, 13, 12, 6, 3, 6, 6, 9, 7, 13, 15, 6, 7, 12,
     13, 6, 11, 7, 7, 3, 2, 5, 4, 7, 3, 7, 6, 15, 4, 7, 8, 13, 6,
     12, 10, 6, 4, 7, 8, 13, 7, 11, 13, 7, 8, 13, 14, 8, 13, 7, 8,
     4, 3, 7, 6, 12, 6, 13, 9, 6, 7, 11, 13, 7, 15, 7, 6, 3, 6, 15,
     10, 6, 12, 7, 6, 3, 13, 7, 8, 4, 7, 5, 4, 2, 2, 4, 5, 7, 4, 8,
     7, 13, 3, 6, 7, 12, 6, 10, 15, 6, 3, 6, 7, 15, 7, 13, 11, 7,
     6, 9, 13, 6, 12, 6, 7, 3, 4, 8, 7, 13, 8, 14, 13, 8, 7, 13, 11,
     7, 13, 8, 7, 4, 6, 10, 12, 6, 13, 8, 7, 4, 15, 6, 7, 3, 7, 4,
     5, 2, 3, 7, 7, 11, 6, 13, 12, 7, 6, 15, 13, 7, 9, 6, 6, 3, 6,
     12, 13, 7, 15, 7, 7, 5, 10, 6, 8, 4, 6, 3, 4, 2, 6, 13, 15, 7,
     10, 8, 6, 4, 12, 7, 7, 5, 6, 4, 3, 2, 9, 6, 6, 3, 6, 4, 3, 2,
     6, 3, 4, 2, 3, 2, 2, 1};
    unsigned* out = malloc(nrow * sizeof(unsigned));
    for(size_t i=0; i<nrow; i++){
        //printf("types[i]=%u\n", types[i]);
        out[i] = CRF[types[i]]-1;
    }
    return out;
}

unsigned* getR(unsigned* tcase, size_t nrow, size_t* nR){
    unsigned* out = malloc(nrow * sizeof(unsigned));
    size_t count=0;
    for(size_t i=0; i<nrow; i++){
        ////printf("in loop\n");
        ////printf("tcase[%zu]=%u\n", i, tcase[i]);
        unsigned tc = tcase[i];
        if(tc==1 || tc==2 || tc==5 || tc==8 || tc==9 || tc==11 || tc==14){
            out[count] = (unsigned) i;
            count++;
            //printf("tcase matched\n");
        }
        ////printf("end if\n");
    }
    ////printf("end loop");
    *nR = count;
    return(out);
}

double** LambdaMu(double* x1, size_t n){
    double** lambdamu = malloc(2 * sizeof(double*));
    lambdamu[0] = malloc(n * sizeof(double));
    lambdamu[1] = malloc(n * sizeof(double));
    for(size_t i=0; i<n; i++){
        lambdamu[0][i] = floor(x1[i]/9);
        lambdamu[1][i] = 1 - lambdamu[0][i];
    }
    return lambdamu;
}

double* average(double** lambdamu, double* w1, double* w2, size_t n){
    double* lambda = lambdamu[0]; double* mu = lambdamu[1];
    double* out = malloc(n * sizeof(double));
    for(size_t i=0; i<n; i++){
        out[i] =  mu[i]*w1[i] + lambda[i]*w2[i];
    }
    return out;
}

double* average7(double** lambdamu, double* w, size_t n){
    double* lambda = lambdamu[0]; double* mu = lambdamu[1];
    double* out = malloc(n * sizeof(double));
    for(size_t i=0; i<n; i++){
        out[i] =  mu[i]*w[i] + lambda[i];
    }
    return out;
}

double* average8(double** lambdamu, double* w, size_t n){
    double* lambda = lambdamu[0]; double* mu = lambdamu[1];
    double* out = malloc(n * sizeof(double));
    for(size_t i=0; i<n; i++){
        out[i] =  mu[i]*w[i] - lambda[i];
    }
    return out;
}

double** GetPoints(size_t** cubeco, double* values, size_t* p1, unsigned* x1,
                   unsigned* x2, size_t n){
    unsigned* p1x1 = malloc(n * sizeof(unsigned));
    unsigned* p1x2 = malloc(n * sizeof(unsigned));
    double* xx1 = malloc(n * sizeof(double));
    for(size_t i=0; i<n; i++){
        p1x1[i] = p1[i] + x1[i];
        p1x2[i] = p1[i] + x2[i];
        xx1[i] = (double) x1[i];
    }
    double** lambdamu = LambdaMu(xx1, n);
    double* v1 = malloc(n * sizeof(double));
    double* v2 = malloc(n * sizeof(double));
    double* v3 = malloc(n * sizeof(double));
    double* v4 = malloc(n * sizeof(double));
    double* v5 = malloc(n * sizeof(double));
    double* v6 = malloc(n * sizeof(double));
    double* v7 = malloc(n * sizeof(double));
    double* v8 = malloc(n * sizeof(double));
    double* w1 = malloc(n * sizeof(double));
    double* w2 = malloc(n * sizeof(double));
    double* w3 = malloc(n * sizeof(double));
    double* w4 = malloc(n * sizeof(double));
    double* w5 = malloc(n * sizeof(double));
    double* w6 = malloc(n * sizeof(double));
    // double v1[n]; double w1[n];
    // double v2[n]; double w2[n];
    // double v3[n]; double w3[n];
    // double v4[n]; double w4[n];
    // double v5[n]; double w5[n];
    // double v6[n]; double w6[n];
    // double v7[n]; double v8[n];
    for(size_t i=0; i<n; i++){
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
    free(v1); free(w1);
    out[1] = average(lambdamu, v2, w2, n);
    free(v2); free(w2);
    out[2] = average(lambdamu, v3, w3, n);
    free(v3); free(w3);
    out[3] = average(lambdamu, v4, w4, n);
    free(v4); free(w4);
    out[4] = average(lambdamu, v5, w5, n);
    free(v5); free(w5);
    out[5] = average(lambdamu, v6, w6, n);
    free(v6); free(w6);
    out[6] = average7(lambdamu, v7, n);
    free(v7);
    out[7] = average8(lambdamu, v8, n);
    free(v8);
    freeMatrix_d(lambdamu,2);
    free(xx1);
    // free(v1); free(v2); free(v3); free(v4); free(v5); free(v6); free(v7); free(v8);
    // free(w1); free(w2); free(w3); free(w4); free(w5); free(w6);
    return(out);
}

double** CalPoints(double** points, size_t n){
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
    for(size_t i=0; i<n; i++){
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

double** computeContour3d(
    double*** voxel,
    unsigned nx, unsigned ny, unsigned nz,
    double max,
    double level,
    size_t* ntriangles)
{
    printf("START\n");
    size_t nrow;
    unsigned** ijkt = levCells(voxel, nx, ny, nz, level, max, &nrow);
    printf("ijkt[3][0]=%u\n", ijkt[3][0]);
    unsigned* tcase = get_tcase(ijkt[3], nrow);
    printf("tcase[0]=%u\n", tcase[0]);
    printf("nrow: %zu\n", nrow);
    size_t nR;
    unsigned* R = getR(tcase, nrow, &nR);
    printf("getR done\n");
    printf("nR: %zu\n", nR);
    if(nR == 0){
        *ntriangles = 0;
        free(R);
        free(tcase);
        return 0;
    }else{
        size_t** vivjvk = malloc(nrow * sizeof(size_t*));
        printf("allocated vivjvk\n");
        for(size_t i=0; i<nrow; i++){
            vivjvk[i] = malloc(3 * sizeof(size_t));
            for(unsigned j=0; j<3; j++){
                vivjvk[i][j] = (size_t) ijkt[j][i];
            }
        }
        printf("vivjvk done\n");
        size_t** cubeco = GetBasic1(R, nR, vivjvk, 999);
        printf("cubeco done\n");
//        double* values = GetBasic2(voxel, level, R, nR, vivjvk);
        double* values = GetBasic2prime(voxel, level, cubeco, nR);
        size_t* p1 = malloc(nR * sizeof(size_t));
        for(size_t i=0; i<nR; i++){
            p1[i] = i*8 + 1; // -1 ou pas ?
        }
        unsigned* vt = ijkt[3];
        unsigned* cases = malloc(nR * sizeof(unsigned));
        for(size_t i=0; i<nR; i++){
            cases[i] = vt[R[i]]-1; // -1 ou pas ?
        }
        free(R);
        unsigned edgeslengths[nR];
        size_t totalLength = 0;
        for(size_t i=0; i<nR; i++){
            //printf("cases[%zu]=%u",i,cases[i]);
            edgeslengths[i] = edgesLengths[cases[i]];
            totalLength += (size_t) edgeslengths[i];
        }
        printf("totalLength: %zu\n", totalLength);
        *ntriangles = totalLength;
        size_t* p1rep = replicate(p1, edgeslengths, nR);
        size_t* edges = malloc(totalLength * sizeof(size_t));
        size_t edgeiter = 0;
        for(size_t i=0; i<nR; i++){
            for(unsigned j=0; j<edgeslengths[i]; j++){
                edges[edgeiter] = (size_t) (*Edges[cases[i]])[j];
                edgeiter++;
            }
        }
        unsigned* x1 = malloc(totalLength * sizeof(unsigned));
        unsigned* x2 = malloc(totalLength * sizeof(unsigned));
        for(size_t i=0; i<totalLength; i++){
            unsigned* EPi = EdgePoints[edges[i]-1];
            x1[i] = EPi[1];
            x2[i] = EPi[2];
        }
        free(edges);
        double** points = GetPoints(cubeco, values, p1rep, x1, x2, totalLength);
        // //printf("totalLength: %u\n", totalLength);
        double** triangles = CalPoints(points, totalLength);

        unsigned special=0;
        for(size_t i=0; i<nrow; i++){
            unsigned tc = tcase[i];
            if(tc==3 || tc==4 || tc==6 || tc==7 || tc==10 || tc==12 || tc==13){
              special = tc;
              break;
            }
        }
        if(special){
          printf("!!! there are special cases !!! (%u)", special);
        }

        // faire un malloc(0) pour new triangles
        // unsigned* is3 = malloc(nrow * sizeof(unsigned));
        // size_t nR3=0;
        // for(size_t i=0; i<nrow; i++){
        //   if(tcase[i]==3){
        //     is3[i] = 1;
        //     nR3++;
        //   }else{
        //     is3[i] = 0;
        //   }
        // }
        // if(nR3 > 0){
        //   size_t* R3 = malloc(nR3 * sizeof(size_t));
        //   unsigned count_is3=0;
        //   for(size_t i=0; i<nrow; i++){
        //     if(is3[i]){
        //       R3[count_is3] = i;
        //       count_is3++;
        //     }
        //   }
        //   free(is3);
        //   size_t** cubeco3 = GetBasic1(R3, nR3, vivjvk, 999);
        //   double* values3 = GetBasic2prime(voxel, level, cubeco3, nR3);
        //   size_t* p13 = malloc(nR3 * sizeof(size_t));
        //   for(size_t i=0; i<nR3; i++){
        //       p13[i] = i*8 + 1;
        //   }
        //   unsigned* cases3 = malloc(nR3 * sizeof(unsigned));
        //   for(size_t i=0; i<nR3; i++){
        //       cases[i] = vt[R3[i]]-1;
        //   }
        //   free(R3);
        //
        // }

        freeMatrix_s(vivjvk,3);
        freeMatrix_u(ijkt,4);
        freeMatrix_d(points,8);
        free(x1); free(x2);
        freeMatrix_s(cubeco,3);
        free(values);
        free(tcase);
        return triangles;
    }

}
