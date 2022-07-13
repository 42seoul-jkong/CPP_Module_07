/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include <exception>

template <typename T>
class Array
{
public:
    typedef unsigned int index_t;

private:
    Array::index_t n;
    T* a;

public:
    Array();
    Array(Array::index_t n);
    Array(const Array& that);
    Array& operator=(const Array& that);
    ~Array();
    T& operator[](Array::index_t i);
    const T& operator[](Array::index_t i) const;
    Array::index_t size() const;

public:
    class IndexOutOfRangeException : public std::exception
    {
    public:
        IndexOutOfRangeException() throw() {}
        virtual ~IndexOutOfRangeException() throw();
        virtual const char* what() const throw();
    };
};

#include "Array.tpp"
