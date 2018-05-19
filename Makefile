OBJS = Card.o Hand.o GenericPlayer.o Player.o House.o Deck.o Game.o main.o  
CC = g++-5
DEBUG = -g 
INCLUDE = -I./include
SRC_FOLDER = ./src
CFLAGS = $(INCLUDE) -c $(DEBUG)
LFLAGS = $(DEBUG)
VPATH = ./src

all: BLACKJACK

BLACKJACK: $(OBJS) 	
	$(CC) $(LFLAGS) $(OBJS) -o $@ 
Hand.o: Hand.cpp
	$(CC) $(CFLAGS) $<
Card.o: Card.cpp
	$(CC) $(CFLAGS) $<
GenericPlayer.o: GenericPlayer.cpp
	$(CC) $(CFLAGS) $<
Player.o: Player.cpp
	$(CC) $(CFLAGS) $<
House.o: House.cpp
	$(CC) $(CFLAGS) $<
main.o: main.cpp
	$(CC) $(CFLAGS) $<
Deck.o: Deck.cpp
	$(CC) $(CFLAGS) $<

Game.o: Game.cpp
	$(CC) $(CFLAGS) $<
clean:
	rm *.o BLACKJACK
