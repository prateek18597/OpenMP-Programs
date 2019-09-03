#include<omp.h>
#include<stdio.h>

int main(){

	#pragma omp parallel
	{
		int num_threads = omp_get_num_threads();
		int tid = omp_get_thread_num();
		printf("Hello World from thread [%d:%d] [%p:%p]\n",tid,num_threads, &tid, &num_threads);
	}
}