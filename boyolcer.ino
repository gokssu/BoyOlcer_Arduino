int trigPin= 7;
int echoPin= 6;
int ledred= 2;
int ledblue= 4;
int ledgreen= 3;
int ledyellow= 8;
int buttonPin = 5;

int centimetre;
int time;
int sabitcm;
int boy;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledred, OUTPUT);   
  pinMode(ledblue, OUTPUT);   
  pinMode(ledgreen, OUTPUT);
 pinMode(ledyellow, OUTPUT);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time = pulseIn(echoPin, HIGH);  
  sabitcm = (time/29.1/2);
 
Serial.begin(9600);
}

void loop() {
  if(digitalRead(buttonPin) == 1){
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  time = pulseIn(echoPin, HIGH);  
  centimetre = (time/29.1/2);
 
  boy = sabitcm - centimetre;
  
  Serial.print(sabitcm);
  Serial.println(" cm");
  delay(1000);
  Serial.print(boy);
  Serial.println(" cm");
 
    if ((boy<10) ){
      digitalWrite(ledgreen,LOW);
      digitalWrite(ledblue,LOW);
      digitalWrite(ledred,HIGH);
      digitalWrite(ledyellow,LOW);
    } 
   
    else if((boy>10)&& (boy<15)  ){
      digitalWrite(ledgreen,HIGH);
      digitalWrite(ledblue,LOW);
      digitalWrite(ledred,HIGH);
      digitalWrite(ledyellow,LOW);
    }
    else if((boy>15)&& (boy<20)){
      digitalWrite(ledgreen,HIGH);
      digitalWrite(ledblue,HIGH);
      digitalWrite(ledred,HIGH);
      digitalWrite(ledyellow,LOW);
    }
     else if((boy>20)){
      digitalWrite(ledgreen,HIGH);
      digitalWrite(ledblue,HIGH);
      digitalWrite(ledred,HIGH);
      digitalWrite(ledyellow,HIGH);
    }
}
}
