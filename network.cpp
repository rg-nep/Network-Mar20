
#include "network.h"

using namespace std;


void Network::build_network_seed(){
        for (int i=0; i < _seed_size; ++i){
            _nodes.push_back(Node());
            _nodes[i].set_id(_node_counter++);
        }

        for (int i=0; i < _seed_size; ++i){
            for (int j=i; j < _seed_size; ++j){
                _links.push_back(Link(_nodes[i].get_id(), _nodes[j].get_id()));
                //_links.set_id(_link_counter);
                //_link_counter ++;
            }

        }

    }


void Network::view_links(){
    cout << "id : link" << endl;
    for(size_t i{}; i < _links.size(); ++i){
        //cout << _links[i].get_id() << " : " << _links[i].get_str() << endl;
        cout << _links[i].get_id() << " : ("
                << _links[i].get_node_a() << ","
                << _links[i].get_node_b() << ")" << endl;
    }


}

void Network::view_nodes(){
    cout << "ids : "<< endl << "{" ;
    for(size_t i=0; i < _nodes.size(); ++i){
        cout << _nodes[i].get_id() << ",";

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
        _nodes[i].set_id(_node_counter++);
    }

}

