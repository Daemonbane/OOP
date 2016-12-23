#ifndef NTREEITERATOR_H
#define NTREEITERATOR_H
#include "Ntreenode.h"
template<typename T>
struct ntree_iterator {
    shared_ptr<ntree_node<T> > ptr;
	ntree_iterator(shared_ptr <ntree_node<T> > t) {
		ptr = t;
	}

	std::shared_ptr<T> operator * (){ 
		return ptr->fgr;
	}

	std::shared_ptr<T> operator -> (){ 
		return ptr->fgr;
	}

	void operator ++ (){
        if(ptr == nullptr) return;
        if(ptr->sibling) {
            ptr = ptr->sibling;
            while(ptr->child) {
                ptr = ptr->child;
            }
        }
        else {
            if(!ptr->parent.lock())
                ptr = nullptr; 
            else  {
                while(ptr->parent.lock() && ptr->parent.lock()->sibling == ptr)
                    ptr = ptr->parent.lock();
                ptr = ptr->parent.lock();
            }
        } 
	}

	ntree_iterator<T> operator ++ (int){
		ntree_iterator iter(*this); 
		++(*this);
		return iter;
	}

	bool operator == (ntree_iterator<T>const& i) { 
		return ptr == i.ptr;
	}

	bool operator != (ntree_iterator<T>const& i){
		return !(*this == i); 
	}

};

#endif
