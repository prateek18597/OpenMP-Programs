#include<omp.h>
#include<stdio.h>

int main(){
	int numt;
	int tid;
	#pragma omp parallel shared(numt) private(tid)
	{
		numt = omp_get_num_threads();
		tid = omp_get_thread_num();
		int i;
		for(i = 0; i < 10000; i++);
		printf("Hello World from thread %d of %d A(tid): %p and A(numt): %p\n", tid, numt, &tid, &numt);
	}
}