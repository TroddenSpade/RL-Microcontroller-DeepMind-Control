// #include <arduino.h>
#include <iostream>

#include "NeuralNetwork.cpp"

int main() {
    int shape[] = {4, 2, 2, 2};
    int len = 4;
    activation_function afs[] = {SIGMOID, SIGMOID, SIGMOID};

    nn net(shape, len, afs);
    std::cout << "Hello World" << std::endl;
    net.save_weights();
    float input[] = {1.2, 2.3, 3.4, 4.5};
    float* out = net.forward(input);

    std::cout << out[0] << " " << out[1] << " " << std::endl;
    return 0;
}