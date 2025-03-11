#include <Arduino.h>
#include <cmath>
//Função ajustada: d = 262.6551 * L^-0.7816

#define sensor 13
#define LED 17

int tam_amostra = 500;
int leitura_suja, leitura_limpa, filtro;
float soma = 0, final = 0;
int cont = 0;

// Dados coletados manualmente: distâncias conhecidas (em cm)
const int num_medidas = 4;
float distancias[] = { 0.5, 1.0, 1.5, 2.0 };  // Distâncias reais em cm
float leituras[num_medidas];                  // Aqui vamos armazenar as leituras do sensor

// Coeficientes da função d = A * L^B
float A, B;

int leituraSensor(){
      digitalWrite(LED, HIGH);
      delay(10);
      leitura_suja = analogRead(sensor);
      digitalWrite(LED, LOW);
      delay(10);
      leitura_limpa = analogRead(sensor);
      filtro = leitura_suja - leitura_limpa;
      return filtro;
}

// Função para calcular os coeficientes A e B usando regressão linear nos logaritmos
void calcularCoeficientes() {
  float sumLogL = 0, sumLogD = 0, sumLogL2 = 0, sumLogLLogD = 0;

  for (int i = 0; i < num_medidas; i++) {
    float logL = log(leituras[i]);    // ln(L)
    float logD = log(distancias[i]);  // ln(d)

    sumLogL += logL;
    sumLogD += logD;
    sumLogL2 += logL * logL;
    sumLogLLogD += logL * logD;
  }

  // Cálculo do coeficiente B (inclinação da reta)
  B = (num_medidas * sumLogLLogD - sumLogL * sumLogD) / (num_medidas * sumLogL2 - sumLogL * sumLogL);

  // Cálculo do coeficiente A (intercepto da reta)
  float logA = (sumLogD - B * sumLogL) / num_medidas;
  A = exp(logA);  // Convertendo de log(A) para A
}

void setup() {
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
  Serial.println("\n---- Calibração do Sensor  ----");

  // Capturando leituras do sensor
  for (int i = 0; i < num_medidas; i++) {
    Serial.print("Posicione o objeto a ");
    Serial.print(distancias[i]);
    Serial.println(" cm do sensor e aguarde...");
    delay(8000);  // Tempo para reposicionar o objeto

    cont = 0;  // Resetando contador
    soma = 0;

    while (cont < tam_amostra) {
      cont++;

      digitalWrite(LED, HIGH);
      delay(10);

      leitura_suja = analogRead(sensor);
      Serial.print("Sujo: ");
      Serial.print(leitura_suja);
      Serial.print("  /  ");

      digitalWrite(LED, LOW);

      delay(10);

      leitura_limpa = analogRead(sensor);
      Serial.print("Limpo: ");
      Serial.print(leitura_limpa);
      Serial.print("  /  ");

      filtro = leitura_suja - leitura_limpa;
      soma += filtro;

      Serial.print(" Filtro: ");
      Serial.println(filtro);
    }

    final = soma / tam_amostra;

    leituras[i] = final;
    Serial.print("Leitura registrada: ");
    Serial.println(leituras[i]);
  }

  // Calculando coeficientes A e B
  calcularCoeficientes();

  // Exibindo os valores calculados
  Serial.print("Função ajustada: d = ");
  Serial.print(A, 4);
  Serial.print(" * L^");
  Serial.println(B, 4);
}

void loop() {
  
  int leitura = leituraSensor();
  float distancia = A * pow(leitura, B);  // Converte leitura para distância

  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print(" | Distância estimada: ");
  Serial.print(distancia);
  Serial.println(" cm");

  delay(500);
}
