//LCD START
#include <LiquidCrystal.h>

//LCD END


//DIF START
#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262

int melody[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};
//DIF END


//SERVO START

#include <Servo.h> 

int pos1=0;
int pos2=0;

Servo servo_9;

//SERVO END


//INIT
int button1 = 13;  
int button2 = 6;  
int button3 = 7;  
int ledRosu = A5;
int ledVerde = 10;
//END INIT

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  lcd.begin(16, 2);
  pinMode(ledRosu, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  analogWrite(ledRosu,255);
  servo_9.attach(9,500,2500);

}

void loop() {

  if (digitalRead(button1) == HIGH) {
    lcd.print("Hello Worls!");
    digitalWrite(ledVerde,HIGH);
  } 
   else if(digitalRead(button2) == HIGH){
  	
   for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
    for(pos1=0;pos1<=180;pos1+=1){
       servo_9.write(pos1);
       delay(15);
     }
   }
  else if(digitalRead(button3) == HIGH){
  	for (int thisNote = 8; thisNote > 0; thisNote--) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
    for(pos2=180;pos2>=0;pos2-=1){
       servo_9.write(pos2);
       delay(15);
     }
  }
}
