#include "vision.h"
#include <iostream>

using namespace std;

void Vision::updateEnemyPosition(DigitalSensor& front_sensor,
  DigitalSensor& full_left_sensor,
  DigitalSensor& full_right_sensor,
  AnalogSensor& left_sensor,
  AnalogSensor& right_sensor) {

<<<<<<< HEAD
//   Serial.println("esq: ");
//   left_sensor.distance_cm = left_sensor.readSensor(); // lê sensores analogicos chamando 
//   Serial.println(left_sensor.distance_cm);
//   Serial.println(" \t dir: ");
//   right_sensor.distance_cm = right_sensor.readSensor(); // a funcao readSensor do analog_sensor
//   Serial.println(right_sensor.distance_cm);
  
//   front_sensor.enemy_close = front_sensor.readSensor(); // le sensores digitais chamando a 
//   full_left_sensor.enemy_close = full_left_sensor.readSensor(); // funcao readSensor
//   full_right_sensor.enemy_close = full_right_sensor.readSensor(); // do digital_sensor
  //comentando porque não é uma boa pratica atualizar sensores em mais de um lugar

=======
 
>>>>>>> filtro_perobeli

  //Serial.println("estou em vision updateEnemyPosition");
  if (front_sensor.enemy_close != 0) {
    this-> enemy_position = EnemyPosition::FRONT;
    //Serial.println("ah, ta ali na frente");
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
    Serial.println("nao está lendo nada");
  }
}