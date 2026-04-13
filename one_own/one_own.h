#ifndef ONE_OWN
    #define ONE_OWN
    #include <stddef.h>
    typedef struct one_own one_ownptr;

    one_ownptr* one_own_create(size_t size);
    void one_own_move(one_ownptr* targ);
    void* one_own_get(one_ownptr* p);
    void one_own_realloc(one_ownptr* __ptr,size_t __newSize);
    _Bool __one_own_check(one_ownptr* p);
    #ifndef one_own_set
        #define one_own_set(p,t,v) \
        do {\
            if (__one_own_check(p)) {\
                *(v*)one_own_get(p) = v; \
            } \
        } while(0)
    #endif
    void one_own_free(one_ownptr* p);
#endif