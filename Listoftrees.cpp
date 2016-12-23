#include "Listoftrees.h"

void Listoftrees::append(shared_ptr<Figure> fgr) {
    for(auto i: data)  {
        if(i->Size() < 5) {
            i->insert(fgr);
                return;
        }
    }
    shared_ptr<Ntree<Figure> > tree(new Ntree<Figure>());
    tree->insert(fgr);
    data.push_front(tree);
}

void Listoftrees::print() {
    for(auto i: data)  {
        cout << *i << endl;
    }
}

void Listoftrees::del(string mask, double sq) {
    for(auto i: data)  {
        for(ntree_iterator<Figure> j = i->begin(); j != i->end(); j++) {
            Figure& fig =* j.ptr.get()->fgr.get();
            if(j->square() < sq &&(
              (mask.find('T')!=string::npos&&typeid(Trap)  == typeid(fig)) ||          
              (mask.find('S')!=string::npos&&typeid(Square)== typeid(fig)) ||          
              (mask.find('R')!=string::npos&&typeid(Rect)  == typeid(fig))  
                        )) {
                 i->remove(j); 
            }
        }
    }
}
