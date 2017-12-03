#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../ListArray.h"
#include "../PrettyPrintList.h"

using testing::Eq;
using namespace NListArray;


class ClassDeclaration: public testing::Test{
public:


	ListArray<int, 10>* obj = new ListArray<int, 10>;
	ListArray<int, 10>* obj2 = new ListArray<int, 10>;
	ClassDeclaration(){

		// first method of insertion (LIFO)
		Position p = obj->first();          // ╔═    ═╗
		obj->insert(p,17);                  // ║   70 ║
		obj->insert(p,20);                  // ║   30 ║
		obj->insert(p,3);                   // ║    3 ║
		obj->insert(p,30);                  // ║   20 ║
		obj->insert(p,70);                  // ║   17 ║
											// ╚═    ═╝


		// second method of insertion (FIFO)        // ╔═    ═╗
		p = obj2->first();obj2->insert(p,6);        // ║    6 ║
		p = obj2->next(p);obj2->insert(p,99);       // ║   99 ║
		p = obj2->next(p);obj2->insert(p,16874);    // ║16874 ║
		p = obj2->next(p);obj2->insert(p,1);        // ║    1 ║
		p = obj2->next(p);obj2->insert(p,468);      // ║  468 ║
													// ╚═    ═╝

//		PrintList::printListArray(obj,5);
//		std::cout << std::endl;
//		PrintList::printListArray(obj2,5);

	}

	~ClassDeclaration(){
		delete obj,obj2;
	}
};

TEST_F(ClassDeclaration, Empty){
	ASSERT_EQ(obj->isEmpty(), false );
}

TEST_F(ClassDeclaration, First){
	ASSERT_EQ(obj->first(),1);
	ASSERT_EQ(obj2->first(),1);
}

TEST_F(ClassDeclaration, Last){
	Position p = obj->first();
	ASSERT_FALSE(obj->isLast(p));
	ASSERT_TRUE(obj->isLast(5));

}

TEST_F(ClassDeclaration, Next){
	Position p = obj->first();
	int tmp = obj->get(obj->next(p));
	Position next = obj->next(p);

	ASSERT_EQ(obj->next(p), next);
	ASSERT_EQ(tmp, obj->get( next ));
}

TEST_F(ClassDeclaration, Previous){
	Position p = obj->first();
	int tmp = obj->get(p);
	Position next = obj->next(p);

	ASSERT_EQ(p, obj->previous(next));
	ASSERT_EQ(tmp, obj->get( obj->previous(next) ));
}

TEST_F(ClassDeclaration, Get){
	Position p = obj->first();

	ASSERT_EQ(obj->get(p),70);
	p = obj->next(p);

	ASSERT_EQ(obj->get(p),30);
	p = obj->next(p);

	ASSERT_EQ(obj->get(p),3);
	p = obj->next(p);

	ASSERT_EQ(obj->get(p),20);
	p = obj->next(p);

	ASSERT_EQ(obj->get(p),17);
	p = obj->next(p);
}
TEST_F(ClassDeclaration, Get_2){
	Position p = obj2->first();
	ASSERT_EQ(obj2->get(p),6);

	p = obj2->next(p);
	ASSERT_EQ(obj2->get(p),99);

	p = obj2->next(p);
	ASSERT_EQ(obj2->get(p),16874);

	p = obj2->next(p);
	ASSERT_EQ(obj2->get(p),1);

	p = obj2->next(p);
	ASSERT_EQ(obj2->get(p),468);


}

TEST_F(ClassDeclaration, Set){

	auto cp = *obj;
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
	auto cp = *obj;

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
	auto cp = *obj2;

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
