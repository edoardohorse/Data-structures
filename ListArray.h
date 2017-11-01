#pragma once

template <typename TipoElem, int MaxLength>
class ListArray{
public:
	ListArray(){
		lenght = 0;
	}

	bool isEmpty(){return lenght == 0;}

	bool isLast(int p){return lenght-1 == p;}

	int first(){return 0;}

	int next(int p){
		if( p+1 < MaxLength){
			return p+1;
		}
	}

	int previous(int p){
		if(p-1 >= 0){
			return p-1;
		}
	}

	TipoElem get(int p){ return list[p];}

	void set(int p, TipoElem val){ list[p] = val;}


	void insert(int p, TipoElem val){
		int i;
		for(i=lenght-1; i >= p;i--){
			list[i+1] = list[i];
		}
		list[p] = val;
		lenght++;
	}

	void remove(int p){
		for(int i = p; i < lenght-1; i++){
			list[i] = list[i+1];
		}
		lenght--;
	}



private:
	TipoElem list[MaxLength];
	int lenght;
};