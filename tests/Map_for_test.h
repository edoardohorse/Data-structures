#pragma once

#include "Hash.h"

namespace NMapTest{

	template<typename TypeKey, typename TypeElem, const int NBucket = 10>
	class Map{
	public:

		bool has(TypeKey);
		void insert(TypeKey, TypeElem);
		void remove(TypeKey);
		TypeElem get(TypeKey);
		void set(TypeKey, TypeElem);

	private:
		class Bucket{
		public:
			TypeElem value;
			bool isEmpty = true;
		};

		struct map{
			Bucket v[NBucket];
			Bucket operator[] (TypeKey k) const {
				Hash h = toHash(k, NBucket);
				return v[h];
			}
			Bucket& operator[] (TypeKey k) {
				Hash h = toHash(k, NBucket);
				return v[h];
			}
		}map;




	};

	template<typename TypeKey, typename TypeElem, int NBucket>
	bool Map<TypeKey, TypeElem, NBucket>::has(TypeKey k) {
		return !map[k].isEmpty;
	}

	template<typename TypeKey, typename TypeElem, int NBucket>
	void Map<TypeKey, TypeElem, NBucket>::insert(TypeKey k, TypeElem e) {
		
		map[k].value = e;
		map[k].isEmpty = false;
	}

	template<typename TypeKey, typename TypeElem, int NBucket>
	void Map<TypeKey, TypeElem, NBucket>::remove(TypeKey k) {
		map[k].isEmpty = true;
	}

	template<typename TypeKey, typename TypeElem, int NBucket>
	TypeElem Map<TypeKey, TypeElem, NBucket>::get(TypeKey k) {
		return map[k].value;
	}

	template<typename TypeKey, typename TypeElem, int NBucket>
	void Map<TypeKey, TypeElem, NBucket>::set(TypeKey k, TypeElem e) {
		map[k].value = e;
	}
}