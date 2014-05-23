CC=g++
CPPFLAGS=-g -Wall

all : game

game: hello.o RPGCharacter.o 
	$(CC) $(CPPFLAGS) hello.o RPGCharacter.o -o game

hello.o : hello.cc RPGCharacter.h
	$(CC) $(CPPFLAGS) -c hello.cc

RPGCharacter.o : RPGCharacter.h RPGCharacter.cc
	$(CC) $(CPPFLAGS) -c RPGCharacter.cc 

clean :
	rm -rf *.o game *.dSYM




