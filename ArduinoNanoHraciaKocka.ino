int buttonPin = 8;
int ledPins[] = {2, 3, 4, 5, 6, 7};
int displayState = 0;
bool buttonPressed = false;
int brightnessLevel = 50; // Nastavte hodnotu intenzity svietenia (0 - 255)

void setup() {
  randomSeed(analogRead(0));
  pinMode(buttonPin, INPUT_PULLUP);
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    int randomTime = random(1, 7);
    for (int i = 0; i < randomTime; i++) {
      analogWrite(ledPins[i], brightnessLevel); // Nastavte intenzitu svietenia
    }
    displayState = randomTime;
    delay(1000); // Počkajte 1 sekundu
    for (int i = 0; i < displayState; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }

  if (digitalRead(buttonPin) == HIGH && buttonPressed) {
    buttonPressed = false;
  }
}
