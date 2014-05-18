CC=gcc
CFLAGS=-std=c99 -I./

all: libparser.a

libparser.a: parser.o
	$(AR) cr $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	$(RM) *.o 

cleanall: clean
	$(RM) libparser.a
