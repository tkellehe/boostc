//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>
#include <boostc/stdint.h>


#ifdef BSTC_LEAST_CPP11
# include <cinttypes>
#elif defined(BSTC_LEAST_C99)
# include <inttypes.h>
#endif


// The standard states that if FIXEDTYPE_MAX is not defined,
// then the typedef for the fixed type is not defined.


//------------------------------------------------------------------------------------------------------------
//                                               [u]int8
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uint8_t) || defined(bstc_int8_t)
# ifndef bstc_prid8
#  ifdef PRId8
#   define bstc_prid8 PRId8
#  else
#   define bstc_prid8 "hhd"
#  endif
# endif
# ifndef bstc_prii8
#  ifdef PRIi8
#   define bstc_prii8 PRIi8
#  else
#   define bstc_prii8 "hhi"
#  endif
# endif
# ifndef bstc_priu8
#  ifdef PRIu8
#   define bstc_priu8 PRIu8
#  else
#   define bstc_priu8 "hhu"
#  endif
# endif
# ifndef bstc_prio8
#  ifdef PRIo8
#   define bstc_prio8 PRIo8
#  else
#   define bstc_prio8 "hho"
#  endif
# endif
# ifndef bstc_prix8
#  ifdef PRIx8
#   define bstc_prix8 PRIx8
#  else
#   define bstc_prix8 "hhx"
#  endif
# endif
# ifndef bstc_priX8
#  ifdef PRIX8
#   define bstc_priX8 PRIX8
#  else
#   define bstc_priX8 "hhX"
#  endif
# endif
# ifndef bstc_scnd8
#  ifdef SCNd8
#   define bstc_scnd8 SCNd8
#  else
#   define bstc_scnd8 "hhd"
#  endif
# endif
# ifndef bstc_scni8
#  ifdef SCNi8
#   define bstc_scni8 SCNi8
#  else
#   define bstc_scni8 "hhi"
#  endif
# endif
# ifndef bstc_scnu8
#  ifdef SCNu8
#   define bstc_scnu8 SCNu8
#  else
#   define bstc_scnu8 "hhu"
#  endif
# endif
# ifndef bstc_scno8
#  ifdef SCNo8
#   define bstc_scno8 SCNo8
#  else
#   define bstc_scno8 "hho"
#  endif
# endif
# ifndef bstc_scnx8
#  ifdef SCNx8
#   define bstc_scnx8 SCNx8
#  else
#   define bstc_scnx8 "hhx"
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int16
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uint16_t) || defined(bstc_int16_t)
# ifndef bstc_prid16
#  ifdef PRId16
#   define bstc_prid16 PRId16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_prid16 "hd"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_prid16 "hhd"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_prii16
#  ifdef PRIi16
#   define bstc_prii16 PRIi16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_prii16 "hi"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_prii16 "hhi"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_priu16
#  ifdef PRIu16
#   define bstc_priu16 PRIu16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_priu16 "hu"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_priu16 "hhu"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_prio16
#  ifdef PRIo16
#   define bstc_prio16 PRIo16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_prio16 "ho"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_prio16 "hho"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_prix16
#  ifdef PRIx16
#   define bstc_prix16 PRIx16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_prix16 "hx"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_prix16 "hhx"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_priX16
#  ifdef PRIX16
#   define bstc_priX16 PRIX16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_priX16 "hX"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_priX16 "hhX"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_scnd16
#  ifdef SCNd16
#   define bstc_scnd16 SCNd16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_scnd16 "hd"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_scnd16 "hhd"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_scni16
#  ifdef SCNi16
#   define bstc_scni16 SCNi16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_scni16 "hi"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_scni16 "hhi"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_scnu16
#  ifdef SCNu16
#   define bstc_scnu16 SCNu16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_scnu16 "hu"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_scnu16 "hhu"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_scno16
#  ifdef SCNo16
#   define bstc_scno16 SCNo16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_scno16 "ho"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_scno16 "hho"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
# ifndef bstc_scnx16
#  ifdef SCNx16
#   define bstc_scnx16 SCNx16
#  else
#   if bstc_uint_max == bstc_uint16_max
#    define bstc_scnx16 "hx"
#   elif bstc_ushrt_max == bstc_uint16_max
#    define bstc_scnx16 "hhx"
#   else
#    error "BOOSTC format macro could not be determined for [u]int16_t."
#   endif
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int32
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uint32_t) || defined(bstc_int32_t)
# ifndef bstc_prid32
#  ifdef PRId32
#   define bstc_prid32 PRId32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_prid32 "ld"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_prid32 "d"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_prid32 "hd"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_prii32
#  ifdef PRIi32
#   define bstc_prii32 PRIi32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_prii32 "li"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_prii32 "i"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_prii32 "hi"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_priu32
#  ifdef PRIu32
#   define bstc_priu32 PRIu32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_priu32 "lu"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_priu32 "u"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_priu32 "hu"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_prio32
#  ifdef PRIo32
#   define bstc_prio32 PRIo32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_prio32 "lo"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_prio32 "o"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_prio32 "ho"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_prix32
#  ifdef PRIx32
#   define bstc_prix32 PRIx32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_prix32 "lx"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_prix32 "x"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_prix32 "hx"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_priX32
#  ifdef PRIX32
#   define bstc_priX32 PRIX32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_priX32 "lX"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_priX32 "X"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_priX32 "hX"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_scnd32
#  ifdef SCNd32
#   define bstc_scnd32 SCNd32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_scnd32 "ld"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_scnd32 "d"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_scnd32 "hd"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_scni32
#  ifdef SCNi32
#   define bstc_scni32 SCNi32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_scni32 "li"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_scni32 "i"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_scni32 "hi"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_scnu32
#  ifdef SCNu32
#   define bstc_scnu32 SCNu32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_scnu32 "lu"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_scnu32 "u"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_scnu32 "hu"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_scno32
#  ifdef SCNo32
#   define bstc_scno32 SCNo32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_scno32 "lo"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_scno32 "o"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_scno32 "ho"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
# ifndef bstc_scnx32
#  ifdef SCNx32
#   define bstc_scnx32 SCNx32
#  else
#   if bstc_ulong_max == bstc_uint32_max
#    define bstc_scnx32 "lx"
#   elif bstc_uint_max == bstc_uint32_max
#    define bstc_scnx32 "x"
#   elif bstc_ushrt_max == bstc_uint32_max
#    define bstc_scnx32 "hx"
#   else
#    error "BOOSTC format macro could not be determined for [u]int32_t."
#   endif
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int64
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uint64_t) || defined(bstc_int64_t)
# ifndef bstc_prid64
#  ifdef PRId64
#   define bstc_prid64 PRId64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_prid64 "I64d"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_prid64 "lld"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_prid64 "ld"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_prii64
#  ifdef PRIi64
#   define bstc_prii64 PRIi64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_prii64 "I64i"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_prii64 "lli"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_prii64 "li"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_priu64
#  ifdef PRIu64
#   define bstc_priu64 PRIu64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_priu64 "I64u"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_priu64 "llu"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_priu64 "lu"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_prio64
#  ifdef PRIo64
#   define bstc_prio64 PRIo64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_prio64 "I64o"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_prio64 "llo"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_prio64 "lo"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_prix64
#  ifdef PRIx64
#   define bstc_prix64 PRIx64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_prix64 "I64x"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_prix64 "llx"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_prix64 "lx"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_priX64
#  ifdef PRIX64
#   define bstc_priX64 PRIX64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_priX64 "I64X"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_priX64 "llX"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_priX64 "lX"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scnd64
#  ifdef SCNd64
#   define bstc_scnd64 SCNd64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_scnd64 "I64d"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scnd64 "lld"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scnd64 "ld"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scni64
#  ifdef SCNi64
#   define bstc_scni64 SCNi64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_scni64 "I64i"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scni64 "lli"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scni64 "li"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scnu64
#  ifdef SCNu64
#   define bstc_scnu64 SCNu64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_scnu64 "I64u"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scnu64 "llu"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scnu64 "lu"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scno64
#  ifdef SCNo64
#   define bstc_scno64 SCNo64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_scno64 "I64o"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scno64 "llo"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scno64 "lo"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scnx64
#  ifdef SCNx64
#   define bstc_scnx64 SCNx64
#  else
#   if defined(BSTC_COMPILER_TCC) || defined(BSTC_COMPILER_WATCOM) || defined(BSTC_COMPILER_BORLAND)
#    define  bstc_scnx64 "I64x"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scnx64 "llx"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scnx64 "lx"
#    else
#     error "BOOSTC format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]intptr
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uintptr_t) || defined(bstc_intptr_t)
# ifndef bstc_pridptr
#  ifdef PRIdPTR
#   define bstc_pridptr PRIdPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_pridptr bstc_prid64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_pridptr bstc_prid32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_pridptr bstc_prid16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_pridptr bstc_prid8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_priiptr
#  ifdef PRIiPTR
#   define bstc_priiptr PRIiPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_priiptr bstc_prii64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_priiptr bstc_prii32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_priiptr bstc_prii16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_priiptr bstc_prii8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_priuptr
#  ifdef PRIuPTR
#   define bstc_priuptr PRIuPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_priuptr bstc_priu64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_priuptr bstc_priu32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_priuptr bstc_priu16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_priuptr bstc_priu8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_prioptr
#  ifdef PRIoPTR
#   define bstc_prioptr PRIoPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_prioptr bstc_prio64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_prioptr bstc_prio32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_prioptr bstc_prio16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_prioptr bstc_prio8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_prixptr
#  ifdef PRIxPTR
#   define bstc_prixptr PRIxPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_prixptr bstc_prix64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_prixptr bstc_prix32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_prixptr bstc_prix16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_prixptr bstc_prix8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_priXptr
#  ifdef PRIXPTR
#   define bstc_priXptr PRIXPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_priXptr bstc_priX64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_priXptr bstc_priX32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_priXptr bstc_priX16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_priXptr bstc_priX8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_scndptr
#  ifdef SCNdPTR
#   define bstc_scndptr SCNdPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_scndptr bstc_scnd64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_scndptr bstc_scnd32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_scndptr bstc_scnd16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_scndptr bstc_scnd8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_scniptr
#  ifdef SCNiPTR
#   define bstc_scniptr SCNiPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_scniptr bstc_scni64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_scniptr bstc_scni32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_scniptr bstc_scni16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_scniptr bstc_scni8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_scnuptr
#  ifdef SCNuPTR
#   define bstc_scnuptr SCNuPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_scnuptr bstc_scnu64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_scnuptr bstc_scnu32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_scnuptr bstc_scnu16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_scnuptr bstc_scnu8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_scnoptr
#  ifdef SCNoPTR
#   define bstc_scnoptr SCNoPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_scnoptr bstc_scno64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_scnoptr bstc_scno32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_scnoptr bstc_scno16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_scnoptr bstc_scno8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
# ifndef bstc_scnxptr
#  ifdef SCNxPTR
#   define bstc_scnxptr SCNxPTR
#  else
#   if defined(bstc_uint64_max) && bstc_uintptr_max == bstc_uint64_max
#    define bstc_scnxptr bstc_scnx64
#   elif bstc_uintptr_max == bstc_uint32_max
#    define bstc_scnxptr bstc_scnx32
#   elif bstc_uintptr_max == bstc_uint16_max
#    define bstc_scnxptr bstc_scnx16
#   elif bstc_uintptr_max == bstc_uint8_max
#    define bstc_scnxptr bstc_scnx8
#   else
#    error "BOOSTC format macro could not be determined for [u]intptr_t."
#   endif
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]intmax
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uintmax_t) || defined(bstc_intmax_t)
# ifndef bstc_pridmax
#  ifdef PRIdMAX
#   define bstc_pridmax PRIdMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_pridmax bstc_prid64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_pridmax bstc_prid32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_pridmax bstc_prid16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_pridmax bstc_prid8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_priimax
#  ifdef PRIiMAX
#   define bstc_priimax PRIiMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_priimax bstc_prii64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_priimax bstc_prii32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_priimax bstc_prii16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_priimax bstc_prii8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_priumax
#  ifdef PRIuMAX
#   define bstc_priumax PRIuMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_priumax bstc_priu64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_priumax bstc_priu32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_priumax bstc_priu16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_priumax bstc_priu8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_priomax
#  ifdef PRIoMAX
#   define bstc_priomax PRIoMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_priomax bstc_prio64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_priomax bstc_prio32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_priomax bstc_prio16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_priomax bstc_prio8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_prixmax
#  ifdef PRIxMAX
#   define bstc_prixmax PRIxMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_prixmax bstc_prix64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_prixmax bstc_prix32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_prixmax bstc_prix16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_prixmax bstc_prix8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_priXmax
#  ifdef PRIXMAX
#   define bstc_priXmax PRIXMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_priXmax bstc_priX64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_priXmax bstc_priX32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_priXmax bstc_priX16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_priXmax bstc_priX8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_scndmax
#  ifdef SCNdMAX
#   define bstc_scndmax SCNdMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_scndmax bstc_scnd64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_scndmax bstc_scnd32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_scndmax bstc_scnd16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_scndmax bstc_scnd8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_scnimax
#  ifdef SCNiMAX
#   define bstc_scnimax SCNiMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_scnimax bstc_scni64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_scnimax bstc_scni32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_scnimax bstc_scni16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_scnimax bstc_scni8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_scnumax
#  ifdef SCNuMAX
#   define bstc_scnumax SCNuMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_scnumax bstc_scnu64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_scnumax bstc_scnu32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_scnumax bstc_scnu16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_scnumax bstc_scnu8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_scnomax
#  ifdef SCNoMAX
#   define bstc_scnomax SCNoMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_scnomax bstc_scno64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_scnomax bstc_scno32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_scnomax bstc_scno16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_scnomax bstc_scno8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
# ifndef bstc_scnxmax
#  ifdef SCNxMAX
#   define bstc_scnxmax SCNxMAX
#  else
#   if defined(bstc_uint64_max) && bstc_uintmax_max == bstc_uint64_max
#    define bstc_scnxmax bstc_scnx64
#   elif bstc_uintmax_max == bstc_uint32_max
#    define bstc_scnxmax bstc_scnx32
#   elif bstc_uintmax_max == bstc_uint16_max
#    define bstc_scnxmax bstc_scnx16
#   elif bstc_uintmax_max == bstc_uint8_max
#    define bstc_scnxmax bstc_scnx8
#   else
#    error "BOOSTC format macro could not be determined for [u]intmax_t."
#   endif
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int_least8
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uint_least8_t) || defined(bstc_int_least8_t)
# ifndef bstc_prid_least8
#  ifdef PRIdLEAST8
#   define bstc_prid_least8 PRIdLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_prid_least8 bstc_prid64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_prid_least8 bstc_prid32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_prid_least8 bstc_prid16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_prid_least8 bstc_prid8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_prii_least8
#  ifdef PRIiLEAST8
#   define bstc_prii_least8 PRIiLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_prii_least8 bstc_prii64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_prii_least8 bstc_prii32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_prii_least8 bstc_prii16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_prii_least8 bstc_prii8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_priu_least8
#  ifdef PRIuLEAST8
#   define bstc_priu_least8 PRIuLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_priu_least8 bstc_priu64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_priu_least8 bstc_priu32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_priu_least8 bstc_priu16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_priu_least8 bstc_priu8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_prio_least8
#  ifdef PRIoLEAST8
#   define bstc_prio_least8 PRIoLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_prio_least8 bstc_prio64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_prio_least8 bstc_prio32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_prio_least8 bstc_prio16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_prio_least8 bstc_prio8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_prix_least8
#  ifdef PRIxLEAST8
#   define bstc_prix_least8 PRIxLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_prix_least8 bstc_prix64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_prix_least8 bstc_prix32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_prix_least8 bstc_prix16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_prix_least8 bstc_prix8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_priX_least8
#  ifdef PRIXLEAST8
#   define bstc_priX_least8 PRIXLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_priX_least8 bstc_priX64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_priX_least8 bstc_priX32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_priX_least8 bstc_priX16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_priX_least8 bstc_priX8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_scnd_least8
#  ifdef SCNdLEAST8
#   define bstc_scnd_least8 SCNdLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_scnd_least8 bstc_scnd64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_scnd_least8 bstc_scnd32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_scnd_least8 bstc_scnd16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_scnd_least8 bstc_scnd8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_scni_least8
#  ifdef SCNiLEAST8
#   define bstc_scni_least8 SCNiLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_scni_least8 bstc_scni64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_scni_least8 bstc_scni32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_scni_least8 bstc_scni16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_scni_least8 bstc_scni8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_scnu_least8
#  ifdef SCNuLEAST8
#   define bstc_scnu_least8 SCNuLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_scnu_least8 bstc_scnu64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_scnu_least8 bstc_scnu32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_scnu_least8 bstc_scnu16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_scnu_least8 bstc_scnu8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_scno_least8
#  ifdef SCNoLEAST8
#   define bstc_scno_least8 SCNoLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_scno_least8 bstc_scno64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_scno_least8 bstc_scno32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_scno_least8 bstc_scno16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_scno_least8 bstc_scno8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
# ifndef bstc_scnx_least8
#  ifdef SCNxLEAST8
#   define bstc_scnx_least8 SCNxLEAST8
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least8_max == bstc_uint64_max
#    define bstc_scnx_least8 bstc_scnx64
#   elif bstc_uint_least8_max == bstc_uint32_max
#    define bstc_scnx_least8 bstc_scnx32
#   elif bstc_uint_least8_max == bstc_uint16_max
#    define bstc_scnx_least8 bstc_scnx16
#   elif bstc_uint_least8_max == bstc_uint8_max
#    define bstc_scnx_least8 bstc_scnx8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least8_t."
#   endif
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int_least16
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uint_least16_t) || defined(bstc_int_least16_t)
# ifndef bstc_prid_least16
#  ifdef PRIdLEAST16
#   define bstc_prid_least16 PRIdLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_prid_least16 bstc_prid64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_prid_least16 bstc_prid32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_prid_least16 bstc_prid16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_prid_least16 bstc_prid8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_prii_least16
#  ifdef PRIiLEAST16
#   define bstc_prii_least16 PRIiLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_prii_least16 bstc_prii64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_prii_least16 bstc_prii32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_prii_least16 bstc_prii16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_prii_least16 bstc_prii8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_priu_least16
#  ifdef PRIuLEAST16
#   define bstc_priu_least16 PRIuLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_priu_least16 bstc_priu64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_priu_least16 bstc_priu32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_priu_least16 bstc_priu16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_priu_least16 bstc_priu8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_prio_least16
#  ifdef PRIoLEAST16
#   define bstc_prio_least16 PRIoLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_prio_least16 bstc_prio64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_prio_least16 bstc_prio32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_prio_least16 bstc_prio16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_prio_least16 bstc_prio8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_prix_least16
#  ifdef PRIxLEAST16
#   define bstc_prix_least16 PRIxLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_prix_least16 bstc_prix64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_prix_least16 bstc_prix32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_prix_least16 bstc_prix16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_prix_least16 bstc_prix8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_priX_least16
#  ifdef PRIXLEAST16
#   define bstc_priX_least16 PRIXLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_priX_least16 bstc_priX64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_priX_least16 bstc_priX32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_priX_least16 bstc_priX16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_priX_least16 bstc_priX8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_scnd_least16
#  ifdef SCNdLEAST16
#   define bstc_scnd_least16 SCNdLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_scnd_least16 bstc_scnd64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_scnd_least16 bstc_scnd32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_scnd_least16 bstc_scnd16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_scnd_least16 bstc_scnd8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_scni_least16
#  ifdef SCNiLEAST16
#   define bstc_scni_least16 SCNiLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_scni_least16 bstc_scni64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_scni_least16 bstc_scni32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_scni_least16 bstc_scni16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_scni_least16 bstc_scni8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_scnu_least16
#  ifdef SCNuLEAST16
#   define bstc_scnu_least16 SCNuLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_scnu_least16 bstc_scnu64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_scnu_least16 bstc_scnu32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_scnu_least16 bstc_scnu16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_scnu_least16 bstc_scnu8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_scno_least16
#  ifdef SCNoLEAST16
#   define bstc_scno_least16 SCNoLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_scno_least16 bstc_scno64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_scno_least16 bstc_scno32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_scno_least16 bstc_scno16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_scno_least16 bstc_scno8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
# ifndef bstc_scnx_least16
#  ifdef SCNxLEAST16
#   define bstc_scnx_least16 SCNxLEAST16
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least16_max == bstc_uint64_max
#    define bstc_scnx_least16 bstc_scnx64
#   elif bstc_uint_least16_max == bstc_uint32_max
#    define bstc_scnx_least16 bstc_scnx32
#   elif bstc_uint_least16_max == bstc_uint16_max
#    define bstc_scnx_least16 bstc_scnx16
#   elif bstc_uint_least16_max == bstc_uint8_max
#    define bstc_scnx_least16 bstc_scnx8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least16_t."
#   endif
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int_least32
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uint_least32_t) || defined(bstc_int_least32_t)
# ifndef bstc_prid_least32
#  ifdef PRIdLEAST32
#   define bstc_prid_least32 PRIdLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_prid_least32 bstc_prid64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_prid_least32 bstc_prid32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_prid_least32 bstc_prid16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_prid_least32 bstc_prid8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_prii_least32
#  ifdef PRIiLEAST32
#   define bstc_prii_least32 PRIiLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_prii_least32 bstc_prii64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_prii_least32 bstc_prii32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_prii_least32 bstc_prii16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_prii_least32 bstc_prii8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_priu_least32
#  ifdef PRIuLEAST32
#   define bstc_priu_least32 PRIuLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_priu_least32 bstc_priu64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_priu_least32 bstc_priu32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_priu_least32 bstc_priu16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_priu_least32 bstc_priu8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_prio_least32
#  ifdef PRIoLEAST32
#   define bstc_prio_least32 PRIoLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_prio_least32 bstc_prio64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_prio_least32 bstc_prio32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_prio_least32 bstc_prio16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_prio_least32 bstc_prio8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_prix_least32
#  ifdef PRIxLEAST32
#   define bstc_prix_least32 PRIxLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_prix_least32 bstc_prix64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_prix_least32 bstc_prix32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_prix_least32 bstc_prix16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_prix_least32 bstc_prix8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_priX_least32
#  ifdef PRIXLEAST32
#   define bstc_priX_least32 PRIXLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_priX_least32 bstc_priX64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_priX_least32 bstc_priX32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_priX_least32 bstc_priX16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_priX_least32 bstc_priX8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_scnd_least32
#  ifdef SCNdLEAST32
#   define bstc_scnd_least32 SCNdLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_scnd_least32 bstc_scnd64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_scnd_least32 bstc_scnd32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_scnd_least32 bstc_scnd16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_scnd_least32 bstc_scnd8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_scni_least32
#  ifdef SCNiLEAST32
#   define bstc_scni_least32 SCNiLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_scni_least32 bstc_scni64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_scni_least32 bstc_scni32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_scni_least32 bstc_scni16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_scni_least32 bstc_scni8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_scnu_least32
#  ifdef SCNuLEAST32
#   define bstc_scnu_least32 SCNuLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_scnu_least32 bstc_scnu64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_scnu_least32 bstc_scnu32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_scnu_least32 bstc_scnu16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_scnu_least32 bstc_scnu8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_scno_least32
#  ifdef SCNoLEAST32
#   define bstc_scno_least32 SCNoLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_scno_least32 bstc_scno64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_scno_least32 bstc_scno32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_scno_least32 bstc_scno16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_scno_least32 bstc_scno8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
# ifndef bstc_scnx_least32
#  ifdef SCNxLEAST32
#   define bstc_scnx_least32 SCNxLEAST32
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least32_max == bstc_uint64_max
#    define bstc_scnx_least32 bstc_scnx64
#   elif bstc_uint_least32_max == bstc_uint32_max
#    define bstc_scnx_least32 bstc_scnx32
#   elif bstc_uint_least32_max == bstc_uint16_max
#    define bstc_scnx_least32 bstc_scnx16
#   elif bstc_uint_least32_max == bstc_uint8_max
#    define bstc_scnx_least32 bstc_scnx8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least32_t."
#   endif
#  endif
# endif
#endif


//------------------------------------------------------------------------------------------------------------
//                                               [u]int_least64
//------------------------------------------------------------------------------------------------------------
#if defined(bstc_uint_least64_t) || defined(bstc_int_least64_t)
# ifndef bstc_prid_least64
#  ifdef PRIdLEAST64
#   define bstc_prid_least64 PRIdLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_prid_least64 bstc_prid64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_prid_least64 bstc_prid32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_prid_least64 bstc_prid16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_prid_least64 bstc_prid8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_prii_least64
#  ifdef PRIiLEAST64
#   define bstc_prii_least64 PRIiLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_prii_least64 bstc_prii64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_prii_least64 bstc_prii32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_prii_least64 bstc_prii16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_prii_least64 bstc_prii8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_priu_least64
#  ifdef PRIuLEAST64
#   define bstc_priu_least64 PRIuLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_priu_least64 bstc_priu64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_priu_least64 bstc_priu32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_priu_least64 bstc_priu16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_priu_least64 bstc_priu8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_prio_least64
#  ifdef PRIoLEAST64
#   define bstc_prio_least64 PRIoLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_prio_least64 bstc_prio64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_prio_least64 bstc_prio32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_prio_least64 bstc_prio16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_prio_least64 bstc_prio8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_prix_least64
#  ifdef PRIxLEAST64
#   define bstc_prix_least64 PRIxLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_prix_least64 bstc_prix64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_prix_least64 bstc_prix32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_prix_least64 bstc_prix16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_prix_least64 bstc_prix8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_priX_least64
#  ifdef PRIXLEAST64
#   define bstc_priX_least64 PRIXLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_priX_least64 bstc_priX64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_priX_least64 bstc_priX32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_priX_least64 bstc_priX16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_priX_least64 bstc_priX8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_scnd_least64
#  ifdef SCNdLEAST64
#   define bstc_scnd_least64 SCNdLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_scnd_least64 bstc_scnd64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_scnd_least64 bstc_scnd32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_scnd_least64 bstc_scnd16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_scnd_least64 bstc_scnd8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_scni_least64
#  ifdef SCNiLEAST64
#   define bstc_scni_least64 SCNiLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_scni_least64 bstc_scni64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_scni_least64 bstc_scni32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_scni_least64 bstc_scni16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_scni_least64 bstc_scni8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_scnu_least64
#  ifdef SCNuLEAST64
#   define bstc_scnu_least64 SCNuLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_scnu_least64 bstc_scnu64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_scnu_least64 bstc_scnu32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_scnu_least64 bstc_scnu16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_scnu_least64 bstc_scnu8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_scno_least64
#  ifdef SCNoLEAST64
#   define bstc_scno_least64 SCNoLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_scno_least64 bstc_scno64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_scno_least64 bstc_scno32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_scno_least64 bstc_scno16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_scno_least64 bstc_scno8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
# ifndef bstc_scnx_least64
#  ifdef SCNxLEAST64
#   define bstc_scnx_least64 SCNxLEAST64
#  else
#   if defined(bstc_uint64_max) && bstc_uint_least64_max == bstc_uint64_max
#    define bstc_scnx_least64 bstc_scnx64
#   elif bstc_uint_least64_max == bstc_uint32_max
#    define bstc_scnx_least64 bstc_scnx32
#   elif bstc_uint_least64_max == bstc_uint16_max
#    define bstc_scnx_least64 bstc_scnx16
#   elif bstc_uint_least64_max == bstc_uint8_max
#    define bstc_scnx_least64 bstc_scnx8
#   else
#    error "BOOSTC format macro could not be determined for [u]int_least64_t."
#   endif
#  endif
# endif
#endif
