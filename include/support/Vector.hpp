#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "support/support.hpp"
#include "config/config.hpp"

namespace supp
{


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
    using value_type = T;

    Vector( uint8_t capacity = cfg::vector::DEFAULT_CAPACITY ) 
        : mCapacity(capacity)
        , mSize(0)
        , mItemArray(new T[mCapacity])
    {}

    ~Vector() { delete[] mItemArray; }

    template<typename F>
    void for_each(F func);

    void push_back(T item);
    uint8_t size() { return mSize; }
    uint8_t capacity() { return mCapacity; }
};

template<typename T>
void Vector<T>::resize()
{
    mCapacity = static_cast<uint8_t>(mCapacity * 1.5f);

    T* newItemArray = new T[mCapacity];

    if(nullptr != newItemArray)
    {
        copyOldItemsTo(newItemArray);

        delete[] mItemArray;

        mItemArray = newItemArray;
    }
    else
    {
        Serial.println("Vector<T>::resize(): new array = nullptr.");   
    }
}

template<typename T>
void Vector<T>::push_back(T item)
{
    if(nullptr != mItemArray)
    {
        if(mSize >= mCapacity)
        {
            resize();
        }

        mItemArray[mSize] = item;

        mSize++;
    } 
    else
    {
        Serial.println("Vector<T>::push_back(): new array = nullptr.");   
    }
}

template<typename T>
template<typename F>
void Vector<T>::for_each(F func)
{
    for(uint8_t i = 0; i < mSize && func( mItemArray[i] ); ++i);
}

}

#endif // VECTOR_HPP