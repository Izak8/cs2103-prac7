#include "Autocomplete.h"

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord)
{
	// use getWords function of Trie
	return dictionary.getWords(partialWord);
}

void Autocomplete::insert(std::string word)
{
	// inserts word into the Trie
	dictionary.insert(word);
}