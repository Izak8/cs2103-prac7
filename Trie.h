#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

class Trie
{
	struct Node
	{
		std::string value;
		bool isTerminal;

		std::vector<Node *> child;
	};

	Node* root;

public:

	Trie();
	~Trie();

};
#endif