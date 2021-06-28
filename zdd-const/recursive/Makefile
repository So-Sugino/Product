CC	= g++
YACC	= yacc
LEX	= flex -l

DIR	= ../..
INCL    = $(DIR)/include
LIB	= $(DIR)/lib/BDD.a
LIB64	= $(DIR)/lib/BDD64.a
XLIB64  = -lX11
#XLIB64  = /usr/X11R6/lib64/libX11.a

PRG     = zdd.out
PRG64   = zdd64.out
PRG_ST  = zdd-static.out
PRG64_ST = zdd64-static.out

OPT 	= -O2 -DYY_ALWAYS_INTERACTIVE -I$(INCL)
OPT64   = $(OPT) -DB_64
OPT_ST  = $(OPT) -DB_STATIC -static
OPT64_ST = $(OPT64) -DB_STATIC -static

OBJ	= rec-cons.o rec-func.o readfile.o
OBJ64   = rec-cons_64.o rec-func_64.o readfile_64.o
OBJ_ST  = rec-cons_st.o rec-func.o readfile.o
OBJ64_ST = rec-cons_64_st.o rec-func_64.o readfile_64.o

all: $(PRG)

64:	$(PRG64)

static:	$(PRG_ST)

64static: $(PRG64_ST)

$(PRG): $(OBJ) $(LIB)
	$(CC) $(OPT) $(OBJ) $(LIB) -o $(PRG)

$(PRG64): $(OBJ64) $(LIB64)
	$(CC) $(OPT64) $(OBJ64) $(LIB64) -o $(PRG64)

$(PRG_ST): $(OBJ_ST) $(LIB)
	$(CC) $(OPT_ST) $(OBJ_ST) $(LIB) -o $(PRG_ST)

$(PRG64_ST): $(OBJ64_ST) $(LIB64)
	$(CC) $(OPT64_ST) $(OBJ64_ST) $(LIB64) -o $(PRG64_ST)

rec-cons.o: rec-cons.cpp readfile.hpp rec-func.hpp $(INCL)/PiDD.h $(INCL)/ZBDD.h $(INCL)/BDD.h
	$(CC) $(OPT) -c rec-cons.cpp

rec-cons_64.o: rec-cons.cpp readfile.hpp rec-func.hpp $(INCL)/PiDD.h $(INCL)/ZBDD.h $(INCL)/BDD.h
	$(CC) $(OPT64) -c rec-cons.cpp -o rec-cons_64.o

rec-cons_st.o: rec-cons.cpp readfile.hpp rec-func.hpp $(INCL)/PiDD.h $(INCL)/ZBDD.h $(INCL)/BDD.h
	$(CC) $(OPT_ST) -c rec-cons.cpp -o rec-cons_st.o

rec-cons_64_st.o: rec-cons.cpp readfile.hpp rec-func.hpp $(INCL)/PiDD.h $(INCL)/ZBDD.h $(INCL)/BDD.h
	$(CC) $(OPT64_ST) -c rec-cons.cpp -o rec-cons_64_st.o

rec-func.o: rec-func.cpp $(INCL)/PiDD.h $(INCL)/ZBDD.h $(INCL)/BDD.h
	$(CC) $(OPT) -c rec-func.cpp

rec-func_64.o: rec-func.cpp $(INCL)/PiDD.h $(INCL)/ZBDD.h $(INCL)/BDD.h
	$(CC) $(OPT64) -c rec-func.cpp -o rec-func_64.o

readfile.o: readfile.cpp
	$(CC) $(OPT) -c readfile.cpp -o readfile.o

readfile_64.o: readfile.cpp 
	$(CC) $(OPT64) -c readfile.cpp -o readfile_64.o

clean:
	rm -f *.o
	rm -f *.out