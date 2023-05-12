#ifndef TRIE_H
#define TRIE_H

#include <vector>

template <class T>
class Trie
{
	struct Node
	{
		T data;
		std::vector<Node *> child;
	}

	Node* root;
public:


}
#endif