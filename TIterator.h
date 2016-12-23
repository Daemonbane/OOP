#ifndef TITERATOR_H 
#define TITERATOR_H 
#include <memory>
#include <iostream>
#include "Listitem1.h"
using std::shared_ptr;

template <class T>
class TIterator {
	private:
	shared_ptr <node<T>> ptr;

public:

	TIterator (shared_ptr <node<T>> t) {
		ptr = t;
	}

	std::shared_ptr<T> operator * (){ 
		return ptr->fgr;
	}

	std::shared_ptr<T> operator -> (){ 
		return ptr->fgr;
	}

	void operator ++ (){
		ptr = ptr->next;
	}

	TIterator operator ++ (int){
		TIterator iter(*this); 
		++(*this);
		return iter;
	}

	bool operator == (TIterator const& i) { 
		return ptr == i.ptr;
	}

	bool operator != (TIterator const& i){
		return !(*this == i); 
	}

};
#endif
