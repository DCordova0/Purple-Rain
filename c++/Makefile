CC = g++
CFLAGS = -Wall -lSDL2
EXE = exe

all: $(EXE) purge
	
$(EXE): main.o  Drop.o
	$(CC) main.o Drop.o $(CFLAGS) -o $(EXE)

Drop.o:  Drop.h Drop.cpp
	$(CC) -c Drop.cpp $(CFLAGS)
main.o: main.cpp main.h
	$(CC) -c main.cpp $(CFLAGS)
purge:
	rm *.o
clean:
	rm exe
