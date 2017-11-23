#include <iostream>
#include "ListArray.h"
#include "ListCursor.h"
#include "PrettyPrintList.h"




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




//	TableCell<int> p = TableCell<int>(Thickness::Thick, 8, true);
//	p.value = a[0][0];
//	std::cout << p;
//	p.value = a[0][1];
//	std::cout << p;
//	p.value = a[1][0];
//	std::cout << p;
//	p.value = a[1][1];
//	std::cout << p;


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

	auto ls = new ListCursor<char, 10>();
	Position p = ls->first();
	ls->insert(p,'3');
	p = ls->next(p);
	ls->set(p,'6');
	p = ls->next(p);
	ls->set(p,'9');
//	ls->insert(p,'6');
//	p = ls->next(p);
//	ls->insert(p,'9');

//	p= ls->next(p);
//	ls->insert(p,'6');

	ls->print();

	delete ls;


//	getchar();
	return 0;
}



