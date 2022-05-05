#include <Servo.h>

const int letDownYourHair = 13;
const int windowRapunzel = 10;
const int lantern1 = 5;
const int lantern2 = 4;

int letDownYourHairState = 0;
int windowRapunzelState = 0;

Servo servo;

void setup() {

  pinMode(lantern1, OUTPUT);
  pinMode(lantern2, OUTPUT);
  pinMode(windowRapunzel, INPUT);

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

  Serial.println(letDownYourHairState);
}
