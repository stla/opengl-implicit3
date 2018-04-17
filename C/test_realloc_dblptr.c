#include <stdlib.h>
#include <stdio.h>

int main(){
  unsigned** a1 = malloc(2 * sizeof(unsigned*));
  for(unsigned i=0; i<2; i++){
    a1[i] = malloc(3 * sizeof(unsigned));
    for(unsigned j=0; j<3; j++){
      a1[i][j] = i+j;
    }
  }

  unsigned** a2 = realloc(a1, 3 * sizeof(unsigned*));
  a2[2] = malloc(3 * sizeof(unsigned));
  for(unsigned j=0; j<3; j++){
    a2[2][j] = 2+j;
  }


  for(unsigned i=0; i<3; i++){
    for(unsigned j=0; j<3; j++){
      printf("a2[%u][%u]=%u ", i, j, a2[i][j]);
    }
    printf("\n");
  }

  free(a2[0]); free(a2[1]); free(a2[2]); free(a2);
  //free(a1[0]); free(a1[1]);free(a1);
  return 0;
}
