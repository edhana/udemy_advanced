// Name: ex3_custom_exceptions.cpp
#include "gtest/gtest.h"
#include <iostream>
#include <exception>
using namespace std;

class MyException: public exception {
public:
    virtual const char * what() const throw() {
        return "Something bad happened!";
    }
};

class TestException {
public:
    void goesWrong() {
        throw MyException();
    }
};

TEST(CustomExceptions, ShouldRunCustomExceptionClass) {
    TestException test;

    // try {
    //     test.goesWrong();
    // }
    // catch(MyException &e) {
    //     cout << e.what() << endl;
    //     EXPECT_STREQ(e.what(), "Something bad happened!");
    // }

    EXPECT_THROW(test.goesWrong(), MyException);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
