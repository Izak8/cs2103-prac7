CC=g++
CFLAGS=-O2 -Wall -std=c++11

BIN=main
OBJ=Trie.o Autocomplete.o PrefixMatcher.o

build: $(BIN).out
	rm -f -r $(OBJ) $(BIN).out
gradescope:
	g++ -o main.out -std=c++11 -O2 -Wall *.cpp

trie.test: TrieTest.o Trie.o
	$(CC) $(CFLAGS) $^ -o $@
autc.test: AutocompleteTest.o Autocomplete.o Trie.o
	$(CC) $(CFLAGS) $^ -o $@

$(BIN).out: $(OBJ) $(BIN).out
	$(CC) $(CFLAGS) $^ -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	clean

clean:
	rm -f -r *.out *.o *.test
