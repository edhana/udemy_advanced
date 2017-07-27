// Name: ex4_subclass_exception_caching.cpp
#include "gtest/gtest.h"
#include <iostream>
#include <exception>
using namespace std;

void goesWrong(bool balloc = false) {
    if(balloc) {
        throw bad_alloc();
    }

    throw exception();
}

void baseTestWrongCatchOrder(string &exception_string) {
    try {
        // SHALL throw a bad_alloc
        goesWrong(true);
    }
    catch(exception &e) {
        cout << "Entering the std::exception class block, but the real exception was: " << e.what()
             << endl;
        exception_string = e.what();
        throw e;
    }
    catch(bad_alloc &e) {
        throw e;
    }
}

TEST(CachingOrder, ShouldTestSubclassExceptionBadAlloc) {
    try {
        goesWrong(true);
    }
    catch(bad_alloc &e) {
        SUCCEED();
    }
    catch(exception &e) {
        FAIL(); 
    }
}

TEST(CachingOrder, ShoudlTestExceptionException) {
    try {
        goesWrong();
    }
    catch(bad_alloc &e) {
        FAIL(); 
    }
    catch(exception &e) {
        SUCCEED();
    }
}

TEST(CachingOrder, ShouldTestWrongTryCatch) {
    string exstr;
    EXPECT_THROW(baseTestWrongCatchOrder(exstr), exception);
    EXPECT_STREQ(exstr.c_str(), "std::bad_alloc");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
