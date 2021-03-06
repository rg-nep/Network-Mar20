
#ifndef NETWORK_NODE_H
#define NETWORK_NODE_H

#include<vector>

class  Node{
    int _id = -1;  /// id of the node
    int _gid = -1; /// group id

    int _degree=0;
    std::vector<int> _links; // to which links the node is connected
public:
    int set_id(int id){
        _id=id;
        }

    int get_id(){
        return _id;
    }

    void increaseDegree(){
        ++_degree;
    }

    int degree(){return _degree;}

};


#endif // NETWORK_NODE_H
