#include<omp.h>
#include<stdio.h>

static int g;
#pragma omp threadprivate(g)

int main(){
	int sh =100,g = 10;
	printf( "Hello sh=%d, glb_tp=%d\n", sh, g ) ;
	#pragma omp parallel
	{
		#pragma omp critical
		printf( "Hello from %d of %d. A(g)=%p, g=%d\n",
		omp_get_thread_num(), omp_get_num_threads(), &g, ++g ) ;
	}

	printf( "Hello sh=%d, g=%d\n", sh, g ) ;
	
	return 0 ;
}