/*
 * A quick test for accessing GPIO pins on STM32F429i dev board
 */

#include "stm32f4xx.h"
#include <stdio.h>
#include <unistd.h>

#include "stm32f4xx_gpio.h"
//#include "stm32f4xx_rcc.h"

const uint16_t LEDS = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
const uint16_t LED[4] = {GPIO_Pin_12, GPIO_Pin_13, GPIO_Pin_14, GPIO_Pin_15};

void init();
void delay();
void toggleGPIOpinISO();

int main(void)
{
    init();

    do {
    	toggleGPIOpinISO(0);
    } while (1);
}

void init()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin = LEDS;
    GPIO_Init(GPIOD, &gpio);
    GPIO_SetBits(GPIOD, LEDS);
}

void toggleGPIOpinISO(unsigned int nr)
{
		delay(2500);
	    GPIO_ResetBits(GPIOD, LEDS);
	    delay(2500);
	    GPIO_SetBits(GPIOD, LED[nr]);
}

void delay(uint32_t ms)
{
    ms *= 3360;
    while(ms--) {
        __NOP();
    }
}
