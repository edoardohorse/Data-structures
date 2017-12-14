#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>
#include "ListCursor_for_test.h"
#include "PrettyPrintList_for_test.h"

#define DEBUG_
using namespace NListCursorTest;

int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc,argv);
	RUN_ALL_TESTS();



//	system("pause");
	return 0;
}