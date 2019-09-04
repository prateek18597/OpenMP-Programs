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
	int tid, numt;

	t1 = omp_get_wtime();
	#pragma omp parallel default(shared) private(tid)
	{
		tid = omp_get_thread_num();
		numt = omp_get_num_threads();
		
		for(i = 0; i < SIZE; i++){
			#pragma omp critical
			{
				sum += array[i];
				i++;
			}
		}
	}
	t2 = omp_get_wtime();

	printf("Sum: %d and Time: %f\n", sum, t2-t1); 
	return 0;
}