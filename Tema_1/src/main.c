#include <Arduino.h>

const int ledL1 = 10;
const int ledL2 = 9;
const int ledL3 = 8;
const int ledL4 = 7;
const int rgbRed = 6;
const int rgbGreen = 5;
const int rgbBlue = 4;
const int butonStart = 3;
const int butonStop = 2;

unsigned long lastDebounceStart = 0;
unsigned long lastDebounceStop = 0;
unsigned long debounceDelay = 50;

int lastButtonStateStart = LOW;
int buttonStateStart = LOW;

int lastButtonStateStop = LOW;
int buttonStateStop = LOW;

int charging = 0;
int stopPressedTime = 0;
int currentLED = 0;

unsigned long previousMillis = 0;
const long interval = 3000;

void setup()
{
  pinMode(ledL1, OUTPUT);
  pinMode(ledL2, OUTPUT);
  pinMode(ledL3, OUTPUT);
  pinMode(ledL4, OUTPUT);
  pinMode(rgbRed, OUTPUT);
  pinMode(rgbBlue, OUTPUT);
  pinMode(rgbGreen, OUTPUT);
  pinMode(butonStart, INPUT_PULLUP);
  pinMode(butonStop, INPUT_PULLUP);

  // initial, ledul RGB = verde
  digitalWrite(rgbGreen, HIGH);
  digitalWrite(rgbRed, LOW);
  digitalWrite(rgbBlue, LOW);
  digitalWrite(ledL1, LOW);
  digitalWrite(ledL2, LOW);
  digitalWrite(ledL3, LOW);
  digitalWrite(ledL4, LOW);
}

void blinkLed(int ledPin)
{
  unsigned long startMillis = millis();
  while (millis() - startMillis < interval)
  {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}

void animatie_final()
{
  delay(10);
  charging = 0;
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(ledL1, HIGH);
    digitalWrite(ledL2, HIGH);
    digitalWrite(ledL3, HIGH);
    digitalWrite(ledL4, HIGH);
    delay(500);
    digitalWrite(ledL1, LOW);
    digitalWrite(ledL2, LOW);
    digitalWrite(ledL3, LOW);
    digitalWrite(ledL4, LOW);
    delay(500);
  }
  digitalWrite(rgbGreen, HIGH);
  digitalWrite(rgbBlue, LOW);
  digitalWrite(rgbRed, LOW);
  digitalWrite(ledL1, LOW);
  digitalWrite(ledL2, LOW);
  digitalWrite(ledL3, LOW);
  digitalWrite(ledL4, LOW);
}
void loop()
{
  unsigned long currentMillis = millis();

  int readingStart = digitalRead(butonStart);
  int readingStop = digitalRead(butonStop);

  // buton Start
  if (readingStart != lastButtonStateStart)
    lastDebounceStart = millis();

  if ((millis() - lastDebounceStart) > debounceDelay)
  {
    if (readingStart != buttonStateStart)
    {
      buttonStateStart = readingStart;
      if (buttonStateStart == LOW && charging == 0)
      {
        delay(20);
        charging = 1;
        currentLED = 1;
        digitalWrite(rgbGreen, LOW);
        digitalWrite(rgbBlue, LOW);
        digitalWrite(rgbRed, HIGH);
        previousMillis = millis();
      }
    }
  }

  // buton stop
  if (readingStop != lastButtonStateStop)
    lastDebounceStop = millis();

  if ((millis() - lastDebounceStop) > debounceDelay)
  {
    if (readingStop != buttonStateStop)
    {
      buttonStateStop = readingStop;
      if (buttonStateStop == LOW && charging == 1)
      {
        if ((millis() - stopPressedTime) >= 1000)
          animatie_final();
      }
      else if (buttonStateStop == HIGH)
        stopPressedTime = millis();
    }
  }

  if (charging == 1)
  {
    static unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();

    if (currentLED == 1)
    {
      blinkLed(ledL1);
      digitalWrite(ledL1, HIGH);
      previousMillis = currentMillis;
    }
    if (currentLED == 2)
    {
      blinkLed(ledL2);
      digitalWrite(ledL2, HIGH);
      previousMillis = currentMillis;
    }
    if (currentLED == 3)
    {
      blinkLed(ledL3);
      digitalWrite(ledL3, HIGH);
      previousMillis = currentMillis;
    }
    if (currentLED == 4)
    {
      blinkLed(ledL4);
      digitalWrite(ledL4, HIGH);
      previousMillis = currentMillis;
    }

    currentLED++;
    if (currentLED > 4)
    {
      animatie_final();
    }
  }
  lastButtonStateStart = readingStart;
  lastButtonStateStop = readingStop;
}