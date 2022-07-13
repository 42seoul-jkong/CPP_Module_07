/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include <cstdlib>

template <typename T>
Array<T>::Array()
    : n(), a(this->n)
{
    // No-OP
}

template <typename T>
Array<T>::Array(Array::index_t n)
    : n(n), a(new T[this->n])
{
    // No-OP
}

template <typename T>
Array<T>::Array(const Array& that)
    : n(that.n), a(new T[this->n])
{
    for (Array::index_t i = 0; i < that.n; i++)
    {
        this->a[i] = that.a[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& that)
{
    Array tmp(that);

    // Begin swap(this->a, tmp.a)
    T* a_x = this->a;
    this->a = tmp.a;
    tmp.a = a_x;
    // End

    // Begin swap(this->n, tmp.n)
    Array::index_t n_x = this->n;
    this->n = tmp.n;
    tmp.n = n_x;
    // End

    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->a;
    this->a = NULL;
    this->n = Array::index_t();
}

template <typename T>
T& Array<T>::operator[](Array::index_t i)
{
    if (i >= n)
    {
        throw Array::IndexOutOfRangeException();
    }
    return this->a[i];
}

template <typename T>
const T& Array<T>::operator[](Array::index_t i) const
{
    if (i >= n)
    {
        throw Array::IndexOutOfRangeException();
    }
    return this->a[i];
}

template <typename T>
typename Array<T>::index_t Array<T>::size() const
{
    return this->n;
}

template <typename T>
Array<T>::IndexOutOfRangeException::~IndexOutOfRangeException() throw() {} // = default

template <typename T>
const char* Array<T>::IndexOutOfRangeException::what() const throw()
{
    return "array index out of range";
}
