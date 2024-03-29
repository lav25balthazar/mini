#include "analog_sensor.h"
#include <iostream>
#include <Arduino.h>
#include <math.h>

using namespace std;

AnalogSensor::AnalogSensor(int pin): filter() {
  this->pin = pin;
}
int AnalogSensor::readSensor() { //lê sensor analógico, dá uma leitura entre 0 e 255/4095 se lê algo
  this->raw_reading = analogRead(this->pin);
  this->filtered_reading = this->filter.updateEstimate(this->raw_reading);
  if (this->filtered_reading >= 0 && this->filtered_reading <= 4095)
    return (int)((4095.0- (float)this->filtered_reading)*(float)ANALOG_TO_CM); //conta do billy para converter (perguntar)
  else
    return -1; // sensor com problema 
}

  
  
