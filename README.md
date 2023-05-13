# EpoxyDebuggerDemo
Example library of VS Code, debugger, EpoxyDuino and AUnit working together

### Usage 
This library is made to work with the Arduino platform.  It is not dependent on other libraries (except for Arduino.h).  _Users_ of the library should not need to include other libraries.

### Development/Continuous Integration
For development (adding features, regression testing, ...), this library depends on the following:
* Github.com (website for repository)
* Github Actions
  * `githubci.yml` -- Arduino board configuration build checks (AVR, ESP32 ...)
  * `aunit_tests.yml` -- regression tests on Linux
See also [Development.md](Development.md)

These Github scripts will check that code compiles and tests PASS, or warn you if there is a regression.

### Regression testing
Regression tests are added to extras/tests/* sketches, and depend on:
* Linux build environment
* the "AUnit" unit testing library
* the "EpoxyDuino" library for basic Linux compatibity
