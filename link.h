
#include <iostream>>

class Link{

    int _id = -1;
    int _gid = -1;

    int _node_a = -1;
    int _node_b = -2;

public:
    Link (int node_a, int node_b){ // constructor
        _node_a = node_a;
        _node_b = node_b;
    }

    void view(){
    std::cout << "(" << _node_a << "," << _node_b << ")" << std::endl;
    }
    int set_id(int id){
        _id=id;
        }

    int get_id(){
        return _id;
        }
};
