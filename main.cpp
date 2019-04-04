#include <Arduino.h>

#include "Trailer.h"

void CheckState(){
  State state = trailer_get_state();
  switch (state){
  case Off:
  break;
  case Sound:
  trailer_check_sensoren();
  break;
  case Parking:
  break;
  case Follow:
  trailer_get_message();
  trailer_check_steering_position();
  break;
  case All:
  trailer_check_sensoren();
  trailer_get_message();
  trailer_check_steering_position();
  trailer_check_collision();
  break;
  // default:
  // break;
}
}

void setup(){

}

void loop (){
CheckState();
}
