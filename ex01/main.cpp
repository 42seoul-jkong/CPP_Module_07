/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "iter.hpp"
#include <iostream>
#include <sstream>
#include <string>

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
    std::size_t len = 10;

    int* arr = new int[len];
    for (std::size_t i = 0; i < len; i++)
    {
        arr[i] = i * i;
    }
    iter(arr, len, print_int);

    std::string* str_arr = new std::string[len];
    for (std::size_t i = 0; i < len; i++)
    {
        std::stringstream ss;
        ss << "Value " << (i + i);
        str_arr[i] = ss.str();
    }
    iter(str_arr, len, print_string);

    delete[] str_arr;
    delete[] arr;

    return 0;
}
