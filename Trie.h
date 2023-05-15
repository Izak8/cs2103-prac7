#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>
#include <vector>

class Trie
{
	struct Node
	{
		std::unordered_map<char, Node*> child;
		bool isTerminal = false;
	};

	Node* root;

	Node* remove(Node* node, std::string const& key, size_t depth);
	Node* traverse(std::string const& key);
public:
	Trie();

	bool search(std::string const& key);
	void insert(std::string const& key);
	void remove(std::string const& key);

	std::vector<std::string> getWords(std::string const& key);
};
#endif