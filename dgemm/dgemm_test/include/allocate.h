#ifndef DGEMM_TEST_H_
#define DGEMM_TEST_H_

#include <stdio.h>
#include <stdlib.h>

double *A, *B, *C;
int m, n, k, i, j;
int alpha, beta;

void Init(){

  int order = 1;

  printf ("\n This example computes real matrix C=alpha*A*B+beta*C using.. \n\n");

  printf("m = \t");
  scanf("%d", &m);
  printf("k = \t");
  scanf("%d", &k);
  printf("n = \t");
  scanf("%d", &n);

//  m = 128*(order), k = 128*(order), n = 128*(order);
  printf("Initializing data for dgemm C=A*B... \n"
	 "A(%ix%i) and B(%ix%i)... \n\n", m, k, k, n);

  alpha = 1, beta = 0;
  printf("alpha = %i, beta = %i \n\n", alpha, beta);
  
  printf("Allocating... \n\n");

  A = (double *)malloc( m*k*sizeof( double ));
  B = (double *)malloc( k*n*sizeof( double ));
  C = (double *)malloc( m*n*sizeof( double ));

  printf("Initializing matrix data \n\n");
  
  for(i = 0; i < (m*k); i++){
      A[i] = 1;
  }
  
  for(i = 0; i < (k*n); i++){
      B[i] = 1;
  }
  
  for(i = 0; i < (m*n); i++){
      C[i] = 1;
  }
  
  printf("Initializing Success \n\n");
}

#endif
