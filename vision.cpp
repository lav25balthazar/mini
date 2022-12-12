#include "vision.h"
#include <iostream>

using namespace std;

void Vision::updateEnemyPosition(DigitalSensor &front_sensor,
    DigitalSensor &full_left_sensor,
    DigitalSensor &full_right_sensor, 
    AnalogSensor &left_sensor, 
    AnalogSensor &right_sensor){

  left_sensor.readSensor(); // lê sensores analogicos chamando 
  right_sensor.readSensor() ; // a funcao readSensor do analog_sensor
  front_sensor.readSensor(); // le sensores digitais chamando a 
  full_left_sensor.readSensor(); // funcao readSensor
  full_right_sensor.readSensor(); // do digital_sensor

  Serial.println("estou em vision updateEnemyPosition");
  if (front_sensor.enemy_close != 0) {
    EnemyPosition::FRONT;
    Serial.println("ah, ta ali na frente"); 
    return;
    }
//  ve na frente
  else if (right_sensor.distance_cm<20 && left_sensor.distance_cm > 20) {
      EnemyPosition::RIGHT;
      Serial.println("ah, ta ali quase na direita");   
      return;  
      }
//  ve na direita meio diagonal
  else if (full_right_sensor.enemy_close != 0) {
       EnemyPosition::FULL_RIGHT;
       Serial.println("ah, ta ali na direita"); 
       return;
    }
//  ve totalmente na direita
  else if (full_left_sensor.enemy_close != 0) {
       EnemyPosition::FULL_LEFT;
       Serial.println("ah, ta ali na esquerda");   
       return;
   }
// ve na esquerda
  else if (left_sensor.distance_cm<20 && right_sensor.distance_cm>20) {
        EnemyPosition::LEFT;
        Serial.println("ah, ta ali quase na esquerda");  
        return;
    }
  //ve quase na esquerda
  else if (left_sensor.distance_cm<20 && right_sensor.distance_cm<20){
        EnemyPosition:: FRONT;
        Serial.println("muito perto, vendo com 2 sensores");   
        return;
    }
  //oponente está muito perto, por isso os 2 sensores estão lendo e provavelmente o digital front também
  else
    Serial.println("nao está lendo nada");
}
