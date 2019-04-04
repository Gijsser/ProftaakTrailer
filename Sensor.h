#ifndef _SENSOR_H
#define _SENSOR_H


#include <stdint.h>

void update_sensor(int sensor);
uint8_t sensor_get_distance(int sensor);

#endif
