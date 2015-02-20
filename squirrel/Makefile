
SQUIRREL=.
MAKE=make

sq32:
	mkdir lib; mkdir bin
	cd squirrel; $(MAKE) 
	cd sqstdlib; $(MAKE) 
	cd sq; $(MAKE) 

sqprof:
	mkdir lib; mkdir bin
	cd squirrel; $(MAKE) sqprof
	cd sqstdlib; $(MAKE) sqprof
	cd sq; $(MAKE) sqprof

sq64:
	mkdir lib; mkdir bin
	cd squirrel; $(MAKE) sq64
	cd sqstdlib; $(MAKE) sq64
	cd sq; $(MAKE) sq64
