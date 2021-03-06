/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

template <typename T>
void swap(T& a, T& b)
{
    if (&a != &b)
    {
        T x = a;
        a = b;
        b = x;
    }
}

template <typename T>
T& min(T& a, T& b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <typename T>
const T& min(const T& a, const T& b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <typename T>
T& max(T& a, T& b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <typename T>
const T& max(const T& a, const T& b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
