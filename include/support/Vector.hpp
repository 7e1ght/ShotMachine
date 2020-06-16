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

    Vector( const Vector& other );
    Vector operator=(const Vector& other) noexcept;

    ~Vector();

    template<typename F>
    void for_each(F func);

    void push_back(T item);
    uint8_t size() const noexcept { return mSize; }
    uint8_t capacity() const noexcept { return mCapacity; }

    const value_type& operator[](const uint8_t index) const
    {
        return mItemArray[index];
    }

    void clear() noexcept
    {
        delete[] mItemArray;

        mItemArray = new T[mCapacity];

        mSize = 0;
    }

    value_type& operator[](const uint8_t index)
    {
        return 
            const_cast<value_type&>
            (
                const_cast<const Vector<value_type>*>(this)->operator[](index)
            );
    }
};

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
: mCapacity(other.mCapacity)
, mSize(other.mSize)
, mItemArray(new T[other.mCapacity])
{
    for(int i = 0; other.size() > i; ++i)
    {
        mItemArray[i] = other[i];
    }
}

template<typename T>
Vector<T> Vector<T>::operator=(const Vector<T>& other) noexcept
{
    mCapacity = other.mCapacity;
    mSize = other.mSize;

    delete[] mItemArray;

    mItemArray = new T[mCapacity];

    for(int i = 0; other.size() > i; ++i)
    {
        mItemArray[i] = other[i];
    }

    return *this;
}

template<typename T>
void Vector<T>::resize()
{
    mCapacity = static_cast<uint8_t>(mCapacity * 2);

    T* newItemArray = new T[mCapacity];

    if(nullptr != newItemArray)
    {
        copyOldItemsTo(newItemArray);

        delete[] mItemArray;

        mItemArray = newItemArray;
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
}

template<typename T>
template<typename F>
void Vector<T>::for_each(F func)
{
    for(uint8_t i = 0; i < mSize && func( mItemArray[i] ); ++i);
}

template<typename T>
inline Vector<T>::~Vector()
{
    delete[] mItemArray;
}










template<typename T>
class Vector<T*>
{
public:
    using value_type = T*;

    Vector( uint8_t capacity = cfg::vector::DEFAULT_CAPACITY ) 
        : mCapacity(capacity)
        , mSize(0)
        , mItemArray(new value_type[mCapacity])
    {}

    ~Vector();

    template<typename F>
    void for_each(F func);
    void clear() noexcept;

    void push_back(value_type item);
    uint8_t size() const noexcept { return mSize; }
    uint8_t capacity() { return mCapacity; }

    const value_type operator[](const uint8_t index) const
    {
        return mItemArray[index];
    }

    value_type operator[](const uint8_t index)
    {
        return 
            const_cast<value_type>
            (
                const_cast<const Vector<value_type>*>(this)->operator[](index)
            );
    }

    Vector operator=(const Vector& other);
    Vector(const Vector& other);
private:
    uint8_t mCapacity;
    uint8_t mSize;

    value_type* mItemArray;

    void resize();
    void copyOldItemsTo(value_type* newArray)
    {
        for(int i = 0; i < mSize; ++i)
        {
            newArray[i] = mItemArray[i];
        }
    }
};

template<typename T>
void Vector<T*>::resize()
{
    mCapacity = static_cast<uint8_t>(mCapacity * 1.5f);

    value_type* newItemArray = new T*[mCapacity];

    if(nullptr != newItemArray)
    {
        copyOldItemsTo(newItemArray);

        delete[] mItemArray;

        mItemArray = newItemArray;
    }
}

template<typename T>
void Vector<T*>::push_back(T* item)
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
}

template<typename T>
template<typename F>
void Vector<T*>::for_each(F func)
{
    for(uint8_t i = 0; i < mSize && func( mItemArray[i] ); ++i);
}

template<typename T>
void Vector<T*>::clear() noexcept
{
    for(uint8_t i = 0; i < mSize; ++i)
    {
        delete mItemArray[i];
    }

    mSize = 0;
}

template<typename T>
Vector<T*>::~Vector()
{
    clear();
    delete mItemArray;
}

template<typename T>
Vector<T*>::Vector(const Vector<T*>& other)
: mCapacity(other.mCapacity)
, mSize(other.mSize)
, mItemArray(new T*[other.mCapacity])
{
    for(int i = 0; other.size() > i; ++i)
    {
        mItemArray[i] = other[i];
    }
}

template<typename T>
Vector<T*> Vector<T*>::operator=(const Vector<T*>& other) noexcept
{
    mCapacity = other.mCapacity;
    mSize = other.mSize;

    delete[] mItemArray;

    mItemArray = new T*[mCapacity];

    for(int i = 0; other.size() > i; ++i)
    {
        mItemArray[i] = other[i];
    }

    return *this;
}

}

#endif // VECTOR_HPP