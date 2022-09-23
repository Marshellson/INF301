CC=clang
CFLAGS=-g -Wall -Wextra -Werror

EXEC=client-introduction client-tutoriel client-interactif crypteMove

all: $(EXEC)

client-interactif: client-interactif.o client.o

client-tutoriel: client-tutoriel.o client.o

client-introduction: client-introduction.o client.o

crypteMove: crypteMove.o client.o

client.o: client.c client.h

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
