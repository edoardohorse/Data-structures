#pragma once
#include <iostream>
#include <stdexcept>


#define MAXLENGTH 1000
#define DEBUG_
#define WIDTH(x) std::setw(x)

template <typename TypeElem>
class ListCursor{
public:

	typedef int Position;

	// Initialize the list to 0 and set all the cursors to theirs next position
	ListCursor();

	// Deconstructor
	~ListCursor();

	// Check if the list is empty
	bool isEmpty();

	// Get first position of the list
	ListCursor::Position first()const;

	// Check if a given position is the last of the list
	bool isLast(ListCursor::Position)const;

	// Return a cursor pointing to the next position of a given Node position
	ListCursor::Position next(ListCursor::Position) const;

	// Return the value of a Node
	TypeElem get(ListCursor::Position) const;

	// Set a value of a Node
	void set(ListCursor::Position, TypeElem);

	// Insert a certain position a value
	void insert(ListCursor::Position&, TypeElem);

	// Remove a Node from list
	void remove(ListCursor::Position&);

	// Return the position of Node that has as next Node the given one
	ListCursor::Position previous(ListCursor::Position);

	/*
	void print() {
		int widthBuffer = 3;
		ListCursor::Position i;

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

private:

	typedef ListCursor::Position List;

	List l;

	struct Node{
		TypeElem value;
		ListCursor::Position next;
	};

	struct{
		Node v[MAXLENGTH+1];
		List free;
	}space;

	// Set all cursors to theirs next position
	void init();

	// Swap two Nodes
	void move(ListCursor::Position&, ListCursor::Position&);
};



template <typename TypeElem>
ListCursor<TypeElem>::ListCursor() {
		l=0;
		init();
	}

template <typename TypeElem>
ListCursor<TypeElem>::~ListCursor(){}

template <typename TypeElem>
bool ListCursor<TypeElem>::isEmpty(){return l == 0;}

template <typename TypeElem>
Position ListCursor<TypeElem>::first()const{return space.v[0].next;}

template <typename TypeElem>
bool ListCursor<TypeElem>::isLast(ListCursor::Position p) const{return space.v[p].next == 0;}

template <typename TypeElem>
Position ListCursor<TypeElem>::next(ListCursor::Position p) const{ return space.v[p].next;}

template <typename TypeElem>
TypeElem ListCursor<TypeElem>::get(ListCursor::Position p) const{return space.v[p].value;}

template <typename TypeElem>
void ListCursor<TypeElem>::set(ListCursor::Position p, TypeElem e){ space.v[p].value = e;}

template <typename TypeElem>
void ListCursor<TypeElem>::insert(ListCursor::Position& p, TypeElem e){
		if(space.free == 0){
			throw std::invalid_argument("Overflow of list dimension");
		}
		else{
			move(space.free,space.v[p].next);
			space.v[space.v[p].next].value = e;
		}
	}

template <typename TypeElem>
void ListCursor<TypeElem>::remove(ListCursor::Position& p){
		ListCursor::Position tmp = space.v[p].next;
		space.v[previous(p)].next = space.v[p].next;

	#ifdef DEBUG_
		space.v[p].value = (TypeElem) NULL;
	#endif

		space.v[p].next = space.free;
		space.free = p;
		p = tmp;
	}

template <typename TypeElem>
Position ListCursor<TypeElem>::previous(ListCursor::Position p){
		ListCursor::Position tmp = first();
		while(next(tmp) != p){
			tmp = next(tmp);
		}
		return tmp;
	}

template <typename TypeElem>
void ListCursor<TypeElem>::init(){
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

template <typename TypeElem>
void ListCursor<TypeElem>::move(ListCursor::Position& free, ListCursor::Position& toMove){
		ListCursor::Position  tmp  = toMove;
		toMove = free;
		free = space.v[free].next;
		space.v[toMove].next = tmp;
	}


/*
   auto L = new ListCursor<char>();

    ListCursor::Position p = L->first();

    L->insert(p,'a');
    p = L->next(p);
    L->insert(p,'b');
    p = L->next(p);
    L->insert(p,'c');
    p = L->next(p);
    L->insert(p,'d');
    p = L->next(p);


 	L->remove(3);
    PrintList::printListCursor(L);



	delete L;
 *
 *
 *
 *
 * */