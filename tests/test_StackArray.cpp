#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "StackArray_for_test.h"

using namespace NStackArrayTest;


class StackArrayTest: public testing::Test{
public:
	StackArray<int>* stk = new StackArray<int>;
	StackArrayTest(){
		stk->push(1);
		stk->push(2);
		stk->push(3);
		stk->push(4);
		stk->push(5);
		stk->push(6);
		stk->push(7);
	}

	~StackArrayTest() {
		delete stk;
	}

};

TEST_F(StackArrayTest, isEmpty){
	auto tmp = new StackArray<int>;
	ASSERT_TRUE(tmp->isEmpty());
	ASSERT_FALSE(stk->isEmpty());
	delete tmp;
}

TEST_F(StackArrayTest, Push){}

TEST_F(StackArrayTest, Top){
	ASSERT_EQ(stk->top(), 7);
}

TEST_F(StackArrayTest, Pop){
	ASSERT_EQ(stk->top(), 7);
	stk->pop();
	ASSERT_EQ(stk->top(), 6);
	stk->push(7);
	ASSERT_EQ(stk->top(), 7);
}
