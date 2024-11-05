#include <Arduino.h>

const int rgbRed = 6;
const int rgbGreen = 5;
const int rgbBlue = 4;
const int btnStart = 3;
const int btnDiff = 2;

bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

unsigned long timpUltimulCuv = 0;
unsigned long timpNivel = 3000;
unsigned long timpInceput = 0;

String vecCuvinte[] = {
    "iso", "blit", "raw", "zoom", "bokeh",
    "lumina", "senzor", "vizor", "macro", "editare",
    "scena", "auto", "clar", "cadru", "focal",
    "filtru", "portret", "aperture", "obiectiv", "noise"};
int cntCuvinte = 0, maxCuvinte = 20;

bool rundaActiva = false;
int nivelDiff = 0;
int cuvCorecte = 0;
bool ultimulCuv = false;

void setareCuloare(int red, int green, int blue)
{
  analogWrite(rgbRed, red);
  analogWrite(rgbGreen, green);
  analogWrite(rgbBlue, blue);
}

void setup()
{
  pinMode(rgbRed, OUTPUT);
  pinMode(rgbGreen, OUTPUT);
  pinMode(rgbBlue, OUTPUT);

  pinMode(btnStart, INPUT_PULLUP);
  pinMode(btnDiff, INPUT_PULLUP);
  setareCuloare(255, 255, 255);
  Serial.begin(9600);
}

void countDown()
{
  int i = 3;
  while (i)
  {
    Serial.println(i);
    setareCuloare(0, 255, 0);
    delay(500);
    setareCuloare(0, 0, 0);
    delay(500);
    i--;
  }
}

void dificultate()
{
  switch (nivelDiff)
  {
  case 0:
    Serial.println("Easy mode on!");
    timpNivel = 3000;
    break;
  case 1:
    Serial.println("Medium mode on!");
    timpNivel = 2000;
    break;
  case 2:
    Serial.println("Hard mode on!");
    timpNivel = 1000;
    break;
  }
}

void incepe()
{
  rundaActiva = true;

  cuvCorecte = 0;
  cntCuvinte = random(0, maxCuvinte);

  timpInceput = millis();
  timpUltimulCuv = millis();

  Serial.print("--------> ");
  Serial.println(vecCuvinte[cntCuvinte]);

  setareCuloare(0, 255, 0);
}

void sfarsit()
{
  rundaActiva = false;

  setareCuloare(255, 255, 255);

  Serial.print("Jocul s-a terminat. Raspunsuri corecte: ");
  Serial.println(cuvCorecte);
}

void loop()
{
  if (digitalRead(btnStart) == LOW && !rundaActiva)
  {
    delay(300);
    countDown();
    incepe();
  }

  if (digitalRead(btnDiff) == LOW && !rundaActiva)
  {
    delay(300);
    nivelDiff = (nivelDiff + 1) % 3;
    dificultate();
    while (digitalRead(btnDiff) == LOW)
    {
    }
  }

  if (rundaActiva)
  {
    if (millis() - timpUltimulCuv >= timpNivel)
    {
      cntCuvinte = random(0, maxCuvinte);

      Serial.print("Timp scurs --------> ");
      Serial.println(vecCuvinte[cntCuvinte]);

      timpUltimulCuv = millis();
    }

    if (Serial.available() > 0)
    {
      String inputCuvant = Serial.readStringUntil('\n');
      Serial.flush();
      inputCuvant.trim();

      Serial.println(inputCuvant);

      if (inputCuvant.equals(vecCuvinte[cntCuvinte]))
      {
        cuvCorecte++;
        cntCuvinte = random(0, maxCuvinte);
        timpUltimulCuv = millis();

        Serial.println("Corect --------> " + vecCuvinte[cntCuvinte]);
        setareCuloare(0, 255, 0);

        ultimulCuv = false;
      }
      else
      {
        Serial.println("Incorect.");
        setareCuloare(255, 0, 0);

        ultimulCuv = true;
      }
    }
    if (ultimulCuv)
      setareCuloare(255, 0, 0);
    // daca ultimul cuv a fost gresit, ledul rosu ramane aprins

    if (digitalRead(btnStart) == LOW)
    {
      delay(300);
      sfarsit();
    }

    if (millis() - timpInceput >= 30000)
      sfarsit();
  }
}
