#ifndef LIST_EX1
#define LIST_EX1
#include "TIterator.h" 
#include <iostream>
#include <memory>
#include <mutex>

using std::endl;
using std::cout;
using std::cin;
using std::shared_ptr;
using std::swap;
using std::ostream;
template <class T> class List_ex {
	shared_ptr<node<T>> head;
	 std::recursive_mutex   *list_mutex; 
public:
	List_ex();

	int size();

	void push_front(shared_ptr <T> ptr);

	void push_back(shared_ptr <T> ptr);

	void pop_first();

	void pop_last();
	TIterator<T> begin();
	TIterator<T> end() ;
    void remove(TIterator<T>);
	void print();
	void print_standart();
	shared_ptr <T>get_first();
    shared_ptr <T>get_last();

	~List_ex(){
	}

	 friend std::ostream& operator<<(std::ostream& os, List_ex <T> &list) {
		shared_ptr <node<T>> tmp = list.head;
		while (tmp != nullptr) {
			tmp->fgr->print(os);
			tmp = tmp->next;
		}
		return os;
	}
	 

};
#endif
