#ifndef SIMPLE_FILTER_H
#define SIMPLE_FILTER_H
#include "Arduino.h"

class SimpleFilter{
    
public:
  SimpleFilter(float _err_measure, float _err_estimate, float _q);
  SimpleFilter();
  float updateEstimate(float mea);    
private:
 // variaveis do filto
  float _err_measure = 5;
  float _err_estimate = 5;
  float _q = 0.1666;
  float _current_estimate = 0;
  float _last_estimate = 0;
  float _kalman_gain = 0;
};


#endif