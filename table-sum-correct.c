#include <stdio.h>
#include <omp.h>

#define N 10

int main(void) {

int i,
    sum=0,
    a[N];


 for(i=0;i<N;i++) a[i] = i;

 sum = 0;

#pragma omp parallel shared(a) private(i) \ reduction(+:sum) \
                     default(none)

{
					 					 
 //myid = omp_get_thread_num();
 //nThreads = omp_get_num_threads();
 
 
 for(i=0;i<N;i++) sum+=a[i];
}
 
 printf("sum = %d\n",sum);
// #create a table where each thread saves its sum, finally the master thread computes the whole sum
return 0;

}
