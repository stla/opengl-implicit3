#include <stdlib.h> // for malloc

int CaseRotationFlip[256][3];

unsigned indexArray[8][3];

unsigned* Edges;

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