#include <VirtualWire.h>

const int receive_pin = 12;

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
  Serial.println("Setup of receiver.");
  delay(1000);

  vw_set_rx_pin(receive_pin);
  vw_setup(500);

  vw_rx_start();
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_have_message())
  {
    Serial.println("Got a new message!");
    
    vw_get_message(buf, &buflen);
    memcpy(&data, &buf, buflen);
    
    Serial.println("data.message: " + (String)data.message);
    Serial.println("data.message: " + (String)data.jakis_numer);
  }
}
