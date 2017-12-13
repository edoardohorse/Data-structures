#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>
#include "StackArray_for_test.h"
#include "PrettyPrintList_for_test.h"

using namespace NStackArrayTest;

int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc,argv);
//	RUN_ALL_TESTS();


	StackArray<int>* stk = new StackArray<int>;

		stk->push(1);
		stk->push(2);
		stk->push(3);
		stk->push(4);
		stk->push(5);
		stk->push(6);
		stk->push(7);

	PrintList::printStackArray(stk);

	system("pause");
	return 0;
}