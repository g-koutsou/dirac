CC=gcc -std=gnu99
CFLAGS=-I./
LDFLAGS=
LIBS=-lm
RANLIB=ranlib

SOURCES=lattice
SP_SOURCES=spinors gauge_fields random_gauge_field plaquette dslash
DP_SOURCES=spinors gauge_fields random_gauge_field plaquette dslash
all: liblat.a

# pull in dependency info for *existing* .o files
include $(wildcard *.d) $(wildcard *.dd) $(wildcard *.fd)

liblat.a: ${addsuffix .o, $(SOURCES)} ${addsuffix .fo, $(SP_SOURCES)} ${addsuffix .do, $(DP_SOURCES)}
	$(AR) cr $@  $?
	$(RANLIB) $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d

%.do: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.dd

%.fo: %.c
	$(CC) -DSINGLE_PRECISION $(CFLAGS) -c $< -o $@
	$(CC) -DSINGLE_PRECISION -MM $(CFLAGS) $< > $*.fd

clean:
	$(RM) *.o *.d *.fo *.do *.fd *.dd

cleanall: clean
	$(RM) liblat.a
