
#ifndef NETWORK_NODE_H
#define NETWORK_NODE_H


class  Node{
    int _id = -1;  /// id of the node
    int _gid = -1; /// group id
public:
    int set_id(int id){
        _id=id;
        }

    int get_id(){
        return _id;
        }
};


#endif // NETWORK_NODE_H
