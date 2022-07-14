/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Array.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

#define MAX_VAL 750

template <typename T>
void iter(Array<T>& array, void (*pfn)(T&))
{
    for (std::size_t i = 0; i < array.size(); i++)
    {
        pfn(array[i]);
    }
}

template <typename T>
void iter(const Array<T>& array, void (*pfn)(const T&))
{
    for (std::size_t i = 0; i < array.size(); i++)
    {
        pfn(array[i]);
    }
}

static void print_int(int& i)
{
    std::cout << "Integer: " << i << std::endl;
}

static void print_string(const std::string& i)
{
    std::cout << "String: " << i << std::endl;
}

int ft_main()
{
    Array<int> empty;

    Array<int> arr(15);
    for (std::size_t i = 0; i < arr.size(); i++)
    {
        arr[i] = i * i;
    }
    iter(arr, print_int);

    Array<std::string> str_arr(25);
    for (std::size_t i = 0; i < str_arr.size(); i++)
    {
        std::stringstream ss;
        ss << "Value " << (i + i);
        str_arr[i] = ss.str();
    }

    const Array<std::string> str_arr2(str_arr);
    iter(str_arr2, print_string);

    str_arr = str_arr2;
    try
    {
        std::cout << str_arr[str_arr.size()] << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
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
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror; //
    return ft_main();
}
