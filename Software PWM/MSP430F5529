#include <msp430.h> 


/**
 * main.c
 */
int unsigned c = 6; //Determines case duty cycle percentage

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

        P1DIR |= BIT0; //Sets P1.0 as Output
        P1OUT |= BIT0; //Turns ON P1.0

        P4DIR |= BIT7; //Sets P1.6 as Output
        P4OUT &=~BIT7; //Turns off P1.6

        P1DIR &=~BIT1; //Sets P1.3 as Input
        P1OUT |= BIT1; //Sets Resistor as Pull-up Resistor
        P1REN |= BIT1; //Sets Resistor on P1.3

        TA0CCTL1 = CCIE;
        TA0CTL=TASSEL_2+MC_1+ID_2 +TACLR + TAIE;

        TA0CCR0 = 255; //Sets Timer count
        TA0CCR1 = 128 ; //Sets Initial Duty cycle percentage
        P1IE |= BIT1; //Interrupt
        P1IES |= BIT1; //Sets Interrupt as activated by positive clock edge
        P1IFG &=~ BIT1; //Clears Interrupt Flags
        _BIS_SR(LPM0_bits + GIE); //Low power mode 0 enabled and Global Interrupt
}
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer0_A1(void)
{
    switch(TA0IV) //Detects which interrupt was flagged
    {
    case 2: //CCR1
        if(c==1)
        {
        P1OUT &=~ BIT0; //Turns OFF P1.0 (Makes sure LED is OFF)
        }
        else
        {
        P1OUT ^= BIT0; //Toggles P1.0
        }
        break;
    case 14: //Overflow
        P1OUT |= BIT0; //Turns ON P1.0
        break;
    }

}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    c=c+1;
    switch(c)
        {
        case 1:
            P1OUT &=~BIT0; //Turns OFF P1.0
            TA0CTL=MC_0; //Stops Timer
            TA0CCR1 = 0; //Duty cycle 0%
              break;
        case 2:
            TA0CTL=TASSEL_2+MC_1+ID_2 +TAIE; //Timer Set to SMCLK, UP, 4 Divider, Timer Interrupt Enabled
              TA0CCR1 = 26 ; //Duty cycle 10%
              break;
        case 3:
              TA0CCR1 = 51 ; //Duty cycle 20%
              break;
        case 4:
              TA0CCR1 = 77 ; //Duty cycle 30%
              break;
        case 5:
              TA0CCR1 = 102; //Duty cycle 40%
              break;
        case 6:
              TA0CCR1 = 128 ; //Duty cycle 50%
              break;
        case 7:
              TA0CCR1 = 158 ; //Duty cycle 60%
              break;
        case 8:
              TA0CCR1 = 179 ; //Duty cycle 70%
              break;
        case 9:
              TA0CCR1 = 204 ; //Duty cycle 80%
              break;
        case 10:
              TA0CCR1 = 230 ; //Duty cycle 90%
              break;
        case 11:
              TA0CCR1 = 255 ; //Duty cycle 100%
              c=0; //Resets
              break;

        }

    P1IFG &=~ BIT1; //Clears Interrupt Flags

}
