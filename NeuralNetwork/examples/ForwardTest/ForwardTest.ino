#include <NeuralNetwork.h>

int len = 2;
Layer layers[] = {
    nn::Linear(5, 32, Tanh),
    nn::Linear(32, 2, None)
};
nn network(layers, len);


void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(LED_BUILTIN, LOW);
    float inputs[5][5];

    Serial.println("reading inputs...");
    for(int i=0; i<5; i++){    
        for(int j=0; j<5; j++){
            while(!Serial.available());
            inputs[i][j] = Serial.readString().toFloat();
            Serial.println();
        }    
    }

    Serial.println("reading weights...");
    network.read_params(Serial);
    Serial.println("done.");

    digitalWrite(LED_BUILTIN, HIGH);
    while(!Serial.available());
    
    for(int i=0; i<5; i++){
        float *outputs = network.forward(inputs[i]);
        Serial.print(inputs[i][0]);
        Serial.print(" ");
        Serial.print(inputs[i][1]);
        Serial.print(" ");
        Serial.print(inputs[i][2]);
        Serial.print(" ");
        Serial.print(inputs[i][3]);
        Serial.print(" ");
        Serial.println(inputs[i][4]);
        
        Serial.print(*(outputs++));
        Serial.print(" ");
        Serial.println(*(outputs));
    }
}
