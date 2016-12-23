#ifndef FIGURE1_H 
#define FIGURE1_H 
#include <iostream>
using std::cout;
class Figure {
public:
	virtual double square() = 0;
	virtual void  print (std::ostream& os = cout) = 0;
	virtual ~Figure() {};
};

bool operator > (Figure &a, Figure& b) {
    return a.square() > b.square();
}

#endif
