/*
 * IRremoteESP8266: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * This is very simple teaching code to show you how to use the library.
 * If you are trying to decode your Infra-Red remote(s) for later replay,
 * use the IRrecvDumpV2.ino example code instead of this.
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Copyright 2009 Ken Shirriff, http://arcfn.com
 * Example circuit diagram:
 *  https://github.com/markszabo/IRremoteESP8266/wiki#ir-receiving
 * Changes:
 *   Version 0.2 June, 2017
 *     Changed GPIO pin to the same as other examples.
 *     Used our own method for printing a uint64_t.
 *     Changed the baud rate to 115200.
 *   Version 0.1 Sept, 2015
 *     Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009
 */

#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

// An IR detector/demodulator is connected to GPIO pin 14(D5 on a NodeMCU
// board).
uint16_t RECV_PIN = 14;

// An LED is connected to GPIO16 (D0 on a NodeMCU Board)
uint16_t LED_PIN = 16;

// define key code
#define KEY_CODE_POWER        0x265BCC7E          // 开关
#define KEY_CODE_SPEED        0x68E5907E          // 风速
#define KEY_CODE_SWING        0xA6BEF07E          // 摇头/导风
#define KEY_CODE_TIMER        0x3768107E          // 定时
#define KEY_CODE_MUTE         0x37B84C7E          // 静音
#define KEY_CODE_TYPE         0x5C8A787E          // 风类


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();  // Start the receiver
  while (!Serial)       // Wait for the serial connection to be establised.
    delay(50);
  Serial.println();
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(RECV_PIN);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    
    switch(results.value)
    {
      case KEY_CODE_POWER:
        blink_led();
        Serial.print("POWER CODE:");
        break;
      case KEY_CODE_SPEED:
        blink_led();
        Serial.print("SPEED CODE:");
        break;
      case KEY_CODE_SWING:
        blink_led();
        Serial.print("SHAKE CODE:");
        break;
      case KEY_CODE_TIMER:
        blink_led();
        Serial.print("TIMER CODE:");
        break;
      case KEY_CODE_MUTE:
        blink_led(5);
        Serial.print("MUTE CODE:");
        break;
      case KEY_CODE_TYPE:
        blink_led();
        Serial.print("TYPE CODE:");
        break;
    }
    
    // print() & println() can't handle printing long longs. (uint64_t)
    serialPrintUint64(results.value, HEX);
    Serial.println("");
    
    irrecv.resume();  // Receive the next value
  }

}

// 闪烁一次LED
void blink_led()
{
  digitalWrite(LED_PIN, LOW);
    
  delay(500);
  
  digitalWrite(LED_PIN, HIGH);
}

