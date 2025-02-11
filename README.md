# PWM Servo e LED com Raspberry Pi Pico

Este projeto demonstra o uso do PWM no Raspberry Pi Pico para controlar um servo motor e um LED, variando seus sinais de PWM gradativamente.

## Requisitos
- Raspberry Pi Pico W
- Servomotor – motor micro servo padrão (simulado no Wokwi)
- LED RGB (simulado no Wokwi) e integrado a BitDogLab
- Ambiente de desenvolvimento:
  - **VS Code** com integração ao **Wokwi**
  - **Pico SDK**
  - **BitDogLab**
  - **GitHub** para versionamento

## Descrição do Código
O código inicializa o Raspberry Pi Pico e configura os seguintes pinos para saída PWM:
- **pwm_pin (GPIO 22)**: Controla o servo motor.
- **LED_pin (GPIO 12)**: Controla o brilho do LED RGB.

A função `duty_cicle` ajusta o ciclo de trabalho (duty cycle) de cada canal PWM com base em um valor percentual. 
O programa executa três ajustes iniciais do PWM para posicionar o servo em ângulos de 180°, 90° e 0° e controlar o brilho do LED proporcionalmente. 
Depois, entra em um loop onde o PWM varia suavemente entre os valores mínimo e máximo.

## Funcionamento
1. **Configuração do PWM**:
   - A frequência do PWM da **GPIO 22** é definida para **50Hz (período de 20ms)**.
   - O ciclo ativo do PWM é ajustado para os seguintes tempos:
     - **2.400µs** → Servo a **180°** (12% duty cycle)
     - **1.470µs** → Servo a **90°** (7.35% duty cycle)
     - **500µs** → Servo a **0°** (2.5% duty cycle)
   - Cada posição é mantida por **5 segundos**.
2. **Movimentação contínua**:
   - O servo se movimenta suavemente entre **0° e 180°**, com incrementos/decrementos de **5µs** e atraso de **10ms**.
3. **Teste com LED RGB**:
   - Utilizando o **BitDogLab**, o comportamento do LED RGB (GPIO 12) é analisado conforme variações do PWM.

## Como Usar
1. Instale o **VS Code** e configure o **Pico SDK**.
2. Integre o **Wokwi** ao ambiente de desenvolvimento.
3. Clone este repositório e compile o código.
4. Simule o funcionamento no **Wokwi**.
5. Utilize a **BitDogLab** para testar a iluminação do LED RGB.

---
✏️ Desenvolvido para experimentação com PWM no Raspberry Pi Pico W com integração ao Wokwi e BitDogLab no contexto da capacitação em sistemas embarcados fornecida pelo CEPEDI.

