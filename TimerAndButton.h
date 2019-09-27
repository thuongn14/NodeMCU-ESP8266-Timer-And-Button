#include <Arduino.h>
#define LED0 0
#define LED1 12
#define LED2 2
#define LED3 14
#define LED4 4
#define LED5 5
#define LED6 16

#define ButtonA 10
#define ButtonB 9

extern bool pressA, pressA1s, pressA3s, pressB, pressB1s, pressB3s;
extern int value, prevValue, countA1s, countA3s, countB1s, countB3s;

void displayToLed(int value);

void readButtonA();

void readButtonB();
