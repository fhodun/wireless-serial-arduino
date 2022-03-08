#include <VirtualWire.h>

const int led_pin = 13;
const int transmit_pin = 12;

struct package
{
  String message;
  float jakis_numer;
};

typedef struct package Package;
Package data;

void setup()
{
  // Initialise the IO and ISR
  vw_set_tx_pin(transmit_pin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(500); // Bits per sec

  pinMode(led_pin, OUTPUT);
}

void loop()
{
  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  readSensor();

  vw_send((uint8_t *)&data, sizeof(data));
  vw_wait_tx(); // Wait until the whole message is gone

  digitalWrite(led_pin, LOW);

  delay(2000);
}

void readSensor()
{
  delay(1000);
  data.message = "elo elo 320";
  data.jakis_numer = 21.37;
}
