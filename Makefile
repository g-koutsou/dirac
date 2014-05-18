CC=gcc -std=c99
CFLAGS=-I./ -I./parser -I./lib
LDFLAGS=-L./parser -L./lib
LIBS=-lparser -llat -lm
.PHONY: lib parser

all: main

main: main.o lib parser
	$(CC) -o $@ $< $(LDFLAGS) $(LIBS)

lib: ./lib/liblat.a

./lib/liblat.a:
	make -C ./lib

parser: ./parser/libparser.a

./parser/libparser.a:
	make -C ./parser

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

cleanall: clean
	make cleanall -C ./lib && \
	make cleanall -C ./parser	

clean:
	$(RM) *.o
