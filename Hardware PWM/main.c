#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
        P2DIR |= BIT0; //Sets P1.6 as Output
        P2SEL0 |= BIT0;
        P2SEL1 &= ~BIT0; //Sets P1.6 as Timer_B
        P1DIR |= BIT0; //Sets P1.0 as Output
        P1OUT &= ~BIT0; //Sets P1.0 as Off

        P1DIR &= ~BIT1; //Sets P1.3 as Input
        P1REN |= BIT1; //Sets resistor on P1.3
        P1OUT |= BIT1; //Sets resistor as pull up

        P1IE |= BIT1; //Sets Interrupt for P1.3
        P1IES |= BIT1; //Sets P1.3 Interrupt on positive edge
        P1IFG &= ~BIT1; //Clears all interrupt flags

        TB1CCTL1 = OUTMOD_7; //Sets the PWM as Reset/Set
        TB1CCR1 = 128; //Sets duty cycle at 50%
        TB1CCR0 = 255; //Sets period

        TB1CTL = TBSSEL_2 + MC_1 + ID_2; //Sets Timer as SMCLK, UP, 4 Divider

        _BIS_SR(LPM0_bits + GIE); //Low power mode 0 and Global Interrupt Enable


    }
    #pragma vector=PORT1_VECTOR
    __interrupt void Port_1(void)
    {

        if(P1IES & BIT1) //Checks for interrupt as positive edge
        {
            P1OUT |= BIT0; //Turns ON P1.0
            P1IES &= ~BIT1; //Sets interrupt to negative edge
            if(TB1CCR1 <= 255) //Checks Capture Compare Register 1's percentage is less than 100%
            {
                TB1CCR1 += 25; //adds 10% duty cycle
            }
            else
            {
                TB1CCR1 = 0; //Sets to 0%
            }
        }
        else
        {
            P1OUT &= ~BIT0; //Turns OFF P1.0
            P1IES |= BIT1; //Sets interrupt to positive edge
        }
        P1IFG &= ~BIT1; //Clears interrupt flags
    }
