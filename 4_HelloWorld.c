#include<omp.h>
#include<stdio.h>

static int tid;
#pragma omp threadprivate(tid)
int main(){

	int numt;
	#pragma omp parallel
	{
		tid = omp_get_thread_num();
		if (tid == 0){
			numt = omp_get_num_threads();
		}
	}

	#pragma omp parallel
	{
		printf("Hello World from thread %d of %d A(tid): %p and A(numt): %p\n", tid, numt, &tid, &numt);
	}
	
	tid = omp_get_thread_num();
	printf("Hello World from thread %d of %d A(tid): %p and A(numt): %p\n", tid, numt, &tid, &numt);
}