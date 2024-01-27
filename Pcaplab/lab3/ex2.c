#include"mpi.h"
#include<stdio.h>

int main(int argc, char* argv[]){
	int rank,size,n,A[100],B[10],c,i,m;
	float C[10];
	float mean,sum, mean_final=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		fprintf(stdout,"Enter value of m: ");
		scanf("%d",&m);
		n=size;
		fprintf(stdout,"Enter %d values: ",n*m);
		fflush(stdout);
		for(i=0;i<n*m;i++)
			scanf("%d",&A[i]);
	}
	MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(A,m,MPI_INT,B,m,MPI_INT,0,MPI_COMM_WORLD);
	fprintf(stdout,"Received in rank %d: ",rank);
	for(i=0;i<m;i++)
		fprintf(stdout,"%d ",B[i]);
	fflush(stdout);
	sum=0;
	for(i=0;i<m;i++)
		sum+=B[i];
	mean=sum/m;
	fprintf(stdout,"rank=%d mean=%f ",rank, mean);
	MPI_Gather(&mean,1,MPI_FLOAT,C,1,MPI_FLOAT,0,MPI_COMM_WORLD);
	if(rank==0){
		//mean_final=0;
		for(i=0;i<n;i++)
			fprintf(stdout,"c[%d]=\n%f ",i,C[i]);
		fflush(stdout);
		for(i=0;i<n;i++)
			mean_final+=C[i];
		mean_final/=n;
		fprintf(stdout,"Result of mean is:%f",mean_final);
	}
	MPI_Finalize();
	return 0;
}