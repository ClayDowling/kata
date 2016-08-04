.PHONY: all test clean

all: test life

clean:
	$(MAKE) -C test clean
	rm -f *.o
	rm -f life

test:
	$(MAKE) -C test full

life: unit.o main.o
	$(CC) -o $@ $^
