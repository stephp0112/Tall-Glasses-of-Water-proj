/*
  circuit:
  - Piezo is on pin 8
  (Breadboard setup)
  ground wire goes on short leg
  resistor goes on + sign side
  green pin wire goes on other end of resistor
  the other end of green wire goes into pin (in this case pin 8)
*/

#include "pitches.h"

const int switchPin = 13;
int switchState = LOW;

// notes in the melody:
int melody[] = {
  NOTE_FS4, NOTE_B4, NOTE_E4, NOTE_FS4, NOTE_DS4, 0, NOTE_FS4, NOTE_B4, NOTE_E4, NOTE_FS4, NOTE_DS4, 0, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_E4, 0, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_D4, NOTE_E4, NOTE_FS4, 0, NOTE_FS3, NOTE_CS4, NOTE_D4, NOTE_B3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2, 4, 2, 4, 1, 2, 2, 4, 2, 4, 1, 2, 2, 4, 4, 4, 1, 2, 4, 4, 4, 2, 4, 1, 2, 2, 2, 2, 1
};

void setup() {
  pinMode(switchPin, INPUT);

}

void loop() {
  switchState = digitalRead(switchPin);
  if (switchState == HIGH) {
    buzzer();
  }
}

void buzzer() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 30; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
