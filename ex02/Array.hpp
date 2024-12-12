#pragma once

#include <iostream>

template<typename T> class Array
{
	private:
		T *array;
		unsigned int _size;

	public:
		Array() : _size(0){
			array = nullptr;
			std::cout << "Default constructor called" << std::endl; 
		}

		Array(unsigned int n) : _size(n){
			array = new T[n]();
			std::cout << "Construction with parameter called" << std::endl;
		}

		Array(const Array &old) : _size(old._size){
			if (old.array != nullptr)
			{
				array = new T[old._size];
				for (unsigned int i = 0; i < old._size; i++)
					array[i] = old[i];
			}
			else
			{
				array = nullptr;
				_size = 0;
			}
			std::cout << "Copy constructor called" << std::endl;
		}

		Array& operator=(const Array &old){
			if (this != &old)
				delete[] array;
			if (old.array != nullptr)
			{
				array = new T[old._size];
				for (unsigned int i = 0; i < old._size; i++)
					array[i] = old[i];
				_size = old._size;
			}
			else
			{
				array = nullptr;
				_size = 0;
			}
			std::cout << "Assignment operator called" << std::endl;
			return *this;
		}

		~Array(){
			std::cout << "Constructor called" << std::endl;
			delete[] array;
		}

		T& operator[](unsigned int index){
			if (index >= _size)
				throw std::out_of_range("Index out of range");
			return array[index];
		}

		const T& operator[](unsigned int index) const{
			if (index >= _size)
				throw std::out_of_range("Index out of range");
			return array[index];
		}

		void	size(){
			std::cout << "Array has " << _size <<" elements" << std::endl;
		}
};