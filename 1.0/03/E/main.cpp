#include <iostream>
#include <vector>

int main(void) {
	std::vector<bool>	numbers(10, false);
	int					num, res = 0;

	std::cin >> num;
	numbers[num] = true;
	std::cin >> num;
	numbers[num] = true;
	std::cin >> num;
	numbers[num] = true;

	std::cin >> num;
	while (true) {
		if (!num)
			break ;
		if (!numbers[num % 10]) {
			numbers[num % 10] = true;
			res++;
		}
		num /= 10;
	}
	std::cout << res << std::endl;
}