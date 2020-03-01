#ifndef LISTED_MAP_H
#define LISTED_MAP_H

#include <support/support.h>

namespace supp
{
    template<typename Key, typename Value>
    class ListedMap
    {
    public:
        using PairType = supp::Pair<Key, Value>;

        ListedMap()
        : mHead(nullptr)
        , mTail(nullptr)
        , mNodeCounter(0)
        {}

        ~ListedMap() 
        {
            clear();
        }

        int16_t size() const { return mNodeCounter; } 

        void emplace(const Key& key, const Value& value);
        void remove(const Key& key);

        const PairType* getPair(const Key& key) const;
        PairType* getPair(const Key& key);

        const Value& operator[](const Key& key) const;
        Value& operator[](const Key& key);

        void clear();
    private:

        struct Node
        {
            PairType pair;
            Node* nextNode;

            Node()
            : pair()
            , nextNode(nullptr) 
            {}

            Node(Key key, Value value)
            : pair(key, value)
            , nextNode(nullptr) 
            {}
        };

        Node* mHead;
        Node* mTail;
        int16_t mNodeCounter;

    };

    template<typename Key, typename Value>
    void ListedMap<Key, Value>::emplace(const Key& key, const Value& value)
    {
        Node* newNode = new Node(key, value);  

        if(nullptr != newNode)
        {
             if(nullptr == mHead)
            {
                mHead = newNode;
                mTail = newNode;
            }
            else
            {
                mTail->nextNode = newNode;
                mTail = newNode;
            }
        }
        else
        {
            Serial.println("ListedMap::emplace(): newNode is nullptr.");
        }

        ++mNodeCounter;
    }

    template<typename Key, typename Value>
    void ListedMap<Key, Value>::remove(const Key& key)
    {
        const Key tKey(key);
        
        Node* currentNode = mHead;
        Node* prevNode = nullptr;

        while(nullptr != currentNode)
        {
            if(tKey == currentNode->pair.getKey())
            {
                if(nullptr != prevNode)
                {
                    prevNode->nextNode = currentNode->nextNode;
                }

                delete currentNode;
                --mNodeCounter;
                break;
            } 
            else
            {
                prevNode = currentNode;
                currentNode = currentNode->nextNode;
            }
        }
    }

    template<typename Key, typename Value>
    const typename ListedMap<Key, Value>::PairType* ListedMap<Key, Value>::getPair(const Key& key) const
    {
        const Key tKey = key;

        Node* currentNode = mHead;
        PairType* res = nullptr;

        while (nullptr != currentNode)
        {
            if(tKey == currentNode->pair.getKey())
            {
                res = &currentNode->pair;
                currentNode = currentNode->nextNode;
            }
            else
            {
                currentNode = currentNode->nextNode;
            }
        }

        return res;
    }

    template<typename Key, typename Value>
    typename ListedMap<Key, Value>::PairType* ListedMap<Key, Value>::getPair(const Key& key)
    {
        return const_cast<PairType*>(
            static_cast<const ListedMap<Key, Value>&>(*this).getPair(key)
            );
    }

    template<typename Key, typename Value>
    const Value& ListedMap<Key, Value>::operator[](const Key& key) const
    {
        return getPair(key)->getValue();
    }

    template<typename Key, typename Value>
    Value& ListedMap<Key, Value>::operator[](const Key& key)
    {
        return getPair(key)->getValue();
    }


    template<typename Key, typename Value>
    void ListedMap<Key, Value>::clear()
    {
        Node* currentNode = mHead;
        Node* nextNode;

        while (nullptr != currentNode)
        {
            nextNode = currentNode->nextNode;
            delete currentNode;
            --mNodeCounter;
            currentNode = nextNode;
        }

        mHead = nullptr;
    }
}

#endif // LISTED_MAP_H