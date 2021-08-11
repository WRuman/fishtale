PROJ=fishtale
CC=g++
SRC=show.h show.cpp main.cpp
LIBS=-lgpiodcxx
CFLAGS=-std=c++17 -Wconversion -Wall -Werror -Wextra -Wpedantic

all:
	$(CC) $(SRC) $(LIBS) $(CFLAGS) -o $(PROJ)

clean:
	rm $(PROJ)
