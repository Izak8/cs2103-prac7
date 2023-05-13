#include "Trie.h"

Trie::Trie()
{
	//Initialize an empty Trie
	root = nullptr;
}

bool Trie::search(std::string key)
{
	
};

void Trie::insert(std::string key)
{
	// Based on pseudocode from : https://en.wikipedia.org/wiki/Trie

	// insert string key into trie

	// use pointer node to track the nodes of the trie
	// starting at root
	Node* currentNode = root;

	// initialize current character as ASCII NUL
	char currentChar = '\0';

	// for each character in key
	for(size_t i = 0; i < key.length(); i++)
	{
		currentChar = key.at(i); // c represents the ith character in key

		// if the current character in key is not a child of the current node
		if(currentNode->child.at(currentChar) == nullptr)
		{
			// create new node with value = currentChar
			// as a child of current node
			currentNode->child.at(currentChar) = new Node(currentChar);
		}
		// node becomes child node with value c
		currentNode = currentNode->child.at(currentChar);
	}

	// once all characters have been inserted, set last as terminal
	currentNode->isTerminal = true;
};

void Trie::remove(std::string key){};