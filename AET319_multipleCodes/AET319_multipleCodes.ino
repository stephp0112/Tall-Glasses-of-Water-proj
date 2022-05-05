#include <Servo.h>
#include "pitches.h"

//switches
const int letDownYourHair = 13; //switch for window pushing hair servo
const int iWannaSeeTheLights = 11; // switch for mood swing gothel servo
const int motherGothelRuffians = 9;       //switch for activating the pop up servo

//LEDs for window
const int windowRapunzel = 10; //rapunzel that activates lights
const int lantern1 = 5;        //LED 1
const int lantern2 = 4;       //LED 2

//piezo
const int rapunzelHair = 12; //hair on ground that activates Piezo

//switch states
int letDownYourHairState = LOW; //switch for window servo
int windowRapunzelState = LOW; //rapunzel that activates lights
int rapunzelHairState = LOW; //hair on ground that activates Piezo
int iWannaSeeTheLightsState = LOW; //switch for mood swing gothel servo
int motherGothelRuffiansState = LOW;    //switch for activating the pop up servo

// notes in the melody:
int melody[] = {
  NOTE_FS4, NOTE_B4, NOTE_E4, NOTE_FS4, NOTE_DS4, 0, NOTE_FS4, NOTE_B4, NOTE_E4, NOTE_FS4, NOTE_DS4, 0, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_E4, 0, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_D4, NOTE_E4, NOTE_FS4, 0, NOTE_FS3, NOTE_CS4, NOTE_D4, NOTE_B3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2, 4, 2, 4, 1, 2, 2, 4, 2, 4, 1, 2, 2, 4, 4, 4, 1, 2, 4, 4, 4, 2, 4, 1, 2, 2, 2, 2, 1
};

Servo windowServo;
Servo gothelServo;

void setup() {

  pinMode(lantern1, OUTPUT);
  pinMode(lantern2, OUTPUT);
  pinMode(windowRapunzel, INPUT);
  pinMode(rapunzelHair, INPUT);
  pinMode(letDownYourHair, INPUT);
  pinMode(iWannaSeeTheLights, INPUT);
  pinMode(motherGothelRuffians, INPUT);


  // servo setup
  windowServo.attach(3);
  gothelServo.attach(7);
  ruffianServo.attach(2);

  //button setup

  Serial.begin(9600);
}

void loop() {
  windowRapunzelState = digitalRead(windowRapunzel);

  if (windowRapunzelState == HIGH) {
    digitalWrite(lantern1, HIGH);             //LEDs turning on and off
    digitalWrite(lantern2, HIGH);

  } else {
    digitalWrite(lantern1, LOW);
    digitalWrite(lantern2, LOW);

  }



  letDownYourHairState = digitalRead(letDownYourHair);
  if (digitalRead(13) == LOW) {
    windowServo.write(180);                 //servo that pushes hair out the window
  } else {
    windowServo.write(90);
  }




  iWannaSeeTheLightsState = digitalRead(iWannaSeeTheLights);
  if (digitalRead(11) == LOW) {
    gothelServo.write(180);                 //servo that turns mother gothel from happy to sad
  } else {
    gothelServo.write(0);
  }


motherGothelRuffiansState = digitalRead(motherGothelRuffians);
if (digitalRead(2) == LOW) {
  ruffianServo.write(180);
} else {
  ruffianServo.write(0);
}

  

  rapunzelHairState = digitalRead(rapunzelHair);
  if (rapunzelHairState == HIGH) {
    buzzer();                               //the hair that gets brushed and plays the piezo
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
