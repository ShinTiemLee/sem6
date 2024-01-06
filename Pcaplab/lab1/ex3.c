#include"mpi.h"
#include<stdio.h>
#include<math.h>

int main(int argc,char* argv[]){
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int op1=5;
	int op2=10;
	switch(rank){
	case 0:
		printf("rank %d: %d + %d = %d",rank,op1,op2,op1+op2);
		break;
	case 1:
	
		printf("rank %d: %d - %d = %d",rank,op1,op2,op1-op2);
		break;
	case 2:
		
		printf("rank %d: %d / %d = %f",rank,op1,op2,(float)op1/(float)op2);
		break;
	case 3:
		
		printf("rank %d: %d * %d = %d",rank,op1,op2,op1*op2);
		break;
	default:printf("ERROR");
		break;

	}
	MPI_Finalize();
	return 0;
}