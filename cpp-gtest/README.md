C++ and Google Test
===================

This repo is intended to be used with CMake, which also means that it is
compatible with JetBrains' CLion IDE, as well as most common IDEs, including
Visual C++ and QtCreator.

Building
--------

From this folder:

    mkdir build
    cd build
    cmake ..
    make

Running Tests
-------------

From within your IDE you can execute the full unit test suite by running the
life_test target.

From the build folder, you can execute `test/life_test` to run tests.

