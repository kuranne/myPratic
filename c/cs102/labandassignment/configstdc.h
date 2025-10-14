#ifndef __clang__
    #pragma GCC optimize("O3", "unroll-loops")
    #ifdef __x86_64__
        #pragma GCC target("avx2")
    #endif
    #ifndef __x86_64__
        #pragma GCC target("arch=armv8-a+simd")
    #endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
