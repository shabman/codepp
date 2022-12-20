//============================================================================
// Name        : codepp.cpp
// Author      : Mustafa Malik
// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)
//============================================================================

#ifndef CODE_PP_INCLUDE_CONFIG_H
#define CODE_PP_INCLUDE_CONFIG_H

#define CODE_PP_SDK_LOCKED
#define CODE_PLUSPLUS_VERSION "0.1"

#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include <cmath>
#include <functional>

#include "core/codeppbase.h"

#define CODEPP_EXPORT extern
#define CODEPP_STATIC static
#define CODEPP_THROWS noexcept(false)
#define CODEPP_NTHROW noexcept

#if __cplusplus <= 201103
    #define CODEPP_DEPRECATED(__discard__)  __attribute__((deprecated))
#elif __cplusplus > 201103
    #define CODEPP_DEPRECATED(__msg)        [[deprecated(__msg)]]
#endif

typedef unsigned int uint;
typedef const unsigned int cuint;

#define MAX_CHAR_BUFFER     1024
#define TEXT_EDITOR_LINES   10

#define AUTO_SYNC_POOL  1
#define SMART_SCAN      AUTO_SYNC_POOL // only available when auto synchronisation is enabled
#define THREAD_POOL_MAX std::thread::hardware_concurrency()

// Ray Library

#include "../lib/rcpp426/include/raylib-cpp.hpp"
#include "core/ui/raygui.h"


#endif /* CODE_PP_INCLUDE_CONFIG_H */
