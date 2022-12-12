
#include "robot.h"

//#include <robot.h>



#include "Arduino.h"

void setup() 
{
  Serial.begin(9600);
  pinMode(RIGHT_MOTOR_PWM_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_IN1_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_IN2_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_PWM_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_IN1_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_IN2_PIN, OUTPUT);
  pinMode(FRONT_SENSOR_PIN, INPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(MICRO_START_SIGNAL_PIN, INPUT);
  
//  pinMode(STDBY,OUTPUT);   /comentei 29 nov 22
//  digitalWrite(STDBY,HIGH); //comentei 29 nov 22

//  ledcAttachPin(LEFT_MOTOR_PWM_PIN, LEFT_MOTOR_CHANNEL);        /comentei 29 nov 22
//  ledcSetup(LEFT_MOTOR_CHANNEL, 12000, 8);                      /comentei 29 nov 22

//  ledcAttachPin(RIGHT_MOTOR_PWM_PIN, RIGHT_MOTOR_CHANNEL);      /comentei 29 nov 22
//  ledcSetup(RIGHT_MOTOR_CHANNEL, 12000, 8);                     /comentei 29 nov 22
}

void loop() 
{

  delay(1000);
  //Serial.println("RUN");
  digitalWrite(17, HIGH);
  digitalWrite(16, LOW);
//  ledcWrite(LEFT_MOTOR_CHANNEL, 255);
  //dacWrite(LEFT_MOTOR_PWM_PIN, 255);
//  delay(1000);
 // ledcWrite(LEFT_MOTOR_CHANNEL, 0);
  //dacWrite(LEFT_MOTOR_PWM_PIN, 0);1
//  delay(1000);
//  ledcWrite(LEFT_MOTOR_CHANNEL, 125);
  //dacWrite(LEFT_MOTOR_PWM_PIN, 0);
 */

  
  static Robot aurora;
  aurora.update();
  aurora.readSensors();
  
  // robot.updateVaiTomarNoCuIron();
}
