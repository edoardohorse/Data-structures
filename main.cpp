#include "ListArray.h"
//#include "ListCursor.h"
#include "PrettyPrintList.h"
#include <cstdlib>



int main() {


    auto ls = new NListCursor::ListCursor<char>();
    NListCursor::Position p = ls->first();

    ls->insert(p,'a');
    p = ls->next(p);
    ls->insert(p,'b');
    p = ls->next(p);
    ls->insert(p,'c');
    p = ls->next(p);
    ls->insert(p,'d');
    p = ls->next(p);


    ls->remove(p);
    PrintList::printListCursor(ls);



    delete ls;



    std::cout << std::endl;
    system("pause");
	return 0;


}



