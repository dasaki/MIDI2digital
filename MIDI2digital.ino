/*
 * MIDI to DIGITAL
 * 
 * Turns pins status to HIGH or LOW according to the MIDI notes received.
 * 
 * 
 * Based in MIDIUSB_read.ino
 *
 * Created: 4/6/2015 10:47:08 AM
 * Author: gurbrinder grewal
 * Modified by Arduino LLC (2015)
 * 
 * Modified: 5/12/2022 by David Sanz Kirbis
 * Added mapping to set pins to HIGH/LOW depending on the midi notes received
 * 
 */ 

// #define SERIAL_DEBUG

#include "MIDIUSB.h"

int led = 13;
#define MAX_NOTES 32
unsigned char  mapping[MAX_NOTES][3] = {
  // { midi note, pin, value }
  // #1 -> A0
  {0x30, A0, LOW},
  {0x31, A0, HIGH},
  // #2 -> A1
  {0x32, A1, LOW},
  {0x33, A1, HIGH},
  // #3 -> A2
  {0x35, A2, LOW},
  {0x36, A2, HIGH},
  // #4 -> A3
  {0x37, A3, LOW},
  {0x38, A3, HIGH},
  // #5 -> D2
  {0x39, 2, LOW},
  {0x3A, 2, HIGH},
  // #6 -> D3
  {0x3C, 3, LOW},
  {0x3D, 3, HIGH},
  // #7 -> D4
  {0x3E, 4, LOW},
  {0x3F, 4, HIGH},
  // #8 -> D5
  {0x41, 5, LOW},
  {0x42, 5, HIGH},
  // #9 -> D6
  {0x43, 6, LOW},
  {0x44, 6, HIGH},
  // #10 -> D7
  {0x45, 7, LOW},
  {0x46, 7, HIGH},
  // #11 -> D8
  {0x48, 8, LOW},
  {0x49, 8, HIGH},
  // #12 -> D9
  {0x4A, 9, LOW},
  {0x4B, 9, HIGH},
  // #13 -> D10
  {0x4D, 10, LOW},
  {0x4E, 10, HIGH},
  // #14 -> D11
  {0x4F, 11, LOW},
  {0x50, 11, HIGH},
  // #15 -> D12
  {0x51, 12, LOW},
  {0x52, 12, HIGH},
  // #16 -> D13
  {0x54, 13, LOW},
  {0x55, 13, HIGH}
  
};

void setup() {
    for (int i = 2; i <= 13; i++)  pinMode(i, OUTPUT);
    for (int i = A0; i < A5; i++)  pinMode(i, OUTPUT);
#ifdef SERIAL_DEBUG
  Serial.begin(115200);
#endif
  /*while (!Serial){
    ;
  }*/
}

void clearPins() {
  for (int i = 2; i < 14; i++)  digitalWrite(i, LOW);
  for (int i = A0; i < A5; i++)   digitalWrite(i, LOW);
}
/*
 *   SET PIN
 *   
 *   Uses the received midi note to set a pin HIGH or LOW 
 *   according to the mapping matrix.
 *   
 */
void setPin(unsigned char midiNote) {
  int i = 0;
  while ((mapping[i][0] != midiNote) &&  ( i < MAX_NOTES)){
    i++;
  }
  if (i < MAX_NOTES) { 
    digitalWrite(mapping[i][1], mapping[i][2]);
#ifdef SERIAL_DEBUG
    Serial.print(i);
    Serial.print("  Pin: ");
    Serial.print(mapping[i][1]);
    Serial.print(" ");
    Serial.println(mapping[i][2]? "HIGH":"LOW");
#endif
  }
}

void loop() {
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
#ifdef SERIAL_DEBUG
      Serial.print("Received: ");
    /*  Serial.print(rx.header, HEX);
      Serial.print("-");
      Serial.print(rx.byte1, HEX);
      Serial.print("-");*/
      Serial.println(rx.byte2, HEX);
     /* Serial.print("-");
      Serial.println(rx.byte3, HEX);*/
#endif
      setPin(rx.byte2);
    }
  } while (rx.header != 0);
}
