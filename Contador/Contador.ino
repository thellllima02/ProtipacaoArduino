bool high = 0;
unsigned long counter = 0;

void setup() {
  Serial.begin(19200);
  pinMode(6, INPUT);

}

void loop() {
  if(digitalRead(6)) high = 1;

  if(!digitalRead(6) && high){
    high = 0;
    counter +=1;
    Serial.println(counter);
  } 

}
