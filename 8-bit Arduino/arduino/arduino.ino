#include <NeuralNetwork.h>

#define IN_LEN 4
#define OUT_LEN 2

typedef enum {RANDOM, UPDATE, COLLECT} State;
State state = UPDATE;

int len = 2;
Layer layers[] = {
    nn::Linear(IN_LEN, 32, Tanh),
    nn::Linear(32, OUT_LEN, None)
};
nn network(layers, len);

String str = "";


void read_inputs(String str, float *input, int len){
	int idx = str.indexOf(';');
	str = str.substring(0, idx);
    for(int i=0; i<len-1; i++){
        int idx = str.indexOf(' ');
        input[i] = str.substring(0, idx).toFloat();
        str = str.substring(++idx, str.length());
    }
  	input[len-1] = str.toFloat();
}


String write_outputs(float *ptr, int len){
    String out = "";
    for(int i=0; i<len; i++){
      	char buff[20];
      	dtostrf(ptr[i], 1, 6, buff);
    	out += buff;
      	out += (i == len-1 ? "" : " "); 
    }
    return out;
}


void setup(){
	pinMode(LED_BUILTIN, OUTPUT);
    Serial3.begin(115200);
	Serial.begin(115200);

	digitalWrite(LED_BUILTIN, HIGH);
	
	//connect to the wifi
	while(!Serial3.available());
	str = Serial3.read();
	Serial.println(str);
		
	while(!Serial3.available());
	str = Serial3.read();
	Serial.println(str);
	
    digitalWrite(LED_BUILTIN, LOW);
}


void loop() {
	
	// get the state
	while(!Serial.available());
	str = Serial.readString();

	Serial3.println(str);
	while(!Serial3.available());

	float input[4];	
	read_inputs(str, input, IN_LEN);
	
	float *outputs = network.forward(input);
	
	String str_out = write_outputs(outputs, OUT_LEN);
	Serial.println(str_out);
}