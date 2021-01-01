//  Copyright (C) 2020-? T. Mitchell Kelleher
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#include <boostc/config.h>


#ifdef __cplusplus
# include <csignal>
#else
# include <signal.h>
#endif


#ifndef bstc_signal
# define bstc_signal signal
#endif


#ifndef bstc_raise
# define bstc_raise raise
#endif


#ifndef bstc_sig_atomic_t
# define bstc_sig_atomic_t sig_atomic_t
#endif


#ifndef bstc_sig_dfl
# define bstc_sig_dfl SIG_DFL
#endif


#ifndef bstc_sig_ign
# define bstc_sig_ign SIG_IGN
#endif


#ifndef bstc_sig_err
# define bstc_sig_err SIG_ERR
#endif


#ifndef bstc_sigabrt
# define bstc_sigabrt SIGABRT
#endif


#ifndef bstc_sigfpe
# define bstc_sigfpe SIGFPE
#endif


#ifndef bstc_sigill
# define bstc_sigill SIGILL
#endif


#ifndef bstc_sigint
# define bstc_sigint SIGINT
#endif


#ifndef bstc_sigsegv
# define bstc_sigsegv SIGSEGV
#endif


#ifndef bstc_sigterm
# define bstc_sigterm SIGTERM
#endif
