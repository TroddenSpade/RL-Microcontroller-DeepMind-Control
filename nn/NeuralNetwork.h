#ifndef NeuralNetwork_h
#define NeuralNetwork_h

// #include "Arduino.h" 


enum activation_function {
    SIGMOID,
    TANH,
    RELU,
    LINEAR
};

enum loss_function {
    L1,
    MSE,

}


class nn {
    public:
        // load network constructor
        nn(activation_function *afs, loss_function ls=MSE, bool backprop=false);
        // new network constructor
        nn(int shape[], int len, activation_function *afs, loss_function ls=MSE, bool backprop=false);
        // network destructor
        ~nn();

        float* forward(float *input, bool grad=false);
        // void backward();

        // saves the network's weights and biases (only in Test Mode)
        int save_weights();

    private:
        // initializes the network's weights and biases
        void initialize();
        void allocate(bool weights, bool backprop);
        float loss_fn(float *ptr_out, float*ptr_target);
        float mse_fn(float *ptr_out, float*ptr_target);
        float l1_fn(float *ptr_out, float*ptr_target);

        float activation_fn(float x, activation_function af);
        float sigmoid_fn(float x);
        float tanh_fn(float x);
        float relu_fn(float x);
        float linear_fn(float x);

        loss_function lf;                                       // loss function
        activation_function *afs;                               // activation functions for each layer
        bool backprop;                                          // whether or not to backpropagate
        int *sh;                                                // shape of network
        int l;                                                  // length of the shape of network
        float *w;                                               // weights
        float *b;                                               // biases
        float *a;                                               // activation outputs (output of layers)
                                                                // (if backprop==true all of the outputs will be saved;
                                                                // otherwise, we will only store two layers for forward pass)

        float *dw;                                              // derivatives with respect to weights (backprop=true)
        float *db;                                              // derivatives with respect to biases (backprop=true)
        float *da;                                              // derivatives with respect to output of the layers (backprop=true)

};

#endif