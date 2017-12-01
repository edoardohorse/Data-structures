#include "ListArray.h"

#define TEMPLATE template<typename TypeElem, int MaxLength>

TEMPLATE
ListArray::ListArray() { length = 0; }

TEMPLATE
bool ListArray::isEmpty(){ return length == 0;}

TEMPLATE
bool ListArray::isLast(Position pos) const{return length-1 == pos;}

TEMPLATE
Position ListArray::next(Position pos){
    if( pos < length-1){
        return pos+1;
    }
    return length-1;
}

TEMPLATE
Position ListArray::previous(Position pos){
    if(pos > 0){
        return pos-1;
    }
    return 0;
}

TEMPLATE
TypeElem ListArray::get(Position pos) const{ return list[pos];}

TEMPLATE
void ListArray::set(Position pos, TypeElem val){ list[pos] = val;}

TEMPLATE
void ListArray::insert(Position pos, TypeElem val){
    Position i;
    for(i=length-1; i >= pos;i--){
        list[i+1] = list[i];
    }
    list[pos] = val;
    length++;
}

TEMPLATE
void ListArray::remove(Position pos){
    for(Position i = pos; i < length-1; i++){
        list[i] = list[i+1];
    }
    length--;
}