#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define col 16 // num de col
#define lin  2 // num de linhas
#define ende  0x27 // endereço do display

LiquidCrystal_I2C lcd(ende,col,lin);

#define sensor1 32 // (1) sensor na placa principal
#define sensor2 25 // (2) primeira placa a esquerda
#define sensor3 26 // (3) segunda placa a esquerda 
#define sensor4 27 // (4) terceira placa a esquerda

#define sensor5 34 // (5) quarta placa (de frente pra principal)
#define sensor6 35 // (6) terceira placa a direita
#define sensor7 15 // (7) segundo a direita
#define sensor8 2 // (8) primeiro a direita

#define led 33

int a1, a2, a3, a4, a5, a6, a7, a8;
int b1, b2, b3, b4, b5, b6, b7, b8;
int c1, c2, c3, c4, c5, c6, c7, c8;

void setup()  
{  
  lcd.init(); // inicializa o display
  lcd.backlight();
  lcd.clear(); 
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT); 
  pinMode(sensor4, INPUT);

  pinMode(sensor5, INPUT); 
  pinMode(sensor6, INPUT);   
  pinMode(sensor7, INPUT); 
  pinMode(sensor8, INPUT); 

  pinMode(led,OUTPUT);
  Serial.begin(115200); 

  lcd.setCursor(0,0); // cursor na coluna 0 linha 0
  lcd.print(" ---PROTOTIPO---");    
  lcd.setCursor(0,1); // cursor na coluna 0 linha 0
  lcd.print(" UDESC JOINVILLE");    
  delay(5000);
  lcd.clear();

}  
   

void loop() {
  digitalWrite(led, HIGH);
  delay(10);
  a1 = analogRead(sensor1);
  a2 = analogRead(sensor2);
  a3 = analogRead(sensor3);
  a4 = analogRead(sensor4);
  a5 = analogRead(sensor5);
  a6 = analogRead(sensor6);
  a7 = analogRead(sensor7);
  a8 = analogRead(sensor8);
  digitalWrite(led, LOW);
  delay(10);
  b1 = analogRead(sensor1);
  b2 = analogRead(sensor2);
  b3 = analogRead(sensor3);
  b4 = analogRead(sensor4);
  b5 = analogRead(sensor5);
  b6 = analogRead(sensor6);
  b7 = analogRead(sensor7);
  b8 = analogRead(sensor8);
  c1 = a1 - b1; 
  c2 = a2 - b2; 
  c3 = a3 - b3; 
  c4 = a4 - b4; 
  c5 = a5 - b5; 
  c6 = a6 - b6; 
  c7 = a7 - b7; 
  c8 = a8 - b8;

  lcd.setCursor(0,0); // cursor na coluna 0 linha 0
  lcd.print(c1);

  /*
  //Serial.print(" A1: ");
  Serial.print(c1);
  Serial.print(" ");
  //Serial.print(" A2: ");
  Serial.print(c2);
  Serial.print(" ");
  //Serial.print(" A3: ");
  Serial.print(c3);
  Serial.print(" ");
  //Serial.print(" A4: ");
  Serial.print(c4);
  Serial.print(" ");
  //Serial.print(" A5: ");
  Serial.print(c5);
  Serial.print(" ");
  //Serial.print(" A6: ");
  Serial.print(c6);
  Serial.print(" ");
  //Serial.print(" A7: ");
  Serial.print(c7);
  Serial.print(" ");
  //Serial.print(" A8: ");
  Serial.print(c8);
  Serial.print(" ");

  
  // para serial plotter
  Serial.print(escala2);
  Serial.print(" ");


  Serial.println();
  */


delay(10);

}
