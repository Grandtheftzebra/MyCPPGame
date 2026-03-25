#ifndef CUSTOM_ASSERT_H
#define CUSTOM_ASSERT_H

#include <cassert>
#include <iostream>

#if DEBUG_ASSERTS
    #define ASSERT_MSG(expr, msg) \
    do { \
        if (!(expr)) { \
            std::cerr << "Assertion failed: " << (msg) << std::endl; \
            assert(expr); \
        } \
    } while (0)
#else
    #define ASSERT_MSG(expr, msg) do { (void)sizeof(expr); } while (0)
#endif

#endif