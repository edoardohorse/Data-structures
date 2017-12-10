#pragma once

namespace NListPointer {

	template<typename TypeElem>
	class ListPointer;

	template<typename TypeElem>
	class Node {
	private:
		TypeElem value;
		Node* next;
		friend class ListPointer<TypeElem>;
	};

	template<typename TypeElem>
	using Position = Node<TypeElem>*;


	template<typename TypeElem>
	class ListPointer {
	public:

		ListPointer();

		~ListPointer();

		bool isEmpty();

		Position<TypeElem> first() const;

		bool isLast(Position<TypeElem>) const;

		Position<TypeElem> next(Position<TypeElem>) const;

		TypeElem get(Position<TypeElem>) const;

		void set(Position<TypeElem>, TypeElem) const;

		void insert(Position<TypeElem>&, TypeElem);

		void remove(Position<TypeElem>&);

		Position<TypeElem> previous(Position<TypeElem>) const;

	private:
		typedef Position<TypeElem> List;
		List ls;
	};

	template<typename TypeElem>
	ListPointer<TypeElem>::ListPointer() {
		ls = new Node<TypeElem>;
		ls->next = nullptr;
	}

	template<typename TypeElem>
	ListPointer<TypeElem>::~ListPointer() {
		Position<TypeElem> tmp = first();
		while(!isLast(tmp)){
			Position<TypeElem> p = tmp;
			tmp = next(tmp);
			delete p;
		}
		delete ls;
	}

	template<typename TypeElem>
	bool ListPointer<TypeElem>::isEmpty() {
		return ls->next == nullptr;
	}

	template<typename TypeElem>
	Position<TypeElem> ListPointer<TypeElem>::first() const {
		return ls->next;
	}

	template<typename TypeElem>
	bool ListPointer<TypeElem>::isLast(Position<TypeElem> p) const {
		return p == nullptr;
	}

	template<typename TypeElem>
	Position<TypeElem> ListPointer<TypeElem>::next(Position<TypeElem> p) const {
		return p->next;
	}

	template<typename TypeElem>
	TypeElem ListPointer<TypeElem>::get(Position<TypeElem> p) const {
		return p->value;
	}

	template<typename TypeElem>
	void ListPointer<TypeElem>::set(Position<TypeElem> p, TypeElem e) const {
		p->value = e;
	}

	template<typename TypeElem>
	Position<TypeElem> ListPointer<TypeElem>::previous(Position<TypeElem> p) const {
		Position<TypeElem> tmp = first();
		while (next(tmp) != p) {
			tmp = next(tmp);
		}
		return tmp;
	}

	template<typename TypeElem>
	void ListPointer<TypeElem>::insert(Position<TypeElem>& p, TypeElem e) {
		Position<TypeElem> newNode = new Node<TypeElem>;
		newNode->value = e;
		newNode->next = p;

		if (p == ls->next) {

			ls->next = newNode;
		} else {
			Position<TypeElem> prev = previous(p);
			prev->next = newNode;

		}
		p = newNode;

	}

	template<typename TypeElem>
	void ListPointer<TypeElem>::remove(Position<TypeElem>& p) {
		Position<TypeElem> toRemove = p;

		if (p == ls->next) {
			ls->next = toRemove->next;
		} else {
			previous(toRemove)->next = toRemove->next;
		}

		p = toRemove->next;
		delete toRemove;
	}


}

/*
 using namespace NListPointer;

template <typename TypeElem>
class ListaP;

template <typename TypeElem>
class Nodo{
private:
	TypeElem value;
	friend class ListaP<TypeElem>;
};

template <typename TypeElem>
class ListaP{
private:

	typedef Nodo<TypeElem>* List;
	List ls = new Nodo<TypeElem>();


public:

	typedef Nodo<TypeElem>* Position;
	List getFirst(){return ls;}
	void setValue(Position p,TypeElem val){
		ls->value = val;
	}

	TypeElem getValue(Position p) const{return ls->value;}

};

 */