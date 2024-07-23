#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <bits/stdc++.h>
#define private public
#include "../AdjacencyList.h"
#include "../AdjacencyList.cpp"

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
    test.insertEdge("samsung.com", "pcbuildinguf.com");
    test.insertEdge("zoom.us", "weather.com");
    test.insertEdge("youtube.com", "openai.com");
    test.insertEdge("stackoverflow.com", "weather.com");
    test.insertEdge("youtube.com", "getbootstrap.com");
    test.insertEdge("youtube.com", "google.com");
    test.insertEdge("chase.com", "stackoverflow.com");
    test.insertEdge("zoom.us", "chase.com");
    test.insertEdge("stackoverflow.com", "pcbuildinguf.com");
    test.insertEdge("microsoft.com", "getbootstrap.com");
    test.insertEdge("wikipedia.org", "youtube.com");
    test.insertEdge("chase.com", "youtube.com");
    test.insertEdge("pcbuildinguf.com", "google.com");
    test.insertEdge("samsung.com", "chase.com");
    test.insertEdge("getbootstrap.com", "stackoverflow.com");
    test.insertEdge("youtube.com", "samsung.com");
    test.insertEdge("youtube.com", "zoom.us");
    test.insertEdge("openai.com", "microsoft.com");
    test.insertEdge("getbootstrap.com", "pcbuildinguf.com");
    test.insertEdge("instagram.com", "youtube.com");
    test.insertEdge("weather.com", "wikipedia.org");
    test.insertEdge("chase.com", "zoom.us");
    test.insertEdge("google.com", "instagram.com");
    test.insertEdge("chase.com", "microsoft.com");
    test.insertEdge("stackoverflow.com", "chase.com");
    test.insertEdge("openai.com", "youtube.com");
    test.insertEdge("microsoft.com", "youtube.com");
    test.insertEdge("zoom.us", "google.com");
    test.insertEdge("microsoft.com", "openai.com");
    test.insertEdge("chase.com", "getbootstrap.com");
    test.insertEdge("youtube.com", "pcbuildinguf.com");
    test.insertEdge("pcbuildinguf.com", "zoom.us");
    test.insertEdge("getbootstrap.com", "wikipedia.org");
    test.insertEdge("zoom.us", "getbootstrap.com");
    test.insertEdge("microsoft.com", "samsung.com");
    test.insertEdge("stackoverflow.com", "instagram.com");
    test.insertEdge("weather.com", "instagram.com");
    test.insertEdge("youtube.com", "microsoft.com");
    test.insertEdge("wikipedia.org", "pcbuildinguf.com");
    test.insertEdge("getbootstrap.com", "chase.com");
    test.insertEdge("samsung.com", "stackoverflow.com");
    test.insertEdge("google.com", "pcbuildinguf.com");
    test.insertEdge("instagram.com", "weather.com");
    test.insertEdge("chase.com", "weather.com");
    test.insertEdge("openai.com", "weather.com");
    test.insertEdge("getbootstrap.com", "instagram.com");
    test.insertEdge("google.com", "stackoverflow.com");
    test.insertEdge("weather.com", "samsung.com");
    test.insertEdge("getbootstrap.com", "microsoft.com");
    test.insertEdge("instagram.com", "google.com");
    test.insertEdge("openai.com", "wikipedia.org");
    test.insertEdge("microsoft.com", "google.com");
    test.insertEdge("openai.com", "instagram.com");
    test.insertEdge("pcbuildinguf.com", "microsoft.com");
    test.insertEdge("instagram.com", "getbootstrap.com");
    test.insertEdge("weather.com", "google.com");
    test.insertEdge("google.com", "getbootstrap.com");
    test.insertEdge("google.com", "microsoft.com");
    test.insertEdge("samsung.com", "wikipedia.org");
    test.insertEdge("stackoverflow.com", "youtube.com");
    test.insertEdge("weather.com", "getbootstrap.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.08, 0.08, 0.08, 0.08, 0.08, 0.08, 0.08, 0.08, 0.08, 0.08, 0.08, 0.08,0.08});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct ranks at p = 2", "Rank Calculations") {
    AdjacencyList test;
    int powerIterations = 2;
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("ufl.edu", "facebook.com");
    test.insertEdge("microsoft.com", "ufl.edu");
    test.insertEdge("microsoft.com", "facebook.com");
    test.insertEdge("disney.com", "facebook.com");
    test.insertEdge("microsoft.com", "samsung.com");
    test.insertEdge("samsung.com", "ufl.edu");
    test.insertEdge("samsung.com", "facebook.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.00,0.57,0.00,0.07,0.37});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct ranks at p = 14", "Rank Calculations") {
    AdjacencyList test;
    int powerIterations = 14;
    test.insertEdge("aman.com", "disney.com");
    test.insertEdge("disney.com", "weather.com");
    test.insertEdge("aman.com", "microsoft.com");
    test.insertEdge("aman.com", "weather.com");
    test.insertEdge("facebook.com", "mozilla.org");
    test.insertEdge("facebook.com", "wikipedia.org");
    test.insertEdge("mozilla.org", "disney.com");
    test.insertEdge("weather.com", "disney.com");
    test.insertEdge("facebook.com", "aman.com");
    test.insertEdge("microsoft.com", "disney.com");
    test.insertEdge("aman.com", "wikipedia.org");
    test.insertEdge("disney.com", "facebook.com");
    test.insertEdge("disney.com", "aman.com");
    test.insertEdge("mozilla.org", "aman.com");
    test.insertEdge("disney.com", "microsoft.com");
    test.insertEdge("wikipedia.org", "microsoft.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.14,0.37,0.09,0.19,0.03,0.12,0.06});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct ranks at p = 10000", "Rank Calculations") {
    AdjacencyList test;
    int powerIterations = 10000;
    test.insertEdge("getbootstrap.com", "instagram.com");
    test.insertEdge("openai.com", "twitter.com");
    test.insertEdge("getbootstrap.com", "openai.com");
    test.insertEdge("twitter.com", "python.org");
    test.insertEdge("aman.com", "getbootstrap.com");
    test.insertEdge("mozilla.org", "openai.com");
    test.insertEdge("aman.com", "wikipedia.org");
    test.insertEdge("wikipedia.org", "instagram.com");
    test.insertEdge("instagram.com", "twitter.com");
    test.insertEdge("instagram.com", "python.org");
    test.insertEdge("instagram.com", "aman.com");
    test.insertEdge("getbootstrap.com", "twitter.com");
    test.insertEdge("openai.com", "python.org");
    test.insertEdge("wikipedia.org", "aman.com");
    test.insertEdge("openai.com", "aman.com");
    test.insertEdge("twitter.com", "openai.com");
    test.insertEdge("python.org", "twitter.com");
    test.insertEdge("openai.com", "mozilla.org");
    test.insertEdge("aman.com", "openai.com");
    test.insertEdge("instagram.com", "mozilla.org");
    test.insertEdge("python.org", "getbootstrap.com");
    test.insertEdge("openai.com", "wikipedia.org");
    test.insertEdge("getbootstrap.com", "wikipedia.org");
    test.insertEdge("twitter.com", "instagram.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.12,0.10,0.13,0.07,0.19,0.12,0.16,0.10});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}

TEST_CASE("Keys have correct ranks at p = 5", "Rank Calculations") {
    AdjacencyList test;
    int powerIterations = 5;
    test.insertEdge("apple.com", "twitter.com");
    test.insertEdge("getbootstrap.com", "stackoverflow.com");
    test.insertEdge("roblox.com", "twitter.com");
    test.insertEdge("google.com", "github.com");
    test.insertEdge("chase.com", "apple.com");
    test.insertEdge("apple.com", "pcbuildinguf.com");
    test.insertEdge("python.org", "google.com");
    test.insertEdge("microsoft.com", "pcbuildinguf.com");
    test.insertEdge("chase.com", "ufl.edu");
    test.insertEdge("getbootstrap.com", "chase.com");
    test.insertEdge("github.com", "ufl.edu");
    test.insertEdge("reactjs.org", "pcbuildinguf.com");
    test.insertEdge("samsung.com", "stackoverflow.com");
    test.insertEdge("youtube.com", "apple.com");
    test.insertEdge("github.com", "stackoverflow.com");
    test.insertEdge("python.org", "microsoft.com");
    test.insertEdge("reactjs.org", "disney.com");
    test.insertEdge("chase.com", "wikipedia.org");
    test.insertEdge("getbootstrap.com", "twitter.com");
    test.insertEdge("openai.com", "youtube.com");
    test.insertEdge("github.com", "weather.com");
    test.insertEdge("python.org", "aman.com");
    test.insertEdge("youtube.com", "wikipedia.org");
    test.insertEdge("youtube.com", "github.com");
    test.insertEdge("stackoverflow.com", "aman.com");
    test.insertEdge("chase.com", "pcbuildinguf.com");
    test.insertEdge("chase.com", "python.org");
    test.insertEdge("disney.com", "python.org");
    test.insertEdge("zoom.us", "aman.com");
    test.insertEdge("zoom.us", "python.org");
    test.insertEdge("facebook.com", "apple.com");
    test.insertEdge("zoom.us", "pcbuildinguf.com");
    test.insertEdge("roblox.com", "getbootstrap.com");
    test.insertEdge("facebook.com", "getbootstrap.com");
    test.insertEdge("samsung.com", "python.org");
    test.insertEdge("roblox.com", "zoom.us");
    test.insertEdge("disney.com", "facebook.com");
    test.insertEdge("youtube.com", "stackoverflow.com");
    test.insertEdge("pcbuildinguf.com", "getbootstrap.com");
    test.insertEdge("stackoverflow.com", "apple.com");
    test.insertEdge("microsoft.com", "aman.com");
    test.insertEdge("wikipedia.org", "roblox.com");
    test.insertEdge("disney.com", "youtube.com");
    test.insertEdge("reactjs.org", "ufl.edu");
    test.insertEdge("github.com", "openai.com");
    test.insertEdge("wikipedia.org", "weather.com");
    test.insertEdge("stackoverflow.com", "github.com");
    test.insertEdge("disney.com", "aman.com");
    test.insertEdge("python.org", "twitter.com");
    test.insertEdge("weather.com", "ufl.edu");
    test.insertEdge("instagram.com", "getbootstrap.com");
    test.insertEdge("github.com", "zoom.us");
    test.insertEdge("openai.com", "instagram.com");
    test.insertEdge("samsung.com", "weather.com");
    test.insertEdge("samsung.com", "microsoft.com");
    test.insertEdge("aman.com", "google.com");
    test.insertEdge("facebook.com", "python.org");
    test.insertEdge("weather.com", "zoom.us");
    test.insertEdge("aman.com", "facebook.com");
    test.insertEdge("aman.com", "github.com");
    test.insertEdge("chase.com", "getbootstrap.com");
    test.insertEdge("getbootstrap.com", "samsung.com");
    test.insertEdge("chase.com", "aman.com");
    test.insertEdge("weather.com", "disney.com");
    test.insertEdge("openai.com", "facebook.com");
    test.insertEdge("microsoft.com", "stackoverflow.com");
    test.insertEdge("twitter.com", "github.com");
    test.insertEdge("openai.com", "pcbuildinguf.com");
    test.insertEdge("pcbuildinguf.com", "microsoft.com");
    test.insertEdge("twitter.com", "zoom.us");
    test.insertEdge("weather.com", "openai.com");
    test.insertEdge("apple.com", "wikipedia.org");
    test.insertEdge("samsung.com", "youtube.com");
    test.insertEdge("facebook.com", "reactjs.org");
    test.insertEdge("chase.com", "openai.com");
    test.insertEdge("instagram.com", "pcbuildinguf.com");
    test.insertEdge("openai.com", "microsoft.com");
    test.insertEdge("disney.com", "getbootstrap.com");
    test.insertEdge("aman.com", "samsung.com");
    test.insertEdge("pcbuildinguf.com", "wikipedia.org");
    test.insertEdge("zoom.us", "samsung.com");
    test.insertEdge("ufl.edu", "zoom.us");
    test.insertEdge("reactjs.org", "twitter.com");
    test.insertEdge("pcbuildinguf.com", "python.org");
    test.insertEdge("twitter.com", "pcbuildinguf.com");
    test.insertEdge("disney.com", "stackoverflow.com");
    test.insertEdge("instagram.com", "openai.com");
    test.insertEdge("getbootstrap.com", "apple.com");
    test.insertEdge("facebook.com", "ufl.edu");
    test.insertEdge("youtube.com", "chase.com");
    test.insertEdge("aman.com", "weather.com");
    test.insertEdge("wikipedia.org", "twitter.com");
    test.insertEdge("zoom.us", "github.com");
    test.insertEdge("stackoverflow.com", "ufl.edu");
    test.insertEdge("aman.com", "zoom.us");
    test.insertEdge("google.com", "ufl.edu");
    test.insertEdge("reactjs.org", "stackoverflow.com");
    test.insertEdge("facebook.com", "youtube.com");
    test.insertEdge("instagram.com", "python.org");
    test.insertEdge("ufl.edu", "github.com");
    test.insertEdge("getbootstrap.com", "youtube.com");
    test.insertEdge("github.com", "facebook.com");
    test.insertEdge("pcbuildinguf.com", "youtube.com");
    test.insertEdge("ufl.edu", "python.org");
    test.insertEdge("ufl.edu", "facebook.com");
    test.insertEdge("aman.com", "chase.com");
    test.calculateInitialRanks();
    for (int i = 1; i < powerIterations; i++) {
        test.calculateRanks();
    }

    vector<float> correctResult({0.06,0.04,0.02,0.01,0.05,0.03,0.09,0.03,0.01,0.04,0.03,0.07,0.07,0.01,0.01,
                                 0.03,0.05,0.06,0.07,0.05,0.04,0.04,0.08});
    vector<float> givenResult = test.getRanks();

    for (decltype(correctResult.size()) i = 0; i < correctResult.size(); i++) {
        REQUIRE(correctResult[i] == givenResult[i]);
    }
}



