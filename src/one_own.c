#include <stdint.h>
#include <stdlib.h>
#include "../include/one_own.h"
struct one_own{
    void* ptr;
    uintptr_t start;
    size_t alloced;
};

one_ownptr* one_own_create(size_t size) {
    one_ownptr* new = malloc(sizeof(struct one_own));
    if (!new) return NULL;
    new->ptr = malloc(size);
    if (!new->ptr) {
        free(new);
        return NULL;
    }
    new->start = (uintptr_t)new->ptr;
    new->alloced = size;
    return new;
}
one_ownptr* one_own_move(one_ownptr* __dest__) {
    if (!one_own_isvalid(__dest__)) return NULL;
    if (!__dest__ || !__dest__->ptr) return NULL;
    one_ownptr* new = malloc(sizeof(struct one_own));
    if (!new) return NULL;
    new->ptr = __dest__->ptr;
    new->alloced = __dest__->alloced;
    new->start = __dest__->start;
    __dest__->ptr = NULL;
    return new;
}
void* one_own_get(one_ownptr* p) {
    if (!one_own_isvalid(p)) return NULL;
    return p->ptr;
}
_Bool one_own_isvalid(one_ownptr* p) {
    if (!p ) return 0;
    if ((uintptr_t)p->ptr != p->start) return 0;
    return 1;
}
void one_own_realloc(one_ownptr* ptr, size_t new_size) {
    if (!one_own_isvalid(ptr)) return;
    
    void* new_ptr = realloc(ptr->ptr, new_size);
    if (!new_ptr) return;
    
    ptr->ptr = new_ptr;
    ptr->start = (uintptr_t)new_ptr;  // ← обновляем start
    ptr->alloced = new_size;
}
void one_own_free(one_ownptr* p) {
    if (!one_own_isvalid(p)) return;
    p->alloced = 0;
    free(p->ptr);
    free(p);
    p = NULL;
}