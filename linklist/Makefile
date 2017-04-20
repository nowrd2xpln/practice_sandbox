CC := gcc
CFLAGS := -I.
DEPS :=
OBJ := linklist.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~
