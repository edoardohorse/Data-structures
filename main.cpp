#include "ListArray.h"
#include "ListCursor.h"
#include "PrettyPrintList.h"
#include <cstdlib>



int main() {

//    ListArray<int,10>* ls = new ListArray<int, 10>;
    ListArray<int, 10>* ls = new ListArray<int, 10>;
    ls->insert(0,17);
    ls->insert(1,20);
    ls->insert(2,3);
    ls->insert(3,30);
    ls->insert(1,70);
    ls->remove(2);

    PrintList::printListArray(ls,4);
    delete ls;

    return 0;
/*
	auto L = new ListCursor<char>();
	auto M = new ListCursor<char>();
	auto S = new ListCursor<char>();

    Position p = L->first();

    L->insert(p,'a');
    p = L->next(p);
    L->insert(p,'b');
    p = L->next(p);
    L->insert(p,'c');
    p = L->next(p);
    L->insert(p,'d');
    p = L->next(p);
    L->insert(p,'e');
    p = L->next(p);
    L->insert(p,'f');
    p = L->next(p);
    L->insert(p,'g');
    p = L->next(p);
    L->insert(p,'h');
    p = L->next(p);
    L->insert(p,'i');
    p = L->next(p);
    L->insert(p,'l');
    p = L->next(p);
    L->insert(p,'m');


    PrintList::printListCursor(L);



	delete L,S,M;


	std::cout << std::endl;
    system("pause");
	return 0;

 */
}



