#include "strategy.h"
#include "micro_start.h"
#include "vision.h"
#include <iostream>

using namespace std;


void AutoStrategy::updateMotors(Vision &vision, MotorControl &left_motor, MotorControl &right_motor){
  if (uStartState::START)
    if(Vision::this->enemy_position!=EnemyPosition::RIGHT, Vison::this->enemy_position !=EnemyPosition::LEFT, this->enemy_position !=EnemyPosition::FRONT)
      
    
};

    int left_motor_power;
    int right_motor_power;
    
