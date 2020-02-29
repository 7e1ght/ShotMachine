#ifndef LISTED_MAP_H
#define LISTED_MAP_H

#include <support/support.h

template<typename Key, typename Vlaue>
class ListedMap
{
public:

private:

    struct Node
    {
        supp::Pair<Key, Value> pair;
        Node* nextNode;
    };
    
};

#endif // LISTED_MAP_H