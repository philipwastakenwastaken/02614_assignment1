TARGET	= libmatmult.so
LIBSRCS	= matrix_math.c
LIBOBJS	= matrix_math.o

OPT	= -g -O3 -std=c99 -funroll-loops
PIC	= -fPIC

CC	= gcc
CFLAGS= $(OPT) $(PIC) $(XOPTS)

SOFLAGS = -shared
XLIBS	= -Lopenblas

$(TARGET): $(LIBOBJS)
	$(CC) -o $@ $(SOFLAGS) $(LIBOBJS) $(XLIBS)

clean:
	@/bin/rm -f core core.* $(LIBOBJS)
