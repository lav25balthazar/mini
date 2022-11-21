#include "analog_sensor.h"
#include <iostream>
#include <Arduido.h>
using namespace std;

AnalogSensor::AnalogSensor(int pin){
  this->pin = pin;
}
int AnalogSensor::readSensor(){ //lê sensor analógico, dá uma leitura entre 0 e 255 se lê algo
  this->raw_reading = analogRead(this->pin);
  if (raw_reading >=0 && raw_reading <=255)
    return this->raw_reading;
  else
    return -1; // sensor com problema 

}
