#include "strategy.h"
#include <iostream>

using namespace std;
//construtor, apenas inicializando as coisas
Move::Move(int left_motor_power, int right_motor_power, int time_ms){ 
    this->left_motor_power = left_motor_power;
    this->right_motor_power = right_motor_power;
    this->time_ms = time_ms; //tempo para movimentação
    this->started = false;  //micro start ainda nao deu sinal
    this->finished = false; //movimentação não terminou (nem começou)
    this->start_time_ms = 0; //tempo que começa movimentação  
}
//retorno paa saber se a movimentação já terminou
bool Move::update(MotorControl &left_motor, MotorControl &right_motor){
    // começa movimentação     
    if (this->start_time_ms >= 0){
      this->started = true;
    }
    // quando passa o tempo de movimentação, em tese, significa que ela já terminou    
    if(millis() - this->start_time_ms >= this->time_ms){
      this->finished == true;
      right_motor.setPower(0); 
      left_motor.setPower(0);
    }
    //quando o tempo é menor que o deterinado, em tese, significa que a movimentação ainda não terminou
    else{
      this->finished = false;
      right_motor.setPower(this->right_motor_power); 
      left_motor.setPower(this->left_motor_power);            
    }
    return finished;
}

InitialStrategy::InitialStrategy(list<Move> moves): moves(moves), current_move(moves.front()){
  this->moves = moves;
  this->moves.pop_front();
  this->strategy_finished = false;  //indica se estratégia incial foi concluída ou não
};
bool InitialStrategy::update(MotorControl &left_motor, MotorControl &right_motor){
  bool move_status = this->current_move.update(left_motor, right_motor);
    
  if (move_status == false){      
    this->current_move = this->moves.front();
    this->current_move = this->moves.pop_front();    
  }  
  this->strategy_finished = (this->current_move.finished) ? true : false; 
  //retorna true se o movimento inicial escolhido foi terminado, false caso contrário.
}

InitialStrategy* get_selected_strategy(int pinA, int pinB, int pinC){
  bool strategyA = digitalRead(pinA);
  bool strategyB = digitalRead(pinB);
  bool strategyC = digitalRead(pinC);
  char strategy;
  
  if (strategyA == true)
    strategy = 'a';
  if (strategyB == true)
    strategy = 'b';
  if (strategyC == true)
    strategy = 'c'; 

  list<Move> moves = {};
  
  switch (strategy){
    case 'a':
      moves.push_back(Move(100,100,100));
      moves.push_back(Move(100,80,200));
      moves.push_back(Move(100,100,100));
      moves.push_back(Move(80,100,200));
      break;
    case 'b':
      moves.push_back(Move(100,90,200));
      moves.push_back(Move(90,100,100));
      moves.push_back(Move(100,100,500));
      moves.push_back(Move(100,80,200));
      break;
    case 'c':
      moves.push_back(Move(90,100,300));
      moves.push_back(Move(100,100,200));
      moves.push_back(Move(100,90,100)); 
      moves.push_back(Move(80,100,200));  
      break;         

  return new InitialStrategy(moves);                      
  }
}

