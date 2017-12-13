#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "ListArray_for_test.h"
#include "ListCursor_for_test.h"
#include "ListPointer_for_test.h"
#include "ListDoublePointer_for_test.h"
#include "ListCircular_for_test.h"

#define WIDTH(x) std::setw(x)

namespace PrintList{

	// Pretty print of list
	template <typename TypeElem, int Length>
	void printListArray(const NListArrayTest::ListArray<TypeElem, Length>* list, int widthBuffer = 3){
		NListArrayTest::Position i=list->first();

		std::cout << std::endl;
		std::cout << (char)201 << (char)205 << WIDTH(widthBuffer);  // ╔═
		std::cout << (char)205 << (char)187;                        // ═╗
		std::cout << std::endl;

		do{
			std::cout << (char)186;                                 // ║
			std::cout << WIDTH(widthBuffer) << list->get(i) << " ";
			std::cout << (char)186;                                 // ║
			std::cout << std::endl;

		}while(!list->isLast(i++));

		std::cout << (char)200 << (char)205 << WIDTH(widthBuffer);  // ╚═
		std::cout << (char)205 << (char)188;                        // ═╝
	}

	// Pretty print of list
	template <typename TypeElem>
	void printListCursor(const NListCursorTest::ListCursor<TypeElem>* list, int widthBuffer = 3) {
		NListCursorTest::Position i=list->first();


		std::cout << std::endl;
		std::cout << (char)201 << (char)205 << WIDTH(widthBuffer);  // ╔═
		std::cout << std::string(7, (char)205);
		std::cout << (char)205 << (char)187;                        // ═╗
		std::cout << std::endl;

		do{
			std::cout << WIDTH(2) << i;
			std::cout << (char)186;                                 // ║
			std::cout << WIDTH(widthBuffer) << list->get(i) << " ";
			std::cout << (char)124 ;                        // |
			std::cout << WIDTH(widthBuffer) << list->next(i) << " ";
			std::cout << (char)186;                                 // ║
			std::cout << std::endl;


		}while(!list->isLast(i++));
		std::cout << "  ";
		std::cout << (char)200 << (char)205 << WIDTH(widthBuffer);  // ╚═
		std::cout << std::string(7, (char)205);
		std::cout << (char)205 << (char)188;                        // ═╝

		std::cout << std::endl;
	}

	template<typename TypeElem>
	void printListPointer(const NListPointerTest::ListPointer<TypeElem>* list, int widthBuffer = 8){
		NListPointerTest::Position<TypeElem> i=list->first();


		std::string cornerLeftTop(1,(char)201);
		cornerLeftTop.append(1,(char)205);

		std::string cornerRightTop(1,(char)205);
		cornerLeftTop.append(1,(char)187);

		std::string cornerLeftBottom(1,(char)200);
		cornerLeftTop.append(1,(char)205);

		std::string cornerRightBottom(1,(char)205);
		cornerLeftTop.append(1,(char)188);

		std::string toPrint;
		std::ostringstream strStream;
		std::ostringstream::streampos posFirstLine;
		std::ostringstream::streampos posLastLine;
		std::ostringstream::streampos pos;
		std::ostringstream::streampos delta;


		posFirstLine = strStream.tellp();
		long long int max = 0;



		do{
			pos = strStream.tellp();
			strStream << WIDTH(2) << i;
			strStream << (char)186;                                 // ║
			strStream <<  list->get(i) << " ";      //"${|}" <<
			strStream << (char)124 ;                        // |
			strStream << list->next(i) << " ";
			strStream << (char)186;                                 // ║
			strStream << std::endl;

			delta = strStream.tellp();
			delta -= sizeof(&i);
			if(max < (delta-pos))
				max = delta-pos;





		}while(!list->isLast(i = list->next(i)));

		posLastLine = strStream.tellp();

		strStream.seekp(posFirstLine);
		strStream << std::string((size_t)max, (char)205) << std::endl << strStream.str();

		strStream.seekp(posLastLine+max+1);
		strStream << std::string((size_t)max, (char) 205);

		/*toPrint = strStream.str() + "\n";
		strStream.seekp(0);
		std::size_t last = toPrint.rfind("${|}");
		std::size_t found = 0;
		while ( found != last ){
			found = toPrint.find("${|}" ,found+1);
			strStream.seekp(found);
			strStream << "c" << strStream.str();

			//toPrint.replace(found,4, std::setw));
		}*/
		toPrint = strStream.str();
		std::cout << toPrint;

	}

	template<typename TypeElem>
	void printListDoublePointer(const NListDoublePointerTest::ListDoublePointer<TypeElem>* list, int widthBuffer = 10){
		NListDoublePointerTest::Position<TypeElem> i=list->first();


		std::string cornerLeftTop(1,(char)201);
		cornerLeftTop.append(1,(char)205);

		std::string cornerRightTop(1,(char)205);
		cornerLeftTop.append(1,(char)187);

		std::string cornerLeftBottom(1,(char)200);
		cornerLeftTop.append(1,(char)205);

		std::string cornerRightBottom(1,(char)205);
		cornerLeftTop.append(1,(char)188);

		std::string toPrint;
		std::ostringstream strStream;
		std::ostringstream::streampos posFirstLine;
		std::ostringstream::streampos posLastLine;
		std::ostringstream::streampos pos;
		std::ostringstream::streampos delta;


		posFirstLine = strStream.tellp();
		long long int max = 0;



		do{
			pos = strStream.tellp();
			strStream << WIDTH(2) << i;
			strStream << (char)186;                                 // ║
			strStream << WIDTH(widthBuffer) << list->get(i) << " ";
			strStream << (char)124 ;                        // |
			strStream << WIDTH(widthBuffer) << list->next(i) << " ";
			strStream << (char)186;                                 // ║
			strStream << WIDTH(widthBuffer) << list->previous(i) << " ";
			strStream << std::endl;

			delta = strStream.tellp();
			delta -= sizeof(&i);
			if(max < (delta-pos))
				max = delta-pos;





		}while(!list->isLast(i = list->next(i)));

		posLastLine = strStream.tellp();

		strStream.seekp(posFirstLine);
		strStream << std::string((size_t)max, (char)205) << std::endl << strStream.str();

		strStream.seekp(posLastLine+max+1);
		strStream << std::string((size_t)max, (char) 205);

		toPrint = strStream.str() + "\n";
		/*
		strStream.seekp(0);
		std::size_t last = toPrint.rfind("${|}");
		std::size_t found = 0;
		while ( found != last ){
			found = toPrint.find("${|}" ,found+1);
			strStream.seekp(found);
			strStream << "c" << strStream.str();

			//toPrint.replace(found,4, std::setw));
		}
		toPrint = strStream.str();
		 */
		std::cout << toPrint;
	}

	template<typename TypeElem>
	void printListCircular(const NListCircularTest::ListCircular<TypeElem>* list, int widthBuffer = 10){
		NListCircularTest::Position<TypeElem> i=list->first();


		std::string cornerLeftTop(1,(char)201);
		cornerLeftTop.append(1,(char)205);

		std::string cornerRightTop(1,(char)205);
		cornerLeftTop.append(1,(char)187);

		std::string cornerLeftBottom(1,(char)200);
		cornerLeftTop.append(1,(char)205);

		std::string cornerRightBottom(1,(char)205);
		cornerLeftTop.append(1,(char)188);

		std::string toPrint;
		std::ostringstream strStream;
		std::ostringstream::streampos posFirstLine;
		std::ostringstream::streampos posLastLine;
		std::ostringstream::streampos pos;
		std::ostringstream::streampos delta;


		posFirstLine = strStream.tellp();
		long long int max = 0;



		do{

			pos = strStream.tellp();
			strStream << WIDTH(2) << i;
			strStream << (char)186;                                 // ║
			strStream << WIDTH(widthBuffer) << list->get(i) << " ";
			strStream << (char)124 ;                        // |
			strStream << WIDTH(widthBuffer) << list->next(i) << " ";
			strStream << (char)186;                                 // ║
			strStream << WIDTH(widthBuffer) << list->previous(i) << " ";
			strStream << std::endl;

			delta = strStream.tellp();
			delta -= sizeof(&i);
			if(max < (delta-pos))
				max = delta-pos;





		}while(!list->isLast(i = list->next(i)));

		posLastLine = strStream.tellp();

		strStream.seekp(posFirstLine);
		strStream << std::string((size_t)max, (char)205) << std::endl << strStream.str();

		strStream.seekp(posLastLine+max+1);
		strStream << std::string((size_t)max, (char) 205);

		toPrint = strStream.str() + "\n";
		/*
		strStream.seekp(0);
		std::size_t last = toPrint.rfind("${|}");
		std::size_t found = 0;
		while ( found != last ){
			found = toPrint.find("${|}" ,found+1);
			strStream.seekp(found);
			strStream << "c" << strStream.str();

			//toPrint.replace(found,4, std::setw));
		}
		toPrint = strStream.str();
		 */
		std::cout << toPrint;
	}
}

