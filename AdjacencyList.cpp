#include "AdjacencyList.h"

void AdjacencyList::insertEdge(const string &from, const string &to) {
    // if both urls aren't keys yet
    if (!graph.count(from)) {
        graph[from] = Vertex();
    }

    if (!graph.count(to)) {
        graph[to] = Vertex();
    }

    // add outbound links to from
    graph.at(from).addOutboundLinks();

    // add inbound links to second
    graph.at(to).addInboundLinks(from);
}

void AdjacencyList::calculateInitialRanks() {
    float initialRank = 1.0 / graph.size();
    for (auto &pair : graph) {
        pair.second.rank = initialRank;
        pair.second.oldRank = initialRank;
    }
}

// TEST CASES

vector<string> AdjacencyList::getKeys() {
    vector<string> result;
    for (auto &pair : graph) {
        result.push_back(pair.first);
    }

    return result;
}

vector<string> AdjacencyList::getInboundLinks(const string &vertex) {
    vector<string> result;
    for (auto &i : graph.at(vertex).links.first) {
        result.push_back(i);
    }

    return result;
}

int AdjacencyList::getNumberOutboundLinks(const string &vertex) {
    int result = graph.at(vertex).links.second;
    return result;
}

vector<float> AdjacencyList::getRanks() {
    vector<float> result;
    vector<string> temp;
    for (auto &pair : graph) {
        temp.push_back(pair.first);
    }
    sort(temp.begin(), temp.end());
    for (auto &key : temp) {
        float rank = graph.at(key).rank;
        rank = round(rank * 100.0) / 100.0;
        result.push_back(rank);
    }

    return result;
}

// END TEST CASES

void AdjacencyList::calculateRanks() {
    for (auto &pair : graph) {
        // (inbound link rank / inbound links outbound links number) is our new rank
        // making sure to use the rank that hasn't been updated
        float newRank = 0;
        for (auto &link : pair.second.links.first) {
            newRank += graph.at(link).oldRank / graph.at(link).links.second;
        }

        pair.second.rank = newRank;
    }

    // updating old rank when complete
    for (auto &pair : graph) {
        pair.second.oldRank = pair.second.rank;
    }
}

bool sortHelper(const pair<string, float> &a, const pair<string, float> &b) {
    return a.first < b.first;
}

void AdjacencyList::printOutput() {
    vector<pair<string, float>> result;
    for (auto &pair : graph) {
        float rank = pair.second.rank;
        rank = round(rank * 100.0) / 100.0;
        result.emplace_back(pair.first, rank);
    }

    sort(result.begin(), result.end(), sortHelper);
    for (auto &pair : result) {
        cout << pair.first << " " << fixed << setprecision(2) << pair.second << endl;
    }
}

void AdjacencyList::Vertex::addInboundLinks(const string &link) {
    // inbound links are implemented as forward list
    links.first.push_front(link);
}

void AdjacencyList::Vertex::addOutboundLinks() {
    // outbound links is implemented as an integer
    links.second += 1;
}


