//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/ctuple.h>
#include <boostc/stdlib.h>


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
# define bstc_alloc_free(tpl) bstc_ctuple_getI(tpl, 0)
#endif
/// \}


/** Get the malloc function that has been packed into the ctuple. */
/// \{
#ifndef bstc_alloc_malloc
# define bstc_alloc_malloc(tpl) bstc_ctuple_getI(tpl, 1)
#endif
/// \}


/** Get the realloc function that has been packed into the ctuple. */
/// \{
#ifndef bstc_alloc_realloc
# define bstc_alloc_realloc(tpl) bstc_ctuple_getI(tpl, 2)
#endif
/// \}


/** Create a copy of the ctuple as an allocator with the free function changed to what is provided. */
/// \{
#ifndef bstc_alloc_set_free
# define bstc_alloc_set_free(tpl, free) bstc_ctuple_setI(tpl, 0, free)
#endif
/// \}


/** Create a copy of the ctuple as an allocator with the malloc function changed to what is provided. */
/// \{
#ifndef bstc_alloc_set_malloc
# define bstc_alloc_set_malloc(tpl, malloc) bstc_ctuple_setI(tpl, 1, malloc)
#endif
/// \}


/** Create a copy of the ctuple as an allocator with the realloc function changed to what is provided. */
/// \{
#ifndef bstc_alloc_set_realloc
# define bstc_alloc_set_realloc(tpl, realloc) bstc_ctuple_setI(tpl, 2, realloc)
#endif
/// \}


/** Default allocator ctuple that use the stdlib memory managers. */
/// \{
#ifndef bstc_alloc_stdlib
# define bstc_alloc_stdlib bstc_ctuple(bstc_free, bstc_malloc, bstc_realloc)
#endif
/// \}


/** Default allocator ctuple that uses the no-op memory manager functions. */
/// \{
#ifndef bstc_alloc_defaults
# define bstc_alloc_defaults bstc_ctuple(bstc_alloc_nofree, bstc_alloc_nomalloc, bstc_alloc_norealloc)
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
# define bstc_alloc_nomalloc(size) ((void*)bstc_null)
#endif
/// \}


/** Default realloc function that does nothing. */
/// \{
#ifndef bstc_alloc_norealloc
# define bstc_alloc_norealloc(memory, size) ((void*)bstc_null)
#endif
/// \}


/** Detects if the ctuple provided could be a valid allocator ctuple. */
/// \{
#ifndef bstc_alloc_isa
# define bstc_alloc_isa(tpl, _t, _f) bstc_ctuple_isa(tpl, bstc_ctuple_hasN(tpl, 3, _t, _f), _f)
#endif
/// \}
