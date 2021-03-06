
#ifndef NETWORK_LINK_H
#define NETWORK_LINK_H

#include <sstream>
#include <iostream>

class Link{

    int _id = -1;
    int _gid = -1;

    int _node_a = -1;
    int _node_b = -2;

public:
    Link (int node_a, int node_b){ // constructor
        _node_a = node_a;
        _node_b = node_b;
        if(_node_a == _node_b){
            std::cerr << "self connection is not allowed" << std::endl;
        }

//        if (node_a < node_b){
//            _node_a = node_a;
//            _node_b = node_b;
//        }
//        else if (node_a > node_b){
//            _node_a = node_b;
//            _node_b = node_a;
//        }
    }

    int get_node_a(){return _node_a;}
    int get_node_b(){return _node_b;}

    void view(){
    std::cout << "(" << _node_a << "," << _node_b << ")" << std::endl;
    }
    int set_id(int id){
        _id=id;
        }

    int get_id(){
        return _id;
        }

    std::string get_str(){
        std::stringstream ss;
        ss << "(" << _node_a << "," << _node_b << ")";
        return ss.str();
    }

};

#endif // NETWORK_LINK_H
