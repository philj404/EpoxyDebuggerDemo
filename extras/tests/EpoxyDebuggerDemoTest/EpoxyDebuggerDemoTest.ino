// EpoxyDebuggerDemo library tests

// Adapted from:
// https://github.com/mmurdoch/arduinounit/blob/master/examples/basic/basic.ino

#include <AUnit.h>
#include "EpoxyDebuggerDemo.h"

test(average3)
{
    double a = 1.0;
    double b = 2.0;
    double x = 3.0;

    double result = average3(a, b, x);

    assertNear(1.0e-3, 2.0, result);
}

//----------------------------------------------------------------------------
// setup() and loop()
//----------------------------------------------------------------------------

void setup()
{
    delay(1000);           // wait for stability on some boards to prevent garbage Serial
    Serial.begin(115200);  // ESP8266 default of 74880 not supported on Linux
    while (!Serial)
        ;                  // for the Arduino Leonardo/Micro only

    Serial.println(F("Running " __FILE__ ",\nBuilt " __DATE__));
    Serial.println(F("This test should produce the following:"));
    Serial.println(
        F("EXAMPLE - SEE THE REAL ONE BELOW: 1 passed, 0 failed, 0 skipped, 0 timed out, out of 1 test(s)."));
    Serial.println(F("----"));
}

void loop()
{
    aunit::TestRunner::run();
}
