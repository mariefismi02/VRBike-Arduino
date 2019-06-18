#include "Speed.h"
#include "Bluetooth.h"
#include "Rotation.h"

Speed speed(6);//Sensor kecepatan
Bluetooth bluetooth(10, 11);//Bluetooth
Rotation rotation;//Sensor rotasi

unsigned long start_time = 0;
unsigned long end_time = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  speed.init();
  rotation.init();
  bluetooth.begin(9600);

   //Delay for sensor
  start_time=millis();
  end_time=start_time+1000;
}

void loop() {
  // put your main code here, to run repeatedly:
  rotation.update();//Perbarui data nilai rotasi

  int pitch = rotation.getPitch();//Ambil rotasi y

  if(millis()<end_time)//Tambah step selama kurang dari setiap 1 detik
  {
    speed.addStep();
  } else {//Set ulang RPS setiap 1 detik

    speed.setRPS();

    float rps = speed.getRPS();

    //Kirim nilai rps melalui bluetooth
    bluetooth.println("rps:"+String(rps));
    Serial.println("rps:"+String(rps));
    
    //Delay for sensor
    start_time=millis();
    end_time=start_time+1000;
  }

  //Kirim data pitch melalui bluetooth setiap 0.2 detik
  if((end_time-millis())%200==0){
    bluetooth.println("agl:"+String(pitch));
    Serial.println("agl:"+String(pitch));
  }
}
