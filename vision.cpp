#include "vision.h"
#include <iostream>

using namespace std;

void updateEnemyPosition(DigitalSensor &front_sensor,
    DigitalSensor &full_left_sensor,
    DigitalSensor &full_right_sensor, 
    AnalogSensor &left_sensor, 
    AnalogSensor &right_sensor){

  if (front_sensor.enemy_close != 0) {
    EnemyPosition::FRONT;
    Serial.println("ah, ta ali na frente");  
    return;
    }
//  ve na frente
  if (right_sensor.distance_cm<20 && left_sensor.distance_cm > 20) {
      EnemyPosition:: RIGHT;
      Serial.println("ah, ta ali quase na direita");   
      return;  
      }
//  ve na direita meio diagonal
  if (full_right_sensor.enemy_close != 0) {
       EnemyPosition::FULL_RIGHT;
       Serial.println("ah, ta ali na direita"); 
       return;
    }
//  ve totalmente na direita
  if (full_left_sensor.enemy_close != 0) {
       EnemyPosition::FULL_LEFT;
       Serial.println("ah, ta ali na esquerda");  
       return;
   }
// ve na esquerda
  if (left_sensor.distance_cm<20 && right_sensor.distance_cm>20) {
        EnemyPosition::LEFT;
        Serial.println("ah, ta ali quase na esquerda"); 
        return;
    }
  //ve quase na esquerda
  if (left_sensor.distance_cm<20 && right_sensor.distance_cm<20){
        EnemyPosition:: FRONT;
        Serial.println("muito perto, vendo com 2 sensores");   
        return;
    }
  //oponente está muito perto, por isso os 2 sensores estão lendo e provavelmente o digital front também
}
