#define echoPin 8
#define trigPin 9

int m11=2,m12=3,m21=4,m22=5,irl=6,irr=7,duration,distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(irl,INPUT);
  pinMode(irr,INPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  if(digitalRead(irr)==1 && (distance>=10 && distance<=30) && digitalRead(irl)==1){
    digitalWrite(m11,HIGH);
    digitalWrite(m12,LOW);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,LOW);
  }
  else if(digitalRead(irl)==1 && digitalRead(irr)==0){
    digitalWrite(m11,HIGH);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,HIGH);
  }
  else if(digitalRead(irl)==0 && digitalRead(irr)==1){
    digitalWrite(m11,LOW);
    digitalWrite(m12,HIGH);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,LOW);
  }
  else{
    digitalWrite(m11,LOW);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,LOW);
  }
  
}
