#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define col 16 // num de col
#define lin  2 // num de linhas
#define ende  0x27 // endereço do display
#define botao1 5
#define botao2 18
#define buzzer 4

int estado1 = 0;
int estado2 = 0;

LiquidCrystal_I2C lcd(ende,col,lin);

void setup()
{ 
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP); 
  pinMode(buzzer, OUTPUT);
  lcd.init(); // inicializa o display
  lcd.backlight();
  lcd.clear(); 
}

void loop() 
{
  estado1 = digitalRead(botao1);
  estado2 = digitalRead(botao2);

  if(estado1 == LOW){
    lcd.setCursor(0,0); // cursor na coluna 0 linha 0
    tone(buzzer, 1000); // Send 1KHz sound signal...
    lcd.print("botao 1 apertado");
    delay(2000);
    noTone(buzzer);
    lcd.clear();
  }

  if(estado2 == LOW){ 
    lcd.setCursor(0,1); // cursor na coluna 0 linha 0
    tone(buzzer, 1000); // Send 1KHz sound signal...
    lcd.print("botao 2 apertado");
    delay(2000);
    noTone(buzzer);
    lcd.clear();  
  }
  
}