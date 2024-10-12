//youtube: skill make
//If you have any problems, ask me in the comments section, I will try to answer quickly

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

int B = 0;
int L = 0;
int P = 0;
int Y = 0;
int input = A0;
int input2 = A1;
int input3 = A2;
int input4 = A3;
int state = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;

Servo servo7;
Servo servo6;
Servo servo5;
Servo servo4;

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.begin(); // initialize the lcd

  // Print a message to the LCD.
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("B = ");
  lcd.print(B);
  lcd.setCursor(8, 0);
  lcd.print("L = ");
  lcd.print(L);
  lcd.setCursor(0, 1);
  lcd.print("P = ");
  lcd.print(P);
  lcd.setCursor(8, 1);
  lcd.print("Y = ");
  lcd.print(Y);
  
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);

  servo7.attach(7);
  servo6.attach(6);
  servo5.attach(5);
  servo4.attach(4);
  
  servo7.write(0);
  servo6.write(0);
  servo5.write(0);
  servo4.write(0);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(12, OUTPUT);
}
void loop()
{
  //reset B
  if(digitalRead(11) == LOW){
    
    lcd.setCursor (4, 0); B = 0; lcd.print(B);lcd.setCursor (5, 0);lcd.print(".");lcd.setCursor (6, 0);lcd.print(".");
  }
  
  
  //number 1
  int counter = digitalRead(A0);
  if (state == 0)
  {
    switch (counter) {

      case 1 : state = 1; lcd.setCursor (4, 0); B = B + 1; lcd.print(B); break;
      case 0 : state = 0; break;

    }
  }

  if (counter == LOW) {
    state = 0;
  }
  //servo.7
  //if (B >= 400){
     //servo7.write(180);

  //}else{
   // servo7.write(0);
  //}
  
  //reset L
  if(digitalRead(10) == LOW){
    
    lcd.setCursor (12, 0); L = 0; lcd.print(L);lcd.setCursor (13, 0);lcd.print(".");lcd.setCursor (14, 0);lcd.print(".");
  }
  
  //number 2
  int counter2 = digitalRead(A1);
  if (state2 == 0)
  {
    switch (counter2) {

      case 1 : state2 = 1; lcd.setCursor (12, 0); L = L + 1; lcd.print(L); break;
      case 0 : state2 = 0; break;

    }
  }

  if (counter2 == LOW) {
    state2 = 0;
  }
  //servo.7
  //if (L >= 500){
    // servo6.write(180);
  //}else{
  //  servo6.write(0);
  //}
  
  //reset P
  if(digitalRead(9) == LOW){
    
    lcd.setCursor (4, 1); P = 0; lcd.print(P);lcd.setCursor (5, 1);lcd.print(".");lcd.setCursor (6, 1);lcd.print(".");
  }
  
  //number 3
  int counter3 = digitalRead(A2);
  if (state3 == 0)
  {
    switch (counter3) {

      case 1 : state3 = 1; lcd.setCursor (4, 1); P = P + 1; lcd.print(P); break;
      case 0 : state3 = 0; break;

    }
  }

  if (counter3 == LOW) {
    state3 = 0;
  }
  
  //reset Y
  if(digitalRead(8) == LOW){
    
    lcd.setCursor (12, 1); Y = 0; lcd.print(Y);lcd.setCursor (13, 1);lcd.print(".");lcd.setCursor (14, 1);lcd.print(".");
  }
  
  //number 4
  int counter4 = digitalRead(A3);
  if (state4 == 0)
  {
    switch (counter4) {

      case 1 : state4 = 1; lcd.setCursor (12, 1); Y = Y + 1; lcd.print(Y); break;
      case 0 : state4 = 0; break;

    }
  }

  if (counter4 == LOW) {
    state4 = 0;
  }
   if(B >= 350||L >= 450){
    digitalWrite(2 , HIGH);
  }else{
    digitalWrite(2 , LOW);
  }
}
