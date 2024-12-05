#pragma once

template<typename T> class Array
{
	private:

	public:
		Array();
		Array(const Array &old);
		Array& operator=(const Array &old);
		~Array();
};