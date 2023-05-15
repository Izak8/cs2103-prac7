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

Trie::Node* Trie::traverse(std::string const& key)
{
	// Starting from root node
	Node* node = root;

	// Traverse to the node at the end of key
	for(auto i = key.begin(); i != key.end(); ++i)
	{
		// For each character
		// if node does not exist return null
		if(node->child[*i] == nullptr)
		{
			return nullptr;
		}

		// otherwise traverse to next
		node = node->child[*i];
	}

	// once traversal complete return node pointer
	return node;
}

std::vector<std::string> Trie::getWords(std::string const& key)
{
	// traverse to the node at key
	Node* node = traverse(key);
 	std::vector<std::string> list = {};

	// base cases
	// if the given key is a word
	if(search(key) == true)
	{
		// push the key to the vector
		list.push_back(key);

		// if there are no more children
		if(node->child.empty())
		{
			// return whole list
			return list;
		}
	}

	// recurisve call
	// for each child of the current node
	for(auto i : node->child)
	{
		char c = i.first;

		// recursively getWords of the key + child character
		std::vector<std::string> words = getWords(key+c);

		// insert new words into the main vector
		list.insert(list.end(),words.begin(), words.end());
	}

	// return the whole list
	return list;
}