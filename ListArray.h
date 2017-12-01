#pragma once

#define ARG TypeElem,MaxLength
#define TEMPLATE template<typename TypeElem, int MaxLength>

typedef int Position;

TEMPLATE
class ListArray{
public:

	ListArray();

	// Check if empty
	bool isEmpty();

	// Check if a given position is the last one
	bool isLast(Position) const;

	// Return first index
	Position first() const;

	// Return the next position
	Position next(Position);

	// Return the previous position
	Position previous(Position);

	// Return the value of a given position
	TypeElem get(Position) const;

	// Set a value to a given position
	void set(Position, TypeElem);

	// Inject a value Position to a given position of the array, all value after the injection are shifted
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


TEMPLATE
ListArray<ARG>::ListArray() { length = 0; }

TEMPLATE
bool ListArray<ARG>::isEmpty(){ return length == 0;}

TEMPLATE
bool ListArray<ARG>::isLast(Position pos) const{return length-1 == pos;}

TEMPLATE
Position ListArray<ARG>::first() const{return 0;}

TEMPLATE
Position ListArray<ARG>::next(Position pos){
    if( pos < length-1){
        return pos+1;
    }
    return length-1;
}

TEMPLATE
Position ListArray<ARG>::previous(Position pos){
    if(pos > 0){
        return pos-1;
    }
    return 0;
}

TEMPLATE
TypeElem ListArray<ARG>::get(Position pos) const{ return list[pos];}

TEMPLATE
void ListArray<ARG>::set(Position pos, TypeElem val){ list[pos] = val;}

TEMPLATE
void ListArray<ARG>::insert(Position pos, TypeElem val){
    Position i;
    for(i=length-1; i >= pos;i--){
        list[i+1] = list[i];
    }
    list[pos] = val;
    length++;
}

TEMPLATE
void ListArray<ARG>::remove(Position pos){
    for(Position i = pos; i < length-1; i++){
        list[i] = list[i+1];
    }
    length--;
}