#include <stdlib.h> // for malloc
#include <stdio.h> // for printf

void displayMatrix_u(unsigned**, unsigned, unsigned);

void displayMatrix(double**, unsigned, unsigned);

//int CaseRotationFlip[256][3];

//size_t indexArray[8][3];

//unsigned** Edges;

//unsigned edgesLengths[254];


// unsigned EdgePoints[13][3];

void freeMatrix_u(unsigned**, unsigned);

void freeMatrix_s(size_t**, size_t);

void freeMatrix_d(double**, unsigned);

unsigned** copyMatrix(unsigned**, unsigned, unsigned);

size_t** minorMatrix(size_t**, unsigned, unsigned, unsigned, unsigned);

size_t** scaleMatrix(size_t, size_t**, unsigned, unsigned);

size_t** scaleMinorMatrix(size_t, size_t**, unsigned, unsigned, unsigned, unsigned);

size_t** matricialSum(size_t**, size_t**, size_t, unsigned);

size_t** levelMatrix(double**, unsigned, unsigned, double, unsigned);

double** toMatrix(double***, unsigned, unsigned, unsigned);

unsigned** whichIndicesAndItems(size_t**, unsigned, unsigned, unsigned*);

void freeArray(double***, unsigned, unsigned);

size_t** kro1(size_t**, unsigned, unsigned, size_t);

size_t** kro2(size_t**, size_t, unsigned, unsigned);

size_t* replicate(size_t*, unsigned*, size_t);

size_t** faceType(double**, unsigned, unsigned, double, double);

unsigned** levCells(double***, unsigned, unsigned, unsigned, double, double, size_t*);

size_t** GetBasic1(unsigned*, size_t, size_t**, unsigned);

double* GetBasic2(double***, double, unsigned*, size_t, size_t**);

unsigned* get_tcase(unsigned*, size_t);

unsigned* getR(unsigned*, size_t, size_t*);

double** LambdaMu(double*, size_t);

double* average(double**, double*, double*, size_t);

double* average7(double**, double*, size_t);

double* average8(double**, double*, size_t);

double** GetPoints(size_t**, double*, size_t*, unsigned*, unsigned*, size_t);

double** CalPoints(double**, size_t);

double** computeContour3d(double***, unsigned, unsigned, unsigned, double, double, size_t*);

double*** voxel(double (*f)(double, double, double), 
                double, double, double, double, double, double, 
                unsigned, unsigned, unsigned);
