CPP=clang++
CPPFLAGS=-I ./cs106lib-0.3.1/CS106

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

all: a.out

clean:
	rm -f a.out cs106lib-0.3.1/CS106/*.a cs106lib-0.3.1/CS106/*.o

a.out: cs106lib-0.3.1/CS106/cs106lib.a
	$(CPP) $(CPPFLAGS) $^ $(P)

cs106lib-0.3.1/CS106/cs106lib.a:
	make -C cs106lib-0.3.1/CS106 -f Makefile

PHONY: all
