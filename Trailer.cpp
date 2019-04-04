#include <Arduino.h>

#include "Trailer.h"
#include "Sensor.h"
#include "StepperMotor.h"
#include "Communication.h"

uint8_t steeringWheelPosition = 0;
uint8_t speed = 0;
uint8_t dangerZone = 4;

State state = Off;

State trailer_get_state(){
  return state;
}

void trailer_set_state(State newstate){
  state = newstate;
}

void trailer_check_sensoren(){
  for(int i =  0; i < 4; i ++){
    update_sensor(i);
  }
}

void trailer_set_steering_wheel_position(uint8_t position){
  steeringWheelPosition = position;
}

uint8_t trailer_check_steering_position(){
  if (steeringWheelPosition != 0){
    stepper_set_positition(steeringWheelPosition - stepper_get_position());
  }
  else{
    stepper_set_positition(-stepper_get_position());
  }
}

void trailer_get_message(){
  if(communication_check_available){
    communication_receive_message();
  }
}

void trailer_check_collision(){
  if(sensor_get_distance(0) >= dangerZone){
    stepper_set_positition(50);
  }
  if(sensor_get_distance(1) >= dangerZone){
    stepper_set_positition(25);
  }
  if(sensor_get_distance(2) >= dangerZone){
    stepper_set_positition(-25);
  }
  if(sensor_get_distance(3) >= dangerZone){
    stepper_set_positition(-50);
  }
  else{
    stepper_set_positition(-stepper_get_position());
  }
}
