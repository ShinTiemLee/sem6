#include"mpi.h"
#include<stdio.h>
#include<math.h>

int main(int argc,char* argv[]){
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	char str[]="Tech";
	switch(rank){
	case 0: if(str[rank]<97)
				str[rank]+=32;
			else
				str[rank]-=32;
			printf("\nRank %d: %s",rank,str);
			break;
	case 1: if(str[rank]<97)
				str[rank]+=32;
			else
				str[rank]-=32;
			printf("\nRank %d: %s",rank,str);
			break;
	case 2: if(str[rank]<97)
				str[rank]+=32;
			else
				str[rank]-=32;
			printf("\nRank %d: %s",rank,str);
			break;
	case 3: if(str[rank]<97)
				str[rank]+=32;
			else
				str[rank]-=32;
			printf("\nRank %d: %s",rank,str);
			break;
	default: printf("Error");
	
	}
	MPI_Finalize();
	return 0;
}