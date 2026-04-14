#ifndef SHARED
    #define SHARE
    #include <stddef.h>
    typedef struct shared shared_ptr;
    shared_ptr* shared_new(size_t size);
    shared_ptr* shared_copy(shared_ptr* targ);
    void* shared_get(shared_ptr* targ);
    #ifndef shared_set
        #define shared_set(p,v) do {\
            if (shared_isvalid(p)) {\
                *shared_get(p) = v;\
            }\
        }while(0)
    #endif
    size_t shared_getrefs(shared_ptr* targ);
    _Bool shared_isvalid(shared_ptr* p);
    void shared_free(shared_ptr** targ);
#endif 