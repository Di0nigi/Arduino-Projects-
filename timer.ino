#include <LiquidCrystal.h>



class timer{
  public:
  int digits[6]={};
  int s1=0;
  int s2=0;
  int m1=0;
  int m2=0;
  int h1=0;
  int h2=0;
  bool goOn;

  void start(){
    goOn=true;
    
  }
  void stop(){
    goOn=false;  
    }

  int * secPassed(){
  if(goOn==true) {  

    
    s1+=1;
    if(s1>9){
        s1=0;
        s2+=1;}
    if(s2>5){
      s2=0;
      m1+=1;            
      }
    if(m1>9){
      m1=0;
      m2+=1;}
    if(m2>5){
      m2=0;
      h1+=1;}
    if (h1>9){
      h1=0;
      h2+=1; 
    }
    if(h2>2){
      s1=0;
      s2=0;
      m1=0;
      m2=0;
      h1=0;
      h2=0;
      }
    digits[0]=h2;
    digits[1]=h1;
    digits[2]=m2;
    digits[3]=m1;
    digits[4]=s2;
    digits[5]=s1;
    return digits;}
    else{
      return;}
      }
    };

LiquidCrystal lcd(12,11,5,4,3,2);
const int switchPin = 6;
int switchState=0;
int prevSwitchState=0;
timer t; 
int * toPrint;
String p;
int c=1;




void setup() {
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);

}

void loop() {
  switchState= digitalRead(switchPin);
  if (switchState!= prevSwitchState){
    c+=1;   
    if (switchState==0 ){
      t.start();
      }
    else{
      t.stop();}    
    }
    if(c%2==0){
  prevSwitchState=switchState;
  }
  
  
  toPrint=t.secPassed();
  //p=static_cast<char>(toPrint[0]);+static_cast<char>(toPrint[1]);+":"+static_cast<char>(toPrint[2]);+static_cast<char>(toPrint[3]);+":"+static_cast<char>(toPrint[4]);+static_cast<char>(toPrint[5]);
  printScreen(toPrint,0);
  delay(1000);
  

}

void printScreen(int * arr,int n){
  lcd.setCursor(n, 0);
  lcd.print(arr[0]);
  lcd.setCursor(n+1, 0);
  lcd.print(arr[1]);
  lcd.setCursor(n+2, 0);
  lcd.print(":");
  lcd.setCursor(n+3, 0);
  lcd.print(arr[2]);
  lcd.setCursor(n+4, 0);
  lcd.print(arr[3]);
  lcd.setCursor(n+5, 0);  
  lcd.print(":");
  lcd.setCursor(n+6, 0);
  lcd.print(arr[4]);
  lcd.setCursor(n+7, 0);
  lcd.print(arr[5]);  
}

