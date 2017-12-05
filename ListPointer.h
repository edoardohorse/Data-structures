#pragma once



namespace NListPointer{

	template <typename TypeElem>
	struct Node{
		TypeElem value;
		Node* next;
	};

	template <typename TypeElem>
	using Position = Node<TypeElem>*;


	template<typename TypeElem>
	class ListPointer{
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
		friend List test(ListPointer& list){
			return list.ls;
		}
	};


	template <typename TypeElem>
	ListPointer<TypeElem>::ListPointer() {
		ls = new Node<TypeElem>;
		ls->next = nullptr;
	}

	template <typename TypeElem>
	ListPointer<TypeElem>::~ListPointer() {
		// TODO Delete all Node
		delete ls;
	}

	template <typename TypeElem>
	bool ListPointer<TypeElem>::isEmpty() {
		return ls->next == nullptr;
	}

	template <typename TypeElem>
	Position<TypeElem>ListPointer<TypeElem>::first() const{
		return ls->next;
	}

	template <typename TypeElem>
	bool ListPointer<TypeElem>::isLast(Position<TypeElem> p) const{
		return p == nullptr;
	}

	template <typename TypeElem>
	Position<TypeElem>ListPointer<TypeElem>::next(Position<TypeElem> p) const{
		return p->next;
	}

	template <typename TypeElem>
	TypeElem ListPointer<TypeElem>::get(Position<TypeElem> p) const{
		return p->value;
	}

	template <typename TypeElem>
	void ListPointer<TypeElem>::set(Position<TypeElem> p, TypeElem e) const{
		p->value = e;
	}

	template <typename TypeElem>
	Position<TypeElem>ListPointer<TypeElem>::previous(Position<TypeElem> p) const{
		Position<TypeElem>tmp = first();
		while (next(tmp) != p) {
			tmp = next(tmp);
		}
		return tmp;
	}

	template <typename TypeElem>
	void ListPointer<TypeElem>::insert(Position<TypeElem>& p, TypeElem e) {
		Position<TypeElem>newNode = new Node<TypeElem>;
		newNode->value = e;
		newNode->next = p;

		if(p == ls->next){

			ls->next = newNode;
		}
		else{
			Position<TypeElem>prev = previous(p);
			prev->next = newNode;

		}
		p = newNode;

	}

	template <typename TypeElem>
	void ListPointer<TypeElem>::remove(Position<TypeElem>& p) {
		Position<TypeElem>toRemove = p;

		if(p == ls->next){
			ls->next = toRemove->next;
		}
		else{
			previous(toRemove)->next = toRemove->next;
		}

		p = toRemove->next;
		delete toRemove;
	}


}