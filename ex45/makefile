CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=a

all: $(EXEC)

a: list.o a.o
	$(CC) -o $@ $^ $(LDFLAGS)

a.o: list.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
