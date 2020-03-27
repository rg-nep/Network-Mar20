#include <iostream>
#include "node.h"
#include "link.h"
#include<vector>
#include "network.h"

using namespace std;


void func1(){

    int a = int(6);
    cout << a << endl;

    Node node1 = Node();
    node1.set_id(100);
    cout << node1.get_id() << endl;

    Node node2 = Node();
    node2.set_id(2);
    cout << node2.get_id() << endl;

    Link link1 = Link(node1.get_id(), node2.get_id());
    link1.view();

}

void func2(){
    int N=5; // seed size
    vector<Node> nodes;
    vector<Link> links;
    for (int i=0; i < N; ++i){
        nodes.push_back(Node());
        nodes[i].set_id(i);
    }

    for (int i=0; i < N; ++i){
        cout << nodes[i].get_id() << endl;
    }

    for (int i=0; i < N; ++i){
        for (int j=i; j < N; ++j){
        links.push_back(Link(nodes[i].get_id(), nodes[j].get_id()));
        }

    }

    for(int i=0; i < links.size(); ++i){
        links[i].view();
    }

}


void func3(){
    int b = 3;
    cout << b << endl;
    int a = int(3); //

    Network net = Network(3);
    net.view_nodes();
    net.view_links();

    net.grow(5);
    net.view_nodes();
    net.view_links();

//    net.connect_nodes(1,4);
//    net.view_links();

}

int main()
{
    cout << "Network Program" << endl;

    //func1();
    //func2();

    func3();

    return 0;
}
