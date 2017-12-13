#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ListCircular_for_test.h"


using testing::Eq;
using namespace NListCircularTest;

class ListCircularTest: public testing::Test{
public:
	
	
	ListCircular<std::string>* ls = new ListCircular<std::string>;
	ListCircular<int>* ls2 = new ListCircular<int>;
	ListCircularTest(){

		auto p = ls->first();
		auto p2 = ls2->first();

		ls->insert(p,"abecedario");
		ls->insert(p,"aperitivo");
		ls->insert(p,"bambola");
		ls->insert(p,"barattolo");
		ls->insert(p,"casale");
		ls->insert(p,"castoro");
		ls->insert(p,"luna");
		ls->insert(p,"tornio");
		ls->insert(p,"paese");


		ls2->insert(p2,1);
		p2 = ls2->next(p2);
		ls2->insert(p2,2);
		p2 = ls2->next(p2);
		ls2->insert(p2,3);
		p2 = ls2->next(p2);
		ls2->insert(p2,4);
		p2 = ls2->next(p2);
		ls2->insert(p2,5);
		p2 = ls2->next(p2);
		ls2->insert(p2,6);
		p2 = ls2->next(p2);
		ls2->insert(p2,7);


	}
	~ListCircularTest(){
		delete ls, ls2;
	}
};

TEST_F(ListCircularTest, Empty){
	auto tmp = new ListCircular<int>;
	ASSERT_TRUE(tmp->isEmpty());
	ASSERT_FALSE(ls->isEmpty());
	ASSERT_FALSE(ls2->isEmpty());
}

TEST_F(ListCircularTest, First){
	ListCircular<int>* tmp = new ListCircular<int>;
	ASSERT_EQ(tmp->first(), tmp->next(tmp->first()));
	delete tmp;
}

TEST_F(ListCircularTest, Last){
	Position<int> p2 = ls2->first();
	while(!ls2->isLast(p2))
		p2 = ls2->next(p2);

	ASSERT_TRUE(ls2->isLast(p2));
	ASSERT_EQ(ls2->get(p2),7);

	Position<std::string> p = ls->first();
	while(!ls->isLast(p))
		p = ls->next(p);
	ASSERT_TRUE(ls->isLast(p));
	ASSERT_EQ(ls->get(p),"abecedario");
}

TEST_F(ListCircularTest, Next){
	// LIFO
	auto p = ls->first();
	ASSERT_EQ(ls->get(p),"paese");
	p = ls->next(p);p = ls->next(p);
	ASSERT_EQ(ls->get(p),"luna");

	// FIFO
	auto p2 = ls2->first();
	ASSERT_EQ(ls2->get(p2),1);
	p2 = ls2->next(p2);
	ASSERT_EQ(ls2->get(p2),2);

}

TEST_F(ListCircularTest, Get){

	Position<std::string> p = ls->first();
	ASSERT_EQ(ls->get(p),"paese");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"tornio");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"luna");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"castoro");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"casale");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"barattolo");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"bambola");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"aperitivo");
	p = ls->next(p); ASSERT_EQ(ls->get(p),"abecedario");



	// FIFO
	Position<int> p2;
	p2 = ls2->first();  ASSERT_EQ(ls2->get(p2),1);
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),2);
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),3);
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),4);
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),5);
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),6);
	p2 = ls2->next(p2); ASSERT_EQ(ls2->get(p2),7);

}

TEST_F(ListCircularTest, Set){
	Position<std::string> p = ls->first();
	ASSERT_EQ(ls->get(p),"paese");
	ls->set(p, "popolo");
	ASSERT_EQ(ls->get(p),"popolo");
	ls->set(p, "paese");
}

TEST_F(ListCircularTest, Insert){}

TEST_F(ListCircularTest, Remove){
	// LIFO

	Position<std::string> p = ls->first();
	p = ls->next(p);
	p = ls->next(p);

	ASSERT_EQ(ls->get(ls->next(p)),"castoro");
	ASSERT_EQ(ls->get(ls->previous(p)),"tornio");

	ls->remove(p);                                  // Remove "luna"
	ASSERT_EQ(ls->get(p),"castoro");
	ASSERT_EQ(ls->get(ls->previous(p)),"tornio");
	ls->insert(p,"luna");

	// FIFO
	Position<int> p2 = ls2->first();
	p2 = ls2->next(p2);
	p2 = ls2->next(p2);

	ASSERT_EQ(ls2->get(p2),3);
	ASSERT_EQ(ls2->get(ls2->previous(p2)),2);

	ls2->remove(p2);                                  // Remove '3'
	ASSERT_EQ(ls2->get(p2),4);
	ASSERT_EQ(ls2->get(ls2->previous(p2)),2);
	ls2->insert(p2,2);
}

TEST_F(ListCircularTest, Previous){
	// LIFO
	Position<std::string> p = ls->first();
	p = ls->next(p);
	p = ls->next(p);
	ASSERT_EQ(ls->get(ls->previous(p)), "tornio");

	// FIFO
	Position<int> p2 = ls2->first();
	p2 = ls2->next(p2);
	p2 = ls2->next(p2);
	ASSERT_EQ(ls2->get(ls2->previous(p2)), 2);
}