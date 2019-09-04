#include<omp.h>
#include<stdio.h>
#define SIZE 10000000
int array[SIZE];

int main(){

	int i = 0;
	for(i = 0; i < SIZE; i++){
		array[i] = 1;
	}

	double t1,t2;
	int sum = 0;
	t1 = omp_get_wtime();
	#pragma omp parallel default(shared)
	{
		int psum = 0;
		#pragma omp for
		for(i = 0; i < SIZE; i++){
			psum += array[i];
		}
		#pragma omp critical
		sum += psum;
	}
	t2 = omp_get_wtime();

	printf("Sum: %d and Time: %f\n", sum, t2-t1); 
	return 0;
}