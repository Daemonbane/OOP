#include "Figure1.h"
#include <iostream>
#include "Rect1.h"
#include "allocator.h"
using std::cin;
using std::endl;
using std::cout;
Allocator rectal_loc(sizeof(Rect));


    void* Rect::operator new(size_t s){
        return rectal_loc.alloc();
    }
    void Rect::operator delete(void *p) {
        rectal_loc.free(p);
    }


Rect::Rect() {
		cin >> size_a;
		cin >> size_b;
	}


double Rect::square()  {
		return size_a * size_b;
	}
	
