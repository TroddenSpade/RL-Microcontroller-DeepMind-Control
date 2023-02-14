#include <NeuralNetwork.h>

void setup() {
    int len = 2;
    Layer layers[] = {
        nn::Linear(5, 32, ReLU),
        nn::Linear(32, 2, None)
    };
    
    nn network(layers, len);

    Serial.begin(9600);
    network.print_params(Serial);

}

void loop() {
    // put your main code here, to run repeatedly:
}
