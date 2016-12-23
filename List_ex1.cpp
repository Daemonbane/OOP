#include <iostream>
#include <memory>
#include "List_ex1.h"

using std::endl;
using std::cout;
using std::cin;
using std::shared_ptr;
using std::swap;
using std::ostream;

template <class T> List_ex<T>::List_ex() :	head(nullptr) {
	}
template <class T>	int List_ex<T> ::size() {
		//O(n) to know size of list
		//useful for loops - get/pop
		if (head == nullptr)
			return 0;
		shared_ptr <node<T>> tmp = head;
		int size = 1;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
			size++;
		}
		return size;

	}

	template <class T> void List_ex<T>::push_front(shared_ptr <T> ptr) {
		//add pointer on figure to the front of the list
		shared_ptr <node<T>> tmp(new node<T>);
		tmp->fgr = ptr;
		tmp->next = head;
		head = tmp;
	}

template <class T>	void List_ex<T>:: push_back(shared_ptr <T> ptr) {
		//add pointer on figure to the back of the list
		shared_ptr <node<T>> tmp = head;
		if (tmp == nullptr) {
			head = shared_ptr <node<T>> (new node<T>);
			head->fgr = ptr;
			head->next = nullptr;
			return;
		}
		while (tmp->next != nullptr) 
			tmp = tmp->next;
		shared_ptr <node<T>> cc (new node<T>);
		cc->fgr = ptr;
		cc->next = nullptr;
		tmp->next = cc;
		return;
	}

	template <class T> void List_ex<T>:: pop_first(){
		//delete first element
		if (head == nullptr)
			throw "try to pop null object";
		head = head->next;
	}

	template <class T> void List_ex<T>:: pop_last() {
		//delete last element
		shared_ptr <node<T>> tmp = head;
		if (tmp == nullptr)
			throw "access exception";
		if (tmp->next == nullptr)
			tmp = nullptr; else { 
		while(tmp->next->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = nullptr; }
	}

	template <class T> void List_ex<T>::print() {
		shared_ptr <node<T>> tmp = head;
		while(tmp != nullptr) {
			tmp->fgr->print();
			tmp = tmp->next;
		}
	}
		template <class T> void List_ex<T>::print_standart() {
		shared_ptr <node<T>> tmp = head;
		while(tmp != nullptr) {
			cout << *(tmp->fgr) << " ";
			tmp = tmp->next;
		}
		cout << "\n";

	}
		
template<class T > future<void> List_ex<T>::sort_in_background() {
        std::packaged_task<void(void) > task(std::bind(std::mem_fn(&List_ex<T>::sort_parallel), this));
        std::future<void> res(task.get_future());
        std::thread th(std::move(task));
        th.detach();
        return res;
}


template<class T> void List_ex<T>::sort() {
    if (size() > 1) {
        std::shared_ptr<T> middle = get_first();
        List_ex<T> left, right;
        pop_first();
        for(auto item: *this) {
            if (*item < *middle) {
                left.push_front(item);
            } else {
                right.push_front(item);
            }
        }

        left.sort();
        right.sort();
        head = nullptr;
        while (left.head) {
            push_back(left.get_first());
            left.pop_first();
        }
        push_back(middle);
        while (right.head) {
            push_back(right.get_first());
            right.pop_first();
        }
    }
}
template<class T> void List_ex<T>::sort_parallel() {
    if (size() > 1) {
        std::shared_ptr<T> middle = get_first();
        List_ex<T> left, right;
        pop_first();
        for(auto item: *this) {
            if (*item < *middle) {
                left.push_front(item);
            } else {
                right.push_front(item);
            }
        }

        std::future<void> left_res = left.sort_in_background();
        std::future<void> right_res = right.sort_in_background();
        head = nullptr;
        left_res.get();
        while (left.head) {
            push_back(left.get_first());
            left.pop_first();
        }
        push_back(middle);
        right_res.get();
        while (right.head) {
            push_back(right.get_first());
            right.pop_first();
        }
    }
}


template <class T>	shared_ptr <T> List_ex<T>:: get_first() {
		//access front element
		if (head == nullptr)
			throw "access exception";
		return head->fgr;
	}
	template <class T> shared_ptr <T> List_ex<T>::get_last() {
		//access last element
		shared_ptr <node<T>> tmp = head;
		if (tmp == nullptr)
			throw "access exception";
		while(tmp->next != nullptr) {
			tmp = tmp->next;
		}
		return tmp->fgr;
	}
	template <class T> 	TIterator<T> List_ex<T>:: begin() {
		return TIterator<T>(head);
	}
	template <class T> 	TIterator<T> List_ex<T>:: end() {
		return TIterator<T>(nullptr);
	}


