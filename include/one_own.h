#ifndef ONE_OWN
    #define ONE_OWN
    #include <stddef.h>
    #include <stdbool.h>
    typedef struct one_own one_ownptr;

    one_ownptr* one_own_create(size_t size);
    one_ownptr* one_own_move(one_ownptr* __dest__);
    void* one_own_get(one_ownptr* p);
    void one_own_realloc(one_ownptr* __ptr,size_t __newSize);
    bool one_own_isvalid(one_ownptr* p);
    #ifndef one_own_set
        #define one_own_set(p,t,v) \
        do {\
            if (one_own_isvalid(p)) {\
                *(t*)one_own_get(p) = v; \
            } \
        } while(0)
    #endif
    void one_own_free(one_ownptr* p);
#endif