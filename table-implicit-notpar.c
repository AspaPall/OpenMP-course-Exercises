#include <stdio.h>
#include <omp.h>

#define N 12

int main(void) {

int i,
    A[N],
    B[N];

 for(i=0;i<N;i++) A[i] = i;

#pragma omp parallel shared(A,B) private(i) default(none)
{
 #pragma omp for
 for(i=1;i<N;i++) B[i] =A[i-1];

 for(i=1;i<N;i++) A[i] =B[i];
}
for(i=0;i<N;i++) printf("A[%d] = %d\n",i,A[i]);
return 0;
// to correct i created a new matrix B. previously all the threads tried to edit or use the same elements at the same time.

return 0;}