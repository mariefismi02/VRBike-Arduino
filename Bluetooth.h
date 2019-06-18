#ifndef Bluetooth_h
#define Bluetooth_h

#include "Arduino.h"
#include <SoftwareSerial.h>

//Menggunakan modul HC-05

class Bluetooth
{
private:
	uint8_t pinTX;
	uint8_t pinRX;
	SoftwareSerial* bluetooth;

public:
	Bluetooth(uint8_t pinTX, uint8_t pinRX);
	void begin(int speed);
	int read();
	void println(String value);
};

#endif


//begin => inisialisasi modul
//read => membaca data yang masuk melalui bluetooth
//println => mengirimkan nilai keluar melalui bluetooth