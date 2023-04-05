#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
	std::ifstream						file("input.txt", std::ifstream::in);
	std::vector<std::pair<long, int> >	array;
	std::vector<long>					result;
	long								n, k, start, end, total;

	if (!file.is_open())
		return 1;

	file >> n >> k;
	result.resize(n, 0);
	array.resize(n, std::pair<long, int>());
	for (int i = 0; i < n; ++i) {
		file >> array[i].first;
		array[i].second = i;
	}
	std::sort(array.begin(), array.end());
	file.close();

	end = k;
	total = 0;
	start = 0;
	for (int i = start; i <= end; ++i)
		total += array[i].first - array[0].first;
	result[array[0].second] = total;
	for (int i = 1; i < n; ++i) {
		total += (array[i].first - array[i - 1].first) * ((i - start - 1) - (end - i));
		while (end < n - 1 && array[end + 1].first - array[i].first < array[i].first - array[start].first) {
			total -= (array[i].first - array[start].first) - (array[end + 1].first - array[i].first);
			end++;
			start++;
		}
		result[array[i].second] = total;
	}
	for (int i = 0; i < n; ++i)
		std::cout << result[i] << " ";
	std::cout << std::endl;
	return 0;
}