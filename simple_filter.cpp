#include "Arduino.h"
#include "simple_filter.h"
#include <math.h>

SimpleFilter::SimpleFilter(float _err_measure, float _err_estimate, float _q){
  this->_err_measure= _err_measure;
  this->_err_estimate= _err_estimate;
  this->_q = _q;
}

float SimpleFilter::updateEstimate(float mea){
  this->_kalman_gain = this->_err_estimate/(this->_err_estimate + this->_err_measure);
  this->_current_estimate = this->_last_estimate + this->_kalman_gain * (mea - this->_last_estimate);
  this->_err_estimate =  (1.0 - this->_kalman_gain)*this->_err_estimate + fabs(this->_last_estimate-this->_current_estimate)*this->_q;
  this->_last_estimate=this->_current_estimate;

  return this->_current_estimate;
}

//src:https://github.com/denyssene/SimpleKalmanFilter/blob/master/src/SimpleKalmanFilter.cpp

