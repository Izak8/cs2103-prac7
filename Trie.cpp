#include "Trie.h"

#include <iostream>

Trie::Trie()
{
	//Initialise an empty node
	root = new Node();
}

bool Trie::search(std::string const& key)
{
	// Track the current node starting at root
	Node* node = root;

	for(auto i = key.begin(); i != key.end(); ++i)
	{
		// Using unordered map. find returns child.end if value not found
		if(node->child.find(*i) == node->child.end())
		{
			// If any given character in key does not exist in trie
			// key does not exist, therefore return false
			return false;
		}

		// Otherwise search for next character
		node = node->child[*i];
	}

	// Return true only if key is not a subprefix
	if (node->isTerminal)
	{
		return true;
	}

	return false;
}

void Trie::insert(std::string const& key)
{
	// Track the current node starting at root
	Node* node = root;

	for(auto i = key.begin(); i != key.end(); ++i)
	{
		if(node->child.find(*i) == node->child.end())
		{
			// If any given character in key does not exist in trie
			// key does not exist, therefore create new node
			node->child[*i] = new Node;
		}

		// Otherwise continue to next character
		node = node->child[*i];
	}

	// End of key marked as terminal
	node->isTerminal = true;
}

void Trie::remove(std::string const& key)
{
	remove(root, key, 0);
}

Trie::Node* Trie::remove(Node* node, std::string const& key, size_t depth)
{
	// Based on pseudocode from lecture content
	// and from https://en.wikipedia.org/wiki/Trie

	if(node == nullptr)
	{
		return nullptr;
	}

	if(depth == key.length())
	{
		if(!node->isTerminal)
		{
			return node;
		}

		node->isTerminal = false;

		if(node->child.empty())
		{
			delete node;
			node = nullptr;
		}

		return node;
	}

	node->child[key.at(depth)] = remove(node->child[key.at(depth)], key, depth+1);

	if(node->child.empty())
	{
		delete node;
		node = nullptr;
	}

	return node;
}

void Trie::printTerminal(std::string const& key)
{
	Node* node = root;

	for(auto i = key.begin(); i != key.end(); ++i)
	{
		std::cout << node->isTerminal;
		node = node->child[*i];
	}
}