#include"mpi.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char* argv[]){
	int rank,size,n,A[10],c,i,m,count;
	char str[100],strr[100],str1[50],str2[50],fstr[200];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==0){
		n=size;
		fprintf(stdout,"Enter string divisible by %d: ",n);
		fflush(stdout);
		fgets(str,100,stdin);
		fprintf(stdout,"Enter string divisible by %d: ",n);
		fflush(stdout);
		fgets(strr,100,stdin);
		m=strlen(str)/n;
	}
	MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(str,m,MPI_CHAR,str1,m,MPI_CHAR,0,MPI_COMM_WORLD);
	MPI_Scatter(strr,m,MPI_CHAR,str2,m,MPI_CHAR,0,MPI_COMM_WORLD);
	fprintf(stdout,"Received in rank %d: ",rank);
	for(i=0;i<m;i++)
		fprintf(stdout,"%c ",str1[i]);
	for(i=0;i<m;i++)
		fprintf(stdout,"%c ",str2[i]);
	i=0;
	for(int j=0;j<m;j++){
		str[i++]=str1[j];
		str[i++]=str2[j];
	}
	str[i]='\0';
	fflush(stdout);
	MPI_Gather(str,2*m,MPI_CHAR,fstr,2*m,MPI_CHAR,0,MPI_COMM_WORLD);
	if(rank==0){
		
		fprintf(stdout,"Final string\n%s ",fstr);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}