#include<stdio.h>
#include"mpi.h"

void error(int ierr){
	int errclass,resultlen;
	char err_buffer[MPI_MAX_ERROR_STRING];

    if (ierr != MPI_SUCCESS) {
       MPI_Error_class(ierr,&errclass);
       MPI_Error_string(ierr,err_buffer,&resultlen);
       fprintf(stderr,"%s",err_buffer);
       MPI_Finalize();             
    }
}

int main(int argc,char* argv[]){
	int size,rank,fact=1,factsum,i,ierr;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
	for(i=1;i<=rank+1;i++){
		fact*=i;
	}
	ierr= MPI_Send(&i, 1, MPI_REAL, 10, 1,MPI_COMM_WORLD);
	error(ierr);
	ierr=MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
	error(ierr);
	fprintf(stdout,"\nRank %d has current sum %d",rank,factsum);
	MPI_Finalize();
	return 0;

}