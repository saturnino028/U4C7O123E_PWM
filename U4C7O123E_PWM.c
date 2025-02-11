#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

/***************** Defines *****************/

#define pwm_pin 22
#define LED_pin 12
#define top 25000

/********** Prototipo de Funcoes **********/

void duty_cicle(float _percent, uint _slice, uint8_t _pin); //Valor percentual do duty cicle (natural)

int main()
{
    float percentual;
    stdio_init_all(); //Inicia perifericos STDIO

    gpio_set_function(pwm_pin, GPIO_FUNC_PWM); //Habilita a função PWM no pino do Servo
    gpio_set_function(LED_pin, GPIO_FUNC_PWM); //Habilita a função PWM no pino do LED
    uint slice_pwm = pwm_gpio_to_slice_num(pwm_pin); //Obter o canal PWM Servo
    uint slice_led = pwm_gpio_to_slice_num(LED_pin); //Obter o canal PWM LED
    pwm_set_clkdiv(slice_pwm, 100.0); //Define o divisor de clock do PWM do Servo
    pwm_set_clkdiv(slice_led, 100.0); //Define o divisor de clock do PWM do LED
    pwm_set_wrap(slice_pwm, top); //Definir valor do WRAP Servo
    pwm_set_wrap(slice_led, top); //Definir valor do WRAP LED

    percentual = 12.0;
    duty_cicle(percentual, slice_pwm, pwm_pin); //Duty cicle 12% - Posição 180° do servo (2400us)
    duty_cicle(percentual, slice_led, LED_pin); //Duty cicle 12% - Brilho reduzido LED
    sleep_ms(5000);

    percentual = 7.35;
    duty_cicle(percentual, slice_pwm, pwm_pin); //Duty cicle 7.35% - Posição 90° do servo (1470 us)
    duty_cicle(percentual, slice_led, LED_pin); //Duty cicle 7.35% - Brilho reduzido LED
    sleep_ms(5000);

    percentual = 2.5;
    duty_cicle(percentual, slice_pwm, pwm_pin); //Duty cicle 2.5% - Posição 0° do servo (500 us)
    duty_cicle(percentual, slice_led, LED_pin); //Duty cicle 2.5% - Brilho reduzido LED
    sleep_ms(5000);

    while (1)
    {
        for(percentual; percentual<12.0; percentual = percentual + 0.025) //Incremento de 5 us
        {
            duty_cicle(percentual, slice_pwm, pwm_pin);
            duty_cicle(percentual, slice_led, LED_pin);
            sleep_ms(10);
        }
        for(percentual; percentual>2.5; percentual = percentual - 0.025) //Dencremento de 5 us
        {
            duty_cicle(percentual, slice_pwm, pwm_pin);
            duty_cicle(percentual, slice_led, LED_pin);
            sleep_ms(10);
        }
    }
    
}

void duty_cicle(float _percent, uint _slice, uint8_t _pin)
{
    pwm_set_enabled(_slice, false); //Desabilita PWM

    uint16_t valor_pwm = (_percent/100) * top;
    pwm_set_gpio_level(_pin, valor_pwm);

    pwm_set_enabled(_slice, true); //Habilitar PWM
}
