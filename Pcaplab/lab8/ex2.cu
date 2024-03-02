#include"cuda_runtime.h"
#include"device_launch_parameters.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define N 1024

__global__ void CUDACount(char* A,char* RS, int *d_countA){
	int i=threadIdx.x;
	int sum=0;
	for(int x=0;x<=i;x++)
		sum+=(*d_countA-1-x);
	for(int j=0;j<(*d_countA-i-1);j++){
		RS[sum+j]=A[j];
	}
}

int main(){
	char A[N],RS[N];
	char *d_A,*d_RS;
	int *d_countA;
	printf("Enter a string: ");
	fgets(A,N,stdin);
	cudaEvent_t start,stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaEventRecord(start,0);
	int len1=strlen(A);
	cudaMalloc((void**)&d_A,strlen(A)*sizeof(char));
	cudaMalloc((void**)&d_RS,strlen(RS)*sizeof(char));
	cudaMalloc((void**)&d_countA,sizeof(int));
	cudaMemcpy(d_A,A,strlen(A)*sizeof(char),cudaMemcpyHostToDevice);
	cudaMemcpy(d_RS,RS,strlen(RS)*sizeof(char),cudaMemcpyHostToDevice);
	cudaMemcpy(d_countA,&len1,sizeof(int),cudaMemcpyHostToDevice);
	

	cudaError_t error=cudaGetLastError();
	if(error!=cudaSuccess){
	printf("CUDA ERROR1: %s\n",cudaGetErrorString(error));
	}
	CUDACount<<<1,strlen(A)>>>(d_A,d_RS,d_countA);
	error=cudaGetLastError();
	if(error!=cudaSuccess){
	printf("CUDA ERROR2: %s\n",cudaGetErrorString(error));
	}
	cudaEventRecord(stop,0);
	cudaEventSynchronize(stop);
	float elapsedTime;
	cudaEventElapsedTime(&elapsedTime,start,stop);
	cudaMemcpy(RS,d_RS,strlen(RS)*sizeof(char),cudaMemcpyDeviceToHost);
	printf("RS = %s",RS);
	printf("TimeTaken=%f",elapsedTime);
	cudaFree(d_A);
	
	return 0;
}