#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#define ANALOG_TO_CM ((float)(20.0 / 2000.0))

class AnalogSensor
{
public:
    int raw_reading;
    int filtered_reading;
    int distance_cm;
    int pin;
    int readSensor();
    int filterSensor();
    AnalogSensor(int pin);
};
private: // variaveis do filto
  float _err_measure;
  float _err_estimate;
  float _q;
  float _current_estimate = 0;
  float _last_estimate = 0;
  float _kalman_gain = 0;

#endif
