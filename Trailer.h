#ifndef _TRAILER_H
#define _TRAILER_H

#include <stdint.h>


enum State {
  Off = 0,
  Sound = 1,
  Parking = 2,
  Follow = 3,
  All = 4
} ;


State trailer_get_state();
void trailer_set_state(State state);
void trailer_check_sensoren();
void trailer_set_steering_wheel_position(uint8_t position);
uint8_t trailer_check_steering_position();
void trailer_get_message();
void trailer_check_collision();
#endif
