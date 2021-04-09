//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOSTC__CONFIG__SELECT_PLATFORM_H
#define BOOSTC__CONFIG__SELECT_PLATFORM_H


/* Determine the Platform type. */
/// \{
#ifndef BSTC_PLATFORM_CONFIG
# if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#  define BSTC_PLATFORM_WIN32
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/win32.h"
#  include <boostc/config/platform/win32.h>
# elif defined(_WIN64) || defined(__WIN64__) || defined(WIN64)
#  define BSTC_PLATFORM_WIN64
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/win64.h"
#  include <boostc/config/platform/win64.h>
# elif defined(__CYGWIN__) && !defined(_WIN32)
#  define BSTC_PLATFORM_CYGWIN
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/cygwin.h"
#  include <boostc/config/platform/cygwin.h>
# elif defined(__ANDROID__)
#  define BSTC_PLATFORM_ANDROID
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/android.h"
#  include <boostc/config/platform/android.h>
# elif (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)
#  define BSTC_PLATFORM_LINUX
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/linux.h"
#  include <boostc/config/platform/linux.h>
# elif defined(__unix__) || (!defined(__APPLE__) && defined(__MACH__))
#  include <sys/param.h>
#  if defined(BSD) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
#   define BSTC_PLATFORM_BSD
#   define BSTC_PLATFORM_CONFIG "boostc/config/platform/bsd.h"
#   include <boostc/config/platform/bsd.h>
#  elif defined(__sgi)
#   define BSTC_PLATFORM_IRIX
#   define BSTC_PLATFORM_CONFIG "boostc/config/platform/irix.h"
#   include <boostc/config/platform/irix.h>
#  endif
# elif defined(__hpux)
#  define BSTC_PLATFORM_HPUX
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/hpux.h"
#  include <boostc/config/platform/hpux.h>
# elif defined(__HAIKU__)
#  define BSTC_PLATFORM_HAIKU
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/haiku.h"
#  include <boostc/config/platform/haiku.h>
# elif defined(__BEOS__)
#  define BSTC_PLATFORM_BEOS
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/beos.h"
#  include <boostc/config/platform/beos.h>
# elif defined(__IBMCPP__) || defined(_AIX)
#  define BSTC_PLATFORM_AIX
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/aix.h"
#  include <boostc/config/platform/aix.h>
# elif defined(__amigaos__)
#  define BSTC_PLATFORM_AMIGAOS
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/amigaos.h"
#  include <boostc/config/platform/amigaos.h>
# elif defined(__QNXNTO__)
#  define BSTC_PLATFORM_QNXNTO
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/qnxnto.h"
#  include <boostc/config/platform/qnxnto.h>
# elif defined(__VXWORKS__)
#  define BSTC_PLATFORM_VXWORKS
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/vxworks.h"
#  include <boostc/config/platform/vxworks.h>
# elif defined(__SYMBIAN32__)
#  define BSTC_PLATFORM_SYMBIAN32
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/symbian32.h"
#  include <boostc/config/platform/symbian32.h>
# elif defined(_CRAYC)
#  define BSTC_PLATFORM_CRAY
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/cray.h"
#  include <boostc/config/platform/cray.h>
# elif defined(__VMS)
#  define BSTC_PLATFORM_VMS
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/vms.h"
#  include <boostc/config/platform/vms.h>
# elif defined(__CloudABI__)
#  define BSTC_PLATFORM_CLOUDABI
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/cloudabi.h"
#  include <boostc/config/platform/cloudabi.h>
# elif defined(__APPLE__) && defined(__MACH__)
#  include <TargetConditionals.h>
#  if TARGET_IPHONE_SIMULATOR == 1
#   define BSTC_PLATFORM_IOS
#   define BSTC_PLATFORM_CONFIG "boostc/config/platform/ios.h"
#   include <boostc/config/platform/ios.h>
#  elif TARGET_OS_IPHONE == 1
#   define BSTC_PLATFORM_IOS
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/ios.h"
#  include <boostc/config/platform/ios.h>
#  elif TARGET_OS_MAC == 1
#   define BSTC_PLATFORM_OSX
#   define BSTC_PLATFORM_CONFIG "boostc/config/platform/osx.h"
#   include <boostc/config/platform/osx.h>
#  endif
# elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#  define BSTC_PLATFORM_MACOS
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/macos.h"
#  include <boostc/config/platform/macos.h>
# elif (defined(__sun) && defined(__SVR4)) || defined(__sparc__) || defined(sun)
#  define BSTC_PLATFORM_SOLARIS
#  define BSTC_PLATFORM_CONFIG "boostc/config/platform/solaris.h"
#  include <boostc/config/platform/solaris.h>
# else
#  define BSTC_PLATFORM_UNKNOWN
# endif
#endif
/// \}


/* Determine the basic type of APIs that are available */
/// \{
#if !defined(BSTC_OSAPI_POSIX) && !defined(BSTC_OSAPI_WINDOWS)
# if defined(unix) || defined(__unix) || defined(_XOPEN_SOURCE) || defined(_POSIX_SOURCE)
#  define BSTC_OSAPI_POSIX
# elif defined(__WINDOWS__)
#  define BSTC_OSAPI_WINDOWS
# else
#  error "BOOSTC platform API could not be determined."
# endif
#endif
/// \}


#endif // BOOSTC__CONFIG__SELECT_PLATFORM_H
