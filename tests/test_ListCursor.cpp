#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ListCursor_for_test.h"

using testing::Eq;
using namespace NListCursorTest;

class ListCursorTest: public testing::Test{
public:

	ListCursor<int>* ls = new ListCursor<int>;
	ListCursor<char>* ls2 = new ListCursor<char>;

    ListCursorTest(){
	    Position p = ls->first();

	    // LIFO
	    ls->insert(p, 1);
	    ls->insert(p, 2);
	    ls->insert(p, 3);
	    ls->insert(p, 4);
	    ls->insert(p, 5);
	    ls->insert(p, 6);

	    // FIFO
	    p = ls2->first(); ls2->insert(p,'a');
	    p = ls2->next(p); ls2->insert(p,'b');
	    p = ls2->next(p); ls2->insert(p,'c');
	    p = ls2->next(p); ls2->insert(p,'d');
	    p = ls2->next(p); ls2->insert(p,'e');
    }
    ~ListCursorTest(){
	    delete ls,ls2;
    }
};

TEST_F(ListCursorTest, Empty){
	auto tmp = new ListCursor<int>;
	ASSERT_TRUE(tmp->isEmpty());
	ASSERT_FALSE(ls->isEmpty());
	delete tmp;
}

TEST_F(ListCursorTest, First){
	ASSERT_EQ(ls->get(ls->first()),6);
	ASSERT_EQ(ls2->get(ls2->first()),'a');
}

TEST_F(ListCursorTest, Last){
	Position p = ls->first();
	while(!ls->isLast(p)){
		p = ls->next(p);
	}
	ASSERT_EQ(ls->next(p),ls->first());

	p = ls2->first();
	while(!ls2->isLast(p)){
		p = ls2->next(p);
	}
	ASSERT_EQ(ls->next(p),ls->first());
}

TEST_F(ListCursorTest, Next){
	Position p = ls->first();
	p = ls->next(p);
	p = ls->next(p);
	ASSERT_EQ(ls->get(p),4);

	p = ls2->first();
	p = ls2->next(p); p = ls2->next(p);
	p = ls2->next(p);
	ASSERT_EQ(ls2->get(p),'d');
}

TEST_F(ListCursorTest, Get){
	Position p;
	p = ls->first(); ASSERT_EQ(ls->get(p),6);
	p = ls->next(p); ASSERT_EQ(ls->get(p),5);
	p = ls->next(p); ASSERT_EQ(ls->get(p),4);
	p = ls->next(p); ASSERT_EQ(ls->get(p),3);
	p = ls->next(p); ASSERT_EQ(ls->get(p),2);
	p = ls->next(p); ASSERT_EQ(ls->get(p),1);

	p = ls2->first(); ASSERT_EQ(ls2->get(p),'a');
	p = ls2->next(p); ASSERT_EQ(ls2->get(p),'b');
	p = ls2->next(p); ASSERT_EQ(ls2->get(p),'c');
	p = ls2->next(p); ASSERT_EQ(ls2->get(p),'d');
	p = ls2->next(p); ASSERT_EQ(ls2->get(p),'e');

}

TEST_F(ListCursorTest, Set){
	Position p = ls->first();
	ASSERT_EQ(ls->get(p),6);
	ls->set(p,76);
	ASSERT_EQ(ls->get(p),76);
	ls->set(p,6);
	ASSERT_EQ(ls->get(p),6);
}

TEST_F(ListCursorTest, Insert){}

TEST_F(ListCursorTest, Remove){
	// LIFO
	Position p = ls->first();
	p = ls->next(p);
	p = ls->next(p);
	ASSERT_EQ(ls->get(p),4);
	ASSERT_EQ(ls->get(ls->next(p)),3);

	ls->remove(p);                              // Remove 3
	ASSERT_EQ(ls->get(p),3);
	ASSERT_EQ(ls->get(ls->next(p)),2);
	p = ls->previous(p);
	ls->insert(p,4);

	p = ls->first(); ASSERT_EQ(ls->get(p),6);
	p = ls->next(p); ASSERT_EQ(ls->get(p),5);
	p = ls->next(p); ASSERT_EQ(ls->get(p),4);
	p = ls->next(p); ASSERT_EQ(ls->get(p),3);
	p = ls->next(p); ASSERT_EQ(ls->get(p),2);
	p = ls->next(p); ASSERT_EQ(ls->get(p),1);

	// FIFO

	p = ls2->first();
	p = ls2->next(p);
	p = ls2->next(p);
	ASSERT_EQ(ls2->get(p), 'c');
	ASSERT_EQ(ls2->get(ls2->next(p)), 'd');

	ls2->remove(p);
	ASSERT_EQ(ls2->get(p), 'd');
	ASSERT_EQ(ls2->get(ls2->next(p)), 'e');
	p = ls2->previous(p);
	ls2->insert(p,'c');


	p = ls2->first(); ASSERT_EQ(ls2->get(p),'a');
	p = ls2->next(p); ASSERT_EQ(ls2->get(p),'b');
	p = ls2->next(p); ASSERT_EQ(ls2->get(p),'c');
	p = ls2->next(p); ASSERT_EQ(ls2->get(p),'d');
	p = ls2->next(p); ASSERT_EQ(ls2->get(p),'e');

}

TEST_F(ListCursorTest, Previous){
	Position p = ls->first();
	p = ls->next(p);
	p = ls->next(p);
	p = ls->next(p);
	ASSERT_EQ(ls->get(p), 3);
}

