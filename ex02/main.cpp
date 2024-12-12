#include "Array.hpp"
#include "MyClass.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<char> chars;
    Array<int> numbers(MAX_VAL);
    Array<MyClass> myclass(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        if (i == 5)
            std::cout << "Value at index 5 is " << value << std::endl;
        myclass[i] = value;
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (myclass[i] != mirror[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    myclass.size();
    numbers.size();
    std::cout << "5 elements in array is " << numbers[5] << std::endl;
    std::cout << "5 elements in myclass is " << myclass[5] << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        myclass[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        myclass[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    // system("leaks convert");
    return 0;
}