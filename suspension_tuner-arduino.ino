#include <SoftwareSerial.h>
#include <ST_HW_HC_SR04.h>

#define BT_STATE_PIN 4
#define BT_SERIAL_TX_PIN 2
#define BT_SERIAL_RX_PIN 3

#define US_TRIG_PIN 12
#define US_ECHO_PIN 11
#define US_TIMEOUT 3000L

SoftwareSerial btSerial(BT_SERIAL_TX_PIN, BT_SERIAL_RX_PIN);

ST_HW_HC_SR04 sensor = ST_HW_HC_SR04(US_TRIG_PIN,US_ECHO_PIN,US_TIMEOUT);
long a;

void setup()
{
  // maybe you have to check if the bluetooth module uses another baud rate
  btSerial.begin(9600);
}

void loop()
{
  if(connected())
  {
    a=sensor.getHitTime();
    btSerial.print(millis());
    btSerial.print(",");
    btSerial.println(a);
  }
}

bool connected()
{
    return(digitalRead(BT_STATE_PIN));
}
