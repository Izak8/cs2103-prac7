#include "PrefixMatcher.h"
#include <iostream>
int PrefixMatcher::selectRouter(std::string networkAddress)
{

	// Stores the list of router addresses which include a subprefix of networkAddress
	std::vector<std::string> list = {};
	// Indicates a byte offset into networkAddress which produces a list of
	// addresses which include the largest subprefix of networkAddress
	size_t offset = 0;


	// For each bit in networkAddress
	for(size_t i = 0; i < networkAddress.size(); i++)
	{
		// Track the offset
		offset = i+1;

		if(addressList.search(networkAddress.substr(0, i+1)) == true)
		{
			// Until the end of key in the Trie is reached
			break;
		}
	}

	// Get the list of addresses
	list = addressList.getWords(networkAddress.substr(0, offset));

	// Find the index to the largest element in the list
	size_t maxElementSize = 0;
	for(size_t i = 0; i < list.size(); i++)
	{
		if(list.at(i).size() > maxElementSize)
		{
			maxElementSize = i;
		}
	}

	// return the router number which has the largest address within networkAddress
	return routerMap.at(list.at(maxElementSize));
}

void PrefixMatcher::insert(std::string address, int routerNumber)
{
	// insert the key-value pair (address, routerNumber) into the router-address map
	routerMap.insert({address, routerNumber});

	// insert the address into the addressList tree
	addressList.insert(address);
}