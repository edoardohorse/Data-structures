#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>


//#include "PrettyPrintList_for_test.h"
#include "ListPointer_for_test.h"



using testing::Eq;
using namespace NListPointerTest;


class ListCursorTest: public testing::Test{
public:

	ListPointer<std::string>* ls  = new ListPointer<std::string>;
	ListPointer<char>* ls2 = new ListPointer<char>;
	ListCursorTest(){
		Position<std::string> p = ls->first();
		Position<char> p2 = ls2->first();

		// first method insertion (LIFO)
		ls->insert(p,"abecedario");
		ls->insert(p,"aperitivo");
		ls->insert(p,"bambola");
		ls->insert(p,"barattolo");
		ls->insert(p,"casale");
		ls->insert(p,"castoro");
		ls->insert(p,"luna");
		ls->insert(p,"tornio");
		ls->insert(p,"paese");

//		PrintList::printListPointer(ls);

		// second method insertion (FIFO)
		p2 = ls2->first();
		ls2->insert(p2,'a');
		p2 = ls2->next(p2);
		ls2->insert(p2,'b');
		p2 = ls2->next(p2);
		ls2->insert(p2,'c');
		p2 = ls2->next(p2);
		ls2->insert(p2,'d');
		p2 = ls2->next(p2);
		ls2->insert(p2,'e');
		p2 = ls2->next(p2);
		ls2->insert(p2,'f');
		p2 = ls2->next(p2);
		ls2->insert(p2,'g');

//	    PrintList::printListPointer(ls2);
	}
	~ListCursorTest(){
		delete ls,ls2;
	}
};


TEST_F(ListCursorTest, Empty){
	ListPointer<int>* tmp = new ListPointer<int>;
	ASSERT_TRUE(tmp->isEmpty());
	ASSERT_FALSE(ls2->isEmpty());
	ASSERT_FALSE(ls->isEmpty());
	delete tmp;
}

TEST_F(ListCursorTest, First){
	ListPointer<int>* tmp = new ListPointer<int>;
	ASSERT_EQ(tmp->first(), nullptr);
	delete tmp;
}

TEST_F(ListCursorTest, Last){
	//	LIFO
	Position<char> p = ls2->first();
	while(!ls2->isLast(p))
		p = ls2->next(p);

	ASSERT_TRUE(ls2->isLast(p));
	ASSERT_TRUE(p == nullptr);

	//	FIFO

	Position<std::string> p2 = ls->first();
	while(!ls->isLast(p2))
		p2 = ls->next(p2);
	ASSERT_TRUE(ls->isLast(p2));
	ASSERT_TRUE(p == nullptr);

}

TEST_F(ListCursorTest, Next){
	// LIFO
	Position<std::string> p = ls->next(ls->first());
	ASSERT_EQ(ls->get(p), "tornio");


	// FIFO
	Position<char> p2 = ls2->next(ls2->first());
	ASSERT_EQ(ls2->get(p2), 'b');
}

TEST_F(ListCursorTest, Get){
	// LIFO
	Position<std::string> p;

	p = ls->first();ASSERT_EQ(ls->get(p),"paese");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"tornio");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"luna");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"castoro");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"casale");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"barattolo");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"bambola");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"aperitivo");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"abecedario");



	// FIFO
	Position<char> p2;
	p2 = ls2->first();  ASSERT_EQ(ls2->get(p2),'a');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'b');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'c');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'d');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'e');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'f');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'g');



}

TEST_F(ListCursorTest, Set){
	Position<std::string> p = ls->first();
	ASSERT_EQ(ls->get(p),"paese");
	ls->set(p, "popolo");
	ASSERT_EQ(ls->get(p),"popolo");
	ls->set(p, "paese");
}

TEST_F(ListCursorTest, Insert){

}


TEST_F(ListCursorTest, Remove){
	// LIFO
	Position<std::string> p = ls->first();
	p = ls->next(p);
	p = ls->next(p);

	ASSERT_EQ(ls->get(p),"luna");
	ASSERT_EQ(ls->get(ls->previous(p)),"tornio");

	ls->remove(p);                                  // Remove "luna"
	ASSERT_EQ(ls->get(p),"castoro");
	ASSERT_EQ(ls->get(ls->previous(p)),"tornio");
	ls->insert(p,"luna");

	p = ls->first();ASSERT_EQ(ls->get(p),"paese");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"tornio");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"luna");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"castoro");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"casale");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"barattolo");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"bambola");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"aperitivo");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"abecedario");


	// FIFO
	Position<char> p2 = ls2->first();
	p2 = ls2->next(p2);
	p2 = ls2->next(p2);

	ASSERT_EQ(ls2->get(p2),'c');
	ASSERT_EQ(ls2->get(ls2->previous(p2)),'b');

	ls2->remove(p2);                                  // Remove 'c'
	ASSERT_EQ(ls2->get(p2),'d');
	ASSERT_EQ(ls2->get(ls2->previous(p2)),'b');
	ls2->insert(p2, 'c');

	p2 = ls2->first();  ASSERT_EQ(ls2->get(p2),'a');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'b');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'c');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'d');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'e');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'f');
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),'g');


}

TEST_F(ListCursorTest, Previous){
	// LIFO
	Position<std::string> p = ls->first();
	p = ls->next(p);
	p = ls->next(p);
	ASSERT_EQ(ls->get(ls->previous(p)), "tornio");

	// FIFO
    ListPointer<char> tmp2 = *ls2;
    Position<char> p2 = tmp2.first();
	p2 = tmp2.next(p2);
	p2 = tmp2.next(p2);
	ASSERT_EQ(tmp2.get(tmp2.previous(p2)), 'b');
}

