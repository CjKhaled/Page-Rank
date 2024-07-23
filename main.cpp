#include <iostream>
#include <sstream>
#include <tuple>
#include "AdjacencyList.h"
using namespace std;

tuple<int, int> getFirstLine() {
    string userInput;
    getline(cin, userInput);

    istringstream parseInput(userInput);
    string numCommands;
    string powerIterations;
    getline(parseInput, numCommands, ' ');
    getline(parseInput, powerIterations);

    return {stoi(numCommands), stoi(powerIterations)};
}

int main() {
    AdjacencyList api;
    int numCommands, powerIterations;
    tie(numCommands, powerIterations) = getFirstLine();
    int count = 0;
    while (count != numCommands) {
        string userInput;
        getline(cin, userInput);

        istringstream parseInput(userInput);
        string from;
        string to;
        getline(parseInput, from, ' ');
        getline(parseInput, to, ' ');
        api.insertEdge(from, to);
        count++;
    }

    api.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        api.calculateRanks();
    }

    api.printOutput();

    return 0;
}
