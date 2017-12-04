
#include "PrettyPrintList.h"
#include <cstdlib>
#include <stdio.h>
#include "ListPointer.h"

using namespace NListPointer;
int main(){

	ListPointer<std::string>* ls  = new ListPointer<std::string>;
	Position<std::string> p = ls->first();


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

	PrintList::printListPointer(ls);

	system("pause");
    return 0;
}




