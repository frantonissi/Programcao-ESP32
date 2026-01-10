#include <Arduino.h>



#define ledVm 15
#define ledAm 2
#define ledVd 4

void configuracao();
void Vermelho();
void Amarelo();
void Verde();

void setup(){
  configuracao();
}

void loop(){
  Vermelho();
  Amarelo();
  Verde();
}

void configuracao(){
  pinMode(ledVm, OUTPUT);
  pinMode(ledAm, OUTPUT);
  pinMode(ledVd, OUTPUT);
}

void Vermelho(){
  digitalWrite(ledVm, HIGH);
  digitalWrite(ledAm, LOW);
  digitalWrite(ledVd, LOW);
  delay(5000);
}
void Amarelo(){
  digitalWrite(ledVm, LOW);
  digitalWrite(ledAm, HIGH);
  digitalWrite(ledVd, LOW);
  delay(6000);
}
void Verde(){
  digitalWrite(ledVm, LOW);
  digitalWrite(ledAm, LOW);
  digitalWrite(ledVd, HIGH);
  delay(7000);
}
