#include <iostream>
#include <vector>

void	setNextOccurenceOfLastElement(int& first, int& last, std::vector<int>& array) {
	while (first < last && array[first] != array[last])
		first++;
}

bool	CheckForSymmetry(int first, int last, std::vector<int>& array) {
	while (first <= last) {
		if (array[first] != array[last])
			return false;
		first++;
		last--;
	}
	return true;
}

int main(void) {
	int					n, start, end;
	std::vector<int>	array;

	std::cin >> n;
	array.resize(n);
	for (int i = 0; i < n; ++i)
		std::cin >> array[i];

	start = 0;
	end = n - 1;
	while (start < n) {
		setNextOccurenceOfLastElement(start, end, array);
		if (CheckForSymmetry(start, end, array))
			break ;
		start++;
	}
	std::cout << start << std::endl;
	for (int i = start - 1; i >= 0; --i)
		std::cout << array[i] << " ";
	if (start)
		std::cout << std::endl;
}