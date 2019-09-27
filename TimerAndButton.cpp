#include "TimerAndButton.h"

int prevValue = 0;
int value = 0;
int countToStatusA = 0;
int countToValueA = 0;

int countToStatusB = 0;
int countToValueB = 0;

bool firstReadA = 0;
bool secondReadA = 0;
bool firstReadB = 0;
bool secondReadB = 0;

bool pressA = 0;
bool pressA1s = 0;
bool pressA3s = 0;

bool pressB = 0;
bool pressB1s = 0;
bool pressB3s = 0;

void displayToLed(int value) {
  digitalWrite(LED0, bitRead(value, 0));
  digitalWrite(LED1, bitRead(value, 1));
  digitalWrite(LED2, bitRead(value, 2));
  digitalWrite(LED3, bitRead(value, 3));
  digitalWrite(LED4, bitRead(value, 4));
  digitalWrite(LED5, bitRead(value, 5));
  digitalWrite(LED6, bitRead(value, 6));
}

// Remember we read button every 10ms, so which so with 100 times is equal to 1 second, 300 times is equal to 3 seconds !!!

void readButtonA() {
  firstReadA = secondReadA;
  secondReadA = digitalRead(ButtonA);
  // We need to check whether the value of the button twice is the same?
  if (secondReadA == firstReadA) {
    if (firstReadA) {
      pressA = 1;
      countToStatusA++;
      if (countToStatusA >= 100) {
        if (countToStatusA >= 300) {
          pressA3s = 1;
          countToValueA++;
          }
        else {
        pressA1s = 1;
        countToValueA++;
        }
      }
    } else {
      // Reset all flag variables if the value of 2 consecutive readings is different
      pressA = 0;
      pressA1s = 0;
      pressA3s = 0;
      countToStatusA = 0;
      countToValueA = 0;
    }
  }
}

void readButtonB() {
  firstReadB = secondReadB;
  secondReadB = digitalRead(ButtonB);
  // We need to check whether the value of the button twice is the same?
  if (secondReadB == firstReadB) {
    if (firstReadB) {
      pressB = 1;
      countToStatusB++;
      if (countToStatusB >= 100) {
        if (countToStatusB >= 300) {
          pressB3s = 1;
          countToValueB++;
          }
        else {
        pressB1s = 1;
        countToValueB++;
        }
      }
    } else {
      // Reset all flag variables if the value of 2 consecutive readings is different
      pressB = 0;
      pressB1s = 0;
      pressB3s = 0;
      countToStatusB = 0;
      countToValueB = 0;
    }
  }
}
