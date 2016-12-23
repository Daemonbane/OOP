#include <iostream>
#include <memory>
#include "Square1.cpp"
#include "Rect1.cpp"
#include "Trap1.cpp"
#include "List_ex1.cpp"
#include "allocator.cpp"
#include "Listoftrees.cpp"
using std::endl;
using std::cout;
using std::cin;
using std::shared_ptr;
using std::swap;
using std::ostream;
int main () {
    Listoftrees lot;
	shared_ptr <Figure> new_ptr(new Rect(10,4));
	shared_ptr <Figure> new_ptr2(new Rect(3,4));
	shared_ptr <Figure> new_ptr3(new Square(3));
	shared_ptr <Figure> new_ptr4(new Rect(11,5));
	shared_ptr <Figure> new_ptr5(new Rect(5,6));
	shared_ptr <Figure> new_ptr6(new Square(7));
	lot.append(new_ptr);
	lot.append(new_ptr2);
	lot.append(new_ptr3);
	lot.append(new_ptr4);
	lot.append(new_ptr5);
	lot.append(new_ptr6);
    lot.print();
    lot.del("R",10000);
    lot.print();
}
