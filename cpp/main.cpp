#include <iostream>
#include "node.h"
#include "link.h"
#include<vector>
#include "network.h"
#include "network_ba.h"
#include <math.h>
#include <fstream>

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

    net.connect_nodes(1,4);
    net.view_links();

    net.connect_nodes(4,2);
    net.view_links();

}

void func4(){
    int b = 3;
    cout << b << endl;
    int a = ceil(1*1.2); //
    cout << a << endl;

    int m = 2;
    NetworkBA net = NetworkBA(m);
    net.view_node_pool();

    net.view_nodes();
    net.view_links();

    // session 04
//    net.addNode();
//    net.view_nodes();
//    net.view_links();
//    net.view_node_pool();

    net.grow(1000);
    net.view_nodes();
    net.view_links();
    net.view_node_pool();

    auto dd = net.degreeDistribution();
    cout << "degree : number of node with that degree" << endl;
    cout << "k : N(k)" << endl;

    ofstream fout("degree-distribution.txt");

    fout << "# degree : number of node with that degree" << endl;
    fout << "# degree distribution BA network" << endl;
    fout << "# <k> <N(k)>" << endl;


    for(int i=0; i < dd.size(); ++i){
        //cout << i << " : " << dd[i] << endl;

        if(dd[i] == 0) continue;
        fout << i << "\t" << dd[i] << endl;
    }

}

int main()
{
    cout << "Network Program" << endl;

    //func1();
    //func2();

//    func3();

    func4();

    cout << "Program ending time : " << endl;
    cout << "Time elapsed in minutes : " << endl;
    return 0;
}
