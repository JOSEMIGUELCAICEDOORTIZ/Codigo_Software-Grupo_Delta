//Añadimos las librerias que vamos a utilizar
#include "HX711.h"
#include <Wire.h> 
#include <Servo.h>
//Creamos el objeto HX711 para controlar el reservorio
HX711 reservorio;
//Creamos el objeto Servo para controlar la válvula mariposa
Servo valvula;
// Declaramos variables
long lectura_reser;
int pos_valvula=0;
void setup() {
  // Iniciamos el monitor serial
Serial.begin(9600);
valvula.attach(9);
}

void loop() {
  lectura_reser = reservorio.get_value(10);
  if(lectura_reser<500){
    
  }else if(lectura_reser>=0 && lectura_reser<500){
    valvula.write(20);
  }else if(lectura_reser>=500 && lectura_reser<1000){
    valvula.write(30);
    }else if(lectura_reser>=1000 && lectura_reser<1500){
    valvula.write(50);
    }else if(lectura_reser>=1500 && lectura_reser<2000){
    valvula.write(60);
    }else {
      valvula.write(0);
      }
delay(60);
}
