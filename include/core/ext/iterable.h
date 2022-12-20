//============================================================================
// Name        : codepp.cpp
// Author      : Mustafa Malik
// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)
//============================================================================

#ifndef CODE_PP_INCLUDE_CORE_EXT_ITERABLE_H
#define CODE_PP_INCLUDE_CORE_EXT_ITERABLE_H

#include "../../config.h"
#include "any.h"

#define __EXPORT CODEPP_EXPORT

// FUNCTION VECTOR ITERATION

__EXPORT void _iterate_clr(linb::any* __arr, cuint& size) {
	for (int i = 0; i < size; i++) {
		(*__arr) = nullptr;
	}
}

__EXPORT void _iterate_func_and_exec(const std::vector<std::function<void()>>& _arr) {
	for (int i = 0; i < _arr.size(); i++) {
		_arr[i]();
	}
}

__EXPORT uint _iterate_func_get_index(const std::vector<std::function<void()>>& _arr, const std::function<void()>* target) {
	unsigned int res = 0;
	for (int i = 0; i < _arr.size(); i++) {
		if (&_arr[i] == target) {
			res = i;
			break;
		}
	}
	return res;
}

// use any
class iterator {
private:
	linb::any* __ptr;
	uint __b;
	uint __m;
	uint __e;
public:
	iterator(linb::any* _a) {
		__ptr = _a;
		__b = 0;
		__e = sizeof(_a[0]) / sizeof(_a);
		__m = __e / 2;
	}
	~iterator() { }
public:
	uint begin() const CODEPP_NTHROW {
		return __b;
	}
	uint middle() const CODEPP_NTHROW {
		return __m;
	}
	uint end() const CODEPP_NTHROW {
		return __e;
	}
};

#endif /* CODE_PP_INCLUDE_CORE_EXT_ITERABLE_H */
