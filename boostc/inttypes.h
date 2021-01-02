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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int16_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#    error "Format macro could not be determined for [u]int32_t."
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
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_prid64 "I64d"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_prid64 "lld"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_prid64 "ld"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_prii64
#  ifdef PRIi64
#   define bstc_prii64 PRIi64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_prii64 "I64i"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_prii64 "lli"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_prii64 "li"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_priu64
#  ifdef PRIu64
#   define bstc_priu64 PRIu64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_priu64 "I64u"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_priu64 "llu"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_priu64 "lu"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_prio64
#  ifdef PRIo64
#   define bstc_prio64 PRIo64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_prio64 "I64o"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_prio64 "llo"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_prio64 "lo"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_prix64
#  ifdef PRIx64
#   define bstc_prix64 PRIx64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_prix64 "I64x"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_prix64 "llx"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_prix64 "lx"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_priX64
#  ifdef PRIX64
#   define bstc_priX64 PRIX64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_priX64 "I64X"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_priX64 "llX"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_priX64 "lX"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scnd64
#  ifdef SCNd64
#   define bstc_scnd64 SCNd64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_scnd64 "I64d"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scnd64 "lld"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scnd64 "ld"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scni64
#  ifdef SCNi64
#   define bstc_scni64 SCNi64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_scni64 "I64i"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scni64 "lli"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scni64 "li"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scnu64
#  ifdef SCNu64
#   define bstc_scnu64 SCNu64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_scnu64 "I64u"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scnu64 "llu"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scnu64 "lu"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scno64
#  ifdef SCNo64
#   define bstc_scno64 SCNo64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_scno64 "I64o"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scno64 "llo"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scno64 "lo"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
# ifndef bstc_scnx64
#  ifdef SCNx64
#   define bstc_scnx64 SCNx64
#  else
#   if defined(BSTC_COMPILER_TCC)
#    define  bstc_scnx64 "I64x"
#   else
#    if defined(bstc_ullong_max) && bstc_ullong_max == bstc_uint64_max
#     define bstc_scnx64 "llx"
#    elif bstc_ulong_max == bstc_uint64_max
#     define bstc_scnx64 "lx"
#    else
#     error "Format macro could not be determined for [u]int64_t."
#    endif
#   endif
#  endif
# endif
#endif
