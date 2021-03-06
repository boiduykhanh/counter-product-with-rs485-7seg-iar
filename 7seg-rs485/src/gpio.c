#include "stm8s.h"
#include "gpio.h"


static void gpio_config (void)
{
  GPIO_Init(GPIOC, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOD, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOA, GPIO_PIN_1|GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOB, GPIO_PIN_4|GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
}


