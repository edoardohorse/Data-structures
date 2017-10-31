#pragma once
#include <iostream>
#include <iomanip>

#include "ListArray.h"

#define WIDTH(x) std::setw(x)

namespace PrintList{

	// Pretty print of list
	template <typename TipoElem, int Length>
	void printListArray(ListArray<TipoElem, Length> list, int widthBuffer = 3) {
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
