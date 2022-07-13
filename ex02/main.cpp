/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Array.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

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

int main()
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
