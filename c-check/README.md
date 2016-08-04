# What Am I Doing Here

Setting up Makefiles for a new C project can be a daunting task.  I'm trying to
provide a basis for a new developer to set up their own Makefiles.  The goal is
not a Makefile that you can use as a starting point, but an understanding of
how this Makefile works, so that you can write your own.

## Top Level Folder

This top level folder contains the source to the API we are creating, a master
Makefile, this README, and a folder where we have defined our tests.

### Makefile

The contents of the Makefile are what are of interest to us here.  First, you
should definitely read the [GNU Makefile manual](http://www.gnu.org/gmake), which
is the source of truth on all things related to GNU Make.  It is also remarkably
readable and full of good examples.

#### Targets

The top level file has several targets: *all*, *clean*, *test* and *life*.  

The first target in the file is the default target, and by convention is the *all*
target.  If you just type "make" on the command line, this is the target which
will be executed.

Following the colon on the same line is the dependencies for this target.  If
any of these dependencies was modified after a file with the same name as the
target, the dependency will be rebuilt and the target rebuilt.

All of the subsequent indented lines after the target represent the recipe to
build the target.  Let's look at the recipes for the other targets.

##### life

This is a straight up recipe to build a final product called "life."  The recipe
itself is rather cryptic, so I'll break it down for you.

  * `$(CC)` will expand to the compiler's executable.  On many systems there is
  a program "cc" which is the C compiler.  But equally common is "gcc" for the
  GNU C compiler, "clang" for the LLVM compiler used on OS X by default and as
  an alternative by many other users.  This is actually an environment variable,
  so you can change the compiler you want to use by setting the CC environment
  variable in your shell.

  * `$@` is the name of the target.  The `-o` option sets the name of the output
  file, so the output of the compile operation will be called "life"

  * `$^` expands to the full list of dependencies listed for the target.  

##### test

This target executes `make` on the test directory, building the full target.
`$(MAKE)` again refers to an environment variable.  By default this is the same
command which you used to execute this Makefile.  While GNU make is the most
common version of make, BSD make is also popular, and is often available on
non-BSD systems as `bmake`.

##### clean

Clean is a traditional target, and exists to clean up the folder into a pristine
state.  This target does three things:

  * Executes the `clean` target in the test folder
  * Removes all files ending with `.o` in this folder.  The -f option keeps
  rm from complaining if there are no files matching `*.o`
  * Removes the executable `life` if it exists.

##### all

This target, which is the default, has no recipe, but does depend on the test
and life targets.  It will first execute the "test" target.  If that succeeds, it
will execute the "life" target.  It is important to put these in this order, so
that no life target is built if the tests fail.  Because of that ordering, we
are protected from creating a life target which fails its tests.


## Further Reading

The `test` folder contains a very different [Makefile](test/README.md).
