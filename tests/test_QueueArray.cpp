#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "QueueArray_for_test.h"

using namespace NQueueArrayTest;

class QueueArrayTest: public testing::Test{

public:

	QueueArray<int>* q = new QueueArray<int>;
	QueueArrayTest(){

		q->push(1);
		q->push(2);
		q->push(3);
		q->push(4);
		q->push(5);
		q->push(6);
		q->push(7);
	}
	~QueueArrayTest(){
		delete q;
	}
};


TEST_F(QueueArrayTest, isEmpty){
	auto tmp = new QueueArray<int>;
	ASSERT_TRUE(tmp->isEmpty());
	ASSERT_FALSE(q->isEmpty());
	delete tmp;
}
TEST_F(QueueArrayTest, Push){}

TEST_F(QueueArrayTest, Top){
	ASSERT_EQ(q->top(),1);
}

TEST_F(QueueArrayTest, Pop){
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

	QueueArray<int>* q = new QueueArray<int>;


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
	PrintList::printQueueArray(q);
	delete(q);
 *
 *
 * */