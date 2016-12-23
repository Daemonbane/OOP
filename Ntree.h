#ifndef NTREE_H
#define NTREE_H
#include "Ntreenode.h"
#include "Ntreeiterator.h"
#include <memory>
#include <iostream>
using std::shared_ptr;
using std::ostream;
using std::cout;
using std::swap;
template<typename T>
class Ntree { 
    shared_ptr<ntree_node<T> > root;
    int sz;
    public:
      void insert(shared_ptr<T> obj) {
          sz++;
          if(!root)
              root = shared_ptr<ntree_node<T> >(new ntree_node<T>(obj));
          else {
              shared_ptr<ntree_node<T> > ptr = root;
              while(true) {
                  if(*obj > *(ptr->fgr)) {
                      if(ptr->sibling) 
                        ptr = ptr->sibling; else {
                            ptr->sibling =shared_ptr<ntree_node<T> >(new ntree_node<T>(obj));
                            ptr->sibling->parent = ptr;
                            break;
                        }
                  } else
                      if(ptr->child)
                          ptr=  ptr->child; else {
                            ptr->child =shared_ptr<ntree_node<T> >(new ntree_node<T>(obj));
                            ptr->child->parent = ptr;
                            break;
                          }
              }
          }
      }
      void remove(ntree_iterator<T> it) {
          if(it != end()) {
            sz--;
            if(it.ptr->sibling && it.ptr->child) {
                shared_ptr<ntree_node<T> > ptr = it.ptr->child;
                while(ptr->sibling) ptr = ptr->sibling;
                swap(ptr->fgr, it.ptr->fgr);
                remove(ntree_iterator<T>(ptr));
            }
            else {
                shared_ptr<ntree_node<T> > ptr = 
                    it.ptr->sibling? it.ptr->sibling : it.ptr->child;
                if(it.ptr == root)
                    root = ptr;
                else if(it.ptr->parent.lock()->sibling == it.ptr)
                    it.ptr->parent.lock()->sibling = ptr;
                else
                    it.ptr->parent.lock()->child = ptr;
            }
          }
      }
      ntree_iterator<T> begin() {
          shared_ptr<ntree_node<T> > ptr = root;
          if(ptr) while(ptr->child) ptr = ptr->child;
          return ptr;
      }
      ntree_iterator<T> end() {
          return ntree_iterator<T>(nullptr);
      }
      Ntree() {
          root = nullptr;
          sz = 0;
      }
      int Size() {
          return sz;
      }
      template<typename TT>
      friend ostream& operator << (ostream&, Ntree<TT>&);
    private:
      void Print(shared_ptr<ntree_node<T> > ptr, int n = 0){
          if(!ptr) return;
          for(int i = 0; i < n; cout << ' ', i++);
          ptr->fgr->print();
          Print(ptr->child, n+4); 
          Print(ptr->sibling, n); 
      }
};
template<typename T> ostream& operator << (ostream& o, Ntree<T>& n) {
    n.Print(n.root);
    return o;
}
#endif
