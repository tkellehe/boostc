#!/usr/bin/env bash

function run_in_vs_env
{
    eval vssetup="\$$1\\vsvars32.bat"
    cmd /Q /C call "$vssetup" "&&" "${@:2}"
}

function run_vs14
{
    run_in_vs_env VS140COMNTOOLS "$@"
}

function run_vs13
{
    run_in_vs_env VS130COMNTOOLS "$@"
}

function run_vs12
{
    run_in_vs_env VS120COMNTOOLS "$@"
}

function run_vs11
{
    run_in_vs_env VS110COMNTOOLS "$@"
}

function run_vs10
{
    run_in_vs_env VS100COMNTOOLS "$@"
}

# Usage: msvc.bash run_v14 cl <compilation options>
"$@"