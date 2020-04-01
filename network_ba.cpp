#include "network_ba.h"
#include <math.h>


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
