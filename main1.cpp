#include <iostream>
#include <memory>
#include "Square1.cpp"
#include "Rect1.cpp"
#include "Trap1.cpp"
#include "List_ex1.cpp"
#include "allocator.cpp"
using std::endl;
using std::cout;
using std::cin;
using std::shared_ptr;
using std::swap;
using std::ostream;
int main () {
	List_ex <Figure> list2;
	shared_ptr <Figure> new_ptr(new Rect(10,4));
	shared_ptr <Figure> new_ptr2(new Rect(3,4));
	shared_ptr <Figure> new_ptr3(new Square(3));
	list2.push_front(new_ptr3);
	list2.push_front(new_ptr2);
	list2.push_back(new_ptr);
	for(auto i : list2) {
		cout << (*i).square();
		cout << endl;
	}
    cout << endl << endl;
    list2.sort_parallel();
	for(auto i : list2) {
		cout << (*i).square();
		cout << endl;
	}
}
