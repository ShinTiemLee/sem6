__kernel void vector_dec(__global int *A,__global int* C){
	int i=get_global_id(0);
		int res=0;
		int p=1;
	while(A[i]!=0){
		if(A[i]%10==1)
			res=res+p;
		A[i]=A[i]/10;
		p=p*2;
	}
	C[i]=res;
}