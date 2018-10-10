#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;

    P1DIR |= BIT0; //Sets P1.0 as Output
    P1OUT |= BIT0; //Turns P1.0 On

    P2DIR |= BIT0; //Sets P1.6 as Output
    P2OUT &=~BIT0; //Turns off P1.6

    P1DIR &=~BIT1; //Sets P1.3 as Input
    P1OUT |= BIT1; //Sets Resistor as Pull-up Resistor
    P1REN |= BIT1; //Sets Resistor on P1.3

    TB0CCTL0 = CCIE; //Interrupt Enabled
    P1IE |= BIT1; //Interrupt
    P1IES |=BIT1; //Sets Interrupt as activated by positive clock edge
    P1IFG &=~BIT1; //Clears Interrupt Flags

    _BIS_SR(LPM0_bits + GIE); //Low power mode 0 and Global Interrupt Enable
}

#pragma vector=TIMER0_B0_VECTOR
__interrupt void Timer0_B0(void)
{
    P2OUT &=~ BIT0; //Turns OFF P4.7
    P1OUT ^= BIT0; //Flashes P1.0 Green LED
    TB0CTL = TBCLR; //Clears Timer
    TB0CTL= MC_0; //Stops Timer

}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{

    P2OUT |= BIT0; //Turns ON P4.7
    TB0CTL = TBCLR; //Clears Timer
    TB0CCR0 = 16000; //Sets delay before next button hit to 1/8 of a second
    TB0CTL = TBSSEL_1 + MC_1 + ID_0; //Sets Timer to ACLK, UP, 1 Divider
    P1IES ^= BIT1; //Toggles the interrupt edge for Button
    P1IFG &=~ BIT1; //Unsets Interrupt Flag

}
