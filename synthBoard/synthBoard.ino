const int rightPin=5;
const int speakerPin=8; 
const int leftPin = 11;
const int ledPin1=10;
const int ledPin2=4;

int notes[] = {
  261, 277, 293, 311, 329, 349, 369, 391, 415, 440, 466, 493
};




void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // put your setup code here, to run once:

}


void loop() {
  int pot1 = analogRead(A0);
  int pot2=analogRead(A2);
  int rightState = digitalRead(rightPin);
  int leftState= digitalRead(leftPin);
  int oct=pot1;
  int del=10+pot2;

   if (leftState==HIGH){

    play(notes[0]+oct,del);
    digitalWrite(ledPin1, HIGH);  }
    

    
    
  
  else{
    digitalWrite(ledPin1, LOW);
  }
  

  if (rightState==HIGH){
    play(notes[11]+oct,del);
    //tone(speakerPin,sensorValue);
    digitalWrite(ledPin2, HIGH);  
  
    //tone(speakerPin,sensorValue+100);
  }
  else{
    //noTone(speakerPin); 
    digitalWrite(ledPin2, LOW);
  }
   

}



void play(int val,int d){
  tone(speakerPin,val);
  delay(d);
  noTone(speakerPin);
}



