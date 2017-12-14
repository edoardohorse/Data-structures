#pragma once

namespace NStackPointerTest{

	template<typename TypeElem>
	class Node{
	public:
		TypeElem getValue() const {return value;}
		void setValue(TypeElem value) {Node::value = value;}
		Node* getNext() const {return next;}
		void setNext(Node* next) {Node::next = next;}
	private:
		TypeElem value;
		Node* next;
	};



	template<typename TypeElem>
	class StackPointer{
	public:
		StackPointer();
		~StackPointer();
		bool isEmpty();
		void push(TypeElem);
		void pop();
		TypeElem top();
	private:
		typedef Node<TypeElem>* Stack;
		Stack stk;
	};

	template<typename TypeElem>
	StackPointer<TypeElem>::StackPointer() {
		stk = new Node<TypeElem>;
		stk->setNext(nullptr);
	}

	template<typename TypeElem>
	StackPointer<TypeElem>::~StackPointer() {
		while(!isEmpty()){
			pop();
		}
		delete stk;
	}

	template<typename TypeElem>
	bool StackPointer<TypeElem>::isEmpty() {
		return stk->getNext() == nullptr;
	}

	template<typename TypeElem>
	void StackPointer<TypeElem>::push(TypeElem e) {
		Stack newNode = new Node<TypeElem>;
		newNode->setValue(e);
		newNode->setNext(stk->getNext());
		stk->setNext(newNode);
	}

	template<typename TypeElem>
	void StackPointer<TypeElem>::pop() {
		Stack toRemove = stk->getNext();
		stk->setNext(toRemove->getNext());
		delete toRemove;
	}

	template<typename TypeElem>
	TypeElem StackPointer<TypeElem>::top() {
		return stk->getNext()->getValue();
	}
};