#ifndef NETWORK_NETWORK_BA_H
#define NETWORK_NETWORK_BA_H

#include "network.h"

// inheritance
class NetworkBA: public Network{
    int _m{1};

    std::vector<int> _node_pool;

public:
    NetworkBA(int m=1);
    void view_node_pool();

    void addNode(); // adding new node
    void grow(int N);

    // session 05
    void reset();
    void init_node_pool();



};

#endif // NETWORK_NETWORK_BA_H
