# *EpoxyDebuggerDemo* library feature development notes



### Linux development
I find it useful to develop code on a Linux computer, as this lets me run my regression tests directly without downloading a sketch, or pushing each change to github.

While I have the Arduino IDE installed, it is more set up to _use_ libraries rather than _create_ them. Example sketches must be built one at a time, so getting interface changes to match in all examples and tests is difficult.

So... the Github Actions use Makefiles and the gcc/g++ toolchain, and I use 'make' in the same way.  In the top-level directory:
* `make all` to do a full build and test
* `make run` to build tests
* `make test` to (build and) run tests
* `make clean` to delete generated output files
* `make debug` to create executables with debugger support

It is important that this library can find the `EpoxyDuino` and `AUnit` libraries it uses for testing.  To ensure this I put my development library repository inside the Arduino "libraries/" directory. Other libraries (which this library depends on) are at the same level.  For example the `AUnit` library will be found  at the relative path "../AUnit":
* libraries/
  * LIBRARY_TO_DEBUG (this library)
  * AUnit/
  * EpoxyDuino/
  * (other libraries...)

### Debugging and development with Visual Studio Code (experimental)
It would be nice to use a debugger while adding features and running my tests.  Debuggers provide much faster feedback than editing/examining `Serial.print(...)` statements with every run.  As a bonus, development under Linux can skip the "download sketch" step, which can take a while for large sketches.

So... this library supports a Visual Studio Code workspace which can build and debug the library and its tests.  To use this capability you must have the following installed:
* Visual Studio Code
  * C/C++ (Microsoft Extension)
  * C/C++ Extension Pack (Microsoft Extension)
  * C/C++ Extension Themes (Microsoft Extension)
  * Makefile Tools (Microsoft Extension)

At the top level of this library, I enter the command: `code EpoxyDebuggerDemo.code-workspace` to run VS Code.  Specifying the code-workspace file helps give VS Code a base path from which to search for useful files and libraries.

Interesting magic is in:
* EpoxyDebuggerDemo.code-workspace
* .vscode/c_cpp_properties.json
* .vscode/launch.json
* .vscode/settings.json
* (not needed? .vscode/tasks.json)

It is important to do a ("clean" and) "debug" build before using the debugger.

I have been able to clean, build, set breakpoints in a regression test, examine variables, step, and continue.

I have set up the VS Code settings to support "Debug" and "Release" configurations.  Usually I use the "Debug" configuration... but "Release" will behave differently and it's also worth testing.  The GitHub regression test uses the "Release" build.

Under "Makefile Tools" tab:
*  set "Configuration" to "Debug"
*  set "Build target" to "configuredBuild"

### Warnings:
* Right now the code must be supported for at least FOUR different platforms.  Any changes need to be confirmed to STILL WORK for all these platforms:
  * Arduino IDE 1.0 (for users)
  * Arduino IDE 2.0 (for users)
  * Linux Makefile (for developers and GitHub integration tests)
  * Visual Studio Code (for local developer debugging)
* The VS code build controls and settings are a bit quirky.  Probably could be cleaner (someday)
* The VS code formatter uses clang-format rather than "Arduino 1.0" or "Arduino 2.0" formatters.  This auto-format mismatch could cause merge conflicts (for example it can keep generating trivial whitespace changes) if ALL developers are not consistent in which formatter they use.
* Note that VS code C++ Intellisense does NOT use the Makefiles to determine what the include paths and build-time #defines are. That needs to be coordinated (Makefiles and .vscode/c_cpp_properties.json).  That should be OK for this example, but if the Makefile gets more complicated, c_cpp_properties.json (or the other .json files) may need to get more complicated too.

### References
* Using C++ on Linux in VS Code https://code.visualstudio.com/docs/cpp/config-linux
* Makefiles in vscode https://earthly.dev/blog/vscode-make/
* Makefile support in vscode https://devblogs.microsoft.com/cppblog/now-announcing-makefile-support-in-visual-studio-code/
