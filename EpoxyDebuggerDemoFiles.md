## EpoxyDebuggerDemo files and purpose

The following files may need some "customization" to be appropriate for your library.  Here are some hints as to what the files do, and which ones you might need to modify or replace.

Hints:
* "COPY".  Copy the file. It _probably_ does not need customization.
* "MODIFY".  Copy the file, but you may need to change something in the file to support your particular needs.
* "OPTIONAL".  Technically this file is not required, but it may be useful. It may need modification to better fit your needs.
* "NOT NEEDED". Typically this is documentation which is only relevant to EpoxyDebuggerDemo example (for example this description).
* "RENAME".  Rename a file to something more appropriate to your needds.

### GitHub Action support
* `.github/workflows/aunit_tests.yml` -- MODIFY. Confirms unit tests PASS on GitHub.  change the "name: " line to something more appropriate for your library
* `.github/workflows/githubci.yml` -- MODIFY. Confirms library builds successfully on various popular Arduino platforms on GitHub.  change the "name: " line to something more appropriate for your library

### Visual Studio build support
Part of the reason for this description file is that the following `.json` files do not support comments.  Here are some comments to go with the files.

* `.vscode/c_cpp_properties.json` -- COPY. Describes how VSCode should BUILD from C++ source files. (You may need to modify it if your "includePath" needs to find a special libary.)
* `.vscode/launch.json` -- COPY. Describes how VSCode should RUN an executable from C++ source files (for example for debugging, or just to see output)
* `.vscode/settings.json` -- COPY. Describes VSCode configuration settings for a build from C++ source files.  For debugging you will want a "Debug" build.

* `examples/Makefile` -- COPY. Builds any examples/ sketches it finds.
* `examples/Average3Demo/Average3Demo.ino` -- MODIFY/RENAME. Trivial example sketch.
* `examples/Average3Demo/Makefile` -- COPY.  Builds a particular sketch.

* `extras/tests/Makefile` -- COPY. Builds any extras/tests/ sketches it finds.
* `extras/tests/EpoxyDebuggerDemoTest/EpoxyDebuggerDemoTest.ino` -- MODIFY/RENAME. Trivial example unit test sketch.
* `extras/tests/EpoxyDebuggerDemoTest/Makefile` -- COPY.  Builds a particular unit test sketch, AND supports running the tests and checking results. (Note this Makefile has EpoxyDuino.mk do most of its work)

* `src/EpoxyDebuggerDemo.cpp` -- MODIFY/RENAME. Trivial example library
* `src/EpoxyDebuggerDemo.h` -- MODIFY/RENAME. Trivial example library header

* `.clang-format` -- OPTIONAL. VSCode formatting rules. Be careful when auto-formatting from different build environments, as they may use different rules/defaults!
* `.gitignore` -- OPTIONAL. Tell git it should not distract me about files with these patterns.
* `Development.md` -- OPTIONAL. Describes how to set up for development.
* `EpoxyDebuggerDemo.code-workspace` -- RENAME. VSCode uses this file to anchor the 'root path' of this library
* `LICENSE` -- OPTIONAL/MODIFY. Real Arduino libraries should have a description of whether commercial use is OK, etc. Your library can have a different license than mine depending on your needs.
* `Makefile` -- MODIFY.  Top-level Makefile to build, run tests, clean etc. You probably want to change the "NAME"
* `README.md` -- MODIFY.  Describes the library for humans. Your own library's description/purpose will be different from this demonstration.
* `library.properties` -- MODIFY. Provides a library description for Arduino.cc tools.  For example library.properties hints which release is current.
