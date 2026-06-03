#include <iostream>
using namespace std;
#define INVALID_CAP -1;
#define OVERFLOW 1;
#define INVALID_INDEX 2;

template <typename T>
class Array
{
private:
    int capacity, lastindex;
    T *arrptr;

public:
    Array(int cap = 0);
    Array(const Array &);
    Array &operator=(const Array &other);
    bool isEmpty();
    bool isFull();
    void append(T data);
    void insert(int, T);
    void edit(int, T);
    void del(int);
    T getElement(int);
    int count();
    int getIndex(T);
    void insertsingle(int index, int data);
    void setContinuesly(int);
    ~Array();
};

template <typename T>
Array<T>::Array(int cap = 0)
{
    lastindex = -1;
    if (capacity <= 0)
        throw INVALID_CAP;
    capacity = cap;
    arrptr = new int[capacity];
}

template <typename T>
Array<T>::~Array()
{
    delete[] arrptr;
}

template <typename T>
Array<T>::Array(const Array &other)
{
    this->capacity = other.capacity;
    this->lastindex = other.lastindex;
    arrptr = new int[capacity];
    for (int i = 0; i < other.lastindex + 1; i++)
    {
        arrptr[i] = other.arrptr[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    delete[] arrptr;
    this->capacity = other.capacity;
    this->lastindex = other.lastindex;
    arrptr = new int[capacity];
    for (int i = 0; i < other.lastindex + 1; i++)
    {
        arrptr[i] = other.arrptr[i];
    }
    return *this;
}

template <typename T>
bool Array<T>::isEmpty()
{
    return lastindex == -1;
}

template <typename T>
void Array<T>::append(T data)
{
    if (capacity == lastindex + 1)
        throw OVERFLOW;
    arrptr[lastindex + 1] = data;
    lastindex++;
}

template <typename T>
void Array<T>::insert(int index, T data)
{
    if (isFull())
        throw OVERFLOW;
    if (index < 0 || index > lastindex + 1)
        throw INVALID_INDEX;
    for (int i = lastindex + 1; i != index; i--)
    {
        arrptr[i] = arrptr[i - 1];
    }
    arrptr[index] = data;
    lastindex + 1;
}

template <typename T>
void Array<T>::edit(int index, T data)
{
    if (index > lastindex || index < 0)
        throw INVALID_INDEX;
    arrptr[index] = data;
}

template <typename T>
void Array<T>::del(int index)
{
    if (index > lastindex || index < 0)
        throw INVALID_INDEX;
    for (int i = index; i != lastindex; i++)
    {
        arrptr[i] = arrptr[i + 1];
    }
    lastindex - 1;
}

template <typename T>
bool Array<T>::isFull()
{
    return capacity == lastindex + 1;
}

template <typename T>
T Array<T>::getElement(int index)
{
    if (index > lastindex || index < 0)
        throw INVALID_INDEX;
    return arrptr[index];
}

template <typename T>
int Array<T>::count()
{
    return lastindex + 1;
}

template <typename T>
int Array<T>::getIndex(T data)
{
    for (int i = 0; i < lastindex + 1; i++)
    {
        if (arrptr[i] == data)
            return i;
    }
    return -1;
}
