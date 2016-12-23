#include "Figure1.h"
#include <iostream>
#include "Square1.h"
#include "allocator.h"
using std::cin;
using std::endl;
using std::cout;

Allocator squar_alloc(sizeof(Square));


    void* Square::operator new(size_t s){
        return squar_alloc.alloc();
    }
    void Square::operator delete(void *p) {
        squar_alloc.free(p);
    }
	Square::Square() {
		cin >> size_a;
	}
	double Square::square()  {
		return size_a * size_a;
	}


