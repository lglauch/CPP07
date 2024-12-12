#pragma once

#include <iostream>
#include <ostream>

class MyClass{
	public:
		unsigned int x;

		MyClass();
		MyClass(unsigned int x);
		MyClass& operator=(const MyClass &old);
		~MyClass();

		bool operator!=(unsigned int value) const;
		bool operator!=(const MyClass &value) const;

};
	std::ostream& operator<<(std::ostream &out, const MyClass &obj);