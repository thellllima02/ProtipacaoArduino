#include <IRremote.h>

const int irReceiverPin = 2;  // Pino conectado ao receptor IR
IRrecv irReceiver(irReceiverPin);  // Inicializa o receptor IR no pino 2
decode_results results;  // Estrutura para armazenar os dados decodificados

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial
  irReceiver.begin(irReceiverPin);  // Inicia o receptor IR
  Serial.println("Aponte o controle remoto para o receptor e pressione um botão.");
}

void loop() {
  if (irReceiver.decode(&results)) {
    Serial.print("Código recebido: 0x");
    Serial.println(results.value, HEX);  // Exibe o código em hexadecimal
    irReceiver.resume();  // Prepara o receptor para o próximo sinal
  }
}
