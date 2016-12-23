#ifndef LISTOFTREES_H
#define LISTOFTREES_H
#include "Ntree.h"
#include "List_ex1.h"
#include <string>
using std::string;

class Listoftrees {
    List_ex<Ntree<Figure> > data;
    public:
      void append(shared_ptr<Figure>);
      void print();
      void del(string mask, double sq);
}
;
#endif
