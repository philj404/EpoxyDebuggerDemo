// Average3Demo.ino
//
// trivial example of a trivial library
//
#include <Arduino.h>

#include <EpoxyDebuggerDemo.h>

void printAverage3(double a, double b, double c) {

    double result = average3(a,b,c);

    Serial.print(F("The average of ")); Serial.print(a);
    Serial.print(F(", ")); Serial.print(b);
    Serial.print(F(", and ")); Serial.print(c);
    Serial.print(F(" is ")); Serial.println(result);
}

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  delay(1000);
  printAverage3(1.0, 2.0, 3.0);
}

// the loop function runs over and over again forever
void loop() {
}

