#pragma once

template <typename TypeElem, int MaxLength>
class ListArray{
public:
	typedef int Position;

	ListArray();

	// Check if empty
	bool isEmpty();

	// Check if a given position is the last one
	bool isLast(Position) const;

	// Return first index
	Position first() const{return 0;}

	// Return the next position
	Position next(Position);

	// Return the previous position
	Position previous(Position);

	// Return the value of a given position
	TypeElem get(Position) const;

	// Set a value to a given position
	void set(Position, TypeElem);

	// Inject a value Posizioneo a given position of the array, all value after the injection are shifted
	void insert(Position, TypeElem);

	// Pop a value from array, next values are translated up
	void remove(Position);


private:
	TypeElem list[MaxLength];
	Position length;

};

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