#ifndef _COMMUNICATION_H
#define _COMMUNICATION_H

void communication_send_sensor(int sensor, uint8_t distance);
int communication_check_available();
void communication_receive_message();
void communication_read_message(String message);
void parse_message(String unparsed, String (*Parsed)[2] ); //Hoe deze opschrijven?
#endif
