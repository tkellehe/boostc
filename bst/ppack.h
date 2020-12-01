#ifndef BST__PPACK_H
#define BST__PPACK_H


#ifdef __cplusplus
extern "C" {
#endif


/* Provide without namespace */
/// \{
#ifdef BST_NO_NAMESPACE
#define ppack bst_ppack
#define punpack bst_punpack
#define ppack_append bst_ppack_append
#define ppack_prepend bst_ppack_prepend
#endif
/// \}


/* Provide a helper that allows for parameter packing and unpacking */
/// \{
#define bst_ppack(...) (__VA_ARGS__)
/* Usage: bst_punpack pkd */
#define bst_punpack(...) __VA_ARGS__
#define bst_ppack_append(pkd, a, ...) (bst_punpack pkd, a, ##__VA_ARGS__)
#define bst_ppack_prepend(pkd, a, ...) (a, ##__VA_ARGS__, bst_punpack pkd)
/// \}


#ifdef __cplusplus
}
#endif


#endif // BST__PPACK_H