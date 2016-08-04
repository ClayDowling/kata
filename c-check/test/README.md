# Test Folder Makefile

This Makefile is doing a number of more intersting things than the top level
Makefile.  The purpose of this folder is for unit tests, to be written before
implementation of actual program logic.  This means I will need to link against
not only the files from this folder, but the files from my source folder.  By
default I also need to execute my test suite(s).

## pkg-config

The pkg-config program is a standard Unixism.  It exists to get information about
libraries that you will need to build and link programs against them.  It is also
available for OS-X as part of homebrew or macports.


## Variables

This Makefile makes extensive use of variables to define behavior.  These variables
are named using common UNIX programming conventions.

  * `CFLAGS` contains a collection of flags which should be passed to the compiler.
  This is an environment variable, and by default most compilers will use the value
  of `CFLAGS` as command line arguments.  This definition will actually execute the
  command contained in backticks to get the value of the variable.  In this case
  the command is to execute pkg-config and retrieve CFLAGS information for the
  check unit testing library.

  * `LIBS` contains the arguments which should be passed to the compiler command
  line in order to link the final executable, including libraries that it may
  use.  In this case we are linking to libcheck, as well as any additional
  libraries which it may require such as pthreads.

  * `VPATH` points to a colon delimited list of folders where the compiler should
  look for source files, in addition to the current folder.  In our test folder,
  it is important to include a *relative* path to the folder which holds the
  program source that we will be testing.

## Targets

### test

This is the default target for this Makefile.  It's dependency is test_life,
another target in this folder (which will generate an executable of the same name).
The recipe for test is to run the `test_life` program built by the dependent
target.

### full

This will execute the `test` target followed by the `memtest` target.  For a
CI build this is the target I would execute, so that I would have a regular check
on my memory management as well as my regular unit tests.

When running a full build on the repo, this is the test target which is run, so
I have a check on memory management before a deployable artifact is built.

### test_life

This builds the actual test program which will run all the tests.  It is written
with the "check" library.  The tests (so far) are all contained in
[test_unit.c](test_unit.c)

If you look at the recipe for [life](../Makefile), you will notice that this
recipe is slightly different.  It includes expansions of `CFLAGS` and `LIBS` in
the command line.  Using `CFLAGS` ensures that the final executable is built
with the same options as all of the .o files that it's assembled from.

The `LIBS` variable carries all of the linking options, which for this program
include libcheck and pthreads.  The exact details will depend on your system, but
the `pkg-config` command that you used to populate `LIBS` will handle that for you.

### memtest

This is a special target for running memory tests with valgrind.  It is noisy, and
I don't care for it as part of the regular red-green-refactor cycle, but it is
still useful.  You can run this separately or as part of the `full` target.
