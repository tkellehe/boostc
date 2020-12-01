#ifndef BST__VECTOR_H
#define BST__VECTOR_H


#include <bst/config.h>
#include <bst/allocator.h>
#include <bst/assert.h>
#include <bst/ppack.h>


/* Provide interface without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define vect_t bst_vect_t
#define vect_init bst_vect_init
#define vect_destroy bst_vect_destroy
#define vect_cnt bst_vect_cnt
#define vect_cap bst_vect_cap
#define vect_rsz bst_vect_rsz
#define vect_rsv bst_vect_rsv
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
#define vect_iter_set bst_vect_iter_set

#define vect_rbegin bst_vect_rbegin
#define vect_rend bst_vect_rend

#define vect_riter_t bst_vect_riter_t
#define vect_riter_nxt bst_vect_riter_nxt
#define vect_riter_eq bst_vect_riter_eq
#define vect_riter_neq bst_vect_riter_neq
#define vect_riter_val bst_vect_riter_val
#define vect_riter_set bst_vect_riter_set
#endif
/// \}


/** Declares the vector type.
 * \param T The type of the vector.
 */
#define bst_vect_t(T) T*


/** Initializes the vector structure.
 * \param vect Reference to the vector.
 * \return Returns one when successful and zero otherwise.
 */
#define bst_vect_init(vect) (*((void**)&(vect)) = bst_null, 1)


/** Destroys and frees any memory allocated for the vector.
 * \param vect Reference to the vector.
 * \return Returns one when successful and zero otherwise.
 */
#define bst_vect_destroy(vect, ...) bst_dtl_vect_destroy_pkd(bst_ppack_prepend(BST_X1ARGS1(0, ##__VA_ARGS__, bst_alloc_stdlib), vect))


/** Gets the number of items that have been added or resized to.
 * \param vect Reference to the vector.
 * \return Returns the number of items.
 */
#define bst_vect_cnt(vect) ((vect) ? bst_dtl_vect_cnt(vect) : 0)


/** Gets the capacity that the vector has been allocated for.
 * \param vect Reference to the vector.
 * \return Returns the capacity for the vector.
 */
#define bst_vect_cap(vect) ((vect) ? bst_dtl_vect_cap(vect) : 0)


/** Resizes the vector to be able to hold the new size.
 * \param vect Reference to the vector.
 * \param nsz The new size for the vector.
 * \return Returns one when successful and zero otherwise.
 */
#define bst_vect_rsz(vect, nsz, ...) bst_dtl_vect_rsz_pkd(bst_ppack_prepend(BST_X1ARGS1(0, ##__VA_ARGS__, bst_alloc_stdlib), vect, nsz))


/** Reserves the requested capacity for the vector by only reserving more.
 * \param vect Reference to the vector.
 * \param ncap The new capacity for the vector.
 * \return Returns one when successful and zero otherwise.
 */
#define bst_vect_rsv(vect, ncap, ...) bst_dtl_vect_rsv_pkd(bst_ppack_prepend(BST_X1ARGS1(0, ##__VA_ARGS__, bst_alloc_stdlib), vect, ncap))


/** Assert at the index provided then read the value in the array.
 * \param vect Reference to the vector.
 * \param i The index to access.
 * \return Returns the value at the index.
 */
#define bst_vect_at(vect, i) (bst_assert((i) < bst_vect_cnt(vect)), vect[i])


/** Checks to see if the vector is empty.
 * \param vect Reference to the vector.
 * \return Returns one if empty and zero otherwise.
 */
#define bst_vect_empty(vect) (bst_vect_cnt(vect) == 0)


/** Get the front value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the first index.
 */
#define bst_vect_front(vect) (vect)[0]


/** Get the back value of the vector.
 * \param vect Reference to the vector.
 * \return Returns the value at the last index.
 */
#define bst_vect_back(vect) (vect)[bst_dtl_vect_cnt(vect)-1]


/** Pushes a single value onto the back of the vector and resizes if needed.
 * \param vect Reference to the vector.
 * \return Returns the new value pushed on.
 */
#define bst_vect_push(vect, val, ...) bst_dtl_vect_push_pkd(bst_ppack_prepend(BST_X1ARGS1(0, ##__VA_ARGS__, bst_alloc_stdlib), vect, val))


// Working on iterator concept.
#define bst_vect_begin(vect) (vect)
#define bst_vect_end(vect) ((vect)+bst_vect_cnt(vect))

#define bst_vect_iter_t(bst_vect_t) bst_vect_t
#define bst_vect_iter_nxt(iter) (++iter)
#define bst_vect_iter_eq(left, right) (left == right)
#define bst_vect_iter_neq(left, right) (left != right)
#define bst_vect_iter_val(iter) *(iter)
#define bst_vect_iter_set(iter, val) (*(iter) = val)

#define bst_vect_rbegin(vect) ((vect)+bst_vect_cnt(vect))
#define bst_vect_rend(vect) ((vect)+1)

#define bst_vect_riter_t(bst_vect_t) bst_vect_t
#define bst_vect_riter_nxt(iter) (--iter)
#define bst_vect_riter_eq(left, right) (left == right)
#define bst_vect_riter_neq(left, right) (left != right)
#define bst_vect_riter_val(iter) *((iter)-1)
#define bst_vect_riter_set(iter, val) (*((iter)-1) = val)


/* Detail code */
/// \{
#define bst_dtl_vect_raw(vect) ((int*)(void*)(vect) - 2)
#define bst_dtl_vect_cap(vect) (bst_dtl_vect_raw(vect)[0])
#define bst_dtl_vect_cnt(vect) (bst_dtl_vect_raw(vect)[1])
#define bst_dtl_vect_push_pkd(pkd) bst_dtl_vect_push pkd
#define bst_dtl_vect_push(vect, val, free, malloc, realloc, ...) \
(\
    bst_dtl_vect_rsz(vect, (bst_vect_cnt(vect))+1, free, malloc, realloc),\
    (vect)[(bst_dtl_vect_cnt(vect))-1] = (val)\
)
#define bst_dtl_vect_destroy_pkd(pkd) bst_dtl_vect_destroy pkd
#define bst_dtl_vect_destroy(vect, free, malloc, realloc, ...) \
    ((vect) ? free(bst_dtl_vect_raw(vect)),*((void**)&(vect))=bst_null,1 : 0)
#define bst_dtl_vect_rsz_pkd(pkd) bst_dtl_vect_rsz pkd
#define bst_dtl_vect_rsz(vect, nsz, free, malloc, realloc, ...) \
((vect) ?\
    (bst_dtl_vect_cap(vect)*2 > (nsz) ?\
        (\
            *((void**)&(vect)) = (void*)((int*)realloc(\
                bst_dtl_vect_raw(vect),\
                sizeof(*(vect))*(bst_dtl_vect_cap(vect)*2) + 2*sizeof(int)\
            ) + 2),\
            bst_dtl_vect_cnt(vect) = (int)(nsz),\
            bst_dtl_vect_cap(vect) = (bst_dtl_vect_cap(vect)*2),\
            (int)((vect) != 0)\
        )\
    :\
        (\
            *((void**)&(vect)) = (void*)((int*)realloc(\
                bst_dtl_vect_raw(vect),\
                sizeof(*(vect))*(nsz) + 2*sizeof(int)\
            ) + 2),\
            bst_dtl_vect_cnt(vect) = (int)(nsz),\
            bst_dtl_vect_cap(vect) = (int)(nsz),\
            (int)((vect) != 0)\
        )\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((int*)malloc(sizeof(*(vect))*(nsz) + 2*sizeof(int)) + 2),\
        bst_dtl_vect_cnt(vect) = (int)(nsz),\
        bst_dtl_vect_cap(vect) = (int)(nsz),\
        (int)((vect) != 0)\
    )\
)
#define bst_dtl_vect_rsv_pkd(pkd) bst_dtl_vect_rsv pkd
#define bst_dtl_vect_rsv(vect, ncap, free, malloc, realloc, ...) \
((vect) ?\
    (bst_dtl_vect_cap(vect) < (ncap) ?\
        (\
            *((void**)&(vect)) = (void*)((int*)realloc(\
                bst_dtl_vect_raw(vect),\
                sizeof(*(vect))*(ncap) + 2*sizeof(int)\
            ) + 2),\
            bst_dtl_vect_cap(vect) = (int)(ncap),\
            (int)((vect) != 0)\
        )\
    :\
        0\
    )\
:\
    (\
        *((void**)&(vect)) = (void*)((int*)malloc(sizeof(*(vect))*(ncap) + 2*sizeof(int)) + 2),\
        bst_dtl_vect_cnt(vect) = 0,\
        bst_dtl_vect_cap(vect) = (int)(ncap),\
        (int)((vect) != 0)\
    )\
)
/// \}


#endif // BST__VECTOR_H
