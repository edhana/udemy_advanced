#include <iostream>
#include <fstream>
#include <algorithm>
#include <experimental/filesystem> // aha! C++17 feature from boost
#include "gtest/gtest.h"
using namespace std;
namespace fs = std::experimental::filesystem;

const string BASE_FILENAME = "text.txt";
const string BASE_READ_FILENAME = "text_2.txt";

class WritingTextFileLecture6 : public ::testing::Test {
public:
    void TearDown() {
        // Remove the test file
        fs::remove(BASE_FILENAME);
    }
};

class ReadingTextFileLecture7 : public ::testing::Test {
public:
    void SetUp() {
        ofstream outFile;

        outFile.open(BASE_READ_FILENAME);

        if(outFile.is_open()) {
            for(int i = 1; i <= 10; i++) {
                outFile << "Test line " << i << endl;
            }
            outFile.close();
        }
    }

    //TODO: Add tear down
};

TEST_F(WritingTextFileLecture6, Ex1CreateNewFileAndWriteInside) {
    fstream outFile;
    outFile.open(BASE_FILENAME, ios::out);

    if(outFile.is_open()) {
        outFile << "Hello there" << endl;
        outFile << 123 << endl;
        outFile.close();
        SUCCEED();
    }
    else {
        cout << "Could not create file: " << BASE_FILENAME << endl;
        FAIL();
    }

}

TEST_F(WritingTextFileLecture6, Ex1ExtendedCreateNewFileWithMultipleTextLines) {
    fstream outFile;
    outFile.open(BASE_FILENAME, ios::out);

    if(outFile.is_open()) {
        outFile << "Line 1" << endl;
        outFile << "Line 2" << endl;
        outFile << "Line 3" << endl;
        outFile.close();
    }
    else {
        cout << "Could not create file: " << BASE_FILENAME << endl;
        FAIL();
    }

    // Openning the file again for reading
    ifstream inFile(BASE_FILENAME);
    int lineCount = count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');
    EXPECT_EQ(lineCount, 3);

    SUCCEED();
}

TEST_F(ReadingTextFileLecture7, Ex2ReadingSomethingBlabla) {
    EXPECT_TRUE(true);
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
