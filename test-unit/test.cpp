#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <bits/stdc++.h>
#define private public
#include "../src/AdjacencyList.h"

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

    for (int i = 0; i < correctResult.size(); i++) {
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

    vector<string> correctResult({"google.com", "gmail.com"});
    vector<string> givenResult = test.getInboundLinks("maps.com");

    for (int i = 0; i < correctResult.size(); i++) {
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

TEST_CASE("Keys have correct ranks at p = 1", "Adjacency List Implementation") {
    AdjacencyList test;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("gmail.com", "maps.com");

    vector<float> correctResult({0.2, 0.2, 0.2, 0.2, 0.2 });
    vector<float> givenResult = test.getRanks();
    sort(givenResult.begin(), givenResult.end());

    for (int i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct ranks at p = 2", "Adjacency List Implementation") {
    AdjacencyList test;
    test.insertEdge("google.com", "gmail.com");
    test.insertEdge("google.com", "maps.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "google.com");
    test.insertEdge("ufl.edu", "gmail.com");
    test.insertEdge("maps.com", "facebook.com");
    test.insertEdge("gmail.com", "maps.com");

    vector<float> correctResult({0.30, 0.15, 0.10, 0.25, 0.20});
    vector<float> givenResult = test.getRanks();
    sort(givenResult.begin(), givenResult.end());

    for (int i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}



