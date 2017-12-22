#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>

#include "PrettyPrintList_for_test.h"

#define DEBUG_

#include "Map_for_test.h"
using namespace NMapTest;



int main(int argc, char* argv[]){
	testing::InitGoogleTest(&argc,argv);
	RUN_ALL_TESTS();

//	auto m = new Map<std::string, int>;


//	system("pause");
	return 0;
}