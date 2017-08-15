//testestest

#include "include/allocate.h"
#include <time.h>
#include <sys/time.h>
#include "cublas_v2.h"
#include <cuda_runtime.h>

double *d_A, *d_B, *d_C;

double wallclock(void)
{
  struct timeval tv;
  struct timezone tz;
  double t;

  gettimeofday(&tv, &tz);

  t = (double)tv.tv_sec*1000;
  t += ((double)tv.tv_usec)/1000.0;

  return t;
}

int main(){

  cudaError_t cudaStat;
  cublasStatus_t stat;
  cublasHandle_t handle;

  double start, end;

  Init();

//cuda memory set
  cudaMalloc((void**)&d_A, m*k*sizeof(double));
  cudaMalloc((void**)&d_B, k*n*sizeof(double));
  cudaStat = cudaMalloc((void**)&d_C, m*n*sizeof(double));

//data Host to Device
  cudaMemcpy(d_A, A, m*k*sizeof(double), cudaMemcpyHostToDevice);
  cudaMemcpy(d_B, B, k*n*sizeof(double), cudaMemcpyHostToDevice);

//handle
//  cublasStatus_t cublasCreate(cublasHandle_t *handle);

  stat = cublasCreate(&handle);
  if (stat != CUBLAS_STATUS_SUCCESS) {
  printf ("CUBLAS initialization failed\n");
  return EXIT_FAILURE;
  }

  stat = cublasSetMatrix (m, n, sizeof(double), C, m, d_C, m);
  if (stat != CUBLAS_STATUS_SUCCESS) {
  printf ("data download failed");
  cudaFree (d_C);
  cublasDestroy(handle);
  return EXIT_FAILURE;
  }
  start = wallclock();
  cublasDgemm(  handle, 
		CUBLAS_OP_N, 
		CUBLAS_OP_N, 
		m, 
		n, 
		k, 
		&alpha, 
		d_A, 
		m, 
		d_B, 
		k, 
		&beta, 
		d_C, 
		n);
  cudaDeviceSynchronize();
  end = wallclock();
  double time = (end - start) * 1e-3;

//data Device to Host
  cudaMemcpy(C, d_C, m*n*sizeof(double), cudaMemcpyDeviceToHost);

  double SIZE = (double)m*n*k;

  printf("Elapsed time is = %f seconds. \n\n", time);
  printf("GPU result : %f GFLOPS \n\n", SIZE / (end - start) * 1e-6);

  printf("%lf\t", C[0]);

  printf("\n");
  free(A), free(B), free(C);
  cudaFree(d_A), cudaFree(d_B), cudaFree(d_C);
  cublasDestroy(handle);

}

