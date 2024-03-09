#include"cuda_runtime.h"
#include"device_launch_parameters.h"
#include<stdio.h>
#include<stdlib.h>

__global__ void rowadd(int *a,int *b,int* t){
	int tid=threadIdx.x,bid=blockIdx.x,width=gridDim.x;
	if(bid==0){
	for(int i=0;i<width;i++)
		t[tid*width+i]=a[tid*width+i]+b[tid*width+i];
		}
}

__global__ void coladd(int *a,int *b,int* t){
	int tid=threadIdx.x,bid=blockIdx.x,width=blockDim.x;
	if(bid==0){
	for(int i=0;i<width;i++)
		t[tid+width*i]=a[tid+width*i]+b[tid+width*i];
	}
}

__global__ void add(int *a,int *b,int* t){
	int tid=threadIdx.x,bid=blockIdx.x,width=blockDim.x;

	t[tid+width*bid]=a[tid+width*bid]+b[tid+width*bid];
		
}

int main(){
int *a,*t,*b,m,n,i,j;
int *d_a,*d_t,*d_b;
printf("Enter value of m: ");
scanf("%d",&m);
printf("Enter value of n: ");
scanf("%d",&n);
int size=sizeof(int)*m*n;
a=(int*)malloc(size);
b=(int*)malloc(size);
t=(int*)malloc(size);
printf("Enter input matrixA:\n");
for(i=0;i<m*n;i++)
	scanf("%d",&a[i]);
printf("Enter input matrixB:\n");
for(i=0;i<m*n;i++)
	scanf("%d",&b[i]);
cudaMalloc((void**)&d_a,size);
cudaMalloc((void**)&d_t,size);
cudaMalloc((void**)&d_b,size);
cudaMemcpy(d_a,a,size,cudaMemcpyHostToDevice);
cudaMemcpy(d_b,b,size,cudaMemcpyHostToDevice);
cudaMemcpy(d_t,t,size,cudaMemcpyHostToDevice);
rowadd<<<n,m>>>(d_a,d_b,d_t);
cudaMemcpy(t,d_t,size,cudaMemcpyDeviceToHost);
printf("Result:\n");
for(i=0;i<m;i++){
	for(j=0;j<n;j++)
		printf("%d\t",t[i*n+j]);
	printf("\n");
}

coladd<<<m,n>>>(d_a,d_b,d_t);
cudaMemcpy(t,d_t,size,cudaMemcpyDeviceToHost);
printf("Result:\n");
for(i=0;i<m;i++){
	for(j=0;j<n;j++)
		printf("%d\t",t[i*n+j]);
	printf("\n");
}

add<<<m,n>>>(d_a,d_b,d_t);
cudaMemcpy(t,d_t,size,cudaMemcpyDeviceToHost);
printf("Result:\n");
for(i=0;i<m;i++){
	for(j=0;j<n;j++)
		printf("%d\t",t[i*n+j]);
	printf("\n");
}

cudaFree(d_a);
cudaFree(d_t);
return 0;
}