#include "w.h"

int num;
int max_layer;


void read_inputs(String str, float *input){
    for(int i=0; i<shape[0]-1; i++){
        int idx = str.indexOf(' ');
        input[i] = str.substring(0, idx).toFloat();
        str = str.substring(++idx, str.length());
    }
  	input[shape[0]-1] = str.toFloat();
}

String write_outputs(float *ptr){
    String out = "";
    for(int i=0; i<shape[num-1]; i++){
      	char buff[20];
      	dtostrf(ptr[i], 1, 6, buff);
    	out += buff;
      	out += (i == shape[num-1]-1 ? "" : " "); 
    }
    return out;
}

void forward_pass(float *ptr_in, float *ptr_out){
    for(int i=0; i<num-1; i++){
        for(int j=0; j<shape[i+1]; j++){
            ptr_out[j] = 0;
            for(int k=0; k<shape[i]; k++){
                ptr_out[j] += ptr_in[k] * weights[i][j*shape[i] + k];
            }
          	if(i==num-2)
              ptr_out[j] += biases[i][j];
          	else
            	ptr_out[j] = tanh(ptr_out[j] + biases[i][j]);
        }
        float *tmp = ptr_in;
        ptr_in = ptr_out;
        ptr_out = tmp;
    }
}


void setup(){
    Serial.begin(115200);
    num = sizeof(shape)/sizeof(shape[0]);
    for(int i=0; i<num; i++){
        if(shape[i]>max_layer)
            max_layer = shape[i];            
    }
}

void loop(){
    while (!Serial.available())
      ;
 	  String str = Serial.readString();
  
  	float input[max_layer];
  	float output[max_layer];

    float *ptr_in = input;
    float *ptr_out = output;
    
  	read_inputs(str, ptr_in);
    
    forward_pass(ptr_in, ptr_out);

    String out = write_outputs(ptr_out);
    Serial.println(out);
    
}