#include "digital_sensor.h"
#include <iostream>
#include <Arduino.h>
using namespace std;

DigitalSensor::DigitalSensor(int pin) {
  this->pin = pin;
}

int DigitalSensor::readSensor() {
  
  this->raw_reading = digitalRead(this->pin); 
  // sempre apontando como se fosse objeito, já que vai usar o pin do robot.h, sempre que mudar, muda também. sempre usar ponteiro.
  if (this->raw_reading == true)
    this->enemy_close == true;
  else
    this->enemy_close == false;
    
  return this->enemy_close; 
}

