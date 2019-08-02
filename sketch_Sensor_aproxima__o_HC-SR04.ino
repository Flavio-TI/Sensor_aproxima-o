//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FLAVIO.ALL

#include "Ultrasonic.h"
Ultrasonic ultrasonic (13,12);
float distancia;

int buzzer = 11;                          //sinalização
int ledPin[7]={4, 5, 6, 7, 8, 9, 10};     //sinalização

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(buzzer, OUTPUT);               //sinalização
  for(int i=0; i<=6; i++)                //sinalização
    pinMode(ledPin[i], OUTPUT);          //sinalização
}

void loop() {
  // put your main code here, to run repeatedly:
  distancia= (ultrasonic.Ranging(CM));
  Serial.print("Distancia= ");
  Serial.print(distancia);
  Serial.println("  cm");
  
  //*********sinalização dos leds e buzer***********   

  if (distancia <= 3) {
    ledDisplay (0, 0, 0, 0, 0, 0, 1); tone(buzzer,1550); delay(100);
    ledDisplay (0, 0, 0, 0, 0, 0, 0); noTone(buzzer);    delay( 50);
  } 
  if (4  <= distancia && distancia <=  7 ) {
    ledDisplay (0, 0, 0, 0, 0, 1, 1); tone(buzzer,1500); delay(150);
    ledDisplay (0, 0, 0, 0, 0, 0, 0); noTone(buzzer);    delay(100);
  }
  if (8  <= distancia && distancia <= 11 ) { 
    ledDisplay (0, 0, 0, 0, 1, 1, 1); tone(buzzer,1400); delay(200);
    ledDisplay (0, 0, 0, 0, 0, 0, 0); noTone(buzzer);    delay(150);
  }
  if (12 <= distancia && distancia <= 15 ) {
    ledDisplay (0, 0, 0, 1, 1, 1, 1); tone(buzzer,1300); delay(250);
    ledDisplay (0, 0, 0, 0, 0, 0, 0); noTone(buzzer);    delay(200);  
  }
  if (16 <= distancia && distancia <= 19 ) {
    ledDisplay (0, 0, 1, 1, 1, 1, 1); tone(buzzer,1200); delay(300);
    ledDisplay (0, 0, 0, 0, 0, 0, 0); noTone(buzzer);    delay(250);
  }
  if (20 <= distancia && distancia <= 24 ) {
    ledDisplay (0, 1, 1, 1, 1, 1, 1); tone(buzzer,800); delay(350);
    ledDisplay (0, 0, 0, 0, 0, 0, 0); noTone(buzzer);    delay(300);
  }
  if (distancia >= 25 ) {
    ledDisplay (1, 1, 1, 1, 1, 1, 1);
    noTone(buzzer);
    delay(650);
  }
  delay(50);  //delay comum
}

void ledDisplay(int a, int b, int c, int d, int e, int f, int g) {
  // coloca o cojunto de leds em high/low conforme programdo para a distancia
  int ledStatepin[7]={a, b, c, d, e, f, g};
  for(int x=0; x<=6; x++) {
    digitalWrite(ledPin[x], ledStatepin[x]);
   }  
}
