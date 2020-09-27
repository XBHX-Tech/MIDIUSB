#include <MIDIUSB.h>

void noteOn(byte channel, byte pitch, byte velocity){
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity){
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value){
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void setup()
{
  pinMode(2, INPUT);
}

void loop()
{
  if(digitalRead(2) == 1)
  {
    noteOn(0, 48, 127);
    MidiUSB.flush();
    delay(3000);
  }
  else
  {
    noteOff(0, 48, 0);
    MidiUSB.flush();
    delay(3000);
  }
}
