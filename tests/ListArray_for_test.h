#pragma once

namespace NListArrayTest {
	typedef int Position;


	template<typename TypeElem, int MaxLength>
	class ListArray {


	public:


		ListArray();

		// Check if empty
		bool isEmpty();

		// Check if a given position is the last one
		bool isLast(Position);

		// Return first index
		Position first();

		// Return the next position
		Position next(Position);

		// Return the previous position
		Position previous(Position);

		// Return the value of a given position
		TypeElem get(Position);

		// Set a value to a given position
		void set(Position, TypeElem);

		// Inject a value Position to a given position of the array, all value after the injection are shifted
		void insert(Position, TypeElem);

		// Pop a value from array, next values are translated up
		void remove(Position);

	private:


		TypeElem list[MaxLength+1];
		Position length;

//		friend ListArray testFunc<TypeElem, MaxLength>(ListArray& ls);
	};


	template<typename TypeElem, int MaxLength>
	ListArray<TypeElem, MaxLength>::ListArray(){ length = 0; }

	template<typename TypeElem, int MaxLength>
	bool ListArray<TypeElem, MaxLength>::isEmpty(){ return length == 0; }

	template<typename TypeElem, int MaxLength>
	bool ListArray<TypeElem, MaxLength>::isLast(Position pos){ return (length)  == pos; }

	template<typename TypeElem, int MaxLength>
	Position ListArray<TypeElem, MaxLength>::first(){ return 1; }

	template<typename TypeElem, int MaxLength>
	Position ListArray<TypeElem, MaxLength>::next(Position pos){
		return pos+1;
	}

	template<typename TypeElem, int MaxLength>
	Position ListArray<TypeElem, MaxLength>::previous(Position pos){
		return pos-1;
	}

	template<typename TypeElem, int MaxLength>
	TypeElem ListArray<TypeElem, MaxLength>::get(Position pos){ return list[pos]; }

	template<typename TypeElem, int MaxLength>
	void ListArray<TypeElem, MaxLength>::set(Position pos, TypeElem val){
		list[pos] = val;
	}

	template<typename TypeElem, int MaxLength>
	void ListArray<TypeElem, MaxLength>::insert(Position pos, TypeElem val){
		Position i;
		for (i = length ; i >= pos; i--){
			list[i + 1] = list[i];
		}
		list[pos] = val;
		length++;
	}

	template<typename TypeElem, int MaxLength>
	void ListArray<TypeElem, MaxLength>::remove(Position pos){
		for (Position i = pos; i < length ; i++){
			list[i] = list[i + 1];
		}
		length--;
	}

/*
 * 	auto* ls = new ListArray<int, 10>;
	ls->insert(0,17);
	ls->insert(1,20);
	ls->insert(2,3);
	ls->insert(3,30);
	ls->insert(1,70);
	ls->remove(2);

	PrintList::printListArray(ls,4);
	delete ls;

 * */

}