//============================================================================
// Name        : codepp.cpp
// Author      : Mustafa Malik
// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)
//============================================================================

#ifndef CODE_PP_INCLUDE_CORE_RUNNABLE_H
#define CODE_PP_INCLUDE_CORE_RUNNABLE_H

#include "../config.h"
#include "ext/iterable.h"

namespace codepp {
namespace core {

// the runnable context should be created in the main thread and passed
// to all children that require this
class runnable final {
public: // static
	// Draw calls
	CODEPP_STATIC std::vector<std::function<void()>> __renderables;
private:
	raylib::Window __win;
	bool __render_running = false;
public:
	bool force_shutdown = false;
private:
	void __cleanup() const CODEPP_NTHROW {
		_iterate_clr(reinterpret_cast<linb::any*>(&__renderables), __renderables.size());
	}
public:
	runnable(const int& width, const int& height, const char* title) : __win(width, height, title) {}
	~runnable() { }
public:
	void loop() CODEPP_NTHROW {
		if (__render_running) {
			return;
		}
		__render_running = true;
		while (!__win.ShouldClose()) {
			if (force_shutdown)
				break;
			// events
			// render
			__win.BeginDrawing();
			_iterate_func_and_exec(__renderables);
			__win.EndDrawing();
		}
		__render_running = false;
		__cleanup();
	}

	CODEPP_STATIC void add_renderable(const std::function<void()>& func) CODEPP_NTHROW {
		__renderables.push_back(func);
	}

	CODEPP_STATIC void remove_renderable(const std::function<void()>& func) CODEPP_NTHROW {
		__renderables[_iterate_func_get_index(__renderables, &func)] = nullptr;
	}

	CODEPP_STATIC void remove_renderable(cuint& index) CODEPP_NTHROW {
		if (__renderables.size() >= index) {
			__renderables[index] = nullptr;
		}
	}
};

}}

#endif /* CODE_PP_INCLUDE_CORE_RUNNABLE_H */
