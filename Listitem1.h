#include "Figure1.h"
#include "Rect1.h"
#include "Square1.h"
#include "Trap1.h"
#include <memory>
#ifndef ListItem_H 
#define ListItem_H 
using std::shared_ptr;
template <class T>
struct node {
	shared_ptr <T> fgr;
	shared_ptr <node<T>> next;
};
#endif
