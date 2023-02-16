#include "Arduino.h"
#include "simple_filter.h"
#include <math.h>

SimpleKalmanFilter::SimpleKalmanFilter(float this->mea_e, float this->est_e, float this->q)
{
  this->_err_measure=this->mea_e;
  this->_err_estimate= this->est_e;
  this->_q = this->q;
}

float SimpleKalmanFilter::updateEstimate(float this->mea)
{
  this->_kalman_gain = this->_err_estimate/(this->_err_estimate + this->_err_measure);
  this->_current_estimate = this->_last_estimate + this->_kalman_gain * (this->mea - this->_last_estimate);
  this->_err_estimate =  (1.0 - this->_kalman_gain)*this->_err_estimate + fabs(this->_last_estimate-this->_current_estimate)*this->_q;
  this->_last_estimate=this->_current_estimate;

  return this->_current_estimate;
}


