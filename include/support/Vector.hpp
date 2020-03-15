#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "support/support.hpp"
#include "config/config.hpp"

namespace vector
{

}

template<typename T>
class Vector
{
private:
    uint8_t mCapacity;
    uint8_t mSize;

    T* mItemArray;

    void resize();
    void copyOldItemsTo(T* newArray)
    {
        for(int i = 0; i < mSize; ++i)
        {
            newArray[i] = mItemArray[i];
        }
    }
public:
    Vector( uint8_t capacity = cfg::vector::DEFAULT_CAPACITY ) 
        : mCapacity(capacity)
        , mSize(0)
        , mItemArray(new T[mCapacity])
    {}

    void push_back(T item);
    uint8_t size() { return mSize; }
    template<typename F>
    void for_each(F func);
};

template<typename T>
void Vector<T>::resize()
{
    const uint8_t mCapacity *= 2; 
    T* newItemArray = new T[newSize];

    copyOldItemsTo(newItemArray);

    mSize = newSize;
    delete[] mItemArray;

    mItemArray = newItemArray;
}

template<typename T>
void Vector<T>::push_back(T item)
{
    if(mSize >= mCapacity)
    {
        resize();
    }

    mItemArray[mSize++] = item;
}

template<typename T>
template<typename F>
void Vector<T>::for_each(F func)
{
    
}



#endif // VECTOR_HPP