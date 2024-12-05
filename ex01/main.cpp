#include "iter.hpp"
#include <iostream>

void print(int &x)
{
	std::cout << x << std::endl;
}

void	increment(int &a)
{
	a++;
}

void decrement(int &a)
{
	a--;
}

void	printChar(char &x)
{
	std::cout << x << std::endl;
}

void	incrChar(char &x)
{
	x++;
}

void	decrChar(char &x)
{
	x--;
}

int	main(void)
{
	int array[] = {1, 2, 3, 4, 5};
	char array2[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	size_t len1 = sizeof(array) / sizeof(array[0]);
	size_t len2 = sizeof(array2) / sizeof(array2[0]);

	std::cout << "Original array" << std::endl;
	iter(array, len1, print);

	iter(array, len1, increment);
	std::cout << "Incremented array" << std::endl;
	iter(array, len1, print);

	iter(array, len1, decrement);
	std::cout << "Decremented array" << std::endl;
	iter(array, len1, print);

	std::cout << "Original array2" << std::endl;
	iter(array2, len2, printChar);

	iter(array2, len2, incrChar);
	std::cout << "Incremented array2" << std::endl;
	iter(array2, len2, printChar);

	iter(array2, len2, decrChar);
	std::cout << "Decremented array2" << std::endl;
	iter(array2, len2, printChar);

	return (0);
}