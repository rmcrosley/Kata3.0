// Rachel Crosley
// 3/22/18
// Assignment

#include "catch.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>



int stringCalculator(const std::string & input) {
    std::istringstream stream(input);
    std::string token;
    int val = 0;
    std::vector<int> values;
    int sum = 0;
    
    if (input.empty())
        return 0;
    
    token = input;
    
    while (std::getline(stream, token)) {
        std::stringstream s(token);
        while(std::getline(s, token, ',')) {
            std::istringstream(token) >> val;
            values.push_back(val);
        }
    }
    
    
    for (auto val : values)
        sum += val;
    
    return sum;
}

TEST_CASE("An empty string returns zero.", "[empty]") {
    REQUIRE(stringCalculator("") == 0);
}

TEST_CASE("single number returns a value", "[one number]") {
    REQUIRE(stringCalculator("1") == 1);
    REQUIRE(stringCalculator("2") == 2);
    REQUIRE(stringCalculator("2000") == 2000);
}

TEST_CASE("Two numbers, comma delimited, returns the sum", "[arithmetic]") {
    REQUIRE(stringCalculator("1,2") == 3);
    REQUIRE(stringCalculator("10,7") == 17);
    REQUIRE(stringCalculator("42,96") == 138);
}

TEST_CASE("Three numbers, delimited, returns the sum", "[arithmetic]") {
    REQUIRE(stringCalculator("1,2,3") == 6);
    REQUIRE(stringCalculator("10,7,3") == 20);
    REQUIRE(stringCalculator("42,96,2") == 140);
    REQUIRE(stringCalculator("1\n2\n3") == 6);
    REQUIRE(stringCalculator("10\n7\n3") == 20);
    REQUIRE(stringCalculator("42\n96\n2") == 140);
}

TEST_CASE("Two numbers, newline delimited, returns the sum", "[arithmetic]") {
    REQUIRE(stringCalculator("1\n2") == 3);
    REQUIRE(stringCalculator("10\n7") == 17);
    REQUIRE(stringCalculator("42\n96") == 138);
}

