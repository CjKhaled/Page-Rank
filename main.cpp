#include <iostream>
#include <sstream>
#include <tuple>
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
    auto [numCommands, powerIterations] = getFirstLine();
    int count = 0;
    while (count != numCommands) {
        string userInput;
        getline(cin, userInput);

        istringstream parseInput(userInput);
        string from;
        string to;
        getline(parseInput, from, ' ');
        getline(parseInput, to, ' ');
        count++;
    }

    return 0;
}
