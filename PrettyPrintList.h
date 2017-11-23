#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "ListArray.h"

#define WIDTH(x) std::setw(x)

namespace PrintList{

	// Pretty print of list
	template <typename TypeElem, int Length>
	void printListArray(ListArray<TypeElem, Length> list, int widthBuffer = 3) {
		int i;
		std::cout << (char)201 << (char)205 << WIDTH(widthBuffer);  // ╔═
		std::cout << (char)205 << (char)187;                        // ═╗
		std::cout << std::endl;

		for(i=0; !list.isLast(i-1) ;i++){
			std::cout << (char)186;                                 // ║
			std::cout << WIDTH(widthBuffer) << list.get(i) << " ";
			std::cout << (char)186;                                 // ║
			std::cout << std::endl;
		}

		std::cout << (char)200 << (char)205 << WIDTH(widthBuffer);  // ╚═
		std::cout << (char)205 << (char)188;                        // ═╝
	}
}


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

};