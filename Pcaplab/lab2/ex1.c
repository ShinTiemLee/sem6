#include"mpi.h"
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    int rank,size;
    char* word=(char*)malloc(sizeof(char)*50);
    //char word[50];
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;
    if(rank==0){
        printf("Enter word in Master process\n");
        scanf("%s",word);
        MPI_Ssend(word,sizeof(word),MPI_CHAR,1,1,MPI_COMM_WORLD);
        fprintf(stdout,"sent %s from process0\n",word);
        fflush(stdout);
        MPI_Recv(word,sizeof(word),MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
        fprintf(stdout,"received %s in process0\n",word);
        fflush(stdout);
    }
    else{
        MPI_Recv(word,sizeof(word),MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
        fprintf(stdout,"received %s in process1\n",word);
        fflush(stdout);
        for(int i=0;i<sizeof(word);i++){
            if(islower(word[i]))
                word[i]=toupper(word[i]);
            else
                word[i]=tolower(word[i]);
        }
        MPI_Ssend(word,sizeof(word),MPI_CHAR,0,1,MPI_COMM_WORLD);
        fprintf(stdout,"sent %s from process1\n",word);
        fflush(stdout);
    }
    MPI_Finalize();
    return 0;
}