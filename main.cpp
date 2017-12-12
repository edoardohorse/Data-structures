
#include "PrettyPrintList.h"
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include "ListPointer.h"

using namespace NListPointer;
int main(){

	ListPointer<std::string>* ls  = new ListPointer<std::string>;
	Position<std::string> p = ls->first();


	// first method insertion (LIFO)
	ls->insert(p,"aaaaaaabecedario");
	ls->insert(p,"aperitivo");
	ls->insert(p,"bambola");
	ls->insert(p,"barattolo");
	ls->insert(p,"casale");
	ls->insert(p,"castoro");
	ls->insert(p,"luna");
	ls->insert(p,"tornio");
	ls->insert(p,"paese");


	PrintList::printListPointer(ls);


//	const char str[] = "Prova";
//	std::stringbuf bf;
//	std::ostream os(&bf);
//	bf.sputn(str, sizeof(str)-1);
//	std::cout << bf.str();

	/*std::string str  = "Prova";
	std::string str2 = "Prova2";
	std::string str3 = "blablablabla";
	std::string str4 = "Prova4";

	std::string v[4] = {str,str2,str3,str4};

	std::ostringstream strStream;
	std::ostringstream::streampos posFirstLine;
	std::ostringstream::streampos posLastLine;

	std::ostringstream::streampos pos;
	std::ostringstream::streampos delta;

	posFirstLine = strStream.tellp();
	long long int max = 0;

	int i=0;

	do {
		pos = strStream.tellp();
		strStream << v[i];
		delta = strStream.tellp();

		if(max < (delta-pos))
			max = delta-pos;

		i++;
	}while(i<4);

	posLastLine = strStream.tellp();

	strStream.seekp(posFirstLine);
	strStream << std::string(max,'_') << std::endl << strStream.str();

	strStream.seekp(posLastLine+max+1);
	strStream << std::endl << std::string(max,'_');




	std::cout << strStream.str();




	std::cout << std::endl;*/
//	system("pause");
	std::ostringstream a = std::setw(4);
	std::string t = ;

    return 0;
}




