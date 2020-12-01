#ifndef BST__ALGORITHM__FIND_H
#define BST__ALGORITHM__FIND_H


#include <bst/config.h>


/* Provide interface with no namespace */
/// \{
#ifdef BST_NO_NAMESPACE
# define alg_findpred bst_alg_findpred
# define alg_find bst_alg_find
#endif
/// \}


/* Uses the BST iterator interface to interact with unordered content */
/// \{
#define bst_alg_find(prefix, iter, end, val) bst_alg_findpred(prefix, iter, end, (BST_JOIN(prefix, _val)(iter) == val))
#define bst_alg_findpred(prefix, iter, end, pred) (\
    ({\
        for(; BST_JOIN(prefix, _neq)(iter, end); BST_JOIN(prefix, _nxt)(iter))\
            if((pred)) break;\
    }),\
    iter\
)
/// \}


#endif
