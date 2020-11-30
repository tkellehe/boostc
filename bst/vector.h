#ifndef BST__VECTOR_H
#define BST__VECTOR_H


#include <bst/config.h>
#include <bst/assert.h>
// #include <bst/allocator.h> // Working on allocator concept.


/* Provide interface without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define vect_t bst_vect_t
#define vect_init bst_vect_init
#define vect_destroy bst_vect_destroy
#define vect_cnt bst_vect_cnt
#define vect_cap bst_vect_cap
#define vect_rsz bst_vect_rsz
#define vect_empty bst_vect_empty
#define vect_front bst_vect_front
#define vect_back bst_vect_back
#define vect_push bst_vect_push

#define vect_begin bst_vect_begin
#define vect_end bst_vect_end

#define vect_iter_t bst_vect_iter_t
#define vect_iter_nxt bst_vect_iter_nxt
#define vect_iter_eq bst_vect_iter_eq
#define vect_iter_neq bst_vect_iter_neq
#define vect_iter_val bst_vect_iter_val

#define vect_rbegin bst_vect_rbegin
#define vect_rend bst_vect_rend

#define vect_riter_t bst_vect_riter_t
#define vect_riter_nxt bst_vect_riter_nxt
#define vect_riter_eq bst_vect_riter_eq
#define vect_riter_neq bst_vect_riter_neq
#define vect_riter_val bst_vect_riter_val
#endif
/// \}


// May change to have default vect be some statically allocated zero sized.
// Then would speed up check to see if null or not.


/** Declares the vector type.
* \param T The type of the vector.
*/
#define bst_vect_t(T) (T)*
#define bst_vect_init(vect) (*((void**)&(vect)) = bst_null, 1)
#define bst_vect_destroy(vect) ((vect) ? free(__bst_vect_raw(vect)),*((void**)&(vect))=bst_null,1 : 0)
#define bst_vect_cnt(vect) ((vect) ? __bst_vect_cnt(vect) : 0)
#define bst_vect_cap(vect) ((vect) ? __bst_vect_cap(vect) : 0)
#define bst_vect_rsz(vect, nsz) ((vect) ?\
    (__bst_vect_cap(vect)*2 > (nsz) ?\
        (\
            *((void**)&(vect)) = (void*)((int*)realloc(__bst_vect_raw(vect), sizeof(*(vect))*(__bst_vect_cap(vect)*2) + 2*sizeof(int)) + 2),\
            __bst_vect_cnt(vect) = (int)(nsz),\
            __bst_vect_cap(vect) = (__bst_vect_cap(vect)*2),\
            (int)((vect) != 0)\
        )\
    :\
        (\
            *((void**)&(vect)) = (void*)((int*)realloc(__bst_vect_raw(vect), sizeof(*(vect))*(nsz) + 2*sizeof(int)) + 2),\
            __bst_vect_cnt(vect) = (int)(nsz),\
            __bst_vect_cap(vect) = (int)(nsz),\
            (int)((vect) != 0)\
        )\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((int*)malloc(sizeof(*(vect))*(nsz) + 2*sizeof(int)) + 2),\
        __bst_vect_cnt(vect) = (int)(nsz),\
        __bst_vect_cap(vect) = (int)(nsz),\
        (int)((vect) != 0)\
    )\
)
#define bst_vect_at(vect, i) (bst_assert((i) < bst_vect_cnt(vect)), vect[i])
#define bst_vect_empty(vect) (bst_vect_cnt(vect) == 0)
#define bst_vect_front(vect) (vect)[0]
#define bst_vect_back(vect) (vect)[__bst_vect_cnt(vect)-1]
#define bst_vect_push(vect, val) (bst_vect_rsz(vect, (__bst_vect_cnt(vect))+1), (vect)[(__bst_vect_cnt(vect))-1] = (val))

#define __bst_vect_raw(vect) ((int*)(void*)(vect) - 2)
#define __bst_vect_cap(vect) (__bst_vect_raw(vect)[0])
#define __bst_vect_cnt(vect) (__bst_vect_raw(vect)[1])



// Working on iterator concept.
#define bst_vect_begin(vect) 0
#define bst_vect_end(vect) bst_vect_cnt(vect)

#define bst_vect_iter_t(T) int
#define bst_vect_iter_nxt(vect, iter) (++iter)
#define bst_vect_iter_eq(vect, left, right) (left == right)
#define bst_vect_iter_neq(vect, left, right) (left != right)
#define bst_vect_iter_val(vect, iter) vect[iter]

#define bst_vect_rbegin(vect) bst_vect_cnt(vect)
#define bst_vect_rend(vect) 0

#define bst_vect_riter_t(T) int
#define bst_vect_riter_nxt(vect, iter) (--iter)
#define bst_vect_riter_eq(vect, left, right) (left == right)
#define bst_vect_riter_neq(vect, left, right) (left != right)
#define bst_vect_riter_val(vect, iter) vect[iter-1]



#endif // BST__VECTOR_H