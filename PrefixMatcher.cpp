#include "PrefixMatcher.h"

int PrefixMatcher::selectRouter(std::string networkAddress)
{
	// Get words with a matching prefix.
	std::vector<std::string> list = addressList.getWords(networkAddress);

	// find the pair with the first address to be matched
	auto i = routerMap.find(list.at(0));

	// if the key doesn't exist return -1
	if(i == routerMap.end())
	{
		return -1;
	}

	// otherwise return the router number with the corresponding address
	return i->second;
}

void PrefixMatcher::insert(std::string address, int routerNumber)
{
	// insert the key-value pair (address, routerNumber) into the router-address map
	routerMap.insert({address, routerNumber});

	// insert the address into the addressList tree
	addressList.insert(address);
}