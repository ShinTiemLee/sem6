#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<stdio.h>

__global__ void add(int *a,int *b,int *c){
	int tid = threadIdx.x ;
	int bid=blockIdx.x;
	if(tid==1)
	c[bid]=a[bid]+b[bid];
}

int main(void){
	int a[100],b[100],c[100];
	int*d_a,*d_b,*d_c;
	int size=sizeof(int)*100;
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter arr A: ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter arr B: ");
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);

	cudaMalloc((void**)&d_a,size);
	cudaMalloc((void**)&d_b,size);
	cudaMalloc((void**)&d_c,size);

	

	cudaMemcpy(d_a,&a,size,cudaMemcpyHostToDevice);
	cudaMemcpy(d_b,&b,size,cudaMemcpyHostToDevice);

	add<<<n,256>>>(d_a,d_b,d_c);

	cudaMemcpy(&c,d_c,size,cudaMemcpyDeviceToHost);
	for(int i=0;i<n;i++)
		printf("%d ",c[i]);
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
	return 0;
}