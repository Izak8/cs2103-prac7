#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

#include "Trie.h"

class Autocomplete
{
	Trie dictionary;
public:
	std::vector<std::string> getSuggestions(std::string partialWord);

	void insert(std::string word);
};
#endif