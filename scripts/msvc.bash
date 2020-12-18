#!/usr/bin/env bash

#  Copyright (C) 2020-? T. Mitchell Kelleher
#
#  Distributed under the Boost Software License, Version 1.0. (See
#  accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt)


function run_env
{
    eval vssetup="\$$1\\vsvars32.bat"
    cmd /Q /C call "$vssetup" "&&" "${@:2}"
}

function vs14
{
    run_env VS140COMNTOOLS "$@"
}

function vs13
{
    run_env VS130COMNTOOLS "$@"
}

function vs12
{
    run_env VS120COMNTOOLS "$@"
}

function vs11
{
    run_env VS110COMNTOOLS "$@"
}

function vs10
{
    run_env VS100COMNTOOLS "$@"
}

# Usage: msvc.bash vs14 cl <compilation options>
"$@"