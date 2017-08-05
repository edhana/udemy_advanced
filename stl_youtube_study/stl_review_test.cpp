#include <iostream>
#include "gtest/gtest.h"
using namespace std;

// Function template
template <typename T>
T square(T x) {
    return x * x;
}

template<typename T>
class BoVector {
    T arr[1000];
    int size;

public:
    BoVector():size(0) {}
    void push(T x) { arr[size] = x; size++; }
    void print() const { for(int i=0; i<size; i++) {cout << arr[i] << endl;} }
    int getSize() const { return size; }
    T get(int index) const { return arr[index]; }
};

template<typename T>
BoVector<T> operator*(const BoVector<T>& rhs1, BoVector<T>& rhs2) {
    BoVector<T> ret;
    for(int i=0; i<rhs1.getSize(); i++) {
        ret.push(rhs1.get(i)*rhs2.get(i));
    }
    return ret;
}

TEST(BasicTemplateTest, ShouldTestBasicFunctionVector) {
    EXPECT_EQ(square<int>(5), 25);
    EXPECT_EQ(square<double>(5.5), 30.25);
}

TEST(BasicTemplateTest, ShouldTestSimplifiedFunctionTemplate) {
    EXPECT_EQ(square(5), 25);
    EXPECT_EQ(square(5.5), 30.25);
}

TEST(BasicTemplateTest, ShouldTestBasicClassTemplate) {
    BoVector<int> bv;
    bv.push(2);
    bv.push(5);
    bv.push(8);
    bv.push(9);
    bv.print();
    EXPECT_EQ(bv.getSize(), 4); // daaa, just to test something
}

TEST(BsicTemplateTEst, ShouldTestBoVectorSquared) {
    BoVector<int> bv;
    bv.push(2);
    bv.push(5);
    bv.push(8);
    bv.push(9);
    bv = square(bv);
    // bv.print();
    EXPECT_EQ(bv.get(0), 4);
    EXPECT_EQ(bv.get(1), 25);
    EXPECT_EQ(bv.get(2), 64);
    EXPECT_EQ(bv.get(3), 81);
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
