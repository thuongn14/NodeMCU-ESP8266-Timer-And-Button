# NodeMCU ESP8266 Timer And Button
## Objectives
- Learn how to use a timer in NodeMCU
- Learn how to read digital inputs and display values via UART/LED using a timer

## Problem
In this lab, we have to write a program that
- Has a timer which has an interrupt in every 10 milliseconds.  
- Reads values of two buttons every 10 milliseconds. The read button function should be called inside the timer interrupt service routine.
- Increases the counter value when the first button is pressed.
- Increases the counter value automatically in every 0.5 seconds, if the first button is pressed in more than 1 second.
- Increases the counter value automatically in every 0.1 seconds, if the first button is pressed in more than 3 seconds.
- Decreases the counter value when the second button is pressed.
- Decreases the counter value automatically in every 0.5 second, if the second button is pressed in more than 1 second.
- Decreases the counter value automatically in every 0.1 second, if the second button is pressed in more than 3 seconds.
- The above values such as 10 ms, 0.5 s, 0.1s, 1 s and 3 s are fixed values as an example. Your program, however, needs to provide an easy way to change those values. For example, you should use DEFINE to define those values.
- If both buttons are pressed, the first button has a higher priority than the second one.
