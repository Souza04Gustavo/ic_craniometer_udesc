Site com todas as informações a respeito do ESP32: https://blog.smartkits.com.br/esp32-pinout-guia-basico-de-gpios/

-> Recomendo a leitura antes de iniciar a manipular os pinos do esp pois eles possuem muitas especificações que demorei pra descobrir e esse site me auxiliou.

INFORMAÇÕES SOBRE OS PINOS ESP32:

NÃO USAR: GPIOS 6 a 12 (usados para memoria flash)
Pinos alerta: 34, 35, 36, 39 (somente entrada)
Pinos para evitar se possível: 1, 3, 5, 14, 15 (não descobri o motivo)

PINOS USADOS NA PLACA V1:
#define sensor1 32 // (1) sensor na placa principal
#define sensor2 25 // (2) primeira placa a esquerda
#define sensor3 26 // (3) segunda placa a esquerda 
#define sensor4 27 // (4) terceira placa a esquerda
#define sensor5 13 // (5) quarta placa (de frente pra principal)
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

