#include<Stepper.h>
#include<Servo.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
Servo myservo;
Servo myservo2;
Stepper mystepper(2048,8,10,9,11);
Adafruit_SSD1306 display(128,64,&Wire,-1);
int speed=15;
int xaxis=A2;
int but=7;
int count=0;
int yaxis=A3;
int buzz=13;
int xval,yval;
int y=90;
int y2=90;
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  mystepper.setSpeed(speed);
  Serial.begin(9600);
  pinMode(xaxis,INPUT);
  pinMode(yaxis,INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(but,INPUT_PULLUP);
  myservo.attach(3);
  myservo2.attach(5);
  myservo.write(y);
  myservo2.write(y2);
}

void loop() {
  if(count%2==0){
    display.clearDisplay();
 display.fillCircle(40,20,5,SSD1306_WHITE);}
 else{
  display.clearDisplay();
 display.fillCircle(80,20,5,SSD1306_WHITE);}
 display.drawLine(42,45,80,45,SSD1306_WHITE);

 display.display();
 
  xval=analogRead(xaxis);
  yval=analogRead(yaxis);
  //Serial.print(xval);
  //Serial.print("          ");
  //Serial.println(yval);
  if(digitalRead(but)==LOW){
    Serial.println("button pressed");
    count++;
    while(digitalRead(but)==LOW){
      digitalRead(but);
    }
    digitalWrite(buzz,HIGH);
    delay(100);
    digitalWrite(buzz,LOW);
    
  }
  if(xval>=800){
    
    while(xval>=800){
    display.drawLine(42,45,80,45,SSD1306_WHITE);
    display.drawLine(42,45,50,54,SSD1306_WHITE);
    display.drawLine(42,45,50,37,SSD1306_WHITE);
    display.display();
    xval=analogRead(xaxis);
    mystepper.step(10);
    
    delay(10);}
display.clearDisplay();
  }
  if(xval<=250){
    
    while(xval<=250){
      display.drawLine(42,45,80,45,SSD1306_WHITE);
     display.drawLine(80,45,68,54,SSD1306_WHITE);
    display.drawLine(80,45,68,37,SSD1306_WHITE);
    display.display();
    xval=analogRead(xaxis);
    mystepper.step(-10);
    
    delay(10);}
    display.clearDisplay();
  }
  if(yval>=800){
    if(count%2==0 && y<=175){
    myservo.write(y);
    y+=5;
    delay(100);}
    else if(count%2!=0 && y2<=175){
      myservo2.write(y2);
      y2+=5;
      delay(100);
    }
  }

  if(yval<=250 ){
    if(count%2==0 && y>=5){
    myservo.write(y);
    y-=5;
    delay(100);}
    else if(count%2!=0 && y2>=5){
      myservo2.write(y2);
      y2-=5;
      delay(100);
    }
  }
}
