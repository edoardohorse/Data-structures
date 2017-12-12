#pragma once

namespace NListPointer {


	template<typename TypeElem>
	class Node {
	public:
		Node *getNext() const {return next;}
		void setNext(Node *next) {next = next;}

	public:
		TypeElem getValue() const {return value;}
		void setValue(TypeElem value) {value = value;}

	private:
		Node* next;
		TypeElem value;
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
		ls->setNext(nullptr);
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
		return ls->getNext() == nullptr;
	}

	template<typename TypeElem>
	Position<TypeElem> ListPointer<TypeElem>::first() const {
		return ls->getNext();
	}

	template<typename TypeElem>
	bool ListPointer<TypeElem>::isLast(Position<TypeElem> p) const {
		return p == nullptr;
	}

	template<typename TypeElem>
	Position<TypeElem> ListPointer<TypeElem>::next(Position<TypeElem> p) const {
		return p->getNext();
	}

	template<typename TypeElem>
	TypeElem ListPointer<TypeElem>::get(Position<TypeElem> p) const {
		return p->getValue();
	}

	template<typename TypeElem>
	void ListPointer<TypeElem>::set(Position<TypeElem> p, TypeElem e) const {
		p->setValue(e);
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
		newNode->setValue(e);
		newNode->setNext(p);

		if (p == ls->getNext()) {

			ls->setNext(newNode);
		} else {
			Position<TypeElem> prev = previous(p);
			prev->setNext(newNode);

		}
		p = newNode;

	}

	template<typename TypeElem>
	void ListPointer<TypeElem>::remove(Position<TypeElem>& p) {
		Position<TypeElem> toRemove = p;

		if (p == ls->getNext()) {
			ls->setNext(toRemove->getNext());
		} else {
			previous(toRemove)->setNext(toRemove->getNext());
		}

		p = toRemove->getNext();
		delete toRemove;
	}


}

