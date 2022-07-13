/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include <cstddef>

template <typename T>
void iter(T* array, std::size_t length, void (*pfn)(T&))
{
    for (std::size_t i = 0; i < length; i++)
    {
        pfn(array[i]);
    }
}

template <typename T>
void iter(const T* array, std::size_t length, void (*pfn)(const T&))
{
    for (std::size_t i = 0; i < length; i++)
    {
        pfn(array[i]);
    }
}
