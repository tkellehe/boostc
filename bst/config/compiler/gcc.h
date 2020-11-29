#ifndef BST__CONFIG__COMPILER__GCC_H
#define BST__CONFIG__COMPILER__GCC_H


/* Provide a way to detect the version of GCC */
/// \{
#define BST_GCC_VER (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
/// \}


/* Add branch predictors */
/// \{
#define BST_LIKELY(x) __builtin_expect(x, 1)
#define BST_UNLIKELY(x) __builtin_expect(x, 0)
/// \}


/// \{
#if !defined(__DARWIN_NO_LONG_LONG)
# define BST_HAS_LONG_LONG
#endif
/// \}

#endif // BST__CONFIG__COMPILER__GCC_H