#include "gtest/gtest.h"
#include "ex1_exception.h"
#include <iostream>

TEST(ExceptionTest, ShouldThrowIntException) {
    EXPECT_THROW(mightGoWrong1(), int);
}

TEST(ExceptionTest, SHouldThrowCharConstStringException) {
    EXPECT_THROW(mightGoWrong2(), const char *);
}

TEST(ExceptionTest, ShouldThrowStringException) {
    EXPECT_THROW(mightGoWrong3(), string);
}

TEST(ExceptionTest, ShouldThowBooleanException) {
    EXPECT_THROW(mightGoWrong4(), bool);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
