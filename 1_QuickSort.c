#include<omp.h>
#include<stdio.h>
#define SIZE 8
typedef long long int ll; 
ll A[SIZE] = {11,42,6,12,9,63,4,10};

ll partition(ll low, ll high){
	ll pivot = A[high-1];
	ll i = -1;
	ll j;
	for(j = 0; j < SIZE -1; j++){
		if(A[j] < pivot){
			i++;
			ll temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	i++;
	A[high-1] = A[i];
	A[i] = pivot;
	return i;
}

void qs(ll low, ll high ){
	if(low < high){
		ll p = partition(low, high);

		qs(low,p);
		qs(p+1,high);
	}
}

int main(){
	qs(0,8);
	int i = 0;
	for(;i<SIZE;i++){
		printf("%lld\t",A[i]);
	}	
	printf("\n");
	return 0;
}