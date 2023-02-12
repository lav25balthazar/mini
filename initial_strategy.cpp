#include "strategy.h"
#include <iostream>

using namespace std;
//construtor, apenas inicializando as coisas
Move::Move(int left_motor_power, int right_motor_power, int time_ms){ 
    this->left_motor_power = left_motor_power;
    this->right_motor_power = right_motor_power;
    this->time_ms = time_ms; //tempo para movimentação já com o delay (eu imagino)
    this->started = false;  //micro start ainda nao deu sinal
    this->finished = false; //movimentação não terminou (nem começou)
    this->start_time_ms = 5000; //tempo que começa movimentação (delay 5s) conferir se ainda é o mesmo
};
//retorno paa saber se a movimentação já terminou
bool Move::update(MotorControl &left_motor, MotorControl &right_motor){
    // começa movimentação depois do delay    
    if (this->start_time_ms >= 5000){
      this->started = true;
    }
    // quando passa o tempo de movimentação, em tese, significa que ela já terminou   (saber se o delay está incluído em time_ms)   
    if(millis() - this->start_time_ms >= this->time_ms){
      this->finished == true;
      right_motor.setPower(0); 
      left_motor.setPower(0);
    }
    //quando o tempo é menor que o deterinado, em tese, significa que a movimentação ainda não terminou
    else{
      this->finished = false;
      right_motor.setPower(this->right_motor_power); 
      left_motor.setPower(this->left_motor_power);            
    }
    return finished;
}


