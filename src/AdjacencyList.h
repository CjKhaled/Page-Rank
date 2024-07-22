#ifndef PROJECT2_ADJACENCYLIST_H
#define PROJECT2_ADJACENCYLIST_H
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <utility>
#include <unordered_map>
using namespace std;

class AdjacencyList {
    // key is unique url
    // value holds inbound links / number of outbound links to url
private:
    struct Vertex {
        float rank;
        pair<forward_list<int>, int> links;
    };
    unordered_map<string, Vertex> graph;

    // test cases
    vector<string> getKeys();
    vector<string> getInboundLinks(const string &vertex);
    int getNumberOutboundLinks(const string &vertex);
    vector<float> getRanks();

public:
    void insertEdge(const string &from, const string &to);
};


#endif //PROJECT2_ADJACENCYLIST_H
