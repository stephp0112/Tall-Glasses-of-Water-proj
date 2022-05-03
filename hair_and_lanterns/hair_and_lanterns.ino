#include <Servo.h>

const int GothelbuttonPin = 13;
const int switchPin = 10;
const int ledPin1 = 5;
const int ledPin2 = 4;

int buttonState = 0;
int switchState = 0;

Servo servo;

void setup() {

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(switchPin, INPUT);

  // servo setup
  servo.attach(3);

  //button setup
  pinMode(GothelbuttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);

  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);

  }

  buttonState = digitalRead(GothelbuttonPin);
  if (digitalRead(13) == LOW) {
    servo.write(180);
  } else {
    servo.write(0);
  }

  Serial.println(buttonState);
}
