CFLAGS = `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH=..

TEST_OBJECTS = test_unit.o

all: test_life
	./test_life

full: all memtest

test_life: unit.o $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

memtest: test_life
	CK_FORK=no valgrind --leak-check=full ./test_life

clean:
	rm -f *.o
	rm -rf *.dSYM
	rm -f test_life
