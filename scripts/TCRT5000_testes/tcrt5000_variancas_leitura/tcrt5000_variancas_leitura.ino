#define sensor 34
#define led 32
#define montante 100

int inicio, noise, a, b, c, num, i;
float faixa;
int count = 0, soma = 0, soma_var = 0;
float media, variancia;
char incomingChar;
int vet[montante];

void setup()  
{  
  pinMode(sensor, INPUT); 
  pinMode(led,OUTPUT);
  Serial.begin(115200);  
}  
   
void loop()  
{ 

  /*--- PROGRAMA DE CALIBRAGEM TCRT5000 ---*/

  while (Serial.available() > 0) {
  // Lê o próximo caractere da porta serial
  Serial.println("Digite (1) para iniciar teste | Digite (2) para reiniciar");
  incomingChar = Serial.read();
    
  switch(incomingChar){


  case '1':

  Serial.println("INICIANDO O TESTE!!!");
      
  while(count < montante){
  digitalWrite(led, HIGH);
  delay(10);
  a = analogRead(sensor);
  digitalWrite(led, LOW);

  delay(10);
  b = analogRead(sensor);

  c = a - b;
  vet[count] = c;
  soma = soma + c;
  count++;
  // Serial.print(a);         //noise+signal
  //Serial.print("\t");
  //Serial.print(b);         //noise
  //Serial.print("\t");
  Serial.print(c);       //denoised signal
  Serial.print("\t");
  Serial.print(count);         //noise+signal
  Serial.print("\t");
  Serial.println();
  }

  media = (soma/montante);
  Serial.println();
  Serial.print("Media:");
  Serial.print(media);
  Serial.println();

  //calculando a variancia amostral
  for(i = 0; i < montante; i++){
    soma_var = soma_var + ( (vet[i] - media)*(vet[i] - media) );
  }
  variancia = sqrt(soma_var/(montante-1));
  Serial.print("Variancia:");
  Serial.print(variancia);
  Serial.println();

  break;

  case '2':
  Serial.println("Variaveis resetadas para teste");
  soma = 0;
  media = 0;
  count = 0;
  soma_var = 0;
  variancia = 0;
  break;

  default:
  break;
  }//fim do switch

    
  }//fim da leitura do serial


}//fim do loop