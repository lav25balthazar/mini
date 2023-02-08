#include "strategy.h"
#include <iostream>

using namespace std;


void AutoStrategy::updateMotors(Vision &vision, MotorControl &left_motor, MotorControl &right_motor){
    if(vision.enemy_position==EnemyPosition::RIGHT){
        left_motor.setPower(90);
        right_motor.setPower(20);}
    else if(vison.enemy_position ==EnemyPosition::LEFT){
        left_motor.setPower(20);
        right_motor.setPower(90);}
    else if(vision.enemy_position ==EnemyPosition::FRONT){
        left_motor.setPower(100);
        right_motor.setPower(100);}
    else if(vision.enemy_position ==EnemyPosition::FULL_LEFT){
        left_motor.setPower(10);
        right_motor.setPower(95);}
    else if(vision.enemy_position ==EnemyPosition::FULL_RIGHT){
        left_motor.setPower(95);
        right_motor.setPower(10);}
};
    
