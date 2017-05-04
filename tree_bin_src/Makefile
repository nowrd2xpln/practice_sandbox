CC := gcc
CFLAGS := -I.
DEPS :=
OBJ := bst.o
TARGET = bst_demo

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	gcc -o $(TARGET) $^ $(CFLAGS)

clean:
	rm -f *.o *~
