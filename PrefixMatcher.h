#ifndef PREFIX_MATCHER_H
#define PREFIX_MATCHER_H

#include <map>
#include <string>
#include "Trie.h"

class PrefixMatcher
{

	std::map<std::string, int> routerMap;
	Trie addressList;

 public:
	int selectRouter(std::string networkAddress);
	void insert(std::string address, int routerNumber);
};
#endif