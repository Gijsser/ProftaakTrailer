
#include <Stepper.h>
#include <Arduino.h>

#include "StepperMotor.h"

uint8_t StepperPosition = 0;

Stepper StepperMotor(32, 8, 10, 9, 11);//Stepper motor met 32 steps / pin 8 - 11

void set_stepper_steps(uint8_t steps){
  StepperMotor.step(steps);
  stepper_set_positition(steps);
}

void stepper_set_positition(uint8_t steps){
    StepperPosition = StepperPosition + steps;
}

uint8_t stepper_get_position(){
  return StepperPosition;
}
