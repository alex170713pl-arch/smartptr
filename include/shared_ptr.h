#ifndef SHARED
    #define SHARE
    #include <stddef.h>
    typedef struct shared shared_ptr;
    typedef struct weak weak_ptr;
    shared_ptr* shared_new(size_t size);
    shared_ptr* shared_copy(shared_ptr* targ);
    void* shared_get(shared_ptr* targ);
    #ifndef shared_set
        #define shared_set(p,v) do {\
            *shared_get(p) = v;\
        }while(0)
    #endif
    size_t shared_getrefs(shared_ptr* targ);
    _Bool shared_isvalid(shared_ptr* p);
    void shared_free(shared_ptr** targ);
    /*
    weak_ptr* weak_new(shared_ptr* __src__);
    void weak_update(weak_ptr* __src__);
    shared_ptr* weak_lock(weak_ptr* __src__);
    void weak_free(weak_ptr* __src__);
    void weak_unlock(shared_ptr* __src__);
    */
#endif 