#include "PrefixMatcher.h"
#include <iostream>
int PrefixMatcher::selectRouter(std::string networkAddress)
{
	// for each substring from index to i in network address
	std::vector<std::string> list = {};
	for(size_t i = 1; i < networkAddress.length(); i++)
	{
		// where getWords(substring) isn't empty
		std::vector<std::string> routers = addressList.getWords(networkAddress.substr(0, i));
		if(routers.empty())
		{
			break;
		}

		list = routers;
	}

	// find the pair with the longest address
	size_t max = 0;
	for(size_t i = 0; i < list.size(); i++)
	{
		if(list.at(i).size() > max)
		{
			max = i;
		}
	}

	auto i = routerMap.find(list.at(max));

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