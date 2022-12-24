// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)

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
#include <unordered_set>

#define APPLICATION_TITLE "Code++ Editor"

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

// Editor

enum class editor_config {
	is_editing				= false,
	is_locked 				= false,
	is_clickable 			= true,
	is_click_locked 		= false,

	is_scroll_pane_click	= true,
	is_scroll_pane_locked 	= false,
};

// Core classes

template<typename T>
class base {
public:
	virtual ~base();
	virtual void on_event(const T&, void*) const CODEPP_NTHROW;
};

class uiview {
public:
	std::vector<std::function<void()>> draw_calls;
};


// Ray Library

#include "../lib/rcpp426/include/raylib-cpp.hpp"
#include "core/ui/raygui.h"

// KEY BINDS

#if defined(__APPLE__) || defined(__linux__) // macOS and Linux
    #define CODEPP_KEY_OPENPROJ     (IsKeyPressed(KEY_O) && IsKeyDown(KEY_LEFT_ALT)) // ALT + O
	#define CODEPP_KEY_SAVEFILE 	(IsKeyPressed(KEY_S) && IsKeyDown(KEY_LEFT_ALT))
	#define CODEPP_KEY_NEWPROJ 		(IsKeyPressed(KEY_N) && IsKeyDown(KEY_LEFT_ALT))
#elif defined(_WIN32) // Windows 32-64 bit (x86_64)
    #define CODEPP_KEY_OPENPROJ     (IsKeyPressed(KEY_O) && IsKeyDown(KEY_LEFT_CONTROL)) // CONTROL + O
	#define CODEPP_KEY_SAVEFILE 	(IsKeyPressed(KEY_S) && IsKeyDown(KEY_LEFT_CONTROL))
	#define CODEPP_KEY_NEWPROJ 		(IsKeyPressed(KEY_N) && IsKeyDown(KEY_LEFT_CONTROL))
#endif

#define TREE_SIDE_PANEL_COLOUR  BLACK
#define BOTTOM_PANEL_COLOUR     TREE_SIDE_PANEL_COLOUR
#define TOP_PANEL_COLOUR        TREE_SIDE_PANEL_COLOUR

Color _darken_colour(Color* col) CODEPP_NTHROW {
    const unsigned char APPLY_FACTOR = 2;
    Color c = *col;
    c.r = (unsigned char) fmax(c.r * APPLY_FACTOR, 0);
    c.g = (unsigned char) fmax(c.g * APPLY_FACTOR, 0);
    c.b = (unsigned char) fmax(c.b * APPLY_FACTOR, 0);
    return *col;
}

Color _brighten_colour(const Color& col) CODEPP_NTHROW {
    const unsigned char APPLY_FACTOR = 2;
    return Color {
        ((unsigned char) (col.r / APPLY_FACTOR)),
        ((unsigned char) (col.g / APPLY_FACTOR)),
        ((unsigned char) (col.b / APPLY_FACTOR)),
        0
    };
}

void _setup_dir() {
    ChangeDirectory(GetApplicationDirectory());
}

#endif /* CODE_PP_INCLUDE_CONFIG_H */
