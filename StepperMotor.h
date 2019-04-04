#ifndef _STEPPERMOTOR_H
#define _STEPPERMOTOR_H

void set_stepper_steps(uint8_t steps);
void stepper_set_positition(uint8_t steps);
uint8_t stepper_get_position();
#endif
