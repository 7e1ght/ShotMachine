#ifndef LISTED_MAP_H
#define LISTED_MAP_H

#include <support/support.h>

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
        if(nullptr != mHead)
        {
            delete mHead;
        }

        if(nullptr != mTail)
        {
            delete mTail;
        }
    }

    void emplace(const Key& key, const Value& value) const;
    void remove(const Key& key, const Value& value) const;
    PairType& get(const Key& key, const Value& Value) const;

    uint16_t size() const { return mNodeCounter; } 

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

    void addNodeBack(const Node* newNode) const
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

    Node* mHead;
    Node* mTail;
    uint16_t mNodeCounter;

};

template<typename Key, typename Value>
void ListedMap<Key, Value>::emplace(const Key& key, const Value& value) const
{
    Node* newNode = new Node(key, value);  

    if(nullptr != newNode)
    {
        addNodeBack(newNode);
    }
    else
    {
        Serial.println("ListedMap::emplace(): newNode is nullptr.");
    }

    ++mNodeCounter;
}

// check below 

template<typename Key, typename Value>
void ListedMap<Key, Value>::remove(const Key& key, const Value& value) const
{
    const PairType tPair(key, value);
    
    Node* currentNode = mHead;
    Node* prevNode = nullptr;

    while(nullptr != currentNode)
    {
        if(tPair == currentNode->pair)
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
ListedMap<Key, Value>::PairType& ListedMap<Key, Value>::get(const Key& key, const Value& value) const
{
    const PairType tPair(key, value);

    Node* currentNode = mHead;

    while (nullptr != mHead)
    {
        if(tPair == currentNode->pair);
    }
    
}

#endif // LISTED_MAP_H