
#include <Arduino.h>

#define LED 2

unsigned long tempo_Anterior = 0;
const unsigned long intervalo1 = 200;
const unsigned long intervalo2 = 600;
const unsigned long intervalo3 = 200;

enum MOMENTOS{
  CURTO,
  ENTRE1,
  LONGO,
  ENTRE2
};

MOMENTOS piscada = CURTO;


void setup(){
    pinMode(LED, OUTPUT);

}

void loop(){
  boolean botao = true;
  unsigned long agora = millis();
  switch(piscada){ 
    case CURTO:
  if(botao && agora - tempo_Anterior >= intervalo1){
    digitalWrite(LED, HIGH);
    piscada = ENTRE1;
        tempo_Anterior = agora;
  }
    break;
  
    case ENTRE1:
  if(botao && agora - tempo_Anterior >= intervalo3){
    digitalWrite(LED, LOW);
    piscada = LONGO;
        tempo_Anterior = agora;
  }
    break;
  
  case LONGO:
  if(botao && agora - tempo_Anterior >= intervalo2){
    digitalWrite(LED, HIGH);
    piscada = ENTRE2;
        tempo_Anterior = agora;
  }
    break;
  case ENTRE2:
  if(botao && agora - tempo_Anterior >= intervalo3){
    digitalWrite(LED, LOW);
    piscada = CURTO;
        tempo_Anterior = agora;
  }
    break;
}
  
}