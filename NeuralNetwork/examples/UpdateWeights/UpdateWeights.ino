#include <NeuralNetwork.h>

int len = 2;
Layer layers[] = {
    nn::Linear(5, 32, ReLU),
    nn::Linear(32, 2, None)
};

nn network(layers, len);


void setup() {
    Serial.begin(9600);
}


void loop() {
    // put your main code here, to run repeatedly:
    
    while(!Serial.available());

    float new_value = Serial.readString().toFloat();

    network.update_param(new_value, 0, false);

    network.print_params(Serial);
}
