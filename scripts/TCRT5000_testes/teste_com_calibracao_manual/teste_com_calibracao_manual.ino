// definir quais pinos do sensor será utilizado abaixo
#define sensor 13
#define LED 17

int tam_amostra = 1000;
int leitura_suja, leitura_limpa, filtro;
float soma = 0, final = 0;

int i = 0;
int printar = 1;

char selecao;

void setup() {

  Serial.begin(115200);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);

  Serial.println("---------- MENU ----------");
  Serial.println("Digite (1) para efetuar a medição");
}

void loop() {

  if (Serial.available() > 0) {

    Serial.println("Digite (1) para efetuar a medição");

    selecao = Serial.read();  // Lê entrada da serial

    if (selecao == '1') {  

      i = 0;  // Resetando contador
      soma = 0;

      while (i < tam_amostra) {
        i++;

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

      if (printar) {
        Serial.print("\nMédia final com filtro: ");
        Serial.println(final);
        printar = 0;
      }
    } else {
       Serial.println("Digito incorreto!");
    }
  }
}
