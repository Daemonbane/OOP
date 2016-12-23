#include <iostream>
#include <functional>
#include <memory>
#include "Square1.cpp"
#include "Rect1.cpp"
#include "Trap1.cpp"
#include "Ntree.h"
#include "List_ex1.cpp"
#include "allocator.cpp"
#include <ctime>
using std::endl;
using std::cout;
using std::cin;
using std::shared_ptr;
using std::swap;
using std::ostream;

bool operator > (const std::function<void()> &a, const std::function<void()> &b){
    return true;
}

int main () {
    srand(int(time(NULL)));
	List_ex <Figure> list2;
    Ntree<std::function<void(void)> > tree2;
	shared_ptr <Figure> new_ptr(new Rect(10,4));
	shared_ptr <Figure> new_ptr2(new Rect(3,4));
	shared_ptr <Figure> new_ptr3(new Square(3));
	list2.push_back(new_ptr);
	list2.push_front(new_ptr2);
	list2.push_front(new_ptr3);
   
    std::function<void(void)> cmd_generate = [&]() {        
        for(int i=0;i<8;i++) {
            int tp = rand() % 2;
            if(tp == 0)
                list2.push_back(shared_ptr<Figure>(new Rect(rand()%100, rand()%100)));
            else 
                list2.push_back(shared_ptr<Figure>(new Square(rand()%100)));
        }
    };
    std::function<void(void)> cmd_remove = [&]() {
        if(list2.begin()!=list2.end()) 
            for(TIterator<Figure> it = list2.begin(); it != list2.end(); ++it) {
                if((*it)->square() < 50.0f)
                    list2.remove(it);
            }
    };
    tree2.insert(std::shared_ptr<std::function<void(void)> > (&cmd_generate, [](void*) {})); // using custom deleter
    tree2.insert(std::shared_ptr<std::function<void(void)> > (&cmd_remove,   [](void*) {})); // using custom deleter
    for(auto i: tree2) {
        (*i) ();
    } 
	for(auto i : list2) {
		cout << (*i).square();
		cout << endl;
	}
}
