#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <array>

class Trie
{
	struct Node
	{
		std::string value;
		bool isTerminal;

		std::array<Node *, 255> child;
	};

	Node* root;

public:
	Trie();

	bool search(std::string key);
	void insert(std::string key);
	void remove(std::string key);
};
#endif