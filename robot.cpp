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

  
  Serial.println("esq: ");
  this->left_sensor.readSensor(); // lê sensores analogicos chamando 
  Serial.println(this->left_sensor.distance_cm);
  Serial.println(" \t dir: ");
  this->right_sensor.readSensor(); // a funcao readSensor do analog_sensor
  Serial.println(this->right_sensor.distance_cm);
  
  this->front_sensor.readSensor(); // le sensores digitais chamando a 
  this->full_left_sensor.readSensor(); // funcao readSensor
  this->full_right_sensor.readSensor(); // do digital_sensor
  
  

}
void Robot::update() {
  this->ustart.update();
  this->readSensors();
  this->vision.updateEnemyPosition(this->front_sensor, this->full_left_sensor, this->full_right_sensor, this->left_sensor, this->right_sensor);
  if (this->ustart.state == uStartState::START){ // gostaria de criar uma condição em que, no momento que o micro start manda sinal para começar, no micro_start.cpp, start é diferente de 0 p iniciar estrategia. 
    this->robot_state = RobotState::INITIAL_STRATEGY; // colocar estrategia inicial (que no caso não fiz ainda)

    readSensors();
    //movimentacao quando aciona o microstart
    static Move move_esq(80, 100, 200); //usar static para acessar classe sem objeto
      move_esq.update(this->left_motor, this->right_motor);
    if (move_esq.update(this->left_motor, this->right_motor) != 0){   
      static Move move_front(50, 50, 1000);
        move_front.update(this->left_motor, this->right_motor);}
    if (move_front.update(this->left_motor, this->right_motor) != 0){         //add condição para servir de controle dos movimentos
      static Move move_dir(100, 80, 400);
        move_dir.update(this->left_motor, this->right_motor);
    //termina movimetacao                   
    this->auto_strategy.updateMotors(this->vision, this->left_motor, this->right_motor);
    this->robot_state = RobotState::AUTO_STRATEGY;}
  else{
    this->robot_state = RobotState::STOPPED;
    left_motor.setPower(0);
    right_motor.setPower(0);    
  }      
}
