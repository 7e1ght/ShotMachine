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

    void emplace(const Key& key, const Value& value);
    void remove(const Key& key, const Value& value);

    uint16_t size() { return mNodeCounter; } 

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

    Node* mHead;
    Node* mTail;
    uint16_t mNodeCounter;

};

template<typename Key, typename Value>
void ListedMap<Key, Value>::emplace(const Key& key, const Value& value)
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

template<typename Key, typename Value>
void ListedMap<Key, Value>::remove(const Key& key, const Value& value)
{
    supp::Pair<Key, Value> tPair(key, value);
    
    Node* currentNode = mHead;
    Node* prevNode = nullptr;

    while(nullptr != currentNode)
    {
        
    } 

}
#endif // LISTED_MAP_H