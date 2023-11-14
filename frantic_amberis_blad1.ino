#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>
#include<string.h>

#define TRIG 5
#define ECHO 6
#define TRIG2 7
#define ECHO2 8
#define servopin 9
#define LED 12
 
Servo uno_servo;

Adafruit_LiquidCrystal lcd(0);
unsigned int ms=60;

long Tiro(int TRIGpin, int ECHOpin,int tiempo1, int ms1)
{
pinMode(TRIGpin, OUTPUT);
pinMode(ECHOpin, INPUT);
  
  if (tiempo1 >= ms1) 
        {
        digitalWrite(TRIGpin, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIGpin, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIGpin, LOW);
        return pulseIn(ECHOpin, HIGH)/58.2;
   		}
  delay(10);
}

long Tiro2(int TRIG2pin,int ECHO2pin,int tiempo2,int ms2)
{
     pinMode(TRIG2pin, OUTPUT);
	 pinMode(ECHO2pin, INPUT);
       
       if (tiempo2 >= ms2) 
        {
        digitalWrite(TRIG2pin, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIG2pin, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG2pin, LOW);
          return pulseIn(ECHO2pin, HIGH)/58.2;
        }
}
  

void setup() {
pinMode(LED,OUTPUT);
uno_servo.attach(servopin);

Serial.begin(9600);
lcd.begin(16,2);

}

void loop() {
long Distancia = 0;
long Distancia2 = 0;
int tiempo = millis();
  
 Distancia= Tiro(TRIG,ECHO,tiempo,ms);
 Distancia2= Tiro2(TRIG2,ECHO2,tiempo,ms);
     
  
  
   		if(Distancia>2 && Distancia<150)
            {
             uno_servo.write(90);
             delay(10000);
             uno_servo.write(0);
            }else{
            uno_servo.write(0);
            }
   delay(10);
  
      if(Distancia2>2 && Distancia2<15)
          {
           lcd.clear();
           lcd.setCursor(0,0);
           lcd.print("ESTA MUY LLENO");
           lcd.setCursor(1,1);
           lcd.print("VACIAR PRONTO");
           delay(5);
                
            digitalWrite(LED, HIGH);
            delay(100); 
            digitalWrite(LED, LOW);
            delay(100); 
            }else{
                 lcd.clear();
                 }
       
  delay(1000);
}
