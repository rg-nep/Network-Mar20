
#include "network.h"

using namespace std;


void Network::build_network_seed(){
        for (int i=0; i < _seed_size; ++i){
            _nodes.push_back(Node());
            _nodes[i].set_id(_node_counter++);
        }

        for (int i=0; i < _seed_size; ++i){
            for (int j=i+1; j < _seed_size; ++j){ // j starts from i+1
                _nodes[i].increaseDegree();
                _nodes[j].increaseDegree();

                _links.push_back(Link(_nodes[i].get_id(), _nodes[j].get_id()));
                _links[_link_counter].set_id(_link_counter);
                _link_counter ++;
            }

        }

    }


void Network::view_links(){
    cout << "Viewing Links" << endl;
    cout << "id : link" << endl;
    for(size_t i{}; i < _links.size(); ++i){
        cout << _links[i].get_id() << " : " << _links[i].get_str() << endl;
//        cout << _links[i].get_id() << " : ("
//                << _links[i].get_node_a() << ","
//                << _links[i].get_node_b() << ")" << endl;
    }


}

void Network::view_nodes(){
    cout << "Viewing Nodes" << endl;
    cout << "ids : degree {"  << endl;
    for(size_t i=0; i < _nodes.size(); ++i){
        cout << _nodes[i].get_id() << " : " << _nodes[i].degree() << endl;

    }
    cout << "}" << endl;
}


void Network::grow(int N){
    if(N <= _seed_size){
        cerr << "cannot grow to lesser size" << endl;
    }
    int N_size = N;
    for (int i=_node_counter; i < N_size; ++i){
        _nodes.push_back(Node());
        _nodes[i].set_id(i);
        ++_node_counter;
    }

}

void Network::connect_nodes(int a, int b){
    if(a >= _node_counter || b >= _node_counter){
        cerr << "nodes does not exists" << endl;
    }
    //int pp = vec[i];//
    Node na = _nodes[a]; // to ensure that nodes exists
    Node nb = _nodes[b];
    _links.push_back(Link(na.get_id(), nb.get_id()));
    _links[_link_counter].set_id(_link_counter);
    _link_counter += 1;

    // session 04 : update degree
    _nodes[a].increaseDegree();
    _nodes[b].increaseDegree();

}


std::vector<int> Network::degreeDistribution(){
    vector<int>  degs;
    for(auto n: _nodes){// range based for loop
        int d = n.degree();
        if(degs.size() < d+1){
            degs.resize(d+1);
        }
        ++degs[d];
    }
    return degs;
}
