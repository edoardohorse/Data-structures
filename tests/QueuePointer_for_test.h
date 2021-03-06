#pragma once

namespace NQueuePointerTest{


	template<typename  TypeElem>
	class Node{
	private:
		TypeElem value;
		Node* next;
	public:
		TypeElem getValue() const {return value;}
		void setValue(TypeElem value) {Node::value = value;}
		Node* getNext() const {return next;}
		void setNext(Node* next) {Node::next = next;}

	};


	template<typename TypeElem>
	class QueuePointer{
	public:
		QueuePointer();
		~QueuePointer();
		bool isEmpty();
		void pop();
		void push(TypeElem);
		TypeElem top();
	private:

		struct {
			Node<TypeElem>* head;
			Node<TypeElem>* tail;
		}queue;
	};

	template<typename TypeElem>
	QueuePointer<TypeElem>::QueuePointer() {
		queue.head = nullptr;
		queue.tail = nullptr;
	}

	template<typename TypeElem>
	QueuePointer<TypeElem>::~QueuePointer() {
		while(!isEmpty()){
			pop();
		}
	}

	template<typename TypeElem>
	bool QueuePointer<TypeElem>::isEmpty() {
		return queue.head == nullptr;
	}

	template<typename TypeElem>
	void QueuePointer<TypeElem>::pop() {
		Node<TypeElem>* toRemove = queue.head;
		queue.head = queue.head->getNext();
		if(isEmpty())
			queue.tail = nullptr;
		delete toRemove;
	}

	template<typename TypeElem>
	TypeElem QueuePointer<TypeElem>::top() {
		return queue.head->getValue();
	}

	template<typename TypeElem>
	void QueuePointer<TypeElem>::push(TypeElem e) {
		auto newNode = new Node<TypeElem>;
		newNode->setValue(e);
		if(queue.head == nullptr){
			queue.head = newNode;
			newNode->setNext(queue.tail);
		}
		else{
			newNode->setNext(queue.tail->getNext());
			queue.tail->setNext(newNode);
		}

		queue.tail = newNode;

	}

}