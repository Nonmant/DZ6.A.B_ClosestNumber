#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "5 5\n"
                "1 3 5 7 9 \n"
                "2 4 8 1 6 "
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    INFO(buffer.str());
    REQUIRE(buffer.str() ==
            "1\n"
            "3\n"
            "7\n"
            "1\n"
            "5\n"
    );
}

TEST_CASE("test 2", ""){
    std::stringstream input(
            "6 11\n"
            "1 1 4 4 8 120 \n"
            "1 2 3 4 5 6 7 8 63 64 65 "
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "1\n"
            "1\n"
            "4\n"
            "4\n"
            "4\n"
            "4\n"
            "8\n"
            "8\n"
            "8\n"
            "8\n"
            "120\n"
    );
}

TEST_CASE("test 3", ""){
    std::stringstream input(
            "10 10\n"
            "-5 1 1 3 5 5 8 12 13 16 \n"
            "0 3 7 -17 23 11 0 11 15 7 "
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "1\n"
            "3\n"
            "8\n"
            "-5\n"
            "16\n"
            "12\n"
            "1\n"
            "12\n"
            "16\n"
            "8\n"
    );
}

TEST_CASE("one element", ""){
    std::stringstream input(
            "1 10\n"
            "1 \n"
            "0 3 7 -17 23 11 0 11 15 7 "
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
    );
}

TEST_CASE("same elements", ""){
    std::stringstream input(
            "10 10\n"
            "1 1 1 1 1 1 1 1 1 1 \n"
            "0 3 7 -17 23 11 0 11 15 7 "
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
            "1\n"
    );
}
