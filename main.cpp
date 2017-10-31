#include <iostream>
#include "ListArray.h"
#include "PrettyPrintList.h"



int main() {


	auto* ls = new ListArray<int, 10>;
	ls->insert(0,17);
	ls->insert(1,20);
	ls->insert(2,3);
	ls->insert(3,30);

	ls->insert(1,70);
	ls->remove(2);

	PrintList::printListArray(*ls,4);
	delete ls;
	return 0;
}