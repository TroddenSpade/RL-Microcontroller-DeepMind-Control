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

    WiFi.mode(WIFI_STA);
    WiFi.begin("USSID", "PASS"); // change it to your ussid and password

    while (WiFi.status() != WL_CONNECTED){
        delay(500);
    }
	Serial.write(0x1);

    while(!client.connect(host, port)){
        delay(500);
    }
	Serial.write(0x1);
    client.stop();
}

void loop()
{    
	while(!Serial.available());
    str = Serial.readString();

    while(!client.connect(host, port)){
        delay(100);
    }

    client.println(str);
    delay(100);
    
    while (!client.available());
    Serial.write(client.read());

    client.stop();

}