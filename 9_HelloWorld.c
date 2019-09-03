#include<omp.h>
#include<stdio.h>

int main(){
	int x;
	printf("Enter a number:");
	scanf("%d",&x);

	#pragma omp parallel shared(x) if(x%2==0)
	{
		int tid = omp_get_thread_num();
		printf("Hello World! : %d\n", tid);
	}

	#pragma omp parallel shared(x) if(x%2==1)
	{
		int tid = omp_get_thread_num();
		printf("Bye World! : %d\n", tid);
	}
	return 0;
}