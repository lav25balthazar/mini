#include "robot.h"
#include <iostream>
#include <Arduino.h>
using namespace std;

Robot::Robot():front_sensor(FRONT_SENSOR_PIN), full_left_sensor(FULL_LEFT_SENSOR_PIN), full_right_sensor(FULL_RIGHT_SENSOR_PIN), left_sensor(LEFT_SENSOR_PIN), right_sensor(RIGHT_SENSOR_PIN), left_motor(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_IN1_PIN, LEFT_MOTOR_IN2_PIN, LEFT_MOTOR_SPEED_CONST), right_motor(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_IN1_PIN, RIGHT_MOTOR_IN2_PIN, RIGHT_MOTOR_SPEED_CONST), ustart(MICRO_START_SIGNAL_PIN), vision()
{
  this->robot_state = RobotState::AWAITING_START; // criando os construtores, robô esperando sinal de start do microstart
  //construtores criados com : -> código já executa direto para criação dos construtores.
}

void Robot::readSensors(){
  left_sensor.readSensor(); // lê sensores analogicos chamando 
  right_sensor.readSensor(); // a funcao readSensor do analog_sensor
  front_sensor.readSensor(); // le sensores digitais chamando a 
  full_left_sensor.readSensor(); // funcao readSensor
  full_right_sensor.readSensor(); // do digital_sensor
   
}
void Robot::update(){
  uStart(MICRO_START_SIGNAL_PIN) = ustart;
  if (uStartState::START) // gostaria de criar uma condição em que, no momento que o micro start manda sinal para começar, no micro_start.cpp, start é diferente de 0 p iniciar estrategia. 
    this->robot_state = RobotState::INITIAL_STRATEGY;
  else
    this->robot_state = RobotState::STOPPED;
  }
