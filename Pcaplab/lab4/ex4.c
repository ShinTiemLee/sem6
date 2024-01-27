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
	int size,rank,i,ierr;
	int mat[4][4];
	int sum[4],tsum[4];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
	if(rank==0){
		fprintf(stdout,"Enter a 4x4 matrix: ");
		for(i=0;i<4;i++){
			for(int j=0;j<4;j++)
				scanf("%d",&mat[i][j]);
		}
	}
	MPI_Scatter(mat,4,MPI_INT,&sum,4,MPI_INT,0,MPI_COMM_WORLD);

	ierr=MPI_Scan(&sum,&tsum,4,MPI_FLOAT,MPI_SUM,MPI_COMM_WORLD);
	error(ierr);
	//MPI_Barrier(MPI_COMM_WORLD);
	for(i=0;i<4;i++)
		fprintf(stdout,"%d ",tsum[i]);
	fprintf(stdout,"\n");
	MPI_Finalize();
	return 0;

}