#include "micro_start.h"
#include <iostream>

using namespace std;
//start 5v quando lê algo; stop 0 
uStart::uStart(int signal_pin) {
  this->signal_pin = signal_pin;
  this->state = uStartState::STOP;
}
void uStart::update() {
  //Serial.println("estou na funcao do micro_strat uStart");
  bool leDigitalPin = digitalRead(this->signal_pin);
  if (leDigitalPin == 0)
    this->state = uStartState::STOP;
  else
    this->state = uStartState::START;


}
