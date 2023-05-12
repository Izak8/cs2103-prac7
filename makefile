CC=g++
CFLAGS=-O2 -Wall -std=c++11

BIN=main.out
OBJ=main.o

build: $(BIN)
	rm -f -r $(OBJ)
gradescope:
	g++ -o main.out -std=c++11 -O2 -Wall *.cpp

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	clean

clean:
	rm -f -r $(OBJ) $(BIN)
