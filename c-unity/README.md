# C and Unity

This repo is intended to be used with CMake, which also means that it is
compatible with JetBrains' CLion IDE, as well as most common IDEs, including
Visual C++ and QtCreator.

## Building

From this folder:

    mkdir build
    cd build
    cmake ..
    make

## Running Tests

From within your IDE you can execute the full unit test suite by running the
life_test target.

From the build folder, you can execute `test/life_test` to run tests.

## CMake

CMake is something of a meta wrapper for make.  It has a fairly high level description of your project in CMakeLists.txt.  The cmake program will convert that to a build system of your choosing.  On UNIX and OS X systems that choice is usually a Makefile, but it can produce a number of other targets, including Visual Studio solution files.

There are a couple of mandatory boilerplate items in a CMakeLists.txt file.  The very first thing you must do is include the cmake_minimum_required macro.  This will tell any version of cmake running the file if it has the necessary features to generate your Makefile.

The second boilerplate item in the PROJECT macro, which defines the name of this package.  This will in turn define a variable PROJECT_NAME, which you can use in recipes.  If you generate a Microsoft solution file, it will also name the package in the solution file.

In the top level CMakeLists.txt file we have a few more simple commands.  add_subdirectory is used twice to tell cmake that there are additional folders which should be scanned as part of the project.

`add_subdirectory(test)` adds our test folder (which will use google test)

`set(APP_SOURCE ...)` defines a variable called APP_SOURCE, which contains the values unit.cpp and unit.h.

`add_executable(${PROJECT_NAME} ...)` tells cmake that you want to create an executable named ${PROJECT_NAME}, which in this case expands to "life" and is made up of the files main.cpp and the list of files defined by APP_SOURCE earlier.


# Unity

Full details of the Unity test framework from Throw The Switch is at https://github.com/ThrowTheSwitch/Unity.  It's a very capable testing framework for C, and one of my go to testing frameworks.  GoogleTest is the other, and the choice probably depends on needs unrelated to your code, and more to do with the ecosystem around your code like test reporting and mocking.