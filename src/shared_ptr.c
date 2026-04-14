#include "../include/shared_ptr.h"
#include <stdlib.h>
struct shared {
    void* ptr;
    size_t refs;
};
struct weak {
    shared_ptr* ptr;
};
shared_ptr* shared_new(size_t size) {
    shared_ptr* new = malloc(sizeof(shared_ptr));
    if (!new) return NULL;
    new->ptr = malloc(size);
    if (!new->ptr) {
        free(new);
        return NULL;
    }
    new->refs = 1;
    return new;
}
shared_ptr* shared_copy(shared_ptr* targ) {
    if (!targ || !targ->ptr) return NULL;
        targ->refs++;
    return targ;
}
void* shared_get(shared_ptr* targ) {
    if (!targ || !targ->ptr) return NULL;
    return targ->ptr;
}
size_t shared_getrefs(shared_ptr* targ){
    if (!targ || !targ->ptr) return 0;
    return targ->refs;
}
_Bool shared_isvalid(shared_ptr* p) {
    return  p && p->ptr;
}
void shared_free(shared_ptr** targ) {
    if (!targ || !*targ) return;
    
    shared_ptr* p = *targ;
    if (!p->ptr) return;
    
    if (p->refs > 0) {
        p->refs--;
    }
    
    if (p->refs == 0) {
        free(p->ptr);
        free(p);
        *targ = NULL; 
    }
}