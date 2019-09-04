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
	for(i = 0; i < SIZE; i++){
		sum += array[i];
	}
	t2 = omp_get_wtime();

	printf("Sum: %d and Time: %f\n", sum, t2-t1); 
	return 0;
}