# Lab 3: Debouncing

## Summary
 The two programs that were created were made with two boards MSP430F5529 and the MSP430FR2311 the reason theres were chosen rather than the MSP430G2553 was the effective deboucing already integrated into the board. The boards debounce by waiting 1/8 of a second to preform an action which just toggles the button. Delaying this stops the LED from being triggered by the button again until the action is preformed.

## General Functionality
 The programs work with a timer when the button is pressed and release the timer starts after 1/8 of a second it toggles the button using an interrupt.
 
## Inputs and Outputs

### MSP430F5529
 INPUTS: P1.1-Button
 OUTPUTS: P1.0- Red LED, P4.7-Green LED
 Timer: TimerA0
 
### MSP430FR2311
 INPUTS: P1.3-Button  
 OUTPUTS: P1.0-Green LED, P2.0-Red LED
 Timer: TimerB0
 
## Authors

   Author: Kieran O'Connor  
   Last Editted: 10/9/2018
   
# Software Debouncing
In previous labs, we talked about how objects such as switches can cause some nasty effects since they are actually a mechanical system at heart. We talked about the simple hardware method of debouncing, but due to the many different design constraints, you may not be able to add or adjust hardware. Debouncing is also only one of many applications which would require the use of built in Timers to allow for other processes to take place.

## Task
You need to utilize the TIMER modules within the MSP430 processors to implement a debounced switch to control the state of an LED. You most likely will want to hook up your buttons on the development boards to an oscilloscope to see how much time it takes for the buttons to settle. The idea here is that your processor should be able to run other code, while relying on timers and interrupts to manage the debouncing in the background. *You should not be using polling techniques for this assignment.*

## Deliverables
You will need to have two folders in this repository, one for each of the processors that you used for this part of the lab. Remember to replace this README with your own.

### Hints
You need to take a look at how the P1IE and P1IES registers work and how to control them within an interrupt routine. Remember that the debouncing is not going to be the main process you are going to run by the end of the lab.

## Extra Work
### Low Power Modes
Go into the datasheets or look online for information about the low power modes of your processors and using Energy Trace, see what the lowest power consumption you can achieve while still running your debouncing code. Take a note when your processor is not driving the LED (or unplug the header connecting the LED and check) but running the interrupt routine for your debouncing.

### Double the fun
Can you expand your code to debounce two switches? Do you have to use two Timer peripherals to do this?
