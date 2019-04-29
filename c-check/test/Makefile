CFLAGS = `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH=..

TEST_OBJECTS = test_bowling.o test_unit.o

all: test_bowling
	./test_bowling

full: all memtest

test_bowling: bowling.o $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

memtest: test_bowling
	CK_FORK=no valgrind --leak-check=full ./test_bowling

clean:
	rm -f *.o
	rm -rf *.dSYM
	rm -f test_bowling
