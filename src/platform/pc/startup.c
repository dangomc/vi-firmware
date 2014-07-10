/*
 * Derived from startup code originally published by Jakub Piotr Cłapa,
 * Copyright (c) 2010 LoEE under the new BSD license.
 *
 * See also: http://bitbucket.org/jpc/lpc1768/
 *
 * NVIC handler names from NXP UM10360, comments taken from Opendous Inc. under
 * the following license:
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that the
 * copyright notice and this permission notice and warranty disclaimer appear in
 * supporting documentation, and that the name of the author not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.

 * The author disclaim all warranties with regard to this software, including
 * all implied warranties of merchantability and fitness.  In no event shall the
 * author be liable for any special, indirect or consequential damages or any
 * damages whatsoever resulting from loss of use, data or profits, whether in an
 * action of contract, negligence or other tortious action, arising out of or in
 * connection with the use or performance of this software.
 */
//#include "LPC17xx.h"

// Defined in linker script
extern void __stack(void);
/*extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;*/

// Defined by user application
extern int main (void);

// Dummy handler.
void Default_Handler (void) { while (1); }

// Weakly bind all interrupt vectors to the dummy handler.
void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void HardFault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void MemManage_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void BusFault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void UsageFault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void SVC_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void DebugMon_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void PendSV_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void SysTick_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void WDT_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void TIMER0_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void TIMER1_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void TIMER2_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void TIMER3_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART0_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART1_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART2_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void UART3_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void PWM1_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C0_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C1_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void I2C2_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void SPI_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void SSP0_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void SSP1_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void PLL0_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void RTC_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void EINT0_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void EINT1_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void EINT2_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void EINT3_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void ADC_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void BOD_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void USB_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void CAN_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void DMA_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void I2S_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void ENET_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void RIT_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void MCPWM_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void QEI_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void PLL1_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void USBActivity_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));
void CANActivity_IRQHandler(void) __attribute__ ((weak, alias ("Default_Handler")));

// The signature of Cortex-M3 interrupt handlers.
typedef void (* const Interrupt_Handler_P)(void);

// Forward declaration of Reset_Handler so we can refernece interrupt_vectors
// when setting the VTOR in the handler.
void Reset_Handler(void);

// Interrupt vectors table
__attribute__ ((section(".isr_vector")))
Interrupt_Handler_P interrupt_vectors[] = {};

void Reset_Handler(void) {

  // Everything is ready. Run the user program.
  main();
  //while(1); // in case main() fails
}
