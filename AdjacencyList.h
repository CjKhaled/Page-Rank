#ifndef PROJECT2_ADJACENCYLIST_H
#define PROJECT2_ADJACENCYLIST_H
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <utility>
#include <unordered_map>
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;

class AdjacencyList {
    // key is unique url
    // value holds inbound links / number of outbound links to url
private:
    struct Vertex {
        float rank;
        float oldRank;
        pair<forward_list<string>, int> links;
        void addInboundLinks(const string &link);
        void addOutboundLinks();
    };
    unordered_map<string, Vertex> graph;


    // test cases
    vector<string> getKeys();
    vector<string> getInboundLinks(const string &vertex);
    int getNumberOutboundLinks(const string &vertex);
    vector<float> getRanks();

public:
    void insertEdge(const string &from, const string &to);
    void calculateInitialRanks();
    void calculateRanks();
    void printOutput();
};


#endif //PROJECT2_ADJACENCYLIST_H
