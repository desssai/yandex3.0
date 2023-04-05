#include <iostream>
#include <fstream>
#include <vector>

class Country {
public:
	
	Country(void) : requireMoney(0), requireEducation(0), index(0), smallestIndexWithEducation(0), smallestIndexWithoutEducation(0) { };
	~Country() { };

	int		requireMoney;
	bool	requireEducation;
	int		index;
	int		smallestIndexWithEducation;
	int		smallestIndexWithoutEducation;
};

bool	operator == (const Country& lhs, const Country& rhs) {
	return lhs.requireMoney == rhs.requireMoney;
}

bool	operator != (const Country& lhs, const Country& rhs) {
	return !(lhs == rhs);
}

bool	operator < (const Country& lhs, const Country& rhs) {
	return lhs.requireMoney < rhs.requireMoney;
}

bool	operator <= (const Country& lhs, const Country& rhs) {
	return !(rhs < lhs);
}

bool	operator > (const Country& lhs, const Country& rhs) {
	return rhs < lhs;
}

bool	operator >= (const Country& lhs, const Country& rhs) {
	return !(lhs < rhs);
}

class Classmate {
public:
	Classmate(void) : Money(0), Education(0), ParentsOverseas(0) { };
	~Classmate() { };

	int		Money;
	bool	Education;
	int		ParentsOverseas;
};

int main(void) {
	std::ifstream			file("input.txt", std::ifstream::in);
	std::vector<Country>	map;
	std::vector<Classmate>	list;
	std::vector<int>		AcceptWithParentsNationality;
	int						n, q, prevWithoutEducation, prevWithEducation, min, mid, max;

	
	/* Input data for countries. */

	file >> n;
	map.resize(n, Country());
	AcceptWithParentsNationality.resize(n, 0);
	for (int i = 0 ; i < n; ++i)
		file >> map[i].requireMoney;
	for (int i = 0 ; i < n; ++i)
		file >> map[i].requireEducation;
	for (int i = 0 ; i < n; ++i)
		map[i].index = i + 1;
	for (int i = 0 ; i < n; ++i)
		file >> AcceptWithParentsNationality[i];
	
	/* Sort countries based on minimum salary requirement O(n x log(n)). */

	std::sort(map.begin(), map.end());
	
	/* Find the smallest index of the country with no Education requirement for each country that requires an Education. 
	** The search is limited to countries with less minimum salary requirements. This index lets optimise search for people 
	** with no education. */


	prevWithEducation = INT_MAX;
	prevWithoutEducation = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if (!map[i].requireEducation && map[i].index < prevWithoutEducation)
			prevWithoutEducation = map[i].index;
		if (map[i].requireEducation && map[i].index < prevWithEducation)
			prevWithEducation = map[i].index;
		map[i].smallestIndexWithEducation = (prevWithEducation != INT_MAX ? prevWithEducation : 0);
		map[i].smallestIndexWithoutEducation = (prevWithoutEducation != INT_MAX ? prevWithoutEducation : 0);
	}
	
	/* Input data for classmates. */

	file >> q;
	list.resize(q, Classmate());
	for (int i = 0; i < q; ++i)
		file >> list[i].Money;
	for (int i = 0; i < q; ++i)
		file >> list[i].Education;
	for (int i = 0; i < q; ++i)
		file >> list[i].ParentsOverseas;
	
	/* Find a suitable country for each classmate by using binary search on minimum salary requirements O(n x log(n)) again. */
	
	for (int i = 0; i < q; ++i) {
		min = 0;
		max = n - 1;
		while (min <= max) {
			mid = (min + max) >> 1;
			if (map[mid].requireMoney == list[i].Money && mid)
				break ;
			if (map[mid].requireMoney < list[i].Money && mid == max || map[mid + 1].requireMoney > list[i].Money)
				break ;
			else if (map[mid].requireMoney < list[i].Money && mid == max || map[mid + 1].requireMoney < list[i].Money)
				min = mid + 1;
			else
				max = mid - 1;
		}
		if (map[mid].requireMoney <= list[i].Money) {
			min = INT_MAX;
			if (map[i].smallestIndexWithoutEducation)
				min = map[i].smallestIndexWithoutEducation;
			if (list[i].Education && map[i].smallestIndexWithEducation && map[i].smallestIndexWithEducation < min)
				min = map[i].smallestIndexWithEducation;
			if (list[i].ParentsOverseas && AcceptWithParentsNationality[list[i].ParentsOverseas - 1] && list[i].ParentsOverseas < min)
				min = list[i].ParentsOverseas;
			std::cout << (min == INT_MAX ? 0 : min) << " ";
		}
		else
			std::cout << "0 ";
	}
	std::cout << std::endl;
	file.close();
}