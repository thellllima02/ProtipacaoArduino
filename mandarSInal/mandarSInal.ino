#include <IRremote.h>

const int irEmitterPin = 3; // Pino conectado ao emissor IR
IRsend irSender;

unsigned long ligarCodigo = 0x4E5B7891;  // Substitua pelo código capturado para "Ligar"
unsigned long desligarCodigo = 0xEC6DD3FA; // Substitua pelo código capturado para "Desligar"

void setup() {
  Serial.begin(9600);
  irSender.begin(irEmitterPin); // Inicializa o emissor IR
  Serial.println("Pressione 'L' para ligar ou 'D' para desligar o ar-condicionado");
}

void loop() {
  if (Serial.available()) {
    char comando = Serial.read(); // Lê o comando do monitor serial
    if (comando == 'L') {
      Serial.println("Enviando comando para LIGAR");
      irSender.sendNEC(ligarCodigo, 32); // Envia o código para Ligar
    } else if (comando == 'D') {
      Serial.println("Enviando comando para DESLIGAR");
      irSender.sendNEC(desligarCodigo, 32); // Envia o código para Desligar
    }
  }
}
