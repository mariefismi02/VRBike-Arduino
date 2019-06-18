#ifndef Rotation_h
#define Rotation_h

#include "Arduino.h"
#include <Wire.h>
#define MPU 0x68

//Menggunakan Modul MPU-6050

class Rotation
{
private:
	double AcX, AcY, AcZ;
    int pitch, roll;
    double FunctionsPitchRoll(double A, double B, double C);

public:
	Rotation();
	void init();
	void update();
	int getPitch();
	int getRoll();
};

#endif

//init => inisialisasi modul
//update => perbarui nilai rotasi (dipanggil setiap update)
//getPitch => mengambil nilai rotasi y
//get Roll => mengambil nilai rotasi x