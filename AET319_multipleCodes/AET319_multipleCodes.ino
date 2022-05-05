#include <Servo.h>
#include "pitches.h"

const int letDownYourHair = 13;
const int windowRapunzel = 10;
const int lantern1 = 5;
const int lantern2 = 4;
const int rapunzelHair = 12;

int letDownYourHairState = LOW;
int windowRapunzelState = LOW;
int rapunzelHairState = LOW;

// notes in the melody:
int melody[] = {
  NOTE_FS4, NOTE_B4, NOTE_E4, NOTE_FS4, NOTE_DS4, 0, NOTE_FS4, NOTE_B4, NOTE_E4, NOTE_FS4, NOTE_DS4, 0, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_E4, 0, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_D4, NOTE_E4, NOTE_FS4, 0, NOTE_FS3, NOTE_CS4, NOTE_D4, NOTE_B3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2, 4, 2, 4, 1, 2, 2, 4, 2, 4, 1, 2, 2, 4, 4, 4, 1, 2, 4, 4, 4, 2, 4, 1, 2, 2, 2, 2, 1
};

Servo servo;

void setup() {

  pinMode(lantern1, OUTPUT);
  pinMode(lantern2, OUTPUT);
  pinMode(windowRapunzel, INPUT);
  pinMode(rapunzelHair, INPUT);


  // servo setup
  servo.attach(3);

  //button setup
  pinMode(letDownYourHair, INPUT);

  Serial.begin(9600);
}

void loop() {
  windowRapunzelState = digitalRead(windowRapunzel);

  if (windowRapunzelState == HIGH) {
    digitalWrite(lantern1, HIGH);
    digitalWrite(lantern2, HIGH);

  } else {
    digitalWrite(lantern1, LOW);
    digitalWrite(lantern2, LOW);

  }

  letDownYourHairState = digitalRead(letDownYourHair);
  if (digitalRead(13) == LOW) {
    servo.write(180);
  } else {
    servo.write(90);
  }

  rapunzelHairState = digitalRead(rapunzelHair);
  if (rapunzelHairState == HIGH) {
    buzzer();
  }
  Serial.println(letDownYourHairState);
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
