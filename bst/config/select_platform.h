#ifndef BST__CONFIG__SELECT_PLATFORM_H
#define BST__CONFIG__SELECT_PLATFORM_H


/* Determine the Platform type */
/// \{
#ifndef BST_PLATFORM_CONFIG
# if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#  define BST_PLATFORM_WIN32
#  define BST_PLATFORM_CONFIG "bst/config/platform/win32.h"
# elif defined(_WIN64) || defined(__WIN64__) || defined(WIN64)
#  define BST_PLATFORM_WIN64
#  define BST_PLATFORM_CONFIG "bst/config/platform/win64.h"
# elif defined(__CYGWIN__) && !defined(_WIN32)
#  define BST_PLATFORM_CYGWIN
#  define BST_PLATFORM_CONFIG "bst/config/platform/cygwin.h"
# elif defined(__ANDROID__)
#  define BST_PLATFORM_ANDROID
#  define BST_PLATFORM_CONFIG "bst/config/platform/android.h"
# elif (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)
#  define BST_PLATFORM_LINUX
#  define BST_PLATFORM_CONFIG "bst/config/platform/linux.h"
# elif defined(__unix__) || (!defined(__APPLE__) && defined(__MACH__))
#  include <sys/param.h>
#  if defined(BSD) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
#   define BST_PLATFORM_BSD
#   define BST_PLATFORM_CONFIG "bst/config/platform/bsd.h"
#  elif defined(__sgi)
#   define BST_PLATFORM_IRIX
#   define BST_PLATFORM_CONFIG "bst/config/platform/irix.h"
#  endif
# elif defined(__hpux)
#  define BST_PLATFORM_HPUX
#  define BST_PLATFORM_CONFIG "bst/config/platform/hpux.h"
# elif defined(__HAIKU__)
#  define BST_PLATFORM_HAIKU
#  define BST_PLATFORM_CONFIG "bst/config/platform/haiku.h"
# elif defined(__BEOS__)
#  define BST_PLATFORM_BEOS
#  define BST_PLATFORM_CONFIG "bst/config/platform/beos.h"
# elif defined(__IBMCPP__) || defined(_AIX)
#  define BST_PLATFORM_AIX
#  define BST_PLATFORM_CONFIG "bst/config/platform/aix.h"
# elif defined(__amigaos__)
#  define BST_PLATFORM_AMIGAOS
#  define BST_PLATFORM_CONFIG "bst/config/platform/amigaos.h"
# elif defined(__QNXNTO__)
#  define BST_PLATFORM_QNXNTO
#  define BST_PLATFORM_CONFIG "bst/config/platform/qnxnto.h"
# elif defined(__VXWORKS__)
#  define BST_PLATFORM_VXWORKS
#  define BST_PLATFORM_CONFIG "bst/config/platform/vxworks.h"
# elif defined(__SYMBIAN32__)
#  define BST_PLATFORM_SYMBIAN32
#  define BST_PLATFORM_CONFIG "bst/config/platform/symbian32.h"
# elif defined(_CRAYC)
#  define BST_PLATFORM_CRAY
#  define BST_PLATFORM_CONFIG "bst/config/platform/cray.h"
# elif defined(__VMS)
#  define BST_PLATFORM_VMS
#  define BST_PLATFORM_CONFIG "bst/config/platform/vms.h"
# elif defined(__CloudABI__)
#  define BST_PLATFORM_CLOUDABI
#  define BST_PLATFORM_CONFIG "bst/config/platform/cloudabi.h"
# elif defined(__APPLE__) && defined(__MACH__)
#  include <TargetConditionals.h>
#  if TARGET_IPHONE_SIMULATOR == 1
#   define BST_PLATFORM_IOS
#   define BST_PLATFORM_CONFIG "bst/config/platform/ios.h"
#  elif TARGET_OS_IPHONE == 1
#   define BST_PLATFORM_IOS
#  define BST_PLATFORM_CONFIG "bst/config/platform/ios.h"
#  elif TARGET_OS_MAC == 1
#   define BST_PLATFORM_OSX
#   define BST_PLATFORM_CONFIG "bst/config/platform/osx.h"
#  endif
# elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#  define BST_PLATFORM_MACOS
#  define BST_PLATFORM_CONFIG "bst/config/platform/macos.h"
# elif (defined(__sun) && defined(__SVR4)) || defined(__sparc__) || defined(sun)
#  define BST_PLATFORM_SOLARIS
#  define BST_PLATFORM_CONFIG "bst/config/platform/solaris.h"
# else
#  define BST_PLATFORM_UNKNOWN
# endif
#endif
/// \}


/* Determine the basic type of APIs that are available */
/// \{
#if defined(unix) || defined(__unix) || defined(_XOPEN_SOURCE) || defined(_POSIX_SOURCE) \
    || defined(BST_PLATFORM_LINUX)
# define BST_OSAPI_POSIX
#elif defined(BST_PLATFORM_WIN32) || defined(BST_PLATFORM_WIN64) || defined(__WINDOWS__)
# define BST_OSAPI_WINDOWS
#endif
/// \}


#endif // BST__CONFIG__SELECT_PLATFORM_H
