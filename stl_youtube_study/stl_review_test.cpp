#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set> // set and multiset
#include <map> // map and multimap
#include <unordered_set> // unordered set/multiset
#include <unordered_map> // unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric> // some numeric algorithm
#include <functional> // for the functors
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

TEST(BasicTemplateTEst, ShouldTestBoVectorSquared) {
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

// Introduction to STL #1 video
TEST(StlExample1, ShouldResortTheVector) {
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8); // vec: {4, 1, 8}

    vector<int>::iterator itr1 = vec.begin();
    vector<int>::iterator itr2 = vec.end();

    // Recommended way of traversing a vector
    for(vector<int>::iterator itr = itr1; itr != itr2; ++itr) {
        cout << *itr << " "; // To print out 4 1 8
    }

    // using at throws range error exception if out of range
    EXPECT_EQ(vec.at(0), 4);
    EXPECT_EQ(vec.at(1), 1);
    EXPECT_EQ(vec.at(2), 8);

    // sorting
    sort(itr1, itr2);

    cout << endl; // print an empty line
    cout << "Printing the sorted array: ";
    for(vector<int>::iterator itr = itr1; itr != itr2; ++itr) {
        cout << *itr << " "; // To print out 4 1 8
    }

    // C++11 way of traversing a vector
    for(auto it: vec) {
        cout << it << " ";
    }

    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec.at(1), 4);
    EXPECT_EQ(vec.at(2), 8);

    // vector are contiguos allocated in memory
    int *p = &vec[0];
}

// Sequence containers
TEST(StlExample2, SequenceContainerShouldShowCommonContainersMethods) {
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8); // vec: {4, 1, 8}

    // Common member functions of all containers
    if (vec.empty()) { cout << "Not possible." << endl; }

    cout << "Vector size: " << vec.size() << endl; // 3

    vector<int> vec2(vec); // Copy constructor, vec2: {4, 1, 8}

    vec.clear(); // Remove all items in vec; ve.size() == 0
    EXPECT_EQ(vec.size(), 0);

    vec2.swap(vec); // vec2 becomes empty, and vec has 3 items.
    for(auto it: vec)
        cout << "swaped vec: " << it << endl;

    EXPECT_EQ(vec2.size(), 0);
    EXPECT_EQ(vec.size(), 3);
}

// Deque
TEST(StlExample2, ShoudlShowExampleOfDequeContainer) {
    deque<int> deq = { 4, 6, 7 };
    deq.push_front(2);
    deq.push_back(3);

    EXPECT_EQ(deq.at(0), 2);
    EXPECT_EQ(deq.at(1), 4);
    EXPECT_EQ(deq.at(4), 3);

    cout << "Deque example: " << endl;
    for(auto it: deq) {
        cout << it << " ";
    }
}

// Lists -- double linked list
TEST(StlExample2, ShoudlShowExampleDoubleLinkedList) {
    list<int> mylist = { 5, 2, 9 };
    mylist.push_back(6);
    mylist.push_front(4);

    for(auto it: mylist)
        cout << it << " ";

    list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2); // itr -> 2
    mylist.insert(itr, 8); // fast insert O(1)

    cout << endl;
    for(auto it: mylist)
        cout << it << " ";

    itr++;
    mylist.erase(itr);
    // EXPECT_EQ(mylist.at(4), 6); // No random access no [] and at available

    cout << endl;
    for(auto it: mylist)
        cout << it << " ";
}
int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
