#include <IRremote.h>

const int irReceiverPin = 2; // Pino conectado ao receptor IR

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(irReceiverPin, INPUT); // Define o pino do receptor IR como entrada

  // Inicia o receptor IR (compatível com versões mais recentes da IRremote)
  IrReceiver.begin(irReceiverPin, ENABLE_LED_FEEDBACK); 
  Serial.println("Aponte o controle remoto para o receptor e pressione um botão.");
}

void loop() {
  // Verifica se há dados disponíveis no receptor IR
  if (IrReceiver.decode()) {
    // Exibe o código recebido em hexadecimal
    Serial.print("Código recebido: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // Reseta o receptor para o próximo sinal
    IrReceiver.resume();
  }
}

