#include <iostream>
#include "gtest/gtest.h"
using namespace std;

struct tree {
    int x;
    tree * l;
    tree * r;
};

int countVisible(int height, tree * T) {
    int ret = 0;
    static int base = 0;

    if(T != NULL){
        if(height == 0){
            base = T->x;
            ret = 1;
        }
        height++;

        // left side
        if((T->l != NULL)) {
            if(base <= T->l->x)
                ret++;

            ret += countVisible(height, T->l);
            ret += countVisible(height, T->r);
        }

        // right side
        if((T->r != NULL)) {
            if(base <= T->r->x)
                ret++; 

            ret += countVisible(height, T->l);
            ret += countVisible(height, T->r);
        }
    }

    return ret;
}

int solution(tree *T) {
    if(T){
        // height 0 for the first argument
        return countVisible(0, T); 
    }

    return -1;
}

TEST(CodilityChallenge1, ShouldTestWithOneElement) {
    tree teste = {5, NULL, NULL};
    EXPECT_EQ(solution(&teste), 1);
}

TEST(CodilityChallenge1, ShouldTestWithTwoElements) {
    tree teste, lt;

    lt = {3, NULL, NULL};
    teste = {5, &lt, NULL};

    EXPECT_EQ(solution(&teste), 1);
}

TEST(CodilityChallenge1, ShouldTestWithTreeElements) {
    tree teste, lt, rt, llt, lrt, rlt;

    llt = {20, NULL, NULL};
    lrt = {21, NULL, NULL};

    rlt = {1, NULL, NULL};
    rt = {10, &rlt, NULL};

    lt = {3, &llt, &lrt};
    teste = {5, &lt, NULL};

    EXPECT_EQ(solution(&teste), 3);
}

TEST(CodilityChallenge1, ShoudTest1LevelElementCountTree) {
    tree t, lt, rt, llt, lrt;
    llt = {1, NULL, NULL};
    lrt = {2, NULL, NULL};

    rt =  {5, NULL, NULL};

    lt = {3, &llt, &lrt};
    t = {10, &lt, &rt};
    EXPECT_EQ(solution(&t), 1);
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
