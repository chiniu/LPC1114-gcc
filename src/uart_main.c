/****************************************************************************
 *   $Id:: uart_main.c 4824 2010-09-07 18:47:51Z nxp21346                   $
 *   Project: NXP LPC11xx UART example
 *
 *   Description:
 *     This file contains UART test modules, main entry, to test UART APIs.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#include "driver_config.h"
#include "target_config.h"

#include "uart.h"
#include "gpio.h"

extern volatile uint32_t UARTCount;
extern volatile uint8_t UARTBuffer[BUFSIZE];
extern volatile uint32_t p0_2_counter;

int main (void) {
   int i;
   uint32_t cnt = 0;
   int led = 0; /* on state */
	  /* Basic chip initialization is taken care of in SystemInit() called
	   * from the startup code. SystemInit() and chip settings are defined
	   * in the CMSIS system_<part family>.c file.
	   */

  /* NVIC is installed inside UARTInit file. */
  UARTInit(UART_BAUD);
  printf("LPC1114 init\n");

  GPIOInit();

  LPC_IOCON->PIO0_1 = 0; 
#if 0
  GPIOSetDir(PORT0, 1, 1);
  GPIOSetValue(PORT0, 1, led);
  GPIOSetValue(PORT0, 1, 1);
#else

  GPIOSetDir(PORT0, 1, 0);
#endif

#if CONFIG_GPIO_DEFAULT_PIOINT0_IRQHANDLER==1
  LPC_IOCON->PIO0_2 = 0; 
  GPIOSetDir(PORT0, 1, 0);
  GPIOSetInterrupt(PORT0, 1, 0, 0, 0);
  GPIOIntEnable(PORT0, 1); 
#else

 #endif



  while (1) 
  {				/* Loop forever */
	if ( UARTCount != 0 )
	{
	  LPC_UART->IER = IER_THRE | IER_RLS;			/* Disable RBR */
	  UARTSend( (uint8_t *)UARTBuffer, UARTCount );
	  UARTCount = 0;
	  LPC_UART->IER = IER_THRE | IER_RLS | IER_RBR;	/* Re-enable RBR */
	}
    
#if CONFIG_GPIO_DEFAULT_PIOINT0_IRQHANDLER==1
    if(cnt != p0_2_counter){
   /*     led ^= led;
        GPIOSetValue(PORT0, 1, led);
*/
        printf("=");
        cnt = p0_2_counter;
    }
#else
#endif
    if (GPIOGetValue(PORT0, 1) != 1)
      printf("-");
      
  }
}
