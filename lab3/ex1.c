#include"mpi.h"
#include<stdio.h>

int main(int argc, char* argv[]){
	int rank,size,n,A[10],B[10],c,i;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		n=size;
		fprintf(stdout,"Enter %d values: ",n);
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
	}
	MPI_Scatter(A,1,MPI_INT,&c,1,MPI_INT,0,MPI_COMM_WORLD);
	fprintf(stdout,"Received %d in rank %d ",c,rank);
	for(i=c-1;i>0;i--)
		c*=i;
	MPI_Gather(&c,1,MPI_INT,B,1,MPI_INT,0,MPI_COMM_WORLD);
	if(rank==0){
		int sum=0;
		for(i=0;i<n;i++)
			sum+=B[i];
		fprintf(stdout,"Result of summation is:%d",sum);
	}
	MPI_Finalize();
	return 0;
}