# Atividade 1: Temporizador Periódico

## Descrição

Este projeto implementa um semáforo utilizando a placa Raspberry Pi Pico W, três LEDs (vermelho, amarelo e verde) e resistores de 330 Ω. A temporização de cada sinal é de 3 segundos, controlada por um temporizador periódico fornecido pelo SDK do Pico. O funcionamento segue o ciclo: vermelho → amarelo → verde.

---

## Requisitos

1) O acionamento dos LEDs deve iniciar na cor vermelha, alterando para amarelo e, em seguida, verde.
2) O temporizador deve ser ajustado para um atraso de 3 segundos (3.000 ms).
3) A mudança de estado dos LEDs deve ser implementada na função de call-back do temporizador.
4) A rotina principal deve imprimir uma mensagem no console a cada segundo.
5) O experimento deve ser realizado utilizando a Ferramenta Educacional BitDogLab com um LED RGB nos GPIOs 11, 12 e 13.

---

## Funcionalidade do Código

- **Temporizador periódico**:
  - Utiliza `add_repeating_timer_ms()` para alternar os LEDs a cada 3 segundos.

- **Função de callback (`traffic_lights_routine`)**:
  - Desliga o LED atual.
  - Alterna para o próximo LED.
  - Imprime no console qual LED foi desligado e qual foi ligado.

- **Loop principal (`while (true)`)**:
  - Aguarda 1 segundo.
  - Imprime "passou 1 segundo" no console.

---

## Biblioteca `led.h`

- **`void led_init(uint8_t pin);`**
  - Inicializa um pino como saída para controle de LED.

- **`void led_state(uint8_t pin, uint8_t state);`**
  - Define o estado do LED (ligado/desligado) no pino especificado.

---

## Esquema de Ligação

| LED      | Pino GPIO |
|----------|----------|
| Vermelho | GPIO 13  |
| Amarelo  | GPIO 12  |
| Verde    | GPIO 11  |

Cada LED está conectado a um pino GPIO através de um resistor de 330 Ω.

---

## Como Executar o Projeto

1) **Configurar o ambiente**:
   - Instale o Raspberry Pi Pico SDK.
   - Configure o ambiente de desenvolvimento.

2) **Compilar o código**:
   - Clone o repositório no diretório que você quer compilar utilizando:
     ```bash
     git clone https://github.com/yaaggo/periodic-timer-embarcatech.git
     ```
   - Compile utilizando as ferramentas do SDK do Pico.
   - (opcional) Se estiver utilizando a exntensão do Raspberry Pi Pico SDK no vscode, importe o projeto e compile pela extensão

4) **Fazer upload para a placa**:
   - Conecte a Raspberry Pi Pico via USB.
   - Envie o binário gerado para a placa.

5) **Executar o código**:
   - Observe os LEDs alternando a cada 3 segundos.
   - Acompanhe as mensagens no console serial.

---

## Observações

- Este projeto demonstra o uso de temporizadores periódicos na Raspberry Pi Pico.
- `add_repeating_timer_ms()` facilita a execução de funções em intervalos regulares.
- O loop principal garante que o programa continue rodando enquanto o temporizador gerencia os LEDs.

