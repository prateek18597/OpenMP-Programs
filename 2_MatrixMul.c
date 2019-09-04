#include<omp.h>
#include<stdio.h>
#define m 3
#define n 3

int main()
{
	int A[m][n] = {{11,12,13},{11,12,13},{11,12,13}};
	int B[n][m] = {{43,4,25},{87,21,56},{32,64,78}};
	int C[m][m] = {0};
	double t1,t2;
	t1 = omp_get_wtime();
	int i = 0;
	int j = 0, k = 0;
	for( i = 0; i < m ; i++){
		for( j = 0; j < n; j++){
			for( k = 0; k < n; k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}

	for(i = 0; i < m; i++){
		for( j = 0; j < m; j++){
			printf("%d\t",C[i][j]);
		}
		printf("\n");
	}
	t2 = omp_get_wtime();
	printf("Time:%f\n", t2-t1);
}