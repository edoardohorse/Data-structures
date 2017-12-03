#include "ListArray_full.h"
//#include "ListCursor.h"
#include "PrettyPrintList.h"
#include <cstdlib>



int main() {


    auto* ls = new ListArray<int, 10>;
    ListArray::Position p = ls->first();
    ls->insert(p,17); p = ls->next(p);
    ls->insert(p,20); p = ls->next(p);
    ls->insert(p,3); p = ls->next(p);
    ls->insert(p,30);

    p = ls->previous(p);
    p = ls->previous(p);
    ls->insert(p,70);

    p = ls->next(p);
    ls->remove(p);

    PrintList::printListArray(ls,4);
    delete ls;



    std::cout << std::endl;
    system("pause");
	return 0;


}



