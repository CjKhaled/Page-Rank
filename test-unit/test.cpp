#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <bits/stdc++.h>
#define private public
#include "../src/AdjacencyList.h"
#include "../src//AdjacencyList.cpp"

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

TEST_CASE("Map has correct keys in order", "Adjacency List Implementation") {
    AdjacencyList test;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("gmail.com", "maps.com");

    vector<string> correctResult({"facebook.com", "gmail.com", "google.com", "maps.com", "ufl.edu"});
    vector<string> givenResult = test.getKeys();
    sort(givenResult.begin(), givenResult.end());

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct inbound links", "Adjacency List Implementation") {
    AdjacencyList test;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("gmail.com", "maps.com");

    vector<string> correctResult({"gmail.com", "google.com"});
    vector<string> givenResult = test.getInboundLinks("maps.com");
    sort(givenResult.begin(), givenResult.end());

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct number of outbound links", "Adjacency List Implementation") {
    AdjacencyList test;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("gmail.com", "maps.com");

    int correctResult = 2;
    int givenResult = test.getNumberOutboundLinks("ufl.edu");

    REQUIRE(correctResult == givenResult);
}

TEST_CASE("Keys have correct ranks at p = 1", "Rank Calculations") {
    AdjacencyList test;
    int powerIterations = 1;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("gmail.com", "maps.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.2, 0.2, 0.2, 0.2, 0.2});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct ranks at p = 2", "Rank Calculations") {
    AdjacencyList test;
    int powerIterations = 2;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("gmail.com", "maps.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.20, 0.20, 0.10, 0.30, 0.20});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct ranks at p = 3", "Rank Calculations") {
    AdjacencyList test;
    int powerIterations = 3;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("gmail.com", "maps.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.30, 0.15, 0.10, 0.25, 0.20});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct ranks at p = 10000", "Rank Calculations") {
    AdjacencyList test;
    int powerIterations = 10000;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("gmail.com", "maps.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.24, 0.18, 0.12, 0.24, 0.24});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct ranks at p = 5", "Rank Calculations") {
    AdjacencyList test;
    int powerIterations = 10000;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("maps.com", "quora.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.02, 0.04, 0.02, 0.02, 0.02, 0.02});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}



