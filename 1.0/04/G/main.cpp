#include <iostream>
#include <string>
#include <cmath>
#include <map>

void	deposit(std::map<std::string, long long>& data) {
	std::string	name;
	long long	count;

	std::cin >> name >> count;
	data[name] += count;
}

void	withdraw(std::map<std::string, long long>& data) {
	std::string	name;
	long long	count;

	std::cin >> name >> count;
	data[name] -= count;
}

void	balance(std::map<std::string, long long>& data) {
	std::string	name;

	std::cin >> name;
	try {
		std::cout << data.at(name) << std::endl;
	} catch (std::exception& e) {
		std::cout << "ERROR" << std::endl;
	}
}

void	transfer(std::map<std::string, long long>& data) {
	std::string	name_src, name_dst;
	long long	count;

	std::cin >> name_src >> name_dst >> count;
	data[name_src] -= count;
	data[name_dst] += count;
}

void	income(std::map<std::string, long long>& data) {
	long long	percentile;

	std::cin >> percentile;
	for (auto it = data.begin(), ite = data.end(); it != ite; ++it) {
		if ((*it).second > 0)
			(*it).second += std::floor((((*it).second) / static_cast<double>(100)) * percentile);
	}
}

int main(void) {
	std::string							command, name;
	std::map<std::string, long long>	data;
	long long							n;

	while (true) {
		std::cin >> command;
		if (std::cin.eof())
			return 0;
		if (command == "DEPOSIT")
			deposit(data);
		else if (command == "WITHDRAW")
			withdraw(data);
		else if (command == "BALANCE")
			balance(data);
		else if (command == "TRANSFER")
			transfer(data);
		else if (command == "INCOME")
			income(data);
	}
}
