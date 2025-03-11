#define sensor 34
#define led 32

int a,b,c;
int leituras_intervalo, count, soma_a, soma_b, count2;

void setup()  
{  
  pinMode(sensor, INPUT); 
  pinMode(led,OUTPUT);

  Serial.begin(115200);  
}  
   
void loop()  
{ 
  leituras_intervalo = 5;
  count = 0;
  soma_a = 0;
  count2 = 0;

  digitalWrite(led, HIGH);
  delay(1);
  while(count2 < leituras_intervalo){
    a = analogRead(sensor);
     Serial.print(a); 
    soma_a = soma_a + a;
    count2++;
  }

  soma_b = 0;
  count2 = 0;
  digitalWrite(led, LOW);
  delay(1);
  while(count2 < leituras_intervalo){
    b = analogRead(sensor);
     Serial.print(b); 

    soma_b = soma_b + b;
    count2++;
  }
  count2 = 0;

  c = ((soma_a/leituras_intervalo) - (soma_b/leituras_intervalo));
  Serial.print(c);       //denoised signal

} 