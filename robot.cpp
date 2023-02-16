#include "robot.h"
#include <iostream>
#include <Arduino.h>
using namespace std;

Robot::Robot():front_sensor(FRONT_SENSOR_PIN), full_left_sensor(FULL_LEFT_SENSOR_PIN), full_right_sensor(FULL_RIGHT_SENSOR_PIN), left_sensor(LEFT_SENSOR_PIN), right_sensor(RIGHT_SENSOR_PIN), left_motor(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_IN1_PIN, LEFT_MOTOR_IN2_PIN, LEFT_MOTOR_SPEED_CONST), right_motor(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_IN1_PIN, RIGHT_MOTOR_IN2_PIN, RIGHT_MOTOR_SPEED_CONST), ustart(MICRO_START_SIGNAL_PIN), vision()
{
  this->robot_state = RobotState::AWAITING_START;
  //Serial.println("oi, sou aurora");// criando os construtores, robô esperando sinal de start do microstart
  //construtores criados com : -> código já executa direto para criação dos construtores.
}

void Robot::readSensors() {
  //  vision.updateEnemyPosition(); tentando colocar vision na robot 06/12/2022 // continuação de tentativas 07/12/2022 // tentando 08/10/22 
  //Serial.println("estou na funcao readSensors");
  
  Serial.println("esq: ");
  this->left_sensor.distance_cm = this->left_sensor.readSensor(); // lê sensores analogicos chamando   
  Serial.println(this->left_sensor.distance_cm);
  Serial.println(" \t dir: ");
  this->right_sensor.distance_cm = this->right_sensor.readSensor(); // a funcao readSensor do analog_sensor
  Serial.println(this->right_sensor.distance_cm);
  
  this->front_sensor.enemy_close = this->front_sensor.readSensor(); // le sensores digitais chamando a 
  this->full_left_sensor.enemy_close = this->full_left_sensor.readSensor(); // funcao readSensor
  this->full_right_sensor.enemy_close = this->full_right_sensor.readSensor(); // do digital_sensor
  this->vision.updateEnemyPosition(this->front_sensor, this->full_left_sensor, this->full_right_sensor, this->left_sensor, this->right_sensor);
  

}
void Robot::update() {
  uStart(MICRO_START_SIGNAL_PIN) = ustart;
  //Serial.println("estou na robot em funcao update");
  if (ustart.state == uStartState::START){ // gostaria de criar uma condição em que, no momento que o micro start manda sinal para começar, no micro_start.cpp, start é diferente de 0 p iniciar estrategia. 
    this->robot_state = RobotState::INITIAL_STRATEGY; // colocar estrategia inicial (que no caso não fiz ainda)
    readSensors();
    this->auto_strategy.updateMotors(this->vision, this->left_motor, this->right_motor);
    this->robot_state = RobotState::AUTO_STRATEGY;}
  else
    this->robot_state = RobotState::STOPPED;
}
