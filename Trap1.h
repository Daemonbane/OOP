#ifndef TRAP1_H
#define TRAP1_H
#include "Figure1.h"
#include <iostream>
#include <cmath>
using std::cin;
using std::endl;
using std::cout;
class Trap: public Figure {
	double size_a, size_b,size_c, size_d;
public:
    void* operator new(size_t);
    void operator delete(void*);
	Trap(double a, double b, double c): size_a(a), size_b(b), size_c(c){

	}
	Trap();

	double square();
	void print(std::ostream& os = cout) {
		os << " size a = " << size_a << " size_b = " << size_b 
			<< " size_c = " << size_c << endl;
	}

	
};
#endif
