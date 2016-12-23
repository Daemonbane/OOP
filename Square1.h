#ifndef SQUARE1_H
#define SQUARE1_H
#include "Figure1.h"
#include <iostream>
using std::cin;
using std::endl;
using std::cout;


class Square: public Figure {
	double size_a;
public:
    void* operator new(size_t);
    void operator delete(void*);
	Square(double a):size_a(a) {

	}
	Square();
	double square();
	void print(std::ostream& os = cout) {
		os << " size a = " << size_a << endl;
	}

	~Square() {
	}
};
#endif
