//THIS CODE IS FOR THE BUTTON + LED

//constant variables
const int switchPin = 13;
const int ledPin1 = 4;
const int ledPin2 = 3;

//variables that change
int switchState = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(switchPin, INPUT);
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
}
