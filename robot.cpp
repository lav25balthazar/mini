#include "robot.h"
#include <iostream>
#include <Arduino.h>
using namespace std;

Robot::Robot():front_sensor(FRONT_SENSOR_PIN), full_left_sensor(FULL_LEFT_SENSOR_PIN), full_right_sensor(FULL_RIGHT_SENSOR_PIN), left_sensor(LEFT_SENSOR_PIN), right_sensor(RIGHT_SENSOR_PIN), left_motor(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_IN1_PIN, LEFT_MOTOR_IN2_PIN, LEFT_MOTOR_SPEED_CONST), right_motor(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_IN1_PIN, RIGHT_MOTOR_IN2_PIN, RIGHT_MOTOR_SPEED_CONST), ustart(MICRO_START_SIGNAL_PIN), vision()
{
  this->robot_state = RobotState::AWAITING_START;
  Serial.println("oi, sou aurora");// criando os construtores, robô esperando sinal de start do microstart
  //construtores criados com : -> código já executa direto para criação dos construtores.
}

void Robot::readSensors(){
//  vision.updateEnemyPosition(); tentando colocar vision na robot 06/12/2022 // continuação de tentativas 07/12/2022 // tentando 08/10/22 
  Serial.println("estou na funcao readSensors");  
  this->vision.updateEnemyPosition(this->front_sensor, this->full_left_sensor, this->full_right_sensor, this->left_sensor, this->right_sensor);
  
}
void Robot::update(){
  uStart(MICRO_START_SIGNAL_PIN) = ustart;
  Serial.println("estou na robot em funcao update");
  if (uStartState::START) // gostaria de criar uma condição em que, no momento que o micro start manda sinal para começar, no micro_start.cpp, start é diferente de 0 p iniciar estrategia. 
    this->robot_state = RobotState::INITIAL_STRATEGY;
  else
    this->robot_state = RobotState::STOPPED;
  }
