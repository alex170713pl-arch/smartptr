# smartptr
C lib for smart pointers 

## API
```c
//one_own struct
struct one_own{
    void* ptr;
    uintptr_t start;
    size_t alloced;
};
//create new one_own pointer (to heap)
one_ownptr* one_own_create(size_t size);
// move ownership of __dest__
one_ownptr* one_own_move(one_ownptr* __dest__);
// get c pointer from one_ownptr
void* one_own_get(one_ownptr* p);
// check pointer 
_Bool one_own_isvalid(one_ownptr* p);
// realloc memory in pointer
void one_own_realloc(one_ownptr* ptr, size_t new_size);
// free of one_ownptr
void one_own_free(one_ownptr* p);
// MACRO: set value to one_ownptr
#define one_own_set(p,t,v) 
/*                  ^ ^ ^
         pointer____| | |
         type_________| |
         value__________|
*/
//shared_ptr struct
struct shared {
    void* ptr;
    size_t refs;
};
//create new shared_ptr
shared_ptr* shared_new(size_t size);
//copy reference to pointer 
shared_ptr* shared_copy(shared_ptr* targ);
//get c pointer from shared
void* shared_get(shared_ptr* targ);
// get count of references to "targ" 
size_t shared_getrefs(shared_ptr* targ);
// check shared_ptr
_Bool shared_isvalid(shared_ptr* p);
//MACRO: set value to shared_ptr
#define shared_set(p,t,v)
/*                  ^ ^ ^
         pointer____| | |
         type_________| |
         value__________|
*/
//realloc memory in pointer
void shared_realloc(shared_ptr* p,size_t __newsize);
//free reference to shared pointer 
void shared_free(shared_ptr** targ);
```
### Examples
```c
#include "one_own.h" 
#include <stdio.h>
int main() {
    // new pointer with size 4 (int)
    one_ownptr* new = one_own_create(4);
    if (!new) return 1;  // check 
    one_own_set(new,int,20); // set value to pointer
    // output value
    printf("value: %d\n",*(int*)one_own_get(new));
    // pointer valid 
    printf("is valid: %d\n",one_own_isvalid(new));
    one_own_free(new); // pointer invalue
    // output 0 (false)
    printf("is valid: %d\n",one_own_isvalid(new));
    return 0;
}
```
```c
#include "shared_ptr.h" //include shared pointers
#include <stdio.h> 
int main() {
    shared_ptr* test = shared_new(4); // new shared ptr
    shared_set(test,int,67); //set val
    printf("value:%d\n",*(int*)shared_get(test)); // 67
    shared_ptr* test2 = shared_copy(test); // +1 ref
    printf("refs:%d %d\n",shared_getrefs(test),shared_getrefs(test2)); // refs:2 2
    shared_free(&test2);
    printf("refs : %d\n",shared_getrefs(test)); // refs: 1
    printf("valid: %d\n",shared_isvalid(test)); // valid: 1
    shared_free(&test); //free test
    printf("refs : %d\n",shared_getrefs(test)); // refs: 0
    printf("valid: %d\n",shared_isvalid(test)); // valid: 0
    return 0;
}
```
#### Install
enter:
```bash
    make #make static lib
    make MODE=DYNAMIC # make .so file
    make clear # delete object files
```
#### License
    MIT
