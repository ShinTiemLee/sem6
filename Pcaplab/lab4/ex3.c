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
	int size,rank,i,ierr,count=0,key,tcount;
	int mat[3][3];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
	if(rank==0){
		fprintf(stdout,"Enter a 3x3 matrix: ");
		for(i=0;i<3;i++){
			for(int j=0;j<3;j++)
				scanf("%d",&mat[i][j]);
		}
		fprintf(stdout,"Enter key: ");
		scanf("%d",&key);
	}
	MPI_Bcast(mat,9,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&key,1,MPI_INT,0,MPI_COMM_WORLD);
	
	for(i=0;i<3;i++){
		if(key==mat[rank][i])
			count++;
	}

	ierr=MPI_Scan(&count,&tcount,1,MPI_FLOAT,MPI_SUM,MPI_COMM_WORLD);
	error(ierr);
	fprintf(stdout,"\nRank %d has current count %d",rank,tcount);
	MPI_Finalize();
	return 0;

}