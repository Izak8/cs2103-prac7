#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>

class Trie
{
	struct Node
	{
		std::unordered_map<char, Node*> child;
		bool isTerminal = false;
	};

	Node* root;

	Node* remove(Node* node, std::string const& key, size_t depth);

public:
	Trie();

	bool search(std::string const& key);
	void insert(std::string const& key);
	void remove(std::string const& key);

	void printTerminal(std::string const& key);
};
#endif