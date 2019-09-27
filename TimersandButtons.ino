// Create by Nguyen Hoang Thuong
// Email: thuongn14@gmail.com

#include <Ticker.h>
#include "TimerAndButton.h"

enum {WAIT, INCREASE_0NE, INCREASE_EVERY_500MS, INCREASE_EVERY_100MS, DECREASE_ONE, DECREASE_EVERY_500MS, DECREASE_EVERY_100MS} currentState;

// Button A as the value increment button
// Button B as the value decrement button

Ticker TickerA, TickerB;

void setup() {
  Serial.begin(115200);
  pinMode(ButtonA, INPUT);
  pinMode(ButtonB, INPUT);

  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  TickerA.attach_ms(10, readButtonA);
  TickerB.attach_ms(10, readButtonB);
}

void loop() {
  
  switch (currentState) {
    case WAIT:
      if (pressA) {
        value++;
        currentState = INCREASE_0NE;
      }
      else if (pressB) {
        value--;
        currentState = DECREASE_ONE;
      }
      break;

    case INCREASE_0NE:
      if (!pressA) currentState = WAIT;
      else if (pressA1s) currentState = INCREASE_EVERY_500MS;
      break;

    case INCREASE_EVERY_500MS:
      if (countToValueA == 50) {
        value++;
        countToValueA = 0;
      }
      if (!pressA) currentState = WAIT;
      if (pressA3s) currentState = INCREASE_EVERY_100MS;
      break;
      
    case INCREASE_EVERY_100MS:
      if (countToValueA == 10) {
        value++;
        countToValueA = 0;
      }
      if (!pressA) currentState = WAIT;
      break;

    // Because the priority of button A is higher, we should always check the status of button A before reducing the value
      
    case DECREASE_ONE:
      if (pressA) currentState = WAIT;
      else {
        if (!pressB) currentState = WAIT;
        else if (pressB1s) currentState = DECREASE_EVERY_500MS;
      }
      break;
      
    case DECREASE_EVERY_500MS:
      if (pressA) currentState = WAIT;
      else {
        if (countToValueB == 50) {
          value--;
          countToValueB = 0;
        }
        
      if (!pressB) currentState = WAIT;
      if (pressB3s) currentState = DECREASE_EVERY_100MS;
      }
      break;
      
    case DECREASE_EVERY_100MS:
      if (pressA == true) currentState = WAIT;
      if (countToValueB == 10) {
        value--;
        countToValueB = 0;
      }
      if (pressB == 0) currentState = WAIT;
      break;
  }

  // This code to display the value to Serial Monitor that helps to check the result
  // I only print the value when it changes
  // N O T E : If you want to use Serial Monitor, you shouldn't use to the GPIO1 (TXD0) and GPIO (RXD0)
  if (prevValue != value) Serial.println(value);
  prevValue = value;

  // This function to display the value to LEB by bits
  displayToLed(value);
}
