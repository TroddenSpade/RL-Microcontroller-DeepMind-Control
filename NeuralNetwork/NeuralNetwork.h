#ifndef NeuralNetwork_h
#define NeuralNetwork_h

#include <Arduino.h>


enum activation_function {
    Sigmoid,
    Tanh,
    ReLU,
    None
};

typedef struct{
    int input;
    int output;
    activation_function af;
    char* name;
}Layer;


class nn {
    public:
        // new network constructor
        nn(Layer *layers, int length);
        // network destructor
        ~nn();

        // feed forward
        float* forward(float *input);
        // void backward();

        // update weights and biases
        int update_param(float new_value, int idx, bool is_bias);

        // print weights and biases
        int print_params(Stream &serialport);

        int read_params(Stream &serialport);
        

        static Layer Linear(int input, int output, activation_function af);
        static Layer Linear(int input, int output, activation_function af, char* name);

    private:
        // initializes the network's weights and biases
        void initialize();
        void allocate();

        float activation_fn(float x, activation_function af);
        float sigmoid_fn(float x);
        float tanh_fn(float x);
        float relu_fn(float x);
        float linear_fn(float x);

        int l;                                                  // length of the shape of network
        int size_w;
        int size_b;
        float *w;                                               // weights
        float *b;                                               // biases
        float *a;                                               // activations
		    Layer *layers;
};



#endif