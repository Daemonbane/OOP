#ifndef RECT1_H
#define RECT1_H
#include "Figure1.h"
#include <iostream>
using std::cin;
using std::endl;
using std::cout;
class Rect: public Figure {
	double size_a, size_b;
public:
    void* operator new(size_t);
    void operator delete(void*);
	Rect(double a, double b): size_a(a), size_b(b) {

	}
	Rect();

	double square();
	void print(std::ostream& os = cout) {
		os << " size a = " << size_a << " size_b = " << size_b  << endl;
	}

	~Rect()	{
	}
};
#endif
