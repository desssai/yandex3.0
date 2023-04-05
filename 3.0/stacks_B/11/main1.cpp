#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

int	main()
{
	std::fstream		in("input.txt");
	std::string			str;
	std::stack<double, std::vector<double> >	stockpile;

	std::getline(in, str);

	int		k = std::strtoul(str.c_str(), NULL, 10);
	char 	*crsr;

	double	num;
	double	req;
	int		conts;

	while (k--)
	{
		std::getline(in, str);

		crsr = &str[0];
		conts = std::strtoul(crsr, &crsr, 10);
		req = 0;
		
		while (!stockpile.empty())
			stockpile.pop();
		
		while (conts--)
		{
			num = std::strtod(crsr, &crsr);

			if (stockpile.empty() || num <= stockpile.top())
			{
				stockpile.push(num);
				continue ;
			}

			while (!stockpile.empty() && stockpile.top() <= num && req <= stockpile.top())
			{
				req = stockpile.top();
				stockpile.pop();
			}

			if (!stockpile.empty() && stockpile.top() < req)
				break ;

			stockpile.push(num);
		}

		while (!stockpile.empty() && stockpile.top() >= req)
		{
			req = stockpile.top();
			stockpile.pop();
		}

		if (stockpile.empty())
			std::cout << 1 << std::endl;
		else
			std::cout << 0 << std::endl;
	}
}