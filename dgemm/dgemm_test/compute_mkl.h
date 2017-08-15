#ifndef COMPUTE_MKL_H_
#define COMPUTE_MKL_H_

#include "include/allocate.h"
#include <mkl.h>

void compute_mkl(){
    
  printf ("Computing matrix product using MKL dgemm... \n\n");
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                m, n, k, alpha, A, k, B, n, beta, C, n);
  printf ("completed.\n\n");
  
}

#endif
