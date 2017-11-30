#pragma once

#include <iostream>
#include <stdexcept>
#define MAXLENGTH 11

#define DEBUG_

#define WIDTH(x) std::setw(x)

typedef int Position;

template <typename TypeElem>
class ListCursor{


public:
	ListCursor(){
		l = 0;
		init();
	}

	~ListCursor(){}

	bool isEmpty(){ return l == 0;	}

	Position first()const{return space.v[0].next;}

	bool isLast(Position p) const{return space.v[p].next == 0;}

	Position next(Position p) const{ return space.v[p].next;}

	TypeElem get(Position p) const{return space.v[p].value;}

	void set(Position p, TypeElem e){ space.v[p].value = e;}

	void insert(Position& p, TypeElem e){
		if(space.free == 0){
			throw std::invalid_argument("Overflow of list dimension");
		}
		else{
			move(space.free,space.v[p].next);
			space.v[space.v[p].next].value = e;
		}
	}

	void remove(Position& p){
        Position tmp = space.v[p].next;
		space.v[previous(p)].next = space.v[p].next;

        #ifdef DEBUG_
		    space.v[p].value = (TypeElem) NULL;
        #endif

        space.v[p].next = space.free;
		space.free = p;
        p = tmp;
	}
/*
	void print() {
		int widthBuffer = 3;
		Position i;

		std::cout << "  ";
		std::cout << (char)201 << (char)205 << WIDTH(widthBuffer);  // ╔═
		std::cout << std::string(7, (char)205);
		std::cout << (char)205 << (char)187;                        // ═╗
		std::cout << std::endl;

		for(i= 0; i < MAXLENGTH+1 ; i++){
			std::cout << WIDTH(2) << i;
			std::cout << (char) 186;                                 // ║
			std::cout << WIDTH(widthBuffer) << get(i) << " ";
			std::cout << (char) 124;                        // |
			std::cout << WIDTH(widthBuffer) << next(i) << " ";
			std::cout << (char) 186;                                 // ║
			std::cout << std::endl;
		}

		std::cout << "  ";
		std::cout << (char) 200 << (char) 205 << WIDTH(widthBuffer);  // ╚═
		std::cout << std::string(7, (char) 205);
		std::cout << (char) 205 << (char) 188;                        // ═╝

		std::cout << std::endl;
		std::cout << "Libera: " << space.free;
		std::cout << std::endl;
		std::cout << std::endl;
	}
*/
    Position previous(Position p){
		Position tmp = first();
		while(next(tmp) != p){
			tmp = next(tmp);
		}
		return tmp;
	}

private:

	typedef Position List;

	List l;

	struct Node{
		TypeElem value;
		Position next;
	};

	struct{
		Node v[MAXLENGTH+1];
		List free;
	}space;

	void init(){
		space.free = 1;
		space.v[0].next = 0;
        #ifdef DEBUG_
            space.v[0].value = (TypeElem) NULL;
        #endif
		for(int i=1;i < MAXLENGTH;i++){
        #ifdef DEBUG_
			space.v[i].value = (TypeElem) NULL;
        #endif
			space.v[i].next = i+1;
		}

        #ifdef DEBUG_
		    space.v[MAXLENGTH].value = (TypeElem) NULL;
        #endif

		space.v[MAXLENGTH].next = 0;
	}

public:
	void move(Position& free, Position& toMove){
        Position  tmp  = toMove;
        toMove = free;
        free = space.v[free].next;
        space.v[toMove].next = tmp;

	}
};

