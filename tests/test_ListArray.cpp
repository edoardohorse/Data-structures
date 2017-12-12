#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ListArray_for_test.h"
//#include "../PrettyPrintList.h"

using testing::Eq;
using namespace NListArrayTest;


class ClassDeclaration: public testing::Test{
public:


	ListArray<int, 10>* ls = new ListArray<int, 10>;
	ListArray<int, 10>* ls2 = new ListArray<int, 10>;
	ClassDeclaration(){

		// first method of insertion (LIFO)
		Position p = ls->first();          // ╔═    ═╗
		ls->insert(p,17);                  // ║   70 ║
		ls->insert(p,20);                  // ║   30 ║
		ls->insert(p,3);                   // ║    3 ║
		ls->insert(p,30);                  // ║   20 ║
		ls->insert(p,70);                  // ║   17 ║
											// ╚═    ═╝


		// second method of insertion (FIFO)        // ╔═    ═╗
		p = ls2->first();ls2->insert(p,6);        // ║    6 ║
		p = ls2->next(p);ls2->insert(p,99);       // ║   99 ║
		p = ls2->next(p);ls2->insert(p,16874);    // ║16874 ║
		p = ls2->next(p);ls2->insert(p,1);        // ║    1 ║
		p = ls2->next(p);ls2->insert(p,468);      // ║  468 ║
													// ╚═    ═╝

//		PrintList::printListArray(ls,5);
//		std::cout << std::endl;
//		PrintList::printListArray(ls2,5);

	}

	~ClassDeclaration(){
		delete ls,ls2;
	}
};

TEST_F(ClassDeclaration, Empty){
	ASSERT_EQ(ls->isEmpty(), false );
}

TEST_F(ClassDeclaration, First){
	ASSERT_EQ(ls->first(),1);
	ASSERT_EQ(ls2->first(),1);
}

TEST_F(ClassDeclaration, Last){
	Position p = ls->first();
	ASSERT_FALSE(ls->isLast(p));
	ASSERT_TRUE(ls->isLast(5));

}

TEST_F(ClassDeclaration, Next){
	Position p = ls->first();
	int tmp = ls->get(ls->next(p));
	Position next = ls->next(p);

	ASSERT_EQ(ls->next(p), next);
	ASSERT_EQ(tmp, ls->get( next ));
}

TEST_F(ClassDeclaration, Previous){
	Position p = ls->first();
	int tmp = ls->get(p);
	Position next = ls->next(p);

	ASSERT_EQ(p, ls->previous(next));
	ASSERT_EQ(tmp, ls->get( ls->previous(next) ));
}

TEST_F(ClassDeclaration, Get){
	Position p = ls->first();

	ASSERT_EQ(ls->get(p),70);
	p = ls->next(p);

	ASSERT_EQ(ls->get(p),30);
	p = ls->next(p);

	ASSERT_EQ(ls->get(p),3);
	p = ls->next(p);

	ASSERT_EQ(ls->get(p),20);
	p = ls->next(p);

	ASSERT_EQ(ls->get(p),17);
	p = ls->next(p);
}
TEST_F(ClassDeclaration, Get_2){
	Position p = ls2->first();
	ASSERT_EQ(ls2->get(p),6);

	p = ls2->next(p);
	ASSERT_EQ(ls2->get(p),99);

	p = ls2->next(p);
	ASSERT_EQ(ls2->get(p),16874);

	p = ls2->next(p);
	ASSERT_EQ(ls2->get(p),1);

	p = ls2->next(p);
	ASSERT_EQ(ls2->get(p),468);


}

TEST_F(ClassDeclaration, Set){

	auto cp = *ls;
	Position p = cp.first();
	cp.set(p,100);
	ASSERT_EQ(cp.get(p),100);

	p = cp.previous(p);
	cp.set(p,6);
	ASSERT_EQ(cp.get(p),6);

	p = cp.previous(p);
	cp.set(p,1500);
	ASSERT_EQ(cp.get(p),1500);

	p = cp.previous(p);
	cp.set(p,48);
	ASSERT_EQ(cp.get(p),48);

	p = cp.previous(p);
	cp.set(p,76);
	ASSERT_EQ(cp.get(p),76);

}

TEST_F(ClassDeclaration, Insert){
	auto cp = *ls;

	Position p = cp.first();
	p = cp.next(p);
	p = cp.next(p);

	cp.insert(p,3589);

	p = cp.first();
	ASSERT_EQ(cp.get(p),70);
	p = cp.next(p);

	ASSERT_EQ(cp.get(p),30);
	p = cp.next(p);

	ASSERT_EQ(cp.get(p),3589);
	p = cp.next(p);

	ASSERT_EQ(cp.get(p),3);
	p = cp.next(p);

	ASSERT_EQ(cp.get(p),20);
	p = cp.next(p);

	ASSERT_EQ(cp.get(p),17);
	p = cp.next(p);

	ASSERT_EQ(cp.get(4),3);
}

TEST_F(ClassDeclaration, Remove){
	auto cp = *ls2;

	Position p = cp.first();
	p = cp.next(p);
	p = cp.next(p);

	cp.remove(p);

	p = cp.first();
	ASSERT_EQ(cp.get(p),6);

	p = cp.next(p);
	ASSERT_EQ(cp.get(p),99);

//	p = cp.next(p);
//	ASSERT_EQ(cp.get(p),16874);     // Suppose to be the third

	p = cp.next(p);
	ASSERT_EQ(cp.get(p),1);

	p = cp.next(p);
	ASSERT_EQ(cp.get(p),468);


	ASSERT_EQ(cp.get(3),1);
	ASSERT_EQ(cp.get(4),468);


}
