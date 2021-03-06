//testestest

#include "compute_mkl.h"
//#include "include/timer.h"
#include <time.h>
#include <sys/time.h>

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

//  mkl_set_num_threads(4);

  double start, end;

  Init();

  start = wallclock();
  compute_mkl();
  end = wallclock();

  double time = (end - start) * 1e-3;
  double size = (double)m*n*k;

  printf("Elapsed time is = %f seconds. \n\n", time);
  printf("%f GFLOPS \n\n",  size / (end - start) * 1e-6);

  printf("%f\n\n", C[0]);

  free(A), free(B), free(C);

}

