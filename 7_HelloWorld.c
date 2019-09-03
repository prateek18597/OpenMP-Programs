#include<omp.h>
#include<stdio.h>

static int tid;
#pragma omp threadprivate(tid)
int main(){

	int numt;
	#pragma omp parallel
	{
		#pragma omp single
		{
			int i=0;
			for(i=0;i<10000;i++);
			numt = omp_get_num_threads();
		}
		tid = omp_get_thread_num();
		
		printf("Hello World from thread %d of %d A(tid): %p and A(numt): %p\n", tid, numt, &tid, &numt);
	}
}	