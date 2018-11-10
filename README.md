# suspension_tuner-arduino
This is a very simple program for Arduino to measure a distance with the ultrasonic sensor HC-SR04 
and send the measured data to any device via bluetooth with the HC-05 bluetooth module.
This setup of the HC-SR04 can be used for distances up to ~30cm and is optimized to measure in a high frequency. 
The distance is not calculated on the Arduino. It only returns the measured time of the ultrasonic impulse.
Output-format, to e.g. a bluetooth terminal, is for every measured value:

\<arduino lifetime in millis\>,\<measured time of ultrasonic impulse in microseconds\>\n

To run the program you need ST_HW_HC_SR04 the library from https://github.com/Spaguetron/ST_HW_HC_SR04 for 
the HC-SR04 and the SoftwareSerial library (is included in Arduino IDE).

How the HC-SR04 and the HC05 have to be connected to the Arduino you can see here:

|    HC-SR04   	|    Arduino    |     HC-05     |
|:-------------:|:-------------:|:-------------:|
|     GND       |     GND       |      GND      |
|     VCC       |     5V        |      VCC      |
|     ECHO      |     D11       |               |
|     TRIG      |     D12       |               |
|               |     D2        |      TXD      |
|               |     D3        |      RXD      |
|               |     D4        |     STATE     |
