# EpoxyDebuggerDemo

Example library of VS Code, debugger, EpoxyDuino and AUnit working together

### Usage 
This library is made to work with the Arduino platform.  It is not dependent on other libraries (except for Arduino.h).  _Users_ of the library should not need to include other libraries.

(description for EpoxyDebuggerDemo template - obsolete if you have copied it)
Because this is just a TEMPLATE, you do not need to clone this repository! You just want to _COPY_ files into your own library. Instead of cloning:

* Start with your own git repository (for example a directory with `git init`)
* "Download ZIP" a copy of the EpoxyDebuggerDemo "main" branch
* unzip and copy these files to where you want.  Be careful to avoid overwriting your own files (.gitignore, .clang-format, LICENSE etc.) unless you really mean it.
* Modify files as needed to make them better match your library's requirements.  For example this README.md file is talking about the template, and _your own README.md should describe your code._
* For files which might need adjustment, search for "EpoxyDebuggerDemo". _You will need some other name after copying the template to your own library._  The word "CHANGE_ME" is also a hint that this template needs more changes for your code.

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
* the "EpoxyDuino" library for basic Linux compatibility
