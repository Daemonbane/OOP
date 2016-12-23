#ifndef NTREENODE_H
#define NTREENODE_H
#include <memory>
using std::shared_ptr;
using std::weak_ptr;
template<typename T>
struct ntree_node {
    weak_ptr<ntree_node<T> > parent;
    shared_ptr<ntree_node<T> > child, sibling;
    shared_ptr<T> fgr;
    ntree_node(shared_ptr<T> f) {
        fgr = f;
        child = nullptr;
        sibling = nullptr;
    } 
};
#endif

