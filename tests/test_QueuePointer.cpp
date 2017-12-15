#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "QueuePointer_for_test.h"

using namespace NQueuePointerTest;
class QueuePointerTest: public testing::Test{

public:

	QueuePointer<int>* q = new QueuePointer<int>;
	QueuePointerTest(){

		q->push(1);
		q->push(2);
		q->push(3);
		q->push(4);
		q->push(5);
		q->push(6);
		q->push(7);
	}
	~QueuePointerTest(){
		delete q;
	}
};


TEST_F(QueuePointerTest, isEmpty){
	auto tmp = new QueuePointer<int>;
	ASSERT_TRUE(tmp->isEmpty());
	ASSERT_FALSE(q->isEmpty());
	delete tmp;
}
TEST_F(QueuePointerTest, Push){}

TEST_F(QueuePointerTest, Top){
	ASSERT_EQ(q->top(),1);
}

TEST_F(QueuePointerTest, Pop){
	ASSERT_EQ(q->top(), 1);
	q->pop();
	ASSERT_EQ(q->top(), 2);


	while (!q->isEmpty()){
		q->pop();
	}
	q->push(1);
	q->push(2);
	q->push(3);
	q->push(4);
	q->push(5);
	q->push(6);
	q->push(7);
	ASSERT_EQ(q->top(), 1);
}


/*

	QueuePointer<int>* q = new QueuePointer<int>;


	q->push(1);
	q->push(2);
	q->push(3);
	q->push(4);
	q->push(5);
	q->push(6);
	q->push(7);
	q->push(8);             // First
	q->push(9);
	q->push(10);

	q->pop();
	q->pop();
	q->pop();
	q->pop();
	q->pop();
	q->pop();
	q->pop();


	q->push(7);
	q->push(6);
	q->push(5);
	q->push(4);
	q->push(3);
	q->push(2);
	q->push(1);         // Last
	PrintList::printQueuePointer(q);
	delete(q);
 *
 *
 * */