#include "vision.h"
#include <iostream>

using namespace std;

void Vision::updateEnemyPosition(DigitalSensor& front_sensor,
  DigitalSensor& full_left_sensor,
  DigitalSensor& full_right_sensor,
  AnalogSensor& left_sensor,
  AnalogSensor& right_sensor) {

  //Serial.println("estou em vision updateEnemyPosition");
  if (front_sensor.enemy_close != 0) {
    this-> enemy_position = EnemyPosition::FRONT;
    Serial.println("FRONT");
    return;
  }
  //  ve na frente
  else if (right_sensor.distance_cm < 20 && left_sensor.distance_cm > 20) {
    this-> enemy_position =EnemyPosition::RIGHT;
    Serial.println("RIGHT");
    return;
  }
  //  ve na direita meio diagonal
  else if (full_right_sensor.enemy_close != 0) {
    this-> enemy_position =EnemyPosition::FULL_RIGHT;
    Serial.println("FULL_RIGHT");
    return;
  }
  //  ve totalmente na direita
  else if (full_left_sensor.enemy_close != 0) {
    this-> enemy_position =EnemyPosition::FULL_LEFT;
    Serial.println("FULL_LEFT");
    return;
  }
  // ve na esquerda
  else if (left_sensor.distance_cm < 20 && right_sensor.distance_cm>20) {
    this-> enemy_position =EnemyPosition::LEFT;
    Serial.println("LEFT");
    return;
  }
  //ve quase na esquerda
  else if (left_sensor.distance_cm < 20 && right_sensor.distance_cm < 20) {
    this-> enemy_position =EnemyPosition::FRONT;
    Serial.println("FRONT");
    return;
  }
  //oponente está muito perto, por isso os 2 sensores estão lendo e provavelmente o digital front também
  else{
    Serial.println("nao está lendo nada");}
}
