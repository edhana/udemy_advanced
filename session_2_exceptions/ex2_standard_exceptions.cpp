// Class 2 Standard Exceptions
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

class CanGoWrong {
public:
    CanGoWrong() {
        char *pMemory = new char[999999999999999];
        delete [] pMemory;
    }
};

TEST(StandardExceptionTest, ShouldThrowBadAlloc) {
    try {
        CanGoWrong();
    }
    catch(bad_alloc &e) {
        cout << "Catched error: " << e.what() << endl;
        EXPECT_STREQ(e.what(), "std::bad_alloc");
    }

    cout << "still running ..." << endl;
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
