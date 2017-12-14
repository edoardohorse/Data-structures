#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "StackPointer_for_test.h"

using namespace NStackPointerTest;


class StackPointerTest: public testing::Test{
public:
	StackPointer<int>* stk = new StackPointer<int>;
	StackPointerTest(){
		stk->push(1);
		stk->push(2);
		stk->push(3);
		stk->push(4);
		stk->push(5);
		stk->push(6);
		stk->push(7);
	}

	~StackPointerTest(){
		delete stk;
	}

};

TEST_F(StackPointerTest, isEmpty){
	auto tmp = new StackPointer<int>;
	ASSERT_TRUE(tmp->isEmpty());
	ASSERT_FALSE(stk->isEmpty());
	delete tmp;
}

TEST_F(StackPointerTest, Push){}

TEST_F(StackPointerTest, Top){
	ASSERT_EQ(stk->top(), 7);
}

TEST_F(StackPointerTest, Pop){
	ASSERT_EQ(stk->top(), 7);
	stk->pop();
	ASSERT_EQ(stk->top(), 6);
	stk->push(7);
	ASSERT_EQ(stk->top(), 7);
}
