__kernel void vector_swap(__global int *A){
	int i=get_global_id(0);
	if(i%2==0){
	int temp=A[i];
	A[i]=A[i+1];
	A[i+1]=temp;
}
}