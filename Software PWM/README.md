# Lab 3: Software PWM

## Summary
 Theses programs included use the MSP430F5529 and MSP430G2553. Each of the programs start at a light level of 50% for a set LED, rises by 10% everytime a button is pressed and resets to 0% after the button is pressed at 100%.

## General Functionality
 For these programs the an LED is originally set to a duty cycle of 50% with a timer with a frequency of 1kHz. With the button the duty cycle is changed everytime a button is pressed triggering an interrupt changing the value with a case statement increasing the duty cycle by 10% and reset to 0 when 100% is reached. 
 
## Inputs and Outputs

### MSP430F5529
 INPUTS: P1.1-Button  
 OUTPUTS: P1.0- Red LED, P4.7-Green LED  
 Timers: TimerA0
 
### MSP430G2553
 INPUTS: P1.3-Button  
 OUTPUTS: P1.0-Green LED, P1.6-Red LED  
 Timers: TimerA0
 
## Authors

   Author: Kieran O'Connor  
   Last Editted: 10/10/2018
   
# Software PWM
Most microprocessors will have a Timer module, but depending on the device, some may not come with pre-built PWM modules. Instead, you may have to utilize software techniques to synthesize PWM on your own.

## Task
You need to generate a 1kHz PWM signal with a duty cycle between 0% and 100%. Upon the processor starting up, you should PWM one of the on-board LEDs at a 50% duty cycle. Upon pressing one of the on-board buttons, the duty cycle of the LED should increase by 10%. Once you have reached 100%, your duty cycle should go back to 0% on the next button press. You also need to implement the other LED to light up when the Duty Cycle button is depressed and turns back off when it is let go. This is to help you figure out if the button has triggered multiple interrupts.

## Deliverables
You will need to have two folders in this repository, one for each of the processors that you used for this part of the lab. Remember to replace this README with your own.

### Hints
You really, really, really, really need to hook up the output of your LED pin to an oscilloscope to make sure that the duty cycle is accurate. Also, since you are going to be doing a lot of initialization, it would be helpful for all persons involved if you created your main function like:

```c
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	LEDSetup(); // Initialize our LEDS
	ButtonSetup();  // Initialize our button
	TimerA0Setup(); // Initialize Timer0
	TimerA1Setup(); // Initialize Timer1
	__bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt
}
```

This way, each of the steps in initialization can be isolated for easier understanding and debugging.


## Extra Work
### Linear Brightness
Much like every other things with humans, not everything we interact with we perceive as linear. For senses such as sight or hearing, certain features such as volume or brightness have a logarithmic relationship with our senses. Instead of just incrementing by 10%, try making the brightness appear to change linearly.

### Power Comparison
Since you are effectively turning the LED off for some period of time, it should follow that the amount of power you are using over time should be less. Using Energy Trace, compare the power consumption of the different duty cycles. What happens if you use the pre-divider in the timer module for the PWM (does it consume less power)?
