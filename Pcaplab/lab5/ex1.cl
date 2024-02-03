__kernel void vector_octal(__global int *A,__global int* C){
	int i=get_global_id(0);
		int oct=0;
		int p=1;
	while(A[i]!=0){
		oct=oct+(A[i]%8)*p;
		A[i]=A[i]/8;
		p=p*10;
	}
	C[i]=oct;
}