#include <time.h>
#include <math.h>

#include "NeuralNetwork.h"


nn::nn(Layer *layers, int length){
    nn::l = length;
    nn::layers = layers;
    
	// Allocate Memory for weights, biases, and outputs
	nn::allocate();
	// Initialize the weights
	nn::initialize();
}

nn::~nn(){
	free(nn::w);
}

static Layer nn::Linear(int input, int output, activation_function af, char* name){
	return {input, output, af, name};
}

static Layer nn::Linear(int input, int output, activation_function af){
	char name[20];
	sprintf(name, "layer_%d", (int)time(NULL));
	return {input, output, af, name};
}

void nn::allocate(){
	nn::size_w = 0;
	nn::size_b = 0;
	int size_max = 0;

	for(int i=0; i<nn::l; i++){
		if (nn::layers[i].output > size_max) size_max = nn::layers[i].output;

		nn::size_w += nn::layers[i].input * nn::layers[i].output;
        nn::size_b += nn::layers[i].output;
	}

    nn::w = (float *)malloc(nn::size_w * sizeof(float));
    nn::b = (float *)malloc(nn::size_b * sizeof(float));
    nn::a = (float *)malloc(2 * size_max * sizeof(float));
}

void nn::initialize(){
	// randomSeed(42);
	srand(42);

	float *w_ptr = nn::w;
	float *b_ptr = nn::b;

	for(int i=0; i<nn::l; i++){	
		// calculate the range for the weights
		float lower = (-1.0 / sqrt(nn::layers[i].input));
		float upper = (1.0 / sqrt(nn::layers[i].input));

		// generate random numbers for the weights
		for(int j=0; j<nn::layers[i].input*nn::layers[i].output; j++){
			*w_ptr = (upper - lower) * ((float)(rand() % (int)1e+6) / (int)1e+6) + lower;
			w_ptr++;
		}

		// generate random numbers for the biases
		for(int j=0; j<nn::layers[i].output; j++){
			*b_ptr = 0;
			b_ptr++;
		}
	}
}

float* nn::forward(float *in_ptr){

	float *w_ptr = nn::w;
	float *b_ptr = nn::b;
	float *a_ptr = nn::a;

	for(int i=0; i<nn::l; i++){
		for(int j=0; j<nn::layers[i].output; j++){
			
			*a_ptr = 0;
			float *p = in_ptr;
			for(int k=0; k<nn::layers[i].input; k++){
				*a_ptr += *(w_ptr++) * *(p++);
			}
			*a_ptr = nn::activation_fn(*a_ptr + *(b_ptr++), nn::layers[i].af);
			a_ptr++;
		}
		in_ptr = a_ptr - nn::layers[i].output;
		if(i%2==1)
			a_ptr = nn::a;

	}
	return in_ptr;
}


int nn::update_param(float new_value, int idx, bool is_bias){
	float *ptr = is_bias ? nn::b : nn::w;
	ptr[idx] = new_value;
	return 0;
}


float nn::activation_fn(float x, activation_function af){
	switch(af){
		case ReLU:
			return nn::relu_fn(x);
		case Sigmoid:
			return nn::sigmoid_fn(x);
		case Tanh:
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


int nn::print_params(Stream &serialport){
    float *ptr = nn::w;
	float *b_ptr = nn::b;

	for(int i=0; i<nn::l; i++){
		serialport.println("Layer: " + String(nn::layers[i].name));

		// weights
		serialport.println("Weights:");
		for(int j=0; j<nn::layers[i].output; j++){
			for(int k=0; k<nn::layers[i].input; k++){
				serialport.print(String(*(ptr++)) + " ");
			}
			serialport.println();
		}

		// biases
		serialport.println("Biases:");
		for(int j=0; j<nn::layers[i].output; j++){
			serialport.println(*(b_ptr++));
		}
	}
	
  return 0;
}

int nn::read_params(Stream &serialport){
    for(int i=0; i<nn::size_w; i++){        
        while(!serialport.available());

        float new_value = serialport.readString().toFloat();
        nn::update_param(new_value, i, false);
        serialport.println();
    }

    for(int i=0; i<nn::size_b; i++){
        while(!serialport.available());

        float new_value = serialport.readString().toFloat();
        nn::update_param(new_value, i, true);
        serialport.println();
    }

    return 0;
}