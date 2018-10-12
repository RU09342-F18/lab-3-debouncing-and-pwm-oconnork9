# Lab 3: Hardware PWM

## Summary
 These programs use the MSP430FR2311 and MSP430G2553 microprocessors. The programs when a button is hit changes the light level of the LED. There are ten different levels of light given with each of the programs starting at half capacity.

## General Functionality
 Each of these programs attach an LED directly to a built in timer set to 1kHz. Capture compare register 1 is set to change in value everytime a button is pressed the duty cycle goes up by 10% and starts at 50%. When it reaches 100% and the button is pressed the duty cycle goes back to 0%.
 
## Inputs and Outputs

### MSP430FR2311
 INPUTS: P1.1-Button  
 OUTPUTS: P1.0- Red LED, P2.0-Green LED  
 Timers: TimerB1
 
### MSP430G2553
 INPUTS: P1.3-Button  
 OUTPUTS: P1.0-Green LED, P1.6-Red LED  
 Timers: TimerA0
 
## Authors

   Author: Kieran O'Connor  
   Last Editted: 10/5/2018
   
# Hardware PWM
Now that you have done the software version of PWM, now it is time to start leveraging the other features of these Timer Modules.

## Task
You need to replicate the same behavior as in the software PWM, only using the Timer Modules ability to directly output to a GPIO Pin instead of managing them in software. One way to thing about what should happen is that unless your are doing some other things in your code, your system should initialize, set the Timer Modules, and then turn off the CPU.

## Deliverables
You will need to have two folders in this repository, one for each of the processors that you used for this part of the lab. Remember to replace this README with your own.

### Hints
Read up on the P1SEL registers as well as look at the Timer modules ability to multiplex.

## Extra Work
### Using ACLK
Some of these microprocessors have a built in ACLK which is extremely slow compared to your up to 25MHz available on some of them. What is the overall impact on the system when using this clock? Can you actually use your PWM code with a clock that slow?

### Ultra Low Power
Using a combination of ACLK, Low Power Modes, and any other means you may deem necessary, optimize this PWM code to run at 50% duty cycle with a LED on the MSP430FR5994. In particular, time how long your code can run on the fully charged super capacitor. You do not need to worry about the button control in this case, and you will probably want to disable all the GPIO that you are not using (nudge, nudge, hint, hint).
