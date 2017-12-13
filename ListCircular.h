#pragma once

namespace NListCircular{

	template<typename TypeElem>
	class Node{
		TypeElem value;
		Node* next = nullptr;
		Node* previous = nullptr;

	public:
		TypeElem getValue() const {
			return value;
		}
		void setValue(TypeElem value) {
			Node::value = value;
		}
		Node* getNext() const {
			return next;
		}
		void setNext(Node* next) {
			Node::next = next;
		}
		Node* getPrevious() const {
			return previous;
		}
		void setPrevious(Node* previous) {
			Node::previous = previous;
		}
	};

	template<typename TypeElem>
	using Position = Node<TypeElem>*;

	template<typename TypeElem>
	class ListCircular{
	public:
		ListCircular();
		~ListCircular();
		bool isEmpty() const;
		Position<TypeElem> first() const;
		bool isLast(Position<TypeElem>) const;
		Position<TypeElem> next(Position<TypeElem>) const;
		Position<TypeElem> previous(Position<TypeElem>) const;
		TypeElem get(Position<TypeElem>) const;
		void set(Position<TypeElem>, TypeElem);
		void insert(Position<TypeElem>&,TypeElem);
		void remove(Position<TypeElem>&);

	private:
		typedef Position<TypeElem> List;
		List ls;
		Position<TypeElem> sentinel;
	};

	template<typename TypeElem>
	ListCircular<TypeElem>::ListCircular() {
		ls = new Node<TypeElem>;
		sentinel = new Node<TypeElem>;

		ls->setNext(sentinel);
		sentinel->setNext(sentinel);
		sentinel->setPrevious(sentinel);
	}

	template<typename TypeElem>
	ListCircular<TypeElem>::~ListCircular() {
		Position<TypeElem> tmp = first();
		while(!isLast(tmp)){
			Position<TypeElem> p = tmp;
			tmp = next(p);
			delete p;
		}

		delete ls;
	}

	template<typename TypeElem>
	bool ListCircular<TypeElem>::isEmpty() const{
		return (sentinel->getNext() == sentinel);
	}

	template<typename TypeElem>
	Position<TypeElem> ListCircular<TypeElem>::first() const{
		return sentinel->getNext();
	}

	template<typename TypeElem>
	bool ListCircular<TypeElem>::isLast(Position<TypeElem> p) const{
		return (p == sentinel);
	}

	template<typename TypeElem>
	Position<TypeElem> ListCircular<TypeElem>::next(Position<TypeElem> p) const{
		return p->getNext();
	}

	template<typename TypeElem>
	Position<TypeElem> ListCircular<TypeElem>::previous(Position<TypeElem> p) const{
		return p->getPrevious();
	}

	template<typename TypeElem>
	TypeElem ListCircular<TypeElem>::get(Position<TypeElem> p) const{
		return p->getValue();
	}

	template<typename TypeElem>
	void ListCircular<TypeElem>::set(Position<TypeElem>p , TypeElem e) {
		p->setValue(e);
	}

	template<typename TypeElem>
	void ListCircular<TypeElem>::insert(Position<TypeElem>& p, TypeElem e) {
		Position<TypeElem> newNode = new Node<TypeElem>;
		newNode->setValue(e);
		newNode->setNext(p);
		newNode->setPrevious(p->getPrevious());

		p->getPrevious()->setNext(newNode);
		p->setPrevious(newNode);

		p = newNode;
	}

	template<typename TypeElem>
	void ListCircular<TypeElem>::remove(Position<TypeElem>& p) {
		Position<TypeElem> toRemove = p;

		if(p == ls->getNext()){
			ls->setNext(p->getNext());
		}

		toRemove->getNext()->setPrevious(toRemove->getPrevious());
		toRemove->getPrevious()->setNext(toRemove->getNext());

		p = p->getNext();
		delete toRemove;
	}

}