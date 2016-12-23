#ifndef ALLOCATOR_H
#define ALLOCATOR_H
class Allocator {
    struct Node {
        Node *child, *sibling;    
    };
    struct Heap {
        Heap *nxt;
        int  used;
        char data[];
    };
    Heap* new_heap();
    int sz;
    Node *free_root;
    Heap *memory;
public:
    Allocator(int);
    ~Allocator();
    void *alloc();
    void free(void*);
};
#endif
