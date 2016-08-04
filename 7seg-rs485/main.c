/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "gpio.c"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
unsigned char font[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

/* Private variables ---------------------------------------------------------*/
__IO uint32_t t_delay = 0;
/* Private functions ---------------------------------------------------------*/
static void gpio_config (void);
static void clk_config(void);
void SCANLED (__IO uint8_t a,__IO uint8_t b,__IO uint8_t c,__IO uint8_t d);
void DISPLAY(unsigned char data);
void delay(unsigned int timer);
void delay_ms (__IO uint32_t n);
/* Public functions ----------------------------------------------------------*/

void main(void)
{
  clk_config();
  gpio_config(); 

  enableInterrupts();
  
  while (1)
  {
   
    SCANLED(1,2,3,4);
  }
}


/**
  * @brief gpio_config
  * @param None
  * @retval None
  */

static void clk_config(void)
{
   /* Initialization of the clock , main clock 16Mhz*/
   /* Clock divider to HSI/1 */
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
}
// Scanled 7seg*4
void DISPLAY(unsigned char data)
{
GPIO_Write(GPIOC,(font[data])<<3);
GPIO_Write(GPIOD,((font[data])>>4));
}


void delay(unsigned int timer)
{
while(timer--);
}

void delay_ms (__IO uint32_t n)
{
  t_delay = n;
  while (t_delay != 0);
}

void SCANLED (__IO uint8_t a,__IO uint8_t b,__IO uint8_t c,__IO uint8_t d)
{
  GPIO_WriteLow(GPIOA,LED1);
  GPIO_WriteHigh(GPIOA,LED2);
  GPIO_WriteHigh(GPIOA,LED3);
  GPIO_WriteHigh(GPIOA,LED4);
  DISPLAY (d);
  delay(1000);
  GPIO_WriteLow(GPIOA,LED2);
  GPIO_WriteHigh(GPIOA,LED1);
  GPIO_WriteHigh(GPIOA,LED3);
  GPIO_WriteHigh(GPIOA,LED4);
  DISPLAY (c);
  delay(1000);
  GPIO_WriteLow(GPIOA,LED3);
  GPIO_WriteHigh(GPIOA,LED2);
  GPIO_WriteHigh(GPIOA,LED1);
  GPIO_WriteHigh(GPIOA,LED4);
  DISPLAY (b);
  delay(1000);
  GPIO_WriteLow(GPIOA,LED4);
  GPIO_WriteHigh(GPIOA,LED2);
  GPIO_WriteHigh(GPIOA,LED3);
  GPIO_WriteHigh(GPIOA,LED1);
  DISPLAY (a);
  delay(1000);
}



#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
