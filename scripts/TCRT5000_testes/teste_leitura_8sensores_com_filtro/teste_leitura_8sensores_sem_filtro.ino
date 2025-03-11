#define sensor1 32 // (1) sensor na placa principal

#define sensor2 25 // (2) primeira placa a esquerda
#define sensor3 26 // (3) segunda placa a esquerda 
#define sensor4 27 // (4) terceira placa a esquerda

#define sensor5 13 // (5) quarta placa (de frente pra principal)
//#define sensor6 4 // (6) terceira placa a direita
#define sensor6 14 // (6) terceira placa a direita 
#define sensor7 35 // (7) segundo a direita
#define sensor8 34 // (8) primeiro a direita

#define led1 23
#define led2 33
#define led3 16
#define led4 17
#define led5 15
#define led6 18
#define led7 19
#define led8 4


int tam_amostra = 1000;
int a1, a2, a3, a4, a5, a6, a7, a8;
int b1, b2, b3, b4, b5, b6, b7, b8;
int c1, c2, c3, c4, c5, c6, c7, c8;

float soma1 = 0, final1 = 0;
float soma2 = 0, final2 = 0;
float soma3 = 0, final3 = 0;
float soma4 = 0, final4 = 0;
float soma5 = 0, final5 = 0;
float soma6 = 0, final6 = 0;
float soma7 = 0, final7 = 0;
float soma8 = 0, final8 = 0;


int i = 0;
int printar = 1;

void setup()  
{  
  pinMode(sensor1, INPUT);

  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT); 
  pinMode(sensor4, INPUT);

  pinMode(sensor5, INPUT); 
  pinMode(sensor6, INPUT);   
  pinMode(sensor7, INPUT); 
  pinMode(sensor8, INPUT); 

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);

  Serial.begin(115200);  
}  
   
void loop()  
{ 

  while(i < tam_amostra){
  i++;
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(led7,HIGH); 
  digitalWrite(led8,HIGH);

  //delayMicroseconds(500); 
  delay(10);

  a1 =analogRead(sensor1);
  a2 =analogRead(sensor2);
  a3 =analogRead(sensor3);
  a4 =analogRead(sensor4);
  a5 =analogRead(sensor5);
  a6 =analogRead(sensor6);
  a7 =analogRead(sensor7);
  a8 =analogRead(sensor8);

  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  digitalWrite(led7,LOW); 
  digitalWrite(led8,LOW);

  //delayMicroseconds(500); 
  delay(10);

  b1 =analogRead(sensor1);
  b2 =analogRead(sensor2);
  b3 =analogRead(sensor3);
  b4 =analogRead(sensor4);
  b5 =analogRead(sensor5);
  b6 =analogRead(sensor6);
  b7 =analogRead(sensor7);  
  b8 =analogRead(sensor8);

  c1 = a1 - b1;
  soma1 = soma1 + c1;
  c2 = a2 - b2;
  soma2 = soma2 + c2;
  c3 = a3 - b3;
  soma3 = soma3 + c3;
  c4 = a4 - b4;
  soma4 = soma4 + c4;
  c5 = a5 - b5;
  soma5 = soma5 + c5;
  c6 = a6 - b6;
  soma6 = soma6 + c6;
  c7 = a7 - b7;
  soma7 = soma7 + c7;
  c8 = a8 - b8;
  soma8 = soma8 + c8;

  Serial.print(" S1: ");
  Serial.print(c1);

  Serial.print(" S2: ");
  Serial.print(c2);

  Serial.print(" S3: ");
  Serial.print(c3);

  Serial.print(" S4: ");
  Serial.print(c4);

  Serial.print(" S5: ");
  Serial.print(c5);

  Serial.print(" S6: ");
  Serial.print(c6);

  Serial.print(" S7: ");
  Serial.print(c7);

  Serial.print(" S8: ");
  Serial.print(c8);

  Serial.println();

delay(10);
}


final1 = soma1/tam_amostra;

final2 = soma2/tam_amostra;

final3 = soma3/tam_amostra;

final4 = soma4/tam_amostra;

final5 = soma5/tam_amostra;

final6 = soma6/tam_amostra;

final7 = soma7/tam_amostra;

final8 = soma8/tam_amostra;


while(printar){
 
  Serial.println();
  Serial.print("Média final(1): ");
  Serial.print(final1);
 
  Serial.print(" ");
  Serial.print("Média final(2): ");
  Serial.print(final2);

  Serial.print(" ");
  Serial.print("Média final(3): ");
  Serial.print(final3);

  Serial.print(" ");
  Serial.print("Média final(4): ");
  Serial.print(final4);

  Serial.print(" ");
  Serial.print("Média final(5): ");
  Serial.print(final5);

  Serial.print(" ");
  Serial.print("Média final(6): ");
  Serial.print(final6);

  Serial.print(" ");
  Serial.print("Média final(7): ");
  Serial.print(final7);

  Serial.print(" ");
  Serial.print("Média final(8): ");
  Serial.print(final8);

printar = 0;
}

}//fim do loop