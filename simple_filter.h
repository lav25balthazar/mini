#ifndef SIMPLE_FILTER_H
#define SIMPLE_FILTER_H
#include "Arduino.h"

class SimpleFilter{
    
public

}





private: // variaveis do filto
  float _err_measure;
  float _err_estimate;
  float _q;
  float _current_estimate = 0;
  float _last_estimate = 0;
  float _kalman_gain = 0;



#endif