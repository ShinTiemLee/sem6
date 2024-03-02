#include"cuda_runtime.h"
#include"device_launch_parameters.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define N 1024

__global__ void CUDACount(char* A,char* word,int *d_countA,int *d_countword,unsigned int *d_count){
	int i=threadIdx.x;
	if(i<=(*d_countA-*d_countword)){
		int flag=0;
		for(int j=0;j<*d_countword-1;j++){
			if(A[i]!=word[j]){
				flag=1;
				break;
			}
			i++;
		}
		if(flag==0)
			atomicAdd(d_count,1);
	}
}

int main(){
	char A[N],word[20];
	char *d_A,*d_word;
	unsigned int *count=0,*d_count,result;
	int *d_countA,*d_countword;
	printf("Enter a string: ");
	fgets(A,N,stdin);
	printf("Enter word to count: ");
	fgets(word,20,stdin);
	cudaEvent_t start,stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaEventRecord(start,0);
	cudaMalloc((void**)&d_A,strlen(A)*sizeof(char));
	cudaMalloc((void**)&d_word,strlen(word)*sizeof(char));
	cudaMalloc((void**)&d_countA,sizeof(int));
	cudaMalloc((void**)&d_countword,sizeof(int));
	cudaMalloc((void**)&d_count,sizeof(unsigned int));
	int len1=strlen(A);
	int len2=strlen(word);
	cudaMemcpy(d_A,A,strlen(A)*sizeof(char),cudaMemcpyHostToDevice);
	cudaMemcpy(d_word,word,strlen(word)*sizeof(char),cudaMemcpyHostToDevice);
	cudaMemcpy(d_countA,&len1,sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(d_countword,&len2,sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(d_count,&count,sizeof(unsigned int),cudaMemcpyHostToDevice);

	cudaError_t error=cudaGetLastError();
	if(error!=cudaSuccess){
	printf("CUDA ERROR1: %s\n",cudaGetErrorString(error));
	}
	CUDACount<<<1,strlen(A)>>>(d_A,d_word,d_countA,d_countword,d_count);
	error=cudaGetLastError();
	if(error!=cudaSuccess){
	printf("CUDA ERROR2: %s\n",cudaGetErrorString(error));
	}
	cudaEventRecord(stop,0);
	cudaEventSynchronize(stop);
	float elapsedTime;
	cudaEventElapsedTime(&elapsedTime,start,stop);
	cudaMemcpy(&result,d_count,sizeof(unsigned int),cudaMemcpyDeviceToHost);
	printf("Total occurences of %s=%u",word,result);
	printf("TimeTaken=%f",elapsedTime);
	cudaFree(d_A);
	cudaFree(d_count);
	return 0;
}