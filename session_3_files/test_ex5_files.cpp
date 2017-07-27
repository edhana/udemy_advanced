#include <iostream>
#include <fstream>
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

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
