#include <VirtualWire.h>

const int transmit_pin = 12;

struct package
{
  char message;
  float jakis_numer;
};

typedef struct package Package;
Package data;

void setup()
{
  Serial.begin(9600);
  Serial.println("Setup of transmitter.");
 
  vw_set_tx_pin(transmit_pin);
  vw_set_ptt_inverted(true);
  vw_setup(500);
}

void loop()
{
  readSensor();

  if(vw_send((uint8_t *)&data, sizeof(data))){
    Serial.println("Successfuly sent message.");
  }else{
    Serial.println("There was an error of sending message.");
  }
  vw_wait_tx();

  delay(2000);
}

void readSensor()
{
  delay(1000);
  data.message = 'e';
  data.jakis_numer = 21.37;
}
