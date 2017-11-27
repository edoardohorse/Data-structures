#pragma once

#include <iostream>
#include <iomanip>
#define MAXLENGTH 10

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

	Position first(){return l;}

	bool isLast(Position p){return p == 0;}

	Position next(Position p){ return space.v[p].next;}

	TypeElem get(Position p){return space.v[p].value;}

	void set(Position p, TypeElem e){ space.v[p].value = e;}

	void insert(Position p, TypeElem e){
		if(space.free == 0){
			throw "Errore";
		}
		else if(p==l){
			move(space.free, l);
			space.v[l].value = e;
		}
		else{

			move(space.free,space.v[p].next);
			space.v[space.v[p].next].value = e;
		}
	}

	void remove(Position p){
		if(p==l){
			move(l,space.free);
		}
		else{
			move(space.v[p].next,space.free);
		}
	}

	void print(){
		int widthBuffer = 3;
		Position i;

		std::cout << "  ";
		std::cout << (char)201 << (char)205 << WIDTH(widthBuffer);  // ╔═
		std::cout << std::string(7, (char)205);
		std::cout << (char)205 << (char)187;                        // ═╗
		std::cout << std::endl;

		for(i= 1; i < MAXLENGTH+1 ; i++){
			std::cout << WIDTH(2) << i;
			std::cout << (char)186;                                 // ║
			std::cout << WIDTH(widthBuffer) << get(i) << " ";
			std::cout << (char)124 ;                        // |
			std::cout << WIDTH(widthBuffer) << next(i) << " ";
			std::cout << (char)186;                                 // ║
			std::cout << std::endl;
		}
		std::cout << "  ";
		std::cout << (char)200 << (char)205 << WIDTH(widthBuffer);  // ╚═
		std::cout << std::string(7, (char)205);
		std::cout << (char)205 << (char)188;                        // ═╝

		std::cout << std::endl;
		std::cout << "Libera: " << space.free;
        std::cout << std::endl;
        std::cout << std::endl;
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
		for(int i=1;i < MAXLENGTH;i++){
			space.v[i].value = '-';
			space.v[i].next = i+1;
		}
		space.v[MAXLENGTH].value = '-';
		space.v[MAXLENGTH].next = 0;
	}
public:
	void move(Position& free, Position& toMove){
        Position nextFree = space.v[free].next;
        space.v[free].next = space.v[toMove].next;
        space.v[toMove].next = free;
        toMove = free;
        free = nextFree;

/*
        Position  tmp  = toMove;
        toMove = free;
        free = space.v[free].next;
        space.v[toMove].next = tmp;
*/
	}
};

