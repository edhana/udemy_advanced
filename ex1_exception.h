// Name: exception.h

#include <iostream>
using namespace std;

void mightGoWrong1();
void mightGoWrong2();
void mightGoWrong3();
void mightGoWrong4();

void usesMightGoWrong1() {
    mightGoWrong1();
}

void mightGoWrong1() {
    throw 400;
}

void mightGoWrong2() {
    throw "Something went wrong.";
}

void mightGoWrong3() {
    throw string("Something else (string) went wrong.");
}

void mightGoWrong4() {
    throw false;
}

