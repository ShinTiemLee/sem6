#include<mpi.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    int rank,size,x;
    int  bufsize=MPI_BSEND_OVERHEAD + sizeof(int); 
    int *buf = (int*)malloc(bufsize);
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;
    int arr[size];
    if(rank==0){
        printf("Enter array of size %d in Master process\n",size);
        for(int i=0;i<size;i++)
            scanf("%d",&arr[i]);
        MPI_Buffer_attach( buf, bufsize );
        for(int i=1;i<size;i++){
            MPI_Bsend(&arr[i],1,MPI_INT,i,1,MPI_COMM_WORLD);
        }
        fflush(stdout);
    }
    else if(rank%2==0){
        MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        MPI_Buffer_detach( &buf, &bufsize ); 
        fprintf(stdout,"\nreceived %0.f in process%d",pow(x,2),rank);
        fflush(stdout);
    }
    else {
        MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        MPI_Buffer_detach( &buf, &bufsize ); 
        fprintf(stdout,"\nreceived %0.f in process%d",pow(x,3),rank);
        fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}