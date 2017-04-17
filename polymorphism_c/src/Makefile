CC := gcc
IDIR := ../inc
CFLAGS =-I $(IDIR)
SRCDIR := src
INCDIR := ../inc
BUILDDIR := obj
TARGETDIR := bin


ODIR := obj
LDIR := lib

_DEPS = alu.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = alu.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
