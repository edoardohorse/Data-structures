#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "ListArray.h"
#include "ListCursor.h"
#include "ListPointer.h"
#include "ListDoublePointer.h"
#include "ListCircular.h"

#define WIDTH(x) std::setw(x)

namespace PrintList{

	// Pretty print of list
	template <typename TypeElem, int Length>
	void printListArray(const NListArray::ListArray<TypeElem, Length>* list, int widthBuffer = 3){
		NListArray::Position i=list->first();

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
	void printListCursor(const NListCursor::ListCursor<TypeElem>* list, int widthBuffer = 3) {
		NListCursor::Position i=list->first();


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
	void printListPointer(const NListPointer::ListPointer<TypeElem>* list, int widthBuffer = 8){
		NListPointer::Position<TypeElem> i=list->first();


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
	void printListDoublePointer(const NListDoublePointer::ListDoublePointer<TypeElem>* list, int widthBuffer = 10){
		NListDoublePointer::Position<TypeElem> i=list->first();


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
	void printListCircular(const NListCircular::ListCircular<TypeElem>* list, int widthBuffer = 10){
		NListCircular::Position<TypeElem> i=list->first();


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

/*

enum class Thickness{
	Thin,Thick,NoDefault
};

typedef char Border;

template <typename Type>
class TableCell{
private:
	int length = 0;
	Thickness borderType;
	Border border[6];
	std::string stringToPrint = "";

	void init(){

		switch (borderType){
			case Thickness::Thick: {
				border[0] = (char) 201;
				border[1] = (char) 187;
				border[2] = (char) 200;
				border[3] = (char) 188;

				border[4] = (char) 205;
				border[5] = (char) 186;
				break;
			};
			case Thickness::Thin:{
				border[0] = (char) 218;
				border[1] = (char) 191;
				border[2] = (char) 192;
				border[3] = (char) 217;

				border[4] = (char) 196;
				border[5] = (char) 124;

			};
		}


	}

public:
	Type value;

	bool newLine = false;

	TableCell(){
	}

	TableCell(Thickness b, Type value, bool nL = false){
		borderType = b;
		value = value;

		newLine = nL;
		init();

	}

	TableCell(Border b[], Type value, bool nL = false){
		borderType = Thickness::NoDefault;

		border[0] = b[0];
		border[1] = b[1];
		border[2] = b[2];
		border[3] = b[3];
		border[4] = b[4];
		border[5] = b[5];

		newLine = nL;

		init();

	}

	int getLength(){
		return length;
	}

	void setLength(int length){
		length = length;
	}

	friend std::ostream& operator<<( std::ostream &output, TableCell& tb ) {
		std::stringstream buffer;


		if(tb.newLine)
			std::cout << std::endl;
		std::string str = std::to_string(tb.value);
		int length = (int) str.length();
		tb.setLength(length);

		buffer << tb.border[0];
		buffer << std::string(tb.getLength(), tb.border[4]);
		buffer << tb.border[1];
		std::cout << std::endl;

		buffer << tb.border[5];
		buffer << WIDTH(tb.getLength()) << str;
		buffer << tb.border[5];

		std::cout << std::endl;
		buffer << tb.border[2];
		buffer << std::string(tb.getLength(), tb.border[4]);
		buffer << tb.border[3];

		tb.stringToPrint = buffer.str();
		output << tb.stringToPrint;

		return output;
	}

	void setBorder(Thickness b){
		this->borderType = b;

		init();
	}



};

template <typename TypeElem>
class Table{
public:

	typedef int Dimension;
	Dimension dim[2];
	TableCell<TypeElem>** grid;

	Table(Dimension x, Dimension y,Thickness border){
		dim[0] = x;
		dim[1] = y;

		grid = new TableCell<TypeElem>*[y];

		for(int i=0; i< x; i++){

			grid[i] = new TableCell<TypeElem>[x];

			for(int c=0;c<x;c++){
				grid[i][c].setBorder(border);
				grid[i][c].newLine = false;
			}

		}

	}

	friend std::ostream& operator<<(std::ostream& output, const Table& tb) {

		for(int i=0;i< tb.dim[1];i++){
			for(int c=0;c< tb.dim[0];c++) {
				output << tb.grid[i][c];
			}
			output << std::endl;
		}


		return output;
	}

};*/
