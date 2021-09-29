#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(libladybird-gloss.a, 0.0.0)
AC_CONFIG_HEADERS([config.h])

AC_ARG_PROGRAM

LIB_AC_PROG_CC
LIB_AM_PROG_AS
AC_CHECK_TOOL([AR],[ar])
AC_CHECK_TOOL([RANLIB],[ranlib])

AC_PROG_INSTALL

AC_DEFINE([HAVE_ELF], [1], [Using ELF format])

# from ../libnosys/configure.ac to detect symbol prefix

AC_CACHE_CHECK([for symbol prefix], libc_cv_symbol_prefix, [dnl
cat > conftest.c <<\EOF
foo () { }
EOF
dnl
libc_cv_symbol_prefix=none
if AC_TRY_COMMAND([${CC-cc} -S conftest.c -o - | fgrep "\$foo" > /dev/null]);
then
  libc_cv_symbol_prefix='$'
else
  if AC_TRY_COMMAND([${CC-cc} -S conftest.c -o - | fgrep "_foo" > /dev/null]);
  then
    libc_cv_symbol_prefix=_
  fi
fi
rm -f conftest* ])
if test $libc_cv_symbol_prefix != none; then
  AC_DEFINE_UNQUOTED([__SYMBOL_PREFIX], ["$libc_cv_symbol_prefix"], [C symbol prefix])
else
  AC_DEFINE([__SYMBOL_PREFIX], [""], [C symbol prefix])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
