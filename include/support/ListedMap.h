#ifndef LISTED_MAP_H
#define LISTED_MAP_H

#include <support/support.h>

template<typename Key, typename Value>
class ListedMap
{
public:
    ListedMap()
    : mHead(nullptr)
    , mTail(nullptr)
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

    void emplace(Key key, Value value);

private:

    struct Node
    {
        supp::Pair<Key, Value> pair;
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


    void addNodeBack(const Node* newNode)
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
};

template<typename Key, typename Value>
void ListedMap<Key, Value>::emplace(Key key, Value value)
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
}

#endif // LISTED_MAP_H