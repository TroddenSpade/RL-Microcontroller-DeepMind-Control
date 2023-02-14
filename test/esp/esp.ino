#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const uint16_t port = 8585;
const char *host = "192.168.43.90";
WiFiClient client;

String str = "";

void setup()
{
    Serial.begin(115200);
    Serial.println("Connecting...\n");
    WiFi.mode(WIFI_STA);
    WiFi.begin("Redmi Note 7", "adsodja23i335j"); // change it to your ussid and password
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
    }
	Serial.println("Connected to wifi.");
}

void loop()
{
    if (!client.connect(host, port)){
        delay(1000);
        return;
    }

    Serial.println("Connected to server.");
	
	if(str != ""){
    	client.println(str);
	}
	
    while (client.available() > 0){
        char c = client.read();
        Serial.write(c);
    }
	
    client.stop();
	while(!Serial.available());
	str = Serial.readString();

    delay(1000);
}