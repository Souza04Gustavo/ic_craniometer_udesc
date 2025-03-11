#define sensor 34
#define led 32
#define montante 50

int inicio, noise, a, b, c, num, i;
float faixa;
int count = 0, soma = 0, soma_var = 0;
float media10, variancia10, media20, variancia20, media25, variancia25, media50, variancia50, media5_5, variancia5_5, media10_10, variancia10_10, media15_15, variancia15_15, media20_20, variancia20_20;
int leituras_intervalo;
int soma_a, soma_b, count2;
char incomingChar;
int vet[montante];


void setup() {
  pinMode(sensor, INPUT); 
  pinMode(led,OUTPUT);
  Serial.begin(115200); 
}

void loop() {
 /*--- PROGRAMA DE CALIBRAGEM TCRT5000 ---*/

  while (Serial.available() > 0) {
  // Lê o próximo caractere da porta serial
  Serial.println("Digite (1) para iniciar teste | Digite (2) para reiniciar");
  incomingChar = Serial.read();

  switch(incomingChar){

  //onde os testes de fato sao realizados
  case '1':

  //TESTE 1
  Serial.println("TESTE 10ms entre ON/OFF (20ms para cada leitura)");
      
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
  Serial.print(c);       //denoised signal
  Serial.print("\t");
  Serial.print(count);         //noise+signal
  Serial.print("\t");
  Serial.println();
  }

  media10 = (soma/montante);
  Serial.println();
  Serial.print("Media(10ms):");
  Serial.print(media10);
  Serial.println();

  //calculando a variancia amostral
  for(i = 0; i < montante; i++){
    soma_var = soma_var + ( (vet[i] - media10)*(vet[i] - media10) );
  }
  
  variancia10 = sqrt(soma_var/(montante-1));
  Serial.print("Variancia(10ms):");
  Serial.print(variancia10);
  Serial.println();

  //TESTE 2
  soma = 0;
  count = 0;
  soma_var = 0;
  i = 0;
  for(i = 0; i < montante; i++){
    vet[i] = 0;
  }
  
  Serial.println("TESTE 20ms entre ON/OFF (40ms para cada leitura)");
      
  while(count < montante){
  digitalWrite(led, HIGH);
  delay(20);
  a = analogRead(sensor);
  digitalWrite(led, LOW);
  delay(20);
  b = analogRead(sensor);

  c = a - b;
  vet[count] = c;
  soma = soma + c;
  count++;
  Serial.print(c);       //denoised signal
  Serial.print("\t");
  Serial.print(count);         //noise+signal
  Serial.print("\t");
  Serial.println();
  }

  media20 = (soma/montante);
  Serial.println();
  Serial.print("Media(20ms):");
  Serial.print(media20);
  Serial.println();

  //calculando a variancia amostral
  for(i = 0; i < montante; i++){
    soma_var = soma_var + ( (vet[i] - media20)*(vet[i] - media20) );
  }
  variancia20 = sqrt(soma_var/(montante-1));
  Serial.print("Variancia(20ms):");
  Serial.print(variancia20);
  Serial.println();

  //TESTE 3
  soma = 0;
  count = 0;
  soma_var = 0;
  i = 0;
  for(i = 0; i < montante; i++){
    vet[i] = 0;
  }
  
  Serial.println("TESTE 25ms entre ON/OFF (50ms para cada leitura)");
      
  while(count < montante){
  digitalWrite(led, HIGH);
  delay(25);
  a = analogRead(sensor);
  digitalWrite(led, LOW);
  delay(25);
  b = analogRead(sensor);

  c = a - b;
  vet[count] = c;
  soma = soma + c;
  count++;
  Serial.print(c);       //denoised signal
  Serial.print("\t");
  Serial.print(count);         //noise+signal
  Serial.print("\t");
  Serial.println();
  }

  media25 = (soma/montante);
  Serial.println();
  Serial.print("Media(25ms):");
  Serial.print(media25);
  Serial.println();

  //calculando a variancia amostral
  for(i = 0; i < montante; i++){
    soma_var = soma_var + ( (vet[i] - media25)*(vet[i] - media25) );
  }
  variancia25 = sqrt(soma_var/(montante-1));
  Serial.print("Variancia(25ms):");
  Serial.print(variancia25);
  Serial.println();

  //TESTE 4
  soma = 0;
  count = 0;
  soma_var = 0;
  for(i = 0; i < montante; i++){
    vet[i] = 0;
  }
  
  Serial.println("TESTE 50ms entre ON/OFF (100ms para cada leitura)");
      
  while(count < montante){
  digitalWrite(led, HIGH);
  delay(50);
  a = analogRead(sensor);
  digitalWrite(led, LOW);
  delay(50);
  b = analogRead(sensor);

  c = a - b;
  vet[count] = c;
  soma = soma + c;
  count++;
  Serial.print(c);       //denoised signal
  Serial.print("\t");
  Serial.print(count);         //noise+signal
  Serial.print("\t");
  Serial.println();
  }

  media50 = (soma/montante);
  Serial.println();
  Serial.print("Media(50ms):");
  Serial.print(media50);
  Serial.println();

  //calculando a variancia amostral
  for(i = 0; i < montante; i++){
    soma_var = soma_var + ( (vet[i] - media50)*(vet[i] - media50) );
  }
  variancia50 = sqrt(soma_var/(montante-1));
  Serial.print("Variancia(50ms):");
  Serial.print(variancia50);
  Serial.println();

  //TESTE 5 (SOMATORIO)
  leituras_intervalo = 5;
  soma = 0;
  count = 0;
  soma_var = 0;
  for(i = 0; i < montante; i++){
    vet[i] = 0;
  }

  Serial.println("TESTE 5 leituras entre ON/OFF");

  while(count < montante){

  soma_a = 0;
  digitalWrite(led, HIGH);
  delay(1);
  while(count2 < leituras_intervalo){
    a = analogRead(sensor);
    soma_a = soma_a + a;
    count2++;
  }

  soma_b = 0;
  count2 = 0;
  digitalWrite(led, LOW);
  delay(1);
  while(count2 < leituras_intervalo){
    b = analogRead(sensor);
    soma_b = soma_b + b;
    count2++;
  }
  count2 = 0;

  c = ((soma_a/5) - (soma_b/5));
  vet[count] = c;
  soma = soma + c;
  count++;
  Serial.print(c);       //denoised signal
  Serial.print("\t");
  Serial.print(count);         //noise+signal
  Serial.print("\t");
  Serial.println();
  
  }//fim do while

  media5_5 = (soma/montante);
  Serial.println();
  Serial.print("Media(5_5):");
  Serial.print(media5_5);
  Serial.println();

  //calculando a variancia amostral
  for(i = 0; i < montante; i++){
    soma_var = soma_var + ( (vet[i] - media5_5)*(vet[i] - media5_5) );
  }
  variancia5_5 = sqrt(soma_var/(montante-1));
  Serial.print("Variancia(5_5):");
  Serial.print(variancia5_5);
  Serial.println();

  //TESTE 6 (SOMATORIO 2)
  leituras_intervalo = 10;
  soma = 0;
  count = 0;
  soma_var = 0;
  count2 = 0;
  for(i = 0; i < montante; i++){
    vet[i] = 0;
  }

  Serial.println("TESTE 10 leituras entre ON/OFF");

  while(count < montante){

  soma_a = 0;
  digitalWrite(led, HIGH);
  delay(1);
  while(count2 < leituras_intervalo){
    a = analogRead(sensor);
    soma_a = soma_a + a;
    count2++;
  }

  soma_b = 0;
  count2 = 0;
  digitalWrite(led, LOW);
  delay(1);
  while(count2 < leituras_intervalo){
    b = analogRead(sensor);
    soma_b = soma_b + b;
    count2++;
  }
  count2 = 0;

  c = ((soma_a/leituras_intervalo) - (soma_b/leituras_intervalo));
  vet[count] = c;
  soma = soma + c;
  count++;
  Serial.print(c);       //denoised signal
  Serial.print("\t");
  Serial.print(count);         //noise+signal
  Serial.print("\t");
  Serial.println();
  
  }//fim do while

  media10_10 = (soma/montante);
  Serial.println();
  Serial.print("Media(10_10):");
  Serial.print(media10_10);
  Serial.println();

  //calculando a variancia amostral
  for(i = 0; i < montante; i++){
    soma_var = soma_var + ( (vet[i] - media10_10)*(vet[i] - media10_10) );
  }
  variancia10_10 = sqrt(soma_var/(montante-1));
  Serial.print("Variancia(10_10):");
  Serial.print(variancia10_10);
  Serial.println();


  //TESTE 7 (SOMATORIO 3)
  leituras_intervalo = 15;
  soma = 0;
  count = 0;
  soma_var = 0;
  count2 = 0;
  for(i = 0; i < montante; i++){
    vet[i] = 0;
  }

  Serial.println("TESTE 15 leituras entre ON/OFF");

  while(count < montante){

  soma_a = 0;
  digitalWrite(led, HIGH);
  delay(1);
  while(count2 < leituras_intervalo){
    a = analogRead(sensor);
    soma_a = soma_a + a;
    count2++;
  }

  soma_b = 0;
  count2 = 0;
  digitalWrite(led, LOW);
  delay(1);
  while(count2 < leituras_intervalo){
    b = analogRead(sensor);
    soma_b = soma_b + b;
    count2++;
  }
  count2 = 0;

  c = ((soma_a/leituras_intervalo) - (soma_b/leituras_intervalo));
  vet[count] = c;
  soma = soma + c;
  count++;
  Serial.print(c);       //denoised signal
  Serial.print("\t");
  Serial.print(count);         //noise+signal
  Serial.print("\t");
  Serial.println();
  
  }//fim do while

  media15_15 = (soma/montante);
  Serial.println();
  Serial.print("Media(15_15):");
  Serial.print(media15_15);
  Serial.println();

  //calculando a variancia amostral
  for(i = 0; i < montante; i++){
    soma_var = soma_var + ( (vet[i] - media15_15)*(vet[i] - media15_15) );
  }
  variancia15_15 = sqrt(soma_var/(montante-1));
  Serial.print("Variancia(15_15):");
  Serial.print(variancia15_15);
  Serial.println();

  //TESTE 8 (SOMATORIO 4)
  leituras_intervalo = 20;
  soma = 0;
  count = 0;
  soma_var = 0;
  count2 = 0;
  for(i = 0; i < montante; i++){
    vet[i] = 0;
  }

  Serial.println("TESTE 20 leituras entre ON/OFF");

  while(count < montante){

  soma_a = 0;
  digitalWrite(led, HIGH);
  delay(1);
  while(count2 < leituras_intervalo){
    a = analogRead(sensor);
    soma_a = soma_a + a;
    count2++;
  }

  soma_b = 0;
  count2 = 0;
  digitalWrite(led, LOW);
  delay(1);
  while(count2 < leituras_intervalo){
    b = analogRead(sensor);
    soma_b = soma_b + b;
    count2++;
  }
  count2 = 0;

  c = ((soma_a/leituras_intervalo) - (soma_b/leituras_intervalo));
  vet[count] = c;
  soma = soma + c;
  count++;
  Serial.print(c);       //denoised signal
  Serial.print("\t");
  Serial.print(count);         //noise+signal
  Serial.print("\t");
  Serial.println();
  
  }//fim do while

  media20_20 = (soma/montante);
  /*
  Serial.println();
  Serial.print("Media(20_20):");
  Serial.print(media20_20);
  Serial.println();
  */

  //calculando a variancia amostral
  for(i = 0; i < montante; i++){
    soma_var = soma_var + ( (vet[i] - media20_20)*(vet[i] - media20_20) );
  }
  variancia20_20 = sqrt(soma_var/(montante-1));
  /*
  Serial.print("Variancia(20_20):");
  Serial.print(variancia20_20);
  Serial.println();
  */

  //PRINTS FINAIS
  Serial.println();
  Serial.print("Media(10ms):");
  Serial.print(media10);
  Serial.println();
   Serial.print("Variancia(10ms):");
  Serial.print(variancia10);
  Serial.println();
    Serial.println();
  Serial.print("Media(20ms):");
  Serial.print(media20);
  Serial.println();
   Serial.print("Variancia(20ms):");
  Serial.print(variancia20);
  Serial.println();
  Serial.println();
  Serial.print("Media(25ms):");
  Serial.print(media25);
  Serial.println();
    Serial.print("Variancia(25ms):");
  Serial.print(variancia25);
  Serial.println();
    Serial.println();
  Serial.print("Media(50ms):");
  Serial.print(media50);
  Serial.println();
    Serial.print("Variancia(50ms):");
  Serial.print(variancia50);
  Serial.println();
    Serial.println();
  Serial.print("Media(5_5):");
  Serial.print(media5_5);
  Serial.println();
    Serial.print("Variancia(5_5):");
  Serial.print(variancia5_5);
  Serial.println();
 Serial.println();
  Serial.print("Media(10_10):");
  Serial.print(media10_10);
  Serial.println();
    Serial.print("Variancia(10_10):");
  Serial.print(variancia10_10);
  Serial.println();
   Serial.println();
  Serial.print("Media(15_15):");
  Serial.print(media15_15);
  Serial.println();
   Serial.print("Variancia(15_15):");
  Serial.print(variancia15_15);
  Serial.println();
 Serial.println();
  Serial.print("Media(20_20):");
  Serial.print(media20_20);
  Serial.println();
    Serial.print("Variancia(20_20):");
  Serial.print(variancia20_20);
  Serial.println();





  break;//break do case 1


  case '2':
  Serial.println("Variaveis resetadas para teste");
  soma = 0;
  media10 = 0;
  variancia10 = 0;
  count = 0;
  soma_var = 0;
  for(i = 0; i < montante; i++){
    vet[i] = 0;
  }

  break;


  default:
  break;

  }//fim do switch

  }//fim do while

}
