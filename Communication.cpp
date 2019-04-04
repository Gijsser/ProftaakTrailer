#include <Arduino.h>
#include <SoftwareSerial.h>

#include "Communication.h"

SoftwareSerial Bluetooth(6,5); //Rx, Tx

void communication_send_sensor(int sensor, uint8_t distance){
//  Bluetooth.println("#DISTANCEMETER%d%c", sensor, ":%d%c", distance, "%");
}

int communication_check_available(){
  if (Bluetooth.available() > 0){
    return 1;
  }
  else{
    return 0;
  }
}

void communication_receive_message(){
  String message = Bluetooth.readStringUntil('%');
  communication_read_message(message);
}

void communication_read_message(String message){
  if(message[0] == '#'){ // als start-marker
    String Parsed[2];
    parse_message(message, (&Parsed));
    if (Parsed[0] == "<command>") {
      //<actie>
    }

  else{
    Bluetooth.println("#UNVALID_COMMAND:0%");
  }
}
}

void parse_message(String unparsed, String (&Parsed)[2]){ //kijken bij watch.c
  String parsed;

  for (uint8_t i = 1; i < unparsed.length(); i++) {
    parsed = parsed + unparsed[i];
  }

  int delimiterIndex = parsed.indexOf(':'); // als mid-marker

  if (delimiterIndex > 0) {
    Parsed[0] = parsed.substring(0, delimiterIndex);
    Parsed[1] = parsed.substring(delimiterIndex + 1, parsed.length());
  } else {
    Parsed[0] = parsed;
  }
}
