#include "Bluetooth.h"

Bluetooth::Bluetooth(uint8_t pinTX, uint8_t pinRX){
	this->pinTX = pinTX;
	this->pinRX = pinRX;

}

void Bluetooth::begin(int speed){
	bluetooth = new SoftwareSerial(pinTX, pinRX);

	bluetooth->begin(speed);
}

int Bluetooth::read(){

}

void Bluetooth::println(String value){
	bluetooth->println(value);
}