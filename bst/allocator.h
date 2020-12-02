#include <bst/allocator.h>

// A helper is provided to reference the ppack of the stdlib calls.
#define stdlib alloc_stdlib

// The actual implemenation of the mk_array function. Need the variadic portion to make the other parts easier.
#define mk_array_dtl(T, N, free, malloc, realloc, ...) (T*)malloc(sizeof(T) * N)
// Unpacks the parameters to call the actual implementation.
#define mk_array_dtl_pkd(pkd) mk_array_dtl pkd
// Optional allocator operation where default uses stdlib.
#define mk_array(T, N, ...) \
    mk_array_dtl_pkd(\
        /* Build up the ppack to be decompressed. */\
        ppack_prepend(\
            /* Select the default argument if nothing is provided. */\
            BST_X1ARGS1(0, ##__VA_ARGS__, stdlib), T, N\
        )\
    )

#define rm_array_dtl(array, free, malloc, realloc, ...) free((void*)(array))
#define rm_array_dtl_pkd(pkd) rm_array_dtl pkd
#define rm_array(array, ...) rm_array_dtl_pkd(ppack_prepend(BST_X1ARGS1(0, ##__VA_ARGS__, stdlib), array))

int _pos = 0;
char _memory[1024] = {0,};
void *mymalloc(int size) { int pos = _pos; _pos += size; return (void*)(_memory + pos); }

// The allocator interface provides calls to be able to ensure that the std order is always packed correctly.
// Also, the default free and realloc calls are set to do-nothings.
#define myalloc alloc_ppack_malloc(mymalloc)

int main()
{
    {
        // Use the stdlib memory management calls.
        int *array = mk_array(int, 10);
        rm_array(array);
    }
    {
        // Use the user defined memory management calls.
        int *array = mk_array(int, 10, myalloc);
        // This evaluates to a do-nothing statement.
        rm_array(array, myalloc);
    }
    return 0;
}
