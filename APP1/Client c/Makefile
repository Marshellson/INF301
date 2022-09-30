CC=clang
CFLAGS=-g -Wall -Wextra -Werror

EXEC=client-introduction client-tutoriel client-interactif projetX crypteMove BayOfPigs crypteSeq northwoods

all: $(EXEC)

client-interactif: client-interactif.o client.o

client-tutoriel: client-tutoriel.o client.o

client-introduction: client-introduction.o client.o

projetX: projetX.o client.o

crypteMove: crypteMove.o client.o

BayOfPigs: BayOfPigs.o client.o

crypteSeq: crypteSeq.o client.o

northwoods: northwoods.o client.o

client.o: client.c client.h

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
