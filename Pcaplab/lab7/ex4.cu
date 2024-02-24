#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<stdio.h>

__global__ void add(float *a,float *c){
	int tid = threadIdx.x ;
	int bid=blockIdx.x;
	if(tid==1)
	c[bid]=sin(a[bid]);
}

int main(void){
	float a[100],c[100];
	float *d_a,*d_c;
	int size=sizeof(float)*100;
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter arr A: ");
	for(int i=0;i<n;i++)
		scanf("%f",&a[i]);
	

	cudaMalloc((void**)&d_a,size);
	cudaMalloc((void**)&d_c,size);

	

	cudaMemcpy(d_a,&a,size,cudaMemcpyHostToDevice);
	

	add<<<n,256>>>(d_a,d_c);

	cudaMemcpy(&c,d_c,size,cudaMemcpyDeviceToHost);
	for(int i=0;i<n;i++)
		printf("%f ",c[i]);
	cudaFree(d_a);
	cudaFree(d_c);
	return 0;
}