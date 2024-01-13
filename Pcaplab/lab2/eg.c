#include<mpi.h>
#include<stdio.h>
int main(int argc,char* argv[]){
    int rank,size,x;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;
    if(rank==0){
        printf("Enter value in Master process\n");
        scanf("%d",&x);
        MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);
        fprintf(stdout,"sent %d from process0\n",x);
        fflush(stdout);
    }
    else{
        MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        fprintf(stdout,"received %d in process1",x);
        fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}