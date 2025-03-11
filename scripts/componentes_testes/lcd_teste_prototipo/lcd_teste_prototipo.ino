#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define col 16 // num de col
#define lin  2 // num de linhas
#define ende  0x27 // endereço do display

LiquidCrystal_I2C lcd(ende,col,lin);

void setup()
{ 
  lcd.init(); // inicializa o display
  lcd.backlight();
  lcd.clear(); 
} 

void loop() 
{
    lcd.setCursor(0,0); // cursor na coluna 0 linha 0
    lcd.print(" ---PROTOTIPO---");    
    lcd.setCursor(0,1); // cursor na coluna 0 linha 0
    lcd.print(" UDESC JOINVILLE");    

}