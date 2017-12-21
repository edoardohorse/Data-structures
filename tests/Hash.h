#pragma  once

#include <ctype.h>
#include <string>
#include <math.h>

#define CHANGE_BASE(x)  x* pow(35, len);

typedef unsigned int Hash;




struct Helper{

	std::string toString(char c){
		std::string str="";
		str = (int) c;
		return str;
	}

	std::string toString(std::string c){
		return c;
	}

	template <typename TypeKey>
	std::string toString(TypeKey key){
		return std::to_string(key);
	}

	char toupper(char c){
		if(c >= 'a' && c <= 'z')
			return c-32;
		else
			return c;
	}
};


template <typename TypeKey>
Hash toHash(TypeKey key, int NBucket){

	Helper help;
	std::string str = help.toString(key);
	Hash h = 0;
	int len = str.length()-1;
	char c;
	for(int i=0 ; i< str.length(); i++, len--){

		 c= str.at(i);

		if(c >= '0' && c <= '9'){
			double p =  pow(35.0, len);
			h += (c-48) * p;
		}
		else
		if(c >= 'A' && c <= 'Z' ||
				c >= 'a' && c <= 'z'){
			c = help.toupper(c);
			double p =  pow(35.0, len);
			h += (c-55) * p;
		}
	}

	return h % NBucket;
}