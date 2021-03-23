//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONTAINER__DETAIL__VECTOR_H
#define BOOSTC__CONTAINER__DETAIL__VECTOR_H


#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/stddef.h>
#include <boostc/stdint.h>
#include <boostc/string.h>
#include <boostc/traits/container.h>


#ifdef BSTC_HAS_VARIADIC_MACROS

/** Adds the default vector traits if they are not provided. */
/// {
# define bstc_dtl_vect_add_traits_prepend2(...) bstc_ctuple(__VA_ARGS__)
# define bstc_dtl_vect_add_traits_prepend1(L, R) BSTC_EXPAND(bstc_dtl_vect_add_traits_prepend2(L, R))
# define bstc_dtl_vect_add_traits_prepend(tpl) BSTC_EXPAND(bstc_dtl_vect_add_traits_prepend1(bstc_dtl_vect_traits1(void), bstc_ctuple_layout tpl))
# define bstc_dtl_vect_add_traits_no(tpl) tpl
# define bstc_dtl_vect_add_traits_select(tpl) bstc_container_isa(BSTC_GET_ARG0 tpl, bstc_dtl_vect_add_traits_no, bstc_dtl_vect_add_traits_prepend)
# define bstc_dtl_vect_add_traits(tpl) bstc_dtl_vect_add_traits_select(tpl) (tpl)
/// }


/** Selects the correct function based off of the number of arguments provided. */
/// {
# define bstc_dtl_vect_traits_select(tpl) \
    bstc_ctuple_hasN(tpl, 1,\
        bstc_dtl_vect_traits1,\
        bstc_ctuple_hasN(tpl, 2,\
            bstc_dtl_vect_traits2_select,\
            bstc_dtl_vect_traits3_select\
        )\
    )
/// }


/** Creates the vector traits given only the type. */
/// {
# define bstc_dtl_vect_traits1(T) \
    (\
        T*,\
        T,\
        BSTC_CTUPLE1(T),\
        bstc_dtl_vect_obj_defaults(T),\
        bstc_alloc_stdlib\
    )
/// }


/** Selects the correct function and order of the parameters provided. */
/// {
# define bstc_dtl_vect_traits2_select(x, y) \
    bstc_alloc_isa(x,\
        /* The first argument is an allocator traits so the other has to be the type. */\
        bstc_dtl_vect_traits2_alloc(y, x),\
        bstc_container_isa(x,\
            /* The first argument is a container traits so the other has to be the type. */\
            bstc_dtl_vect_traits2_subtraits(y, x),\
            /* The first argument is the type, so now we check y. */\
            bstc_alloc_isa(y,\
                /* First argument is the type and the second is the allocator traits. */\
                bstc_dtl_vect_traits2_alloc(x, y),\
                /* First argument is the type and the second is the container traits. */\
                bstc_dtl_vect_traits2_subtraits(x, y)\
            )\
        )\
    )
/// }


/** Creates the traits with the type and either the allocator traits or the sub-traits. */
/// {
# define bstc_dtl_vect_traits2_alloc(T, alloc) \
    (\
        T*,\
        T,\
        BSTC_CTUPLE1(T),\
        bstc_dtl_vect_obj_defaults(T),\
        alloc\
    )

# define bstc_dtl_vect_traits2_subtraits(T, subtraits) \
    (\
        T*,\
        T,\
        subtraits,\
        bstc_dtl_vect_obj_defaults(T),\
        bstc_alloc_stdlib\
    )
/// }


/** Selects the correct order for the parameters provided. */
/// {
# define bstc_dtl_vect_traits3_select(x, y, z) \
    bstc_alloc_isa(x,\
        bstc_container_isa(y,\
            bstc_dtl_vect_traits3(z, x, y),\
            bstc_dtl_vect_traits3(y, x, z)\
        ),\
        bstc_container_isa(x,\
            bstc_alloc_isa(y,\
                bstc_dtl_vect_traits3(z, y, x),\
                bstc_dtl_vect_traits3(y, z, x)\
            ),\
            bstc_alloc_isa(y,\
                bstc_dtl_vect_traits3(x, y, z),\
                bstc_dtl_vect_traits3(x, z, y)\
            )\
        )\
    )
/// }
#endif // BSTC_HAS_VARIADIC_MACROS


/** The object like functions supported by the vector. */
/// {
#define bstc_dtl_vect_obj_defaults(T) \
    bstc_obj_traits(\
        T*,\
        bstc_dtl_vect_init,\
        bstc_dtl_vect_destroy,\
        bstc_obj_nocptor,\
        bstc_obj_noassign\
    )
/// }


/** Takes in all templated parts of the vector. */
/// {
#define bstc_dtl_vect_traits3(T, alloc, subtraits) \
    (\
        T*,\
        T,\
        subtraits,\
        bstc_dtl_vect_obj_defaults(T),\
        alloc\
    )
/// }


/** The header structure to the fat pointer. */
/// {
typedef struct { bstc_size_t cap_; bstc_size_t len_; } bstc_dtl_vect_header_t;
#define bstc_dtl_vect_header(vect) (((bstc_dtl_vect_header_t*)(*(vect))) - 1)
/// }



/** Provides the implementation for the ctor selection. */
/// {
#ifdef BSTC_HAS_VARIADIC_MACROS
# define bstc_dtl_vect_ctor_impl(traits, start, len, ctor) \
    bstc_size_t __bstc_dtl_i;\
    for(__bstc_dtl_i = (len); __bstc_dtl_i--;)\
    {\
        bstc_container_info(traits)* __bstc_dtl_item = ((start) + __bstc_dtl_i);\
        ctor(bstc_container_subtraits(traits), __bstc_dtl_item);\
    }
# define bstc_dtl_vect_ctor_container(subtraits, item) bstc_obj_ctor(bstc_container_obj(subtraits))(subtraits, item)
# define bstc_dtl_vect_ctor_no(subtraits, item) ((void)0)
# define bstc_dtl_vect_ctor(traits, start, len) \
    bstc_ctuple_hasGT(bstc_container_subtraits(traits), 1,\
        bstc_dtl_vect_ctor_impl(traits, start, len,\
            bstc_container_isa(bstc_container_subtraits(traits),\
                bstc_dtl_vect_ctor_container,\
                bstc_dtl_vect_ctor_no\
            )\
        ),\
        ((void)0)\
    )
#else
# define bstc_dtl_vect_ctor(traits, start, len) ((void)0)
#endif
/// }


/** Provides the implementation for the dtor selection. */
/// {
#ifdef BSTC_HAS_VARIADIC_MACROS
# define bstc_dtl_vect_dtor_impl(traits, start, len, dtor) \
    bstc_size_t __bstc_dtl_i;\
    for(__bstc_dtl_i = (len); __bstc_dtl_i--;)\
    {\
        bstc_container_info(traits)* __bstc_dtl_item = ((start) + __bstc_dtl_i);\
        dtor(bstc_container_subtraits(traits), __bstc_dtl_item);\
    }
# define bstc_dtl_vect_dtor_container(subtraits, item) bstc_obj_dtor(bstc_container_obj(subtraits))(subtraits, item)
# define bstc_dtl_vect_dtor_no(subtraits, item) ((void)0)
# define bstc_dtl_vect_dtor(traits, start, len) \
    bstc_ctuple_hasGT(bstc_container_subtraits(traits), 1,\
        bstc_dtl_vect_dtor_impl(traits, start, len,\
            bstc_container_isa(bstc_container_subtraits(traits),\
                bstc_dtl_vect_dtor_container,\
                bstc_dtl_vect_dtor_no\
            )\
        ),\
        ((void)0)\
    )
#else
# define bstc_dtl_vect_dtor(traits, start, len) ((void)0)
#endif
/// }


/** Provides the implementation for the ctor selection. */
/// {
#ifdef BSTC_HAS_VARIADIC_MACROS
# define bstc_dtl_vect_cptor_impl(traits, item, val, cptor) cptor(bstc_container_subtraits(traits), item, val)
# define bstc_dtl_vect_cptor_container(subtraits, item, val) bstc_obj_cptor(bstc_container_obj(subtraits))(subtraits, item, val)
# define bstc_dtl_vect_cptor_no(subtraits, item, val) *(item) = (val)
# define bstc_dtl_vect_cptor(traits, item, val) \
    bstc_ctuple_hasGT(bstc_container_subtraits(traits), 1,\
        bstc_dtl_vect_cptor_impl(traits, item, val,\
            bstc_container_isa(bstc_container_subtraits(traits),\
                bstc_dtl_vect_cptor_container,\
                bstc_dtl_vect_cptor_no\
            )\
        ),\
        *(item) = (val)\
    )
#else
# define bstc_dtl_vect_cptor(traits, item, val) *(item) = (val)
#endif
/// }


/** Initializes the vector to null which makes it easier given that we are using fat pointers. */
/// {
#define bstc_dtl_vect_init(traits, vect) *(vect) = bstc_nullptr
/// }


/** Reclaims all of the memory that has been allocated where if BSTC_HAS_VARIADIC_MACROS is defined then it will call the destructor (if possible).
 * The `do-while` is added to force users to end with a semicolon.
 */
/// {
#define bstc_dtl_vect_destroy(traits, vect) \
    do {if(*(vect)) {\
        bstc_dtl_vect_dtor(traits, (*(vect)), bstc_dtl_vect_header(vect)->len_);\
        bstc_alloc_free(bstc_container_alloc(traits))(bstc_dtl_vect_header(vect));\
        *(vect) = bstc_nullptr;}\
    } while(0)
/// }


/** The simple basic access functions. */
/// {
#define bstc_dtl_vect_len(traits, vect) ((*(vect)) ? bstc_dtl_vect_header(vect)->len_ : 0)
#define bstc_dtl_vect_cap(traits, vect) ((*(vect)) ? bstc_dtl_vect_header(vect)->cap_ : 0)
#define bstc_dtl_vect_data(traits, vect) (*(vect))
#define bstc_dtl_vect_empty(traits, vect) (bstc_dtl_vect_len(traits, vect) == 0)
#define bstc_dtl_vect_at(traits, vect, i) ((*(vect))[(i)])
#define bstc_dtl_vect_front(traits, vect) ((*(vect))[0])
#define bstc_dtl_vect_back(traits, vect) ((*(vect))[bstc_dtl_vect_header(vect)->len_-1])
/// }


/** Implements the resize function with dtor and ctor calls depending on how the size changes. */
/// {
#define bstc_dtl_vect_rsz(traits, vect, nsz) \
    do {\
        bstc_size_t __bstc_dtl_nsz = (bstc_size_t)(nsz);\
        if(*(vect)) {\
            /* Check to see if the new size already fits. */\
            if(bstc_dtl_vect_header(vect)->cap_ < __bstc_dtl_nsz) {\
                /* Since it does not fit, check to see if twice the current size will hold the new size. */\
                if(bstc_dtl_vect_header(vect)->cap_*2 > __bstc_dtl_nsz) {\
                    (*((void**)(vect))) = (void*)(((bstc_dtl_vect_header_t*)(bstc_alloc_realloc(bstc_container_alloc(traits))(\
                        (void*)(*(vect)),\
                        sizeof(*(*(vect)))*(bstc_dtl_vect_header(vect)->cap_*2) + sizeof(bstc_dtl_vect_header_t)\
                    )))+1);\
                    bstc_dtl_vect_header(vect)->cap_ = (bstc_dtl_vect_header(vect)->cap_*2);\
                }else{\
                     (*((void**)(vect))) = (void*)(((bstc_dtl_vect_header_t*)(bstc_alloc_realloc(bstc_container_alloc(traits))(\
                        (void*)(*(vect)),\
                        sizeof(*(*(vect)))*(__bstc_dtl_nsz) + sizeof(bstc_dtl_vect_header_t)\
                    )))+1);\
                    bstc_dtl_vect_header(vect)->cap_ = __bstc_dtl_nsz;\
                }\
            }\
        } else { \
             (*((void**)(vect))) = (void*)(((bstc_dtl_vect_header_t*)(bstc_alloc_malloc(bstc_container_alloc(traits))(\
                sizeof(*(*(vect)))*(__bstc_dtl_nsz) + sizeof(bstc_dtl_vect_header_t)\
            )))+1);\
            bstc_dtl_vect_header(vect)->cap_ = __bstc_dtl_nsz;\
        }\
        if(bstc_dtl_vect_header(vect)->len_ < __bstc_dtl_nsz)\
            bstc_dtl_vect_dtor(traits, ((*(vect)) + (__bstc_dtl_nsz - bstc_dtl_vect_header(vect)->len_)), (__bstc_dtl_nsz - bstc_dtl_vect_header(vect)->len_));\
        else\
            bstc_dtl_vect_ctor(traits, ((*(vect)) + (bstc_dtl_vect_header(vect)->len_ - __bstc_dtl_nsz)), (bstc_dtl_vect_header(vect)->len_ - __bstc_dtl_nsz));\
        bstc_dtl_vect_header(vect)->len_ = __bstc_dtl_nsz;\
    } while(0)
/// }


/** Implements the reserve function which merely ensures enough memory is allocated for the request and never shrinks. */
/// {
#define bstc_dtl_vect_rsv(traits, vect, ncap) \
    do {\
        /* Check to see if the new capacity already fits. */\
        bstc_size_t __bstc_dtl_ncap = (bstc_size_t)(ncap);\
        if(*(vect)){\
            if(bstc_dtl_vect_header(vect)->cap_ < __bstc_dtl_ncap) {\
                 (*((void**)(vect))) = (void*)(((bstc_dtl_vect_header_t*)(bstc_alloc_realloc(bstc_container_alloc(traits))(\
                    (void*)(*(vect)),\
                    sizeof(*(*(vect)))*(__bstc_dtl_ncap) + sizeof(bstc_dtl_vect_header_t)\
                )))+1);\
                bstc_dtl_vect_header(vect)->cap_ = __bstc_dtl_ncap;\
            }\
        } else {\
             (*((void**)(vect))) = (void*)(((bstc_dtl_vect_header_t*)(bstc_alloc_malloc(bstc_container_alloc(traits))(\
                sizeof(*(*(vect)))*(__bstc_dtl_ncap) + sizeof(bstc_dtl_vect_header_t)\
            )))+1);\
            bstc_dtl_vect_header(vect)->len_ = 0;\
            bstc_dtl_vect_header(vect)->cap_ = __bstc_dtl_ncap;\
        }\
    } while(0)
/// }


/** Implements the push back function that applies the copy constructor if it is available. */
/// {
#define bstc_dtl_vect_pushb(traits, vect, val) \
    do {\
        if(*(vect)){\
            if(bstc_dtl_vect_header(vect)->cap_ < (bstc_dtl_vect_header(vect)->len_+1))\
            {\
                (*((void**)(vect))) = (void*)(((bstc_dtl_vect_header_t*)(bstc_alloc_realloc(bstc_container_alloc(traits))(\
                    (void*)(*(vect)),\
                    sizeof(*(*(vect)))*(bstc_dtl_vect_header(vect)->cap_*2) + sizeof(bstc_dtl_vect_header_t)\
                )))+1);\
                bstc_dtl_vect_header(vect)->cap_ *= 2;\
            }\
        } else {\
             (*((void**)(vect))) = (void*)(((bstc_dtl_vect_header_t*)(bstc_alloc_malloc(bstc_container_alloc(traits))(\
                sizeof(*(*(vect)))*(2) + sizeof(bstc_dtl_vect_header_t)\
            )))+1);\
            bstc_dtl_vect_header(vect)->len_ = 0;\
            bstc_dtl_vect_header(vect)->cap_ = 2;\
        }\
        bstc_dtl_vect_cptor(traits, ((*(vect)) + bstc_dtl_vect_header(vect)->len_), (val));\
        bstc_dtl_vect_header(vect)->len_ += 1;\
    } while(0)
/// }


#endif // BOOSTC__CONTAINER__DETAIL__VECTOR_H
