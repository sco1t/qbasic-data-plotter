
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int p1;
String inputString = ""; 
float volt, oldvolt;

void setup() {
 analogReference(EXTERNAL); //
  lcd.begin(16, 2);
Serial.begin(9600);
delay(1000);
lcd.clear();
lcd.setCursor(0, 0);
  lcd.print("0.00 volt");
  lcd.setCursor(0, 1);
 lcd.print(analogRead(A5));lcd.print(" ADC");
}

void loop() {



   p1 = analogRead(A5);
   voltage() ;
  if (volt != oldvolt){
  oldvolt = volt ;
    lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(volt);lcd.print(" volt");
  lcd.setCursor(0, 1);
  lcd.print(p1);lcd.print(" ADC");
  delay(100);
  }
 
}

void voltage()
{ volt = (p1 * (5 / 1023.000 )* 22)  ;  }
 
void serialEvent() {
  while (Serial.available()) {
  char inChar = (char)Serial.read();
   
    inputString += inChar;
    
    if (inChar == '\n') {
      if (inputString == "v1\n" or inputString == "v1\r\n") {
    voltage() ;
    Serial.println(volt);inputString = "";
      }
      else { Serial.print("What Bro? ");  Serial.println(inputString);inputString = "";}
    }
  }
}
