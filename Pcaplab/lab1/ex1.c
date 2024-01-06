#include"mpi.h"
#include<stdio.h>
#include<math.h>

int main(int argc,char* argv[]){
	const int x=10;
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	double d=pow(x,rank);
	printf("Rank %d has x=%f",rank,d);
	MPI_Finalize();
	return 0;
}