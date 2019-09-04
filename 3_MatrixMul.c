#include<omp.h>
#include<stdio.h>
#define m 1024
#define n 124
#define p 3
int main()
{
	int A[m][n];
	int B[n][n];
	int D[n][p];
	long long int temp[m][n];
	long long int C[m][p] = {0};


	double t1,t2;
	t1 = omp_get_wtime();
	int i = 0;
	int j = 0, k = 0;
	
	for(i = 0; i < m; i++){
		for( j = 0; j < n; j++){
			A[i][j] = 11 + j;
		}
	}

	for(i = 0; i < n; i++){
		for( j = 0; j < n; j++){
			B[i][j] = i + j;
		}
	}

	for(i = 0; i < n; i++){
		for( j = 0; j < p; j++){
			D[i][j] = 1;
		}
	}

	#pragma omp parallel default(shared) private(i,j,k) num_threads(6)
	{
		#pragma omp for
		for( i = 0; i < m ; i++){ 
			for( j = 0; j < n; j++){
				for( k = 0; k < n; k++){
					temp[i][j] += A[i][k] * B[k][j];
				}
			}
		}

		#pragma omp barrier

		#pragma omp for
		for( i = 0; i < m ; i++){ 
			for( j = 0; j < p; j++){
				for( k = 0; k < n; k++){
					C[i][j] += temp[i][k] * D[k][j];
				}
			}
		}
	}

	for(i = 0; i < m; i++){
		for( j = 0; j < n; j++){
			printf("%lld\t",C[i][j]);
		}
		printf("\n");
	}
	t2 = omp_get_wtime();
	printf("Time:%f\n", t2-t1);
}