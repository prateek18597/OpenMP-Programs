#include<omp.h>
#include<stdio.h>

static int numt;
static int tid;
#pragma omp threadprivate(tid)
int main(){

	#pragma omp parallel num_threads(3)
	{
		printf("Hello: A(tid)= %p A(numt)= %p\n",&tid, &numt);
	}

	#pragma omp parallel num_threads(2)
	{
		printf("\tHello: A(tid)= %p A(numt)= %p\n",&tid, &numt);
	}

	#pragma omp parallel num_threads(4)
	{
		printf("\t\tHello: A(tid)= %p A(numt)= %p\n",&tid, &numt);
	}
}