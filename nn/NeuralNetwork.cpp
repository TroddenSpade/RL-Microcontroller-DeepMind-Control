// #include "Arduino.h”
#include <math.h>

#include "NeuralNetwork.h"

#include "data/w.h"


nn::nn( activation_function *afs, bool backprop){
	nn::w = weights;
	nn::sh = shape;
	nn::l = sizeof(shape) / sizeof(shape[0]);
	nn::backprop = backprop;
	nn::afs = afs;

	// Allocate Memory for outputs
	nn::allocate(false, backprop);
}

nn::nn(int *shape, int len, activation_function *afs, bool backprop){
	nn::sh = shape;
	nn::l = len;
	nn::backprop = backprop;
	nn::afs = afs;

	// Allocate Memory for weights, biases, and outputs
	nn::allocate(true, backprop);
	// Initialize the weights
	nn::initialize();
}

nn::~nn(){
	free(nn::w);
}

void nn::allocate(bool weights, bool backprop){
	int size = 0;
	int sum = 0;
	int maxi = 0;
	for(int i=0; i<l-1; i++){
		size += sh[i] * sh[i+1];
		sum += sh[i+1];
		if (sh[i+1] > maxi)
			maxi = sh[i+1];
	}

	if(weights){
		nn::w = (float *)malloc(size * sizeof(float));
		nn::b = (float *)malloc(sum * sizeof(float));
	}

	if(backprop){
		nn::a = (float *)malloc(sum * sizeof(float));
		nn::da = (float *)malloc(sum * sizeof(float));
		nn::dw = (float *)malloc(size * sizeof(float));
		nn::db = (float *)malloc(sum * sizeof(float));
	}else{
		nn::a = (float *)malloc(2 * maxi * sizeof(float));
	}
}

void nn::initialize(){
	// randomSeed(42);
	srand(42);

	float *w_ptr = nn::w;
	float *b_ptr = nn::b;
	// weights
	for(int i=0; i<l-1; i++){	
		// calculate the range for the weights
		float lower = (-1.0 / sqrt(sh[i]));
		float upper = (1.0 / sqrt(sh[i]));

		// generate random numbers
		for(int j=0; j<sh[i+1]*sh[i]; j++){
			*w_ptr = (upper - lower) * ((float)(rand() % (int)1e+6) / (int)1e+6)  + lower;
			w_ptr++;
		}
	}
	// biases
	for(int i=1; i<l; i++){
		for(int k=0; k<sh[i]; k++){
			*b_ptr = 0;
			b_ptr++;
		}
	}
}

float* nn::forward(float *in_ptr, bool grad){
	std::cout<< in_ptr[0] << " " << in_ptr[1] << " " << in_ptr[2] << " " << in_ptr[3] << std::endl;

	float *w_ptr = nn::w;
	float *b_ptr = nn::b;
	float *a_ptr = nn::a;

	for(int i=1; i<l; i++){
		for(int j=0; j<sh[i]; j++){
			*a_ptr = 0;
			float *p = in_ptr;
			for(int k=0; k<sh[i-1]; k++){
				*a_ptr += *(w_ptr++) * *(p++);
			}
			*a_ptr = nn::activation_fn(*a_ptr + *(b_ptr++), afs[i-1]);
			a_ptr++;
		}
		in_ptr = a_ptr - sh[i];
		std::cout << in_ptr[0] << " " << in_ptr[1] << std::endl;
		if(!grad || !nn::backprop){
			if(i%2==0)
				a_ptr = nn::a;
		}
	}
	return in_ptr;
}

float nn::loss_fn(float *ptr_out, float*ptr_target){
	switch(loss){
		case MSE:
			return nn::mse_fn(ptr_out, ptr_target);
		case L1:
			return nn::l1_fn(ptr_out, ptr_target);
		default:
			return nn::mse_fn(ptr_out, ptr_target);
	}
}

float nn::mse_fn(float *ptr_out, float*ptr_target){
	float sum = 0;
	for(int i=0; i<sh[l-1]; i++){
		sum += pow(*(ptr_out++) - *(ptr_target++), 2);
	}
	return sum / (2 * sh[l-1]);
}

float nn::l1_fn(float *ptr_out, float*ptr_target){
	float sum = 0;
	for(int i=0; i<sh[l-1]; i++){
		sum += abs(*(ptr_out++) - *(ptr_target++));
	}
	return sum / sh[l-1];
}

float nn::activation_fn(float x, activation_function af){
	switch(af){
		case RELU:
			return nn::relu_fn(x);
		case SIGMOID:
			return nn::sigmoid_fn(x);
		case TANH:
			return nn::tanh_fn(x);
		default:
			return nn::linear_fn(x);
	}
}

float nn::sigmoid_fn(float x){
	return 1.0 / (1.0 + exp(-x));
}

float nn::tanh_fn(float x){
	return tanh(x);
	// return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

float nn::relu_fn(float x){
	return (x > 0) ? x : 0;
}

float nn::linear_fn(float x){
	return x;
}

int nn::save_weights(){
      
    FILE *fptr = fopen("saved_w.txt", "w");
    float *ptr = nn::w;

	for(int i=0; i<l; i++){
		fprintf(fptr, "%d,", sh[i]);
	}
	fprintf(fptr, "\n");

	for(int i=0; i<l-1; i++){		
		// weights
		for(int j=0; j<sh[i+1]; j++){
			for(int k=0; k<sh[i]; k++){
				fprintf(fptr, "%.18e,", *ptr);
				ptr++;
			}
			fprintf(fptr, "\n");
		}
	}
	
	for(int i=0; i<l-1; i++){		
		// biases
		for(int b=0; b<sh[i+1]; b++){
			fprintf(fptr, "%.18e,\n", *ptr);
			ptr++;
		}
	}
	
    fclose(fptr);
    return 0;
}