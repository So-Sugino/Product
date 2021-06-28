CC	= g++
YACC	= yacc
LEX	= flex -l

DIR	= ../..
INCL    = $(DIR)/include
LIB	= $(DIR)/lib/BDD64.a
LIB64	= $(DIR)/lib/BDD64.a
#XLIB64  = -lX11
#XLIB64  = /usr/X11R6/lib64/libX11.a

PRG     = seq
PRG64   = seq64
PRG_ST  = seq-static
PRG64_ST = seq64-static

OPT 	= -O2 -DYY_ALWAYS_INTERACTIVE -I$(INCL)
OPT64   = $(OPT) -DB_64
OPT_ST  = $(OPT) -DB_STATIC -static
OPT64_ST = $(OPT64) -DB_STATIC -static

OBJ	= constSeq.o
OBJ64   = constSeq.o
OBJ_ST  = constSeq.o
OBJ64_ST = constSeq.o

all:	$(PRG)    

64:	$(PRG64)    

static:	$(PRG_ST)    

64static: $(PRG64_ST)    

$(PRG): $(OBJ) $(LIB)
	$(CC) $(OPT) $(OBJ) $(LIB) -lX11 -o $(PRG)

$(PRG64): $(OBJ64) $(LIB64)
	$(CC) $(OPT64) $(OBJ64) $(LIB64) $(XLIB64) -o $(PRG64)

$(PRG_ST): $(OBJ_ST) $(LIB)
	$(CC) $(OPT_ST) $(OBJ_ST) $(LIB) -o $(PRG_ST)

$(PRG64_ST): $(OBJ64_ST) $(LIB64)
	$(CC) $(OPT64_ST) $(OBJ64_ST) $(LIB64) -o $(PRG64_ST)

constSeq.o: constSeq.cc $(INCL)/PiDD.h $(INCL)/ZBDD.h $(INCL)/BDD.h $(INCL)/SeqBDD.h
	$(CC) $(OPT64) -c constSeq.cc -o constSeq.o

clean:
	rm -f *.o

