#include <Arduino.h>

enum Estado {
  DESLIGADO,
  ENCHENDO,
  CHEIO,
  FALHA
};

Estado estadoAtual = DESLIGADO;
unsigned long tempoAnterior = 0;
const unsigned long intervalo = 2000;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Sistema iniciado...");
}

void loop() {
  unsigned long agora = millis();

  
  switch(estadoAtual){
    
    case DESLIGADO:
    if(agora - tempoAnterior >= intervalo){
    Serial.println("Estado: Desligado");
    estadoAtual = ENCHENDO;
      tempoAnterior = agora;

    }
    break;
    case ENCHENDO:
    if(agora - tempoAnterior >= intervalo){
    Serial.println("Enchendo...");
    estadoAtual = CHEIO;
    
      tempoAnterior = agora;

    }
    break;
    case CHEIO:
        if(agora - tempoAnterior >= intervalo){
    Serial.println("Cheio!");
    estadoAtual = FALHA;
    
      tempoAnterior = agora;

    }
    break;
    case FALHA:
        if(agora - tempoAnterior >= intervalo){
    Serial.println("Deu falha...");
    estadoAtual = DESLIGADO;
    
      tempoAnterior = agora;

    }
    break;
  }

}
