#include <iostream>
#include <vector>
#include <queue>

int main(void) {
	int								n, m, result = 0;
	long long						maxPlatfromWidth = 0, currentWidth;
	std::vector<long long>			PlatfromWidthVector;
	std::priority_queue<long long>	platfromsWidths;
	std::priority_queue<long long>	guardsWidths;

	std::cin >> n >> m;
	PlatfromWidthVector.resize(n);
	for (int i = 0; i < n; ++i)
		std::cin >> PlatfromWidthVector[i];
	for (int i = n - 1; i >= 0; --i) {
		currentWidth = PlatfromWidthVector[i] - maxPlatfromWidth;
		if (currentWidth > 0) {
			platfromsWidths.push(currentWidth);
			maxPlatfromWidth = PlatfromWidthVector[i];
		}
	}
	PlatfromWidthVector.clear();

	for (int i = 0; i < m; ++i) {
		std::cin >> currentWidth;
		guardsWidths.push(currentWidth);
	}

	while (guardsWidths.size() && platfromsWidths.size()) {	
		if (guardsWidths.top() <= platfromsWidths.top()) {
			platfromsWidths.pop();
			result++;
		}
		guardsWidths.pop();
	}
	std::cout << result << std::endl;
}