#pragma once

#define MAXLENGTH 1000

namespace NStackArrayTest{


	template<typename TypeElem>
	class StackArray{
	public:
		StackArray();
		bool isEmpty();
		void push(TypeElem);
		TypeElem top();
		void pop();

	private:
		struct{
			TypeElem v[MAXLENGTH];
			int head = 0;
		}stk;
	};

	template<typename TypeElem>
	StackArray<TypeElem>::StackArray(){
		stk.head = 0;
	}

	template<typename TypeElem>
	bool StackArray<TypeElem>::isEmpty(){
		return stk.head == 0;
	}

	template<typename TypeElem>
	void StackArray<TypeElem>::push(TypeElem e){
		stk.head++;
		stk.v[ stk.head ] = e;
	}

	template<typename TypeElem>
	TypeElem StackArray<TypeElem>::top(){
		return stk.v[ stk.head ];
	}

	template<typename TypeElem>
	void StackArray<TypeElem>::pop(){
		stk.head--;
	}
}