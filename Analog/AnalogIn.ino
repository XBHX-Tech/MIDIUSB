#include <MIDIUSB.h>

void controlChange(byte channel, byte control, byte value){
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void setup(){
  pinMode(A0, INPUT);
}

void loop(){
  int potState = map(analogRead(A0), 0, 1023, 0, 127);
  controlChange(0, 3, potState);
  MidiUSB.flush();
  delay(100);
}
