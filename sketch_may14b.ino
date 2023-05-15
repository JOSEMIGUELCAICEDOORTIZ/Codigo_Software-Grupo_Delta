//Incluir Librerias
#include "HX711.h"

//Declarar variables
const int Dout_Pin = A0;
const int Sck_Pin = A1;

// Inicializar la celda de carga
HX711 reservorio;

void setup() {
    // Paso 4
    Serial.begin(9600);
    reservorio.begin(Dout_Pin, Sck_Pin);
    Serial.print("Tomando Datos: ");
}

void loop() {

    // Lectura de la celda de carga
    if (reservorio.is_ready()) {
        long lectura = reservorio.read();
        Serial.println(lectura);
    } else if(Serial.read()=="Tara"){
    reservorio.tare(10);
    } else if(Serial.read()=="Calibracion"){
    reservorio.read();
    reservorio.set_scale(); 
    reservorio.tare(20);  
    }else {
    Serial.println("Error");
    }
        
        delay(1000);
    }
