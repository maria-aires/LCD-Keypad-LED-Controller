#include <LiquidCrystal.h>


const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// LEDs
const int ledVermelho = A1;
const int ledVerde = A2;


void setup() {


  lcd.begin(16, 2);
  Serial.begin(9600);


  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);


  lcd.setCursor(0, 0);
  lcd.print("CONTROLE LEDS");
  lcd.setCursor(0, 1);
  lcd.print(" VERDE/VERMELHO");
}


void select() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DOWM-PI/LEFT-DES");
  lcd.setCursor(0,1);
  lcd.print("UP-VD/RIGHT-VM");
  }


void left() {
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVerde, LOW);


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LEDS APAGADOS");
}


void up() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED VERDE");


  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVerde, HIGH);
}


void down() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PISCANDO");


  for (int i = 0; i < 5; i++) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, HIGH);
    delay(300);


    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, LOW);
    delay(300);
  }
}


void right() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED VERMELHO");


  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);
}


void loop() {


  int leitura = analogRead(A0);


  if (leitura < 80) {
    right();
  }
  else if (leitura < 200) {
    up();
  }
  else if (leitura < 400) {
    down();
  }
  else if (leitura < 600) {
    left();
  }
  else if (leitura < 800) {
    select();
  }


  delay(100);
}


