#include <gtest/gtest.h>
#include "BasicVector/basicVector.hpp"
#include <stdexcept>
#include <iostream>

class BasicVecInt : public ::testing::Test{
    protected:
        Vec<int> vecInt;
        void SetUp() override {
            vecInt = {1,2,3};
        }
};

class BasicVecString : public ::testing::Test{
    protected:
        Vec<std::string> vecString;
        void SetUp() override {
            vecString = {"hi", "hello", "hey"};
        }
};

TEST_F(BasicVecInt, SizeCheck){
    ASSERT_EQ(vecInt.size(), 3);
}

TEST_F(BasicVecInt, PopBack){
    vecInt.pop_back();
    ASSERT_EQ(vecInt.size(), 2);
    ASSERT_EQ(vecInt.back(), 2);
}

TEST_F(BasicVecInt, PushBack){
    vecInt.push_back(4);
    ASSERT_EQ(vecInt.size(), 4);
    ASSERT_EQ(vecInt.back(), 4);
}

TEST_F(BasicVecInt, OutOfBounds){
    EXPECT_THROW(vecInt[4], std::out_of_range);
    EXPECT_THROW(vecInt[-1], std::out_of_range);
}

TEST_F(BasicVecInt, Insert){
    ASSERT_EQ(vecInt.front(), 1);
    ASSERT_EQ(vecInt.back(), 3);

    vecInt.insert(0, 10);
    ASSERT_EQ(vecInt[0], 10) << "Insert new value at beginning, value at the beginning should be 10.";

    vecInt.insert(3, 0);
    ASSERT_EQ(vecInt[3], 0) << "Inserted at position 3, value 0, so vecInt[3] should give us 0.";

    vecInt.insert(1, 5);
    ASSERT_EQ(vecInt[1], 5) << "Inserted at position 1, value 5, so vecInt[1] should give us 5.";

    vecInt.insert(6, 50);
    ASSERT_EQ(vecInt[6], 50) << "Insert new value at end of Vec, value should be 50.";

    ASSERT_EQ(vecInt.size(), 7) << "Size should be 7 after insertions.";

    EXPECT_THROW(vecInt.insert(-1, 5), std::out_of_range);
    EXPECT_THROW(vecInt.insert(8, 100), std::out_of_range);

    ASSERT_EQ(vecInt.front(), 10);
    ASSERT_EQ(vecInt.back(), 50);

    Vec<int> expected = {10, 5, 1, 2, 0, 3, 50};
    for(int i = 0; i < vecInt.size(); i++){
        ASSERT_EQ(vecInt[i], expected[i]);
    }
}

TEST_F(BasicVecInt, Delete){
    vecInt.remove(1);
    ASSERT_EQ(vecInt.size(), 2);
    ASSERT_EQ(vecInt[0], 1);
    EXPECT_THROW(vecInt.remove(-1), std::out_of_range);
    EXPECT_THROW(vecInt.remove(3), std::out_of_range);
}


TEST_F(BasicVecInt, Clear){
    vecInt.clear();
    ASSERT_EQ(vecInt.size(), 0);
    ASSERT_EQ(vecInt.begin(), vecInt.end());
    EXPECT_THROW(vecInt.front(), std::out_of_range);
    EXPECT_THROW(vecInt.back(), std::out_of_range);
}

TEST_F(BasicVecString, RangedLoop){
    int i = 0;
    for(auto const& strings : vecString){
        ASSERT_EQ(strings, vecString[i++]); // fun fact: 
        // i++ actually uses i first and then increments it, while ++i would increment i first then use it
    }
}

TEST(EmptyVec, TestEmptyVec){
    Vec<int> empty;
    ASSERT_TRUE(empty.isEmpty()) << "Vec should be empty.";
    ASSERT_EQ(empty.begin(), empty.end()) << "Empty vector should have begin() == end()";
    EXPECT_THROW(empty.front(), std::out_of_range) << "An empty vector does not have a front.";
    EXPECT_THROW(empty.back(), std::out_of_range) << "An empty vector does not have a back.";
    EXPECT_THROW(empty.pop_back(), std::out_of_range) << "Make sure underflow cannot occur.";
}