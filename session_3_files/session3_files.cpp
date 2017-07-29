#include <iostream>
#include <fstream>
#include <algorithm>
#include "gtest/gtest.h"
using namespace std;

const string BASE_FILENAME = "text.txt";

TEST(WritingTextFile , Ex1CreateNewFileAndWriteInside) {
    fstream outFile;
    // ofstream outFile;

    // string outputFileName = "text.txt";
    outFile.open(BASE_FILENAME, ios::out);
    // outFile.open(outputFileName);

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

TEST(WritingTextFile, Ex1ExtendedCreateNewFileWithMultipleTextLines) {
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

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
