#include <iostream>
#include "node.h"
#include "link.h"
#include<vector>
#include "network.h"
#include "network_ba.h"
#include <math.h>
#include <fstream>
#include <chrono>

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
    //cout << b << endl;
    int a = ceil(1*1.2); //
    //cout << a << endl;

    int v = int(3);
    cout << v << endl;

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

    net.grow(10);
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



/*
session 05
*/
void run_network_ba(int argc, char* argv[]){
    if(argc < 4){
        cout << "m  = argv[1]" << endl;
        cout << "N  = argv[2]" << endl;
        cout << "En = argv[3]" << endl;
        return;
    }
    int m = atoi(argv[1]);
    int N = atoi(argv[2]);
    int En = atoi(argv[3]);

    cout << "m  = " << m  << endl;
    cout << "N  = " << N  << endl;
    cout << "En = " << En << endl;


    vector<int> degree_dist;

    NetworkBA net = NetworkBA(m);

    for(size_t e=1; e <= En; ++e){
        auto start = std::chrono::steady_clock::now();

        net.reset();
        net.grow(N);

        auto dd = net.degreeDistribution();
        auto sz = dd.size();
        if (degree_dist.size() < sz){
            degree_dist.resize(sz);
        }
        for(size_t i{}; i < sz; ++i){
            degree_dist[i] += dd[i];
        }
        auto stop = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = stop-start;
        std::cout << "run " << e << ". Elapsed time: " << elapsed_seconds.count() << " sec" << endl;
    }

//    cout << "degree : number of node with that degree" << endl;
//    cout << "k : N(k)" << endl;

    string filename = "degree-distribution_m" + to_string(m) + "_.txt";
    ofstream fout(filename);

    fout << "# degree distribution BA network" << endl;
    fout << "# degree : number of node with that degree" << endl;
    fout << "# <k> <N(k)>" << endl;


    for(int i=0; i < degree_dist.size(); ++i){
        //cout << i << " : " << dd[i] << endl;

        if(degree_dist[i] == 0) continue;
        fout << i << "\t" << degree_dist[i]/double(En) << endl;
    }

}

/**
 session 05
 Command line argument
**/
int main(int argc, char* argv[])
{
    cout << "Network Program" << endl;
    //func1();
    //func2();
//    func3();
    //func4();

    // session 05
    run_network_ba(argc, argv);

    cout << "Program ending time : " << endl;
    cout << "Time elapsed in minutes : " << endl;
    return 0;
}
