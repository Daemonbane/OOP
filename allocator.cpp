#include "allocator.h"
#include <stdlib.h>
#include <stdio.h>
void* Allocator::alloc() {
    if(free_root) { 
        void *ans = free_root;
        free_root = free_root->child;
        return ans;
    }
    else {
        if(memory->used == 8) new_heap();
        return &memory->data[sz*memory->used++];
    }
}

Allocator::Allocator(int sz): sz(sz), free_root(0), memory(0) {
    new_heap();
}

Allocator::~Allocator() {
    while(memory) {
        printf("Deleting heap with %i objects inside (excluding holes)\n", memory->used);
        void *t = (void*) memory;
        memory = memory->nxt;
        ::free(t);
    }
}

Allocator::Heap* Allocator::new_heap() {
    printf("created new heap. sizeof(object) = %i\n", sz);
    Heap *res =(Heap*) malloc(sz*8+sizeof(Heap));
    res->used = 0;
    res->nxt = memory;
    memory = res;
    return res;
}

void Allocator::free(void *p) {
    Node *n = (Node*) p;
    n->child = free_root;
    free_root = n;
}
