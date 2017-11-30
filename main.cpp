#include "ListArray.h"
#include "ListCursor.h"
#include "PrettyPrintList.h"
#include <cstdlib>



int main() {
/* 


	int** a;
	a = new int*[2];
	for(int i=0;i<2;i++)
		a[i] = new int[2];

	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;




 	TableCell<int> p = TableCell<int>(Thickness::Thick, 8, true);
	p.value = a[0][0];
	std::cout << p;
	p.value = a[0][1];
	std::cout << p;
	p.value = a[1][0];
	std::cout << p;
	p.value = a[1][1];
	std::cout << p; 



	auto tbl = new Table<int>(2,2, Thickness::Thin);
	tbl->grid[0][0].value = 1;
//	tbl->grid[0][0].setBorder(Thickness::Thin);
	tbl->grid[0][1].value = 2;
	tbl->grid[1][0].value = 3;
	tbl->grid[1][1].value = 4;
	std::cout << *tbl;
//	p.value = 52310;
//	std::cout << p;

	delete(tbl);
	delete(a);
*/

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
}



