const int distancia_carro = 10; 


//Sensor
const int TRIG = 3;
const int ECHO = 2;

//LED
const int ledRed = 13;


void setup() {
  Serial.begin(9600);
  
  // Configurações do Sensor
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
  // Configurações do LED
  pinMode(ledRed, OUTPUT);  
}

void loop() {
  int distancia = sensor_morcego(TRIG,ECHO);

    if (distancia <= distancia_carro) {
    Serial.print("Ocupado: ");
    Serial.print(distancia);
    Serial.println("cm");
    digitalWrite(ledRed, HIGH);  // Liga o LED para "Ocupado"
}
else if (distancia <= 20) {
    Serial.print("Cuidado: ");
    Serial.print(distancia);
    Serial.println("cm");
    digitalWrite(ledRed, HIGH);  // Liga o LED para "Cuidado"
}
else {
    Serial.print("Livre: ");
    Serial.print(distancia);
    Serial.println("cm");
    digitalWrite(ledRed, LOW);   // Desliga o LED para "Livre"
}


  delay(1000);
  
}

int sensor_morcego(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(5);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(20);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}

