int buttonPin = 8;
int ledPins[] = {2, 3, 4, 5, 6, 7};
bool buttonPressed = false;
int brightnessLevel = 10;

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
    int randomTime = random(2, 7); // Generovať náhodné číslo od 2 do 7

    for (int i = 0; i < randomTime; i++) {
      analogWrite(ledPins[i], brightnessLevel); // Zapnúť náhodné diódy s nastavenou intenzitou svietenia
      digitalWrite(ledPins[i], HIGH);
    }

    delay(1000);
    for (int i = 0; i < 6; i++) {
      analogWrite(ledPins[i], 0); // Vypnúť všetky diódy nastavením intenzity na 0
    }
  }

  if (digitalRead(buttonPin) == HIGH && buttonPressed) {
    buttonPressed = false;
  }
}
