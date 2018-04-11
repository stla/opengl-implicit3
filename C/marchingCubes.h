#include <stdlib.h> // for malloc
#include <stdio.h> // for printf

void displayMatrix_u(unsigned**, unsigned, unsigned);

void displayMatrix(double**, unsigned, unsigned);

int CaseRotationFlip[256][3];

unsigned indexArray[8][3];

//unsigned** Edges;

unsigned edgesLengths[254];

unsigned EdgePoints[13][3];

void freeMatrix_u(unsigned**, unsigned);

void freeMatrix_d(double**, unsigned);

unsigned** copyMatrix(unsigned**, unsigned, unsigned);

unsigned** minorMatrix(unsigned**, unsigned, unsigned, unsigned, unsigned);

unsigned** scaleMatrix(unsigned, unsigned**, unsigned, unsigned);

unsigned** scaleMinorMatrix(unsigned, unsigned**, unsigned, unsigned, unsigned, unsigned);

unsigned** matricialSum(unsigned**, unsigned**, unsigned, unsigned);

unsigned** levelMatrix(double**, unsigned, unsigned, double, unsigned);

double** toMatrix(double***, unsigned, unsigned, unsigned);

unsigned** whichIndicesAndItems(unsigned**, unsigned, unsigned, unsigned*);

void freeArray(double***, unsigned, unsigned);

unsigned** kro1(unsigned**, unsigned, unsigned, unsigned);

unsigned** kro2(unsigned**, unsigned, unsigned, unsigned);

unsigned* replicate(unsigned*, unsigned*, unsigned);

unsigned** faceType(double**, unsigned, unsigned, double, double);

unsigned** levCells(double***, unsigned, unsigned, unsigned, double, double, unsigned*);

unsigned** GetBasic1(unsigned*, unsigned, unsigned**, unsigned);

double* GetBasic2(double***, double, unsigned*, unsigned, unsigned**);

unsigned* get_tcase(unsigned*, unsigned);

unsigned* getR(unsigned*, unsigned, unsigned*);

double** LambdaMu(double*, unsigned);

double* average(double**, double*, double*, unsigned);

double* average7(double**, double*, unsigned);

double* average8(double**, double*, unsigned);

double** GetPoints(unsigned**, double*, unsigned*, unsigned*, unsigned*, unsigned);

double** CalPoints(double**, unsigned);

double** computeContour3d(double***, unsigned, unsigned, unsigned, double, double, unsigned*);

double*** voxel(double (*f)(double, double, double), double, double, double, double, double, double, unsigned);
