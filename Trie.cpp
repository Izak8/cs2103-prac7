#include "Trie.h"
#include <iostream>
Trie::Trie()
{
	//Initialize an empty Trie
	root = new Node(0, false);
}

bool Trie::search(std::string key)
{
	// Based on pseudocode from : https://en.wikipedia.org/wiki/Trie

	// Tracks the current node starting from root.
	Node* currentNode = root;

	// Tracks the current character within the key
	char currentChar = '\0';

	// For each character in key
	for(size_t i = 0; i < key.length(); i++)
	{
		currentChar = key.at(i);
		// if current character is not a child of the current node
		// return false
		if(!currentNode->child.at(currentChar)) {return false;}
		// otherwise continue through to next node
		currentNode = currentNode->child.at(currentChar);
	}

	// 
	return true;
};

void Trie::insert(std::string key)
{
	// Based on pseudocode from : https://en.wikipedia.org/wiki/Trie

	// Tracks the current node starting from root.
	Node* currentNode = root;

	// Tracks the current character within the key
	char currentChar = '\0';

	// For each character in key
	for(size_t i = 0; i < key.length(); i++)
	{
		currentChar = key.at(i); // currentChar = ith character of key string

		// if the current character in key is not a child of the current node
		if(!currentNode->child.at(currentChar))
		{
			// create new node with value = currentChar
			// as a child of current node
			currentNode->child.at(currentChar) = new Node(currentChar, false);
		}
		// continue to next node
		currentNode = currentNode->child.at(currentChar);
	}
	
	// once all characters have been inserted, set last as terminal
	currentNode->isTerminal = true;
};

void Trie::remove(std::string key){};