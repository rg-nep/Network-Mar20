#include "network_ba.h"
#include <math.h>
#include <set>

using namespace std;


NetworkBA::NetworkBA(int m)
    :Network(ceil(1.2*m)) // calling superclass constructor
{
    _m = m;
    //cout << "node pool" << endl;

    for(int i=0; i < _nodes.size(); ++i){

        for(int j=0; j < _nodes[i].degree(); ++j){
            _node_pool.push_back(_nodes[i].get_id());
        }

    }
}

void NetworkBA::view_node_pool(){
    cout << "Node pool : {";
    for(size_t i{}; i < _node_pool.size(); ++i){
        cout << _node_pool[i] << ",";
    }
    cout << "}" << endl;
}

// session 04
void NetworkBA::addNode(){
    cout << "NetworkBA::addNode " << endl;

    _nodes.push_back(Node());
    int node_a = _node_counter; // id of the new node;
    _nodes[node_a].set_id(node_a);
    ++_node_counter;

    // new node must connect with _m other nodes
    set<int> _nodes_to_connect_to; // ensures that no node is selected twice
    while(_nodes_to_connect_to.size()  < _m){
        // chose a node from the pool randomly
        auto r = rand() % _node_pool.size(); // later I will use better random number generator
        _nodes_to_connect_to.emplace(_node_pool[r]);
    }

    for(auto node_b: _nodes_to_connect_to){// range based for loop
        connect_nodes(node_a, node_b);

        _node_pool.push_back(node_a);
        _node_pool.push_back(node_b);
    }


}

// overriding super class method
void NetworkBA::grow(int N){
    if(N <= _seed_size){
        cerr << "cannot grow to lesser size" << endl;
    }
    int N_size = N;
    for (int i=_node_counter; i < N_size; ++i){
/*
    addNode() simplifies the task. we can define it in superclass also.
    that way we don't need to override grow() method
 */
        addNode();
    }
}
