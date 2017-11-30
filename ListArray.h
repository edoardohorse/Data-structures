#pragma once



template <typename TypeElem, int MaxLength>
class ListArray{
public:
	typedef int Position;

	ListArray(){
		length = 0;
	}

	// check if empty
	bool isEmpty(){return length == 0;}

	// check if a given position is the last one
	bool isLast(Position pos) const{return length-1 == pos;}

	// return first index
	Position first() const{return 0;}

	// return the next position
	Position next(Position pos){
		if( pos < length-1){
			return pos+1;
		}
		return length-1;
	}

	// return the previous position
	Position previous(Position pos){
		if(pos > 0){
			return pos-1;
		}
		return 0;
	}

	// return the value of a given position
	TypeElem get(Position pos) const{ return list[pos];}

	// set a value to a given position
	void set(Position pos, TypeElem val){ list[pos] = val;}

	// inject a value Posizioneo a given position of the array, all value after the injection are shifted
	void insert(Position pos, TypeElem val){
		Position i;
		for(i=length-1; i >= pos;i--){
			list[i+1] = list[i];
		}
		list[pos] = val;
		length++;
	}

	// pop a value from array, next values are translated up
	void remove(Position pos){
		for(Position i = pos; i < length-1; i++){
			list[i] = list[i+1];
		}
		length--;
	}



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