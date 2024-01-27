#include"mpi.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char* argv[]){
	int rank,size,n,A[10],c,i,m,count;
	char str[100],str1[50];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		n=size;
		fprintf(stdout,"Enter string divisible by %d: ",n);
		fflush(stdout);
		fgets(str,100,stdin);
		m=strlen(str)/n;
	}
	MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(str,m,MPI_CHAR,str1,m,MPI_CHAR,0,MPI_COMM_WORLD);
	fprintf(stdout,"Received in rank %d: ",rank);
	for(i=0;i<m;i++)
		fprintf(stdout,"%c ",str1[i]);
	fflush(stdout);
	count=0;
	for(i=0;i<m;i++){
		if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u')
			continue;
		if(isalpha(str1[i]))
			count++;
	}
	MPI_Gather(&count,1,MPI_INT,A,1,MPI_INT,0,MPI_COMM_WORLD);
	if(rank==0){
		
		for(i=0;i<n;i++)
			fprintf(stdout,"A[%d]=\n%d ",i,A[i]);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}