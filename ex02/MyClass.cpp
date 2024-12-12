#include "MyClass.hpp"

MyClass::MyClass(void) : x(0){
	std::cout << "MyClass default constructor called" << std::endl;
}

MyClass::MyClass(unsigned int a) : x(a){
	// std::cout << "MyClass constructor with parameter called" << std::endl;
}

MyClass& MyClass::operator=(const MyClass &old){
	if (this != &old)
	{
		x = old.x;
	}
	return *this;
}

MyClass::~MyClass(void){
	// std::cout << "MyClass destructor called" << std::endl;
}

bool MyClass::operator!=(unsigned int value) const{
	return this->x != value;
}

bool MyClass::operator!=(const MyClass &value) const{
	return this->x != value.x;
}

std::ostream& operator<<(std::ostream &out, const MyClass &obj){
	out << obj.x;
	return out;
}