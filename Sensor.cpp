#include <Arduino.h>

#include "Sensor.h"
#include "Communication.h"

int distanceMeters[] = {A0,A1,A2,A3};
uint8_t distanceValue[] = {0,0,0,0};

void update_sensor(int sensor){
  distanceValue[sensor] = map(analogRead(distanceMeters[sensor]), 0, 1023, 0, 6);
  communication_send_sensor(sensor, distanceValue[sensor]);
}

uint8_t sensor_get_distance(int sensor){
  return distanceValue[sensor];
}
