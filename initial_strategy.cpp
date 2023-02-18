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
    if (this->start_time_ms == 0){
      this->start_time_ms = millis();
      this->started = true;
    }
    // quando passa o tempo de movimentação, em tese, significa que ela já terminou    
    if((millis() - this->start_time_ms) >= this->time_ms){
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
    return this->finished;
}

InitialStrategy::InitialStrategy(list<Move> moves): moves(moves), current_move(moves.front()){
  this->strategy_finished = false;  //indica se estratégia incial foi concluída ou não
};
bool InitialStrategy::update(MotorControl &left_motor, MotorControl &right_motor){
  bool move_finished = this->current_move.update(left_motor, right_motor);
    
  if (move_finished == true){               
      if(this->moves.empty())
        this->strategy_finished = true;
      else{
        this->strategy_finished = false;
        this->current_move = this->moves.front(); 
        this->moves.pop_front(); 
        move_finished = this->current_move.update(left_motor, right_motor);        
      }
  }  

  return this->strategy_finished;
  //retorna se o movimento inicial escolhido foi terminado ou  não
}

InitialStrategy* get_selected_strategy(int pinA, int pinB, int pinC){
  bool strategyA = digitalRead(pinA);
  bool strategyB = digitalRead(pinB);
  bool strategyC = digitalRead(pinC);
  int strategy = 0;
  
  if (strategyA == true && strategyB == false && strategyC == false)
    strategy = 1;
  if (strategyA == false && strategyB == true && strategyC == false) 
    strategy = 2;
  if (strategyA == false && strategyB == false && strategyC == true)
    strategy = 3;
  if (strategyA == true && strategyB == true && strategyC == false)
    strategy = 4;
  if (strategyA == true && strategyB == false && strategyC == true)
    strategy = 5;
  if (strategyA == false && strategyB == true && strategyC == true)
    strategy = 6;
  if (strategyA == true && strategyB == true && strategyC == true)
    strategy = 7;
  if (strategyA == false && strategyB == false && strategyC == false)
    strategy = 8;      

  list<Move> moves = {};
  
  switch (strategy){
    case 0:
      Serial.println("estratégia inicial deu b.o");        
    case 1:
      moves.push_back(Move(100,100,100));
      moves.push_back(Move(100,80,200));
      moves.push_back(Move(100,100,100));
      moves.push_back(Move(80,100,200));
      //frente, dir, frente, esq
      break;
    case 2:
      moves.push_back(Move(100,90,200));
      moves.push_back(Move(90,100,100));
      moves.push_back(Move(100,100,500));
      moves.push_back(Move(100,80,200));
      //dir, esq, frente, dir
      break;
    case 3:
      moves.push_back(Move(90,100,300));
      moves.push_back(Move(100,100,200));
      moves.push_back(Move(100,90,100)); 
      moves.push_back(Move(80,100,200));
      //esq, frente, dir, esq        
      break; 
    case 4:
      moves.push_back(Move(90,100,300));
      moves.push_back(Move(100,80,300));
      moves.push_back(Move(80,100,200)); 
      moves.push_back(Move(100,90,100));
      //esq, dir, esq, dir  
      break; 
    case 5:
      moves.push_back(Move(100,80,300));
      moves.push_back(Move(80,100,200));
      moves.push_back(Move(100,90,400)); 
      moves.push_back(Move(80,100,200));
      //dir, esq, dir, esq  
      break; 
    case 6:
      moves.push_back(Move(100,80,300));
      moves.push_back(Move(100,100,400));
      moves.push_back(Move(85,100,100)); 
      moves.push_back(Move(100,100,200));
      //dir, frente, esq, frente  
      break; 
    case 7:
      moves.push_back(Move(100,100,500));
      moves.push_back(Move(100,80,200));
      moves.push_back(Move(85,100,100)); 
      moves.push_back(Move(100,100,300));
      //frente, dir, esq, frente  
      break;
    case 8:
      moves.push_back(Move(90,100,300));
      moves.push_back(Move(100,80,200));
      moves.push_back(Move(100,10,600)); 
      moves.push_back(Move(80,100,200));
      //esq, dir, frente, esq  
      break;         

  return new InitialStrategy(moves);                      
  }
}

