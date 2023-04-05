#include <iostream>
#include <fstream>
#include <vector>

int dpTradeValue(std::vector<int> &stocks, int index, int canBuy, int tradeLimit, std::vector<std::vector<std::vector<int> > >& dp) {
	int buy = 0, sell = 0, skip = 0;

	if (index == stocks.size() || !tradeLimit)
		return 0;
	if (dp[index][canBuy][tradeLimit] != -1)
		return dp[index][canBuy][tradeLimit];
	if (canBuy)
		buy = -stocks[index] + dpTradeValue(stocks, index + 1, 0, tradeLimit, dp);
	else
		sell = stocks[index] + dpTradeValue(stocks, index + 1, 1, tradeLimit - 1, dp);
	skip = dpTradeValue(stocks, index + 1, canBuy, tradeLimit, dp);

	return dp[index][canBuy][tradeLimit] = std::max(buy, std::max(sell, skip));
}

int main() {
	std::ifstream									file("input.txt", std::ifstream::in);
	int												n;
	std::vector<int>								stocks;
	std::vector<std::vector<std::vector<int> > >	dp;
	
	file >> n;
	stocks.resize(n, 0);
	for (int i = 0; i < n; ++i)
		file >> stocks[i];
	file.close();

	dp.resize(n + 1, std::vector<std::vector<int> >(2, std::vector<int>(3, -1)));
	dpTradeValue(stocks, 0, 1, 2, dp);
	
	/* All that's left is to find the amouint of operations and the indexes for those operations.. But im out of time... */
	
	return 0;
}