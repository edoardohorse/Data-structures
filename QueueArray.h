#pragma once
#include <iostream>
#include <stdexcept>

#define MAXLENGTH 1000

namespace NQueueArray{


	template<typename TypeElem>
	class QueueArray{
	public:
		QueueArray();
		bool isEmpty();
		void push(TypeElem);
		TypeElem top();
		void pop();

	private:
		struct{
			TypeElem v[MAXLENGTH];
			int length;
			int head;
		}queue;
	};

	template<typename TypeElem>
	QueueArray<TypeElem>::QueueArray() {
		queue.length = 0;
		queue.head = 0;
	}

	template<typename TypeElem>
	bool QueueArray<TypeElem>::isEmpty() {
		return queue.length == 0;
	}

	template<typename TypeElem>
	void QueueArray<TypeElem>::push(TypeElem e) {
		if(queue.length < MAXLENGTH ){
			queue.v[ ( (queue.head + queue.length) % MAXLENGTH) ] = e;
			queue.length++;
		}
		else{
			throw std::invalid_argument("Overflow of list dimension");
		}
	}

	template<typename TypeElem>
	TypeElem QueueArray<TypeElem>::top() {
		return queue.v[queue.head];
	}

	template<typename TypeElem>
	void QueueArray<TypeElem>::pop() {
		queue.head = (queue.head+1) % MAXLENGTH;
		queue.length--;
	}


}