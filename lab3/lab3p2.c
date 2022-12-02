//#include <stdio.h>

void get_pair(int *input_data,int num_data); 
int mul_op(int i, int j); 
int raise2pwr(int num, int power ); 

void main() { 
	int input_array[6]={2,4,5,3,6,2}; 
	int num_pairs = 3; 
	get_pair(input_array,num_pairs); 
}

void get_pair(int *input_data,int num_data) {
	int x; 
	int output_data; 
	for (x=1; x<=num_data; x++) { 
		output_data = raise2pwr(*input_data, *(input_data+1)); 
		//printf("output data is %d\n",output_data); 
		input_data+=2; 
	} 
}

int raise2pwr(int num, int power ) { 
	int i; 
	int result = 1; 
	for (i=1; i<=power; i++) 
		result = mul_op(result,num); 
	return result; 
} 

//int mul_op(int i, int j) { return i*j; }
int mul_op(int i, int j) {
	int k = i;
	while(j > 1){
		k += i;
		j--;
	} 
	return k; 
}


