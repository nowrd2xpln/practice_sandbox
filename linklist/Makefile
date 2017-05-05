CC := gcc
CFLAGS := -I.
DEPS :=
OBJ := linklist.o
TARGET = ll_demo

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	gcc -o $(TARGET) $^ $(CFLAGS)

clean:
	rm -f *.o *~
