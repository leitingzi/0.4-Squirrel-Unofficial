SQUIRREL= ..


OUT= $(SQUIRREL)/lib/libsquirrel$(BITCOUNT).a
INCZ= -I$(SQUIRREL)/include -I. -Iinclude
DEFS= 
LIB=	

OBJS= \
	sqapi.o \
	sqbaselib.o \
	sqfuncstate.o \
	sqdebug.o \
	sqlexer.o \
	sqobject.o \
	sqcompiler.o \
	sqstate.o \
	sqtable.o \
	sqmem.o \
	sqvm.o \
	sqclass.o
	
SRCS= \
	sqapi.cpp \
	sqbaselib.cpp \
	sqfuncstate.cpp \
	sqdebug.cpp \
	sqlexer.cpp \
	sqobject.cpp \
	sqcompiler.cpp \
	sqstate.cpp \
	sqtable.cpp \
	sqmem.cpp \
	sqvm.cpp \
	sqclass.cpp

	
	
sq32:
	$(eval BITCOUNT:=32)
	gcc -O2 -fno-exceptions -fno-rtti -Wall -fPIC -fno-strict-aliasing -c $(SRCS) $(INCZ) $(DEFS)
	ar rc $(OUT) *.o
	rm *.o

sqprof:
	$(eval BITCOUNT:=32)
	gcc -O2 -pg -fno-exceptions -fno-rtti -pie -gstabs -g3 -Wall -fPIC -fno-strict-aliasing -c $(SRCS) $(INCZ) $(DEFS)
	ar rc $(OUT) *.o
	rm *.o

sq64:
	$(eval BITCOUNT:=64)
	gcc -O2 -m64 -D_SQ64 -fno-exceptions -fno-rtti -Wall -fPIC -fno-strict-aliasing -c $(SRCS) $(INCZ) $(DEFS)
	ar rc $(OUT) *.o
	rm *.o
