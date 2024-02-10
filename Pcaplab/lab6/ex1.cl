__kernel void repeat(__global char* s,__global char* x, int n,int len){
	int i=get_global_id(0);
	for(int j=0;j<len;j++){
		x[i*len+j]=s[j];
	}

}