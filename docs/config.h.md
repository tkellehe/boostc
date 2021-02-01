![boostc icon](https://tkellehe.github.io/boostc/images/boostc-icon.png)

[Home](https://tkellehe.github.io/boostc/docs/)

# boostc/config.h

Utilizes directives to make decisions about the environment.
These decisions include compiler, platform, and language versions.

## Version

 * `BSTC` : Assigned an integer value presenting the current version of __boostc__ included.

|-version-|-description|
|  `0L`   | Unreleased version for testing |

## Language Versions Detection
The following are macros defined depending on if _C++_ is used or _C_ and are determined in the header `boostc/config/version.h`.
Most testing has obviously been done for _C_.
Note that the _C_ group will not be provided if _C++_ is used, and vice versa.

### C Language Detection

 * `BSTC_LEAST_C95` : Present if using a compiler that supports at least _C95_ features.
 * `BSTC_LEAST_C99` : Present if using a compiler that supports at least _C99_ features.
 * `BSTC_LEAST_C11` : Present if using a compiler that supports at least _C11_ features.
 * `BSTC_LEAST_C17` : Present if using a compiler that supports at least _C17_ changes.

### C++ Language Detection

 * `BSTC_LEAST_CPP98` : Present if using a compiler that supports at least _C++98_ features.
 * `BSTC_LEAST_CPP11` : Present if using a compiler that supports at least _C++11_ features.
 * `BSTC_LEAST_CPP14` : Present if using a compiler that supports at least _C++14_ features.
 * `BSTC_LEAST_CPP17` : Present if using a compiler that supports at least _C++17_ features.
 * `BSTC_LEAST_CPP20` : Present if using a compiler that supports at least _C++20_ features.

### Note

 > `BSTC_LEAST_C95` and `BSTC_LEAST_C99` are always present in the current supported version.
 > The same goes for `BSTC_LEAST_CPP98` if using _C++_.
 > This is because _boostc_ utilizes variadic macros which is a _C99_ feature.
 > There are some designs for a non-variadic interface, but not much push at this time.

## Compiler Detection
The following are macros defined depending on the compiler detected.
The lists are organized based off of the level of support.
Some compilers have been tested hands on, some have been estimated, and others can be detected but will not work.

 * `BSTC_COMPILER_UNKNOWN` : Will be defined if a compiler could not be determined.
 * `BSTC_COMPILER_CONFIG` : A string of the _boostc_ compiler header to be included that is defined if a compiler could be determined.

The configuration file that gets included by `BSTC_COMILER_CONFIG` being defined,
provides detection for specific variables and may preset macros within the _boostc_ interface.
For example, `boostc/config/compiler/visualc.h` sets `bstc_int64_t` if the `stdint.h` is not provided and 64-bits is supported.
That way the `boostc/stdint.h` does not have to provide detailed detection for what is very specific to the _visual-c_ compiler.

### Tested

 * `BSTC_COMPILER_CLANG` : Present if the _clang_ compiler is used.
 * `BSTC_COMPILER_GCC` : Present if the _GNU C_ compiler is used.
 * `BSTC_COMPILER_TCC` : Present if the _Tiny-C_ compiler is used.
 * `BSTC_COMPILER_VISUALC` : Present if the _visual-c_ compiler is used.

### Supported?
These have not been tested with the compiler, but there is some preliminary work done.

 * `BSTC_COMPILER_BORLANDC` : Present if the _Borland-C_ compiler is used.
 * `BSTC_COMPILER_WATCOM` : Present if the _Watcom_ compiler is used.

### Detecting?
These should be detecting correctly but have nothing laid out.

* `BSTC_COMPILER_GCCXML` : Present if the _GCCXML_ compiler is used.
* `BSTC_COMPILER_CRAY` : Present if the _CRAY_ compiler is used.
* `BSTC_COMPILER_INTEL` : Present if the _Intel_ compiler is used.
* `BSTC_COMPILER_EMSCRIPTEN` : Present if the _EMSCRIPTEN_ compiler is used.
* `BSTC_COMPILER_MINGW32` : Present if the _MINGW32_ compiler is used.
* `BSTC_COMPILER_MINGW64` : Present if the _MINGW64_ compiler is used.

## Platform Detection

BSTC_PLATFORM_UNKNOWN
BSTC_PLATFORM_CONFIG
The following are macros defined depending on the compiler detected.
The lists are organized based off of the level of support.
Some compilers have been tested hands on, some have been estimated, and others can be detected but will not work.

 * `BSTC_COMPILER_UNKNOWN` : Will be defined if a compiler could not be determined.
 * `BSTC_COMPILER_CONFIG` : A string of the _boostc_ compiler header to be included that is defined if a compiler could be determined.

The configuration file that gets included by `BSTC_COMILER_CONFIG` being defined,
provides detection for specific variables and may preset macros within the _boostc_ interface.
For example, `boostc/config/compiler/visualc.h` sets `bstc_int64_t` if the `stdint.h` is not provided and 64-bits is supported.
That way the `boostc/stdint.h` does not have to provide detailed detection for what is very specific to the _visual-c_ compiler.

### Tested

 * `BSTC_PLATFORM_WIN32` : Present if the _win32_ platform is detected.
 * `BSTC_PLATFORM_CYGWIN` : Present if the _Cygwin_ platform is detected.
 * `BSTC_PLATFORM_LINUX` : Present if the _Linux_ platform is detected.

### Supported?
These have not been tested with the platform, but there is some preliminary work done.

### Detecting?
These should be detecting correctly but have nothing laid out.

 * `BSTC_PLATFORM_WIN64` : Present if the _win64_ platform is detected.
 * `BSTC_PLATFORM_ANDROID` : Present if the _ANDROID_ platform is detected.
 * `BSTC_PLATFORM_BSD` : Present if the _BSD_ platform is detected.
 * `BSTC_PLATFORM_IRIX` : Present if the _IRIX_ platform is detected.
 * `BSTC_PLATFORM_HPUX` : Present if the _HPUX_ platform is detected.
 * `BSTC_PLATFORM_HAIKU` : Present if the _HAIKU_ platform is detected.
 * `BSTC_PLATFORM_BEOS` : Present if the _BEOS_ platform is detected.
 * `BSTC_PLATFORM_AIX` : Present if the _AIX_ platform is detected.
 * `BSTC_PLATFORM_AMIGAOS` : Present if the _AMIGAOS_ platform is detected.
 * `BSTC_PLATFORM_QNXNTO` : Present if the _QNXNTO_ platform is detected.
 * `BSTC_PLATFORM_VXWORKS` : Present if the _VXWORKS_ platform is detected.
 * `BSTC_PLATFORM_SYMBIAN32` : Present if the _SYMBIAN32_ platform is detected.
 * `BSTC_PLATFORM_CRAY` : Present if the _CRAY_ platform is detected.
 * `BSTC_PLATFORM_VMS` : Present if the _VMS_ platform is detected.
 * `BSTC_PLATFORM_CLOUDABI` : Present if the _CLOUDABI_ platform is detected.
 * `BSTC_PLATFORM_IOS` : Present if the _iOS_ platform is detected.
 * `BSTC_PLATFORM_OSX` : Present if the _OSX_ platform is detected.
 * `BSTC_PLATFORM_MACOS` : Present if the _MACOS_ platform is detected.
 * `BSTC_PLATFORM_SOLARIS` : Present if the _SOLARIS_ platform is detected.

## Language/Environment Feature Detection
These are list of macros defined for detecting features about the language/environment.

 * `BSTC_NO_64BIT` & `BSTC_HAS_64BIT` : Defined based off of if 64-bit integers are available.
 * `BOOST_NO_LONG_LONG` & `BOOST_HAS_LONG_LONG` : Defined based off of if `long long` is available.
 * `BSTC_NO_STRING_PASTE` & `BSTC_HAS_STRING_PASTE` : Defined based off if symbols can be pasted next to a string literal.
 * `BSTC_NO_VA_ARGS_PASTE` & `BSTC_HAS_VA_ARGS_PASTE` : Defined based off if concatenation of the empty character and `__VA_ARGS__` is supported by the compiler.
 * `BSTC_NO_STDATOMICS` & `BSTC_HAS_STDATOMICS` : Defined based off if the standard atomics library is provided.
 * `BSTC_NO_STDTHREADS` & `BSTC_HAS_STDTHREADS` : Defined based off if the standard threads library is provided.
 * `BSTC_LIKELY(expr)` : A macro for branch prediction to begin as _likely_ detection if available else it will insert the boolean expression.
 * `BSTC_UNLIKELY(expr)` : A macro for branch prediction to begin as _unlikely_ detection if available else it will insert the boolean expression.
 * `BSTC_INLINE` : Provides _C_ style inline keyword insert if available else it will be empty.
 * `BSTC_INTPTR_NBITS` : A constant macro defined as the number of bits that `intptr_t` is.
 * `bstc_nullptr` : A macro to represent `NULL` and `nullptr` depending on what is supported.

### Macro Helpers
The following are macros provided to assist with creating the _boostc_ library.

 * `BSTC_UNPACK(...)` : Unpacks a symbol parameter tuple representation by using it like `BSTC_UNPACK tpl`.
 * `BSTC_ISA_TUPLE(tpl, _t, _f)` : If the provided symbol is a tuple then `_t` will be inserted, otherwise `_f` will be inserted.
 * `BSTC_IF_ARG0_EMPTY(tpl, _t, _f)` : If the provided tuple represents `(,...)` then `_t` will be inserted, otherwise `_f` will be inserted.
 * `BSTC_JOIN2(L, R)` : Pastes the two symbols provided expanding each one before concatenation.
 * `BSTC_JOIN3(L, C, R)` : Pastes the three symbols provided expanding each one before concatenation.
 * `BSTC_TOSTRING(X)` : Converts the symbols provided into a string and expands them.
 * `BSTC_ARGCNT(...)` : Counts the number of arguments provided where zero is not supported. Note that `BSTC_IF_ARG0_EMPTY` can be used for detecting zero.
 * `BSTC_IFEQ(X, Y, T, F)` : Detects if two literals in `[0-100]` are equal selecting `T` if true and `F` otherwise.
 * `BSTC_IFLT(X, Y, T, F)` : Compares two literals in `[0-100]` if `X` is less than `Y` then `T` is selected and `F` otherwise.
 * `BSTC_IFGT(X, Y, T, F)` : Compares two literals in `[0-100]` if `X` is greater than `Y` then `T` is selected and `F` otherwise.
 * `BSTC_GET_ARG[0-101](...)` : Gets the `Nth` argument provided.
 * `BSTC_CONST_ADD1(N)` : Adds one to a literal in `[0-100]`.
 * `BSTC_CONST_SUB1(N)` : Subs one to a literal in `[1-101]`.
