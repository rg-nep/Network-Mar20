
#ifndef NETWORK_NETWORK_H
#define NETWORK_NETWORK_H

#include <vector>
#include "node.h"
#include "link.h"

// general property of a network
class Network{
    // private
    std::vector<Node> _nodes;
    std::vector<Link> _links;

    int _seed_size;
    int _link_counter=0;
    int _node_counter=0;

public:

    Network(int seed=5){ // constructor
        _seed_size = seed;
        build_network_seed();
    }

    void build_network_seed();
    void view_links();
    void view_nodes();

    void grow(int N);
    void connect_nodes(int a, int b);

};

#endif // NETWORK_NETWORK_H
