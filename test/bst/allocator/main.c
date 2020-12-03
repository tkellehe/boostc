#include <bst/allocator.h>

// A helper is provided to reference the ppack of the stdlib calls.
#define stdlib alloc_stdlib

// The actual implemenation of the mk_array function. Need the variadic portion to make the other parts easier.
#define mk_array_dtl(T, N, alloc, ...) (T*)alloc_malloc(alloc)(sizeof(T) * N)
// Optional allocator operation where default uses stdlib.
#define mk_array(T, N, ...) \
    /* Select the default argument if nothing is provided. */\
    mk_array_dtl(T, N, ppack_defargs(ppack(__VA_ARGS__), ppack(stdlib)))

#define rm_array_dtl(array, alloc, ...) alloc_free(alloc)((void*)(array))
#define rm_array(array, ...) rm_array_dtl(array, ppack_defargs(ppack(__VA_ARGS__), ppack(stdlib)))

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
