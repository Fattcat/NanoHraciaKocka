int buttonPin = 8;
int ledPins[] = {2, 3, 4, 5, 6, 7};
int randomNumber = 0;
bool displayNumber = false;

// 
// CONNECTION SCHEME
// 
// LED 1 --> D2
// LED 2 --> D3
// LED 3 --> D4
// LED 4 --> D5
// LED 5 --> D6
// LED 6 --> D7
// Button 1 --> D8
// 

void setup() {
  randomSeed(analogRead(0));
  pinMode(buttonPin, INPUT_PULLUP);
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Vypnutie LED diód pri inicializácii
  }
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    if (!displayNumber) {
      int randomTime = random(1, 7); // Generovanie náhodného čísla od 1 do 6
      randomNumber = randomTime;

      for (int i = 0; i < 6; i++) {
        if (i < randomTime) {
          analogWrite(ledPins[i], 10); // Zapnutie LED diód na sile 100 (nižší jas)
        } else {
          digitalWrite(ledPins[i], LOW); // Vypnutie LED diód
        }
      }
      displayNumber = true;
    }
  } else if (displayNumber) {
    delay(2000); // Diódy zostanú svietiť po vygenerovaní čísla 2 sekundy
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], LOW); // Vypnutie všetkých LED diód
    }
    displayNumber = false;
  }
}
