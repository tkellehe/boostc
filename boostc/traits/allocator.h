//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/stdlib.h>


/** Ensure that the parameters are packed into a tuple. */
/// \{
#ifndef bstc_alloc
# define bstc_alloc(f, m, r) (f, m, r)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the free function provided. */
/// \{
#ifndef bstc_alloc_pack_free
# define bstc_alloc_pack_free(free) bstc_alloc_set_free(bstc_alloc_defaults, free)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the malloc function provided. */
/// \{
#ifndef bstc_alloc_pack_malloc
# define bstc_alloc_pack_malloc(malloc) bstc_alloc_set_malloc(bstc_alloc_defaults, malloc)
#endif
/// \}


/** Creates a ctuple with the defaults set except for the realloc function provided. */
/// \{
#ifndef bstc_alloc_pack_realloc
# define bstc_alloc_pack_realloc(realloc) bstc_alloc_set_realloc(bstc_alloc_defaults, realloc)
#endif
/// \}


/** Get the free function that has been packed into the ctuple. */
/// \{
#ifndef bstc_alloc_free
# define bstc_dtl_alloc_free(f, m, r) f
# define bstc_alloc_free(tpl) BSTC_EXPAND(bstc_dtl_alloc_free tpl)
#endif
/// \}


/** Get the malloc function that has been packed into the ctuple. */
/// \{
#ifndef bstc_alloc_malloc
# define bstc_dtl_alloc_malloc(f, m, r) m
# define bstc_alloc_malloc(tpl) BSTC_EXPAND(bstc_dtl_alloc_malloc tpl)
#endif
/// \}


/** Get the realloc function that has been packed into the ctuple. */
/// \{
#ifndef bstc_alloc_realloc
# define bstc_dtl_alloc_realloc(f, m, r) r
# define bstc_alloc_realloc(tpl) BSTC_EXPAND(bstc_dtl_alloc_realloc tpl)
#endif
/// \}


/** Create a copy of the ctuple as an allocator with the free function changed to what is provided. */
/// \{
#ifndef bstc_alloc_set_free
# define bstc_dtl_alloc_set_free(tpl, free) bstc_dtl_alloc_set_free_expand(BSTC_LAYOUT3 tpl, free)
# define bstc_dtl_alloc_set_free_expand(L, free) BSTC_EXPAND(bstc_dtl_alloc_set_free_expand1(L, free))
# define bstc_dtl_alloc_set_free_expand1(f, m, r, free) bstc_alloc(free, m, r)
# define bstc_alloc_set_free(tpl, free) BSTC_EXPAND(bstc_dtl_alloc_set_free(tpl, free))
#endif
/// \}


/** Create a copy of the ctuple as an allocator with the malloc function changed to what is provided. */
/// \{
#ifndef bstc_alloc_set_malloc
# define bstc_dtl_alloc_set_malloc(tpl, malloc) bstc_dtl_alloc_set_malloc_expand(BSTC_LAYOUT3 tpl, malloc)
# define bstc_dtl_alloc_set_malloc_expand(L, malloc) BSTC_EXPAND(bstc_dtl_alloc_set_malloc_expand1(L, malloc))
# define bstc_dtl_alloc_set_malloc_expand1(f, m, r, malloc) bstc_alloc(f, malloc, r)
# define bstc_alloc_set_malloc(tpl, malloc) BSTC_EXPAND(bstc_dtl_alloc_set_malloc(tpl, malloc))
#endif
/// \}


/** Create a copy of the ctuple as an allocator with the realloc function changed to what is provided. */
/// \{
#ifndef bstc_alloc_set_realloc
# define bstc_dtl_alloc_set_realloc(tpl, realloc) bstc_dtl_alloc_set_realloc_expand(BSTC_LAYOUT3 tpl, realloc)
# define bstc_dtl_alloc_set_realloc_expand(L, realloc) BSTC_EXPAND(bstc_dtl_alloc_set_realloc_expand1(L, realloc))
# define bstc_dtl_alloc_set_realloc_expand1(f, m, r, realloc) bstc_alloc(f, m, realloc)
# define bstc_alloc_set_realloc(tpl, realloc) BSTC_EXPAND(bstc_dtl_alloc_set_realloc(tpl, realloc))
#endif
/// \}


/** Default allocator ctuple that use the stdlib memory managers. */
/// \{
#ifndef bstc_alloc_stdlib
# define bstc_alloc_stdlib bstc_alloc(bstc_free, bstc_malloc, bstc_realloc)
#endif
/// \}


/** Default allocator ctuple that uses the no-op memory manager functions. */
/// \{
#ifndef bstc_alloc_defaults
# define bstc_alloc_defaults bstc_alloc(bstc_alloc_nofree, bstc_alloc_nomalloc, bstc_alloc_norealloc)
#endif
/// \}


/** Default free function that does nothing. */
/// \{
#ifndef bstc_alloc_nofree
# define bstc_alloc_nofree(memory) ((void)0)
#endif
/// \}


/** Default malloc function that does nothing. */
/// \{
#ifndef bstc_alloc_nomalloc
# define bstc_alloc_nomalloc(size) ((void*)bstc_nullptr)
#endif
/// \}


/** Default realloc function that does nothing. */
/// \{
#ifndef bstc_alloc_norealloc
# define bstc_alloc_norealloc(memory, size) ((void*)bstc_nullptr)
#endif
/// \}


/** Detects if the ctuple provided could be a valid allocator ctuple. */
/// \{
#ifndef bstc_alloc_isa
# ifdef BSTC_HAS_VARIADIC_MACROS
#  define bstc_alloc_isa(tpl, _t, _f) bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 3, _t, _f), _f)
# endif
#endif
/// \}
