CFLAGS = -Wall -Wextra -std=c99

all: annuaire

annuaire: main.o annuaire.o menu.o contact.o
	gcc $(CFLAGS) -o $@ $^

main.o: main.c annuaire.h menu.h
annuaire.o: annuaire.c annuaire.h contact.h
menu.o: menu.c menu.h annuaire.h
contact.o: contact.c contact.h

clean:
	rm -f *.o annuaire