#include <iostream>
#include <string>
#include <vector>

int main(void) {
	int					aSize, bSize;
	std::vector<int>	aCount, bCount;
	std::string			aString, bString;

	std::cin >> aString >> bString;

	aCount.resize(26, 0);
	bCount.resize(26, 0);
	aSize = aString.size();
	bSize = bString.size();
	for (int i = 0; i < aSize; ++i)
		aCount[aString[i] - 'a']++;
	for (int i = 0; i < bSize; ++i)
		bCount[bString[i] - 'a']++;
	std::cout << (aCount == bCount ? 1 : 0) << std::endl;
}