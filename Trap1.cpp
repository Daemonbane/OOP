#include "Figure1.h"
#include "Trap1.h"
#include "allocator.h"
#include <iostream>
#include <cmath>
using std::cin;
using std::endl;
using std::cout;
Allocator trap_alloc(sizeof(Trap));


    void* Trap::operator new(size_t s){
        return trap_alloc.alloc();
    }
    void Trap::operator delete(void *p) {
        trap_alloc.free(p);
    }
	Trap::Trap() {
		cin >> size_a;
		cin >> size_b;
		cin >> size_c;
	}

	double Trap::square() {
		double p=(size_a+size_b)/2;
		

		return p*size_c;
	}



