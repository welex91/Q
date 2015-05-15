#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Q], [0.6], [subramonian@gmail.com])
AM_INIT_AUTOMAKE([-Wall foreign])
AC_CONFIG_SRCDIR([src/q.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_MAKE_SET

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcurl':
AC_CHECK_LIB([curl], [curl_easy_setopt])
# FIXME: Replace `main' with a function in `-ldl':
AC_CHECK_LIB([dl], [dlopen])
# FIXME: Replace `main' with a function in `-lgomp':
AC_CHECK_LIB([gomp], [main])
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [sin])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [pthread_create])

# Checks for header files.
AC_FUNC_ALLOCA
AC_CHECK_HEADERS([arpa/inet.h fcntl.h float.h inttypes.h limits.h malloc.h memory.h netinet/in.h stddef.h stdint.h stdlib.h string.h strings.h sys/socket.h sys/statvfs.h sys/time.h unistd.h values.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_MODE_T
AC_TYPE_PID_T
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MKTIME
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([atexit floor ftruncate getcwd gettimeofday isascii memmove memset mkdir munmap pow putenv regcomp socket sqrt strcasecmp strdup strncasecmp strndup strstr strtol strtoull])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
