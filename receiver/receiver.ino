#include <VirtualWire.h>

const int receive_pin = 12;

struct package
{
  String message = "co jest panie ferdku";
  float jakis_numer = 0.0;
};

typedef struct package Package;
Package data;

void setup()
{
  Serial.begin(9600);
  delay(1000);

  // Initialise the IO and ISR
  vw_set_rx_pin(receive_pin);
  vw_setup(500); // Bits per sec
  vw_rx_start(); // Start the receiver PLL running
}

void loop()
{
  uint8_t buf[sizeof(data)];
  uint8_t buflen = sizeof(data);

  if (vw_have_message()) // Is there a packet for us?
  {
    vw_get_message(buf, &buflen);
    memcpy(&data, &buf, buflen);
    Serial.println("Package:");
    Serial.println("data.message: %s",data.message);
    Serial.println("data.message: %s",data.jakis_numer);
  }
}
