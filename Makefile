TARGET	= libmatmult.so
LIBSRCS	= matrix_math.c
LIBOBJS	= matrix_math.o

OPT	= -g -Ofast -std=c99 -fprofile-use
PIC	= -fPIC

CC	= gcc
CFLAGS= $(OPT) $(PIC) $(XOPTS)

SOFLAGS = -shared
XLIBS	= -Lopenblas

$(TARGET): $(LIBOBJS)
	$(CC) -o $@ $(SOFLAGS) $(LIBOBJS) $(XLIBS)

clean:
	@/bin/rm -f core core.* $(LIBOBJS)
