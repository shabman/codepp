//============================================================================
// Name        : codepp.cpp
// Author      : Mustafa Malik
// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)
//============================================================================

#ifndef CODE_PP_INCLUDE_EVENTS_SUBSCRIBER_H
#define CODE_PP_INCLUDE_EVENTS_SUBSCRIBER_H

#include "config.h"
#include "../core/ext/iterable.h"

using namespace codepp;

namespace codepp {
namespace events {

class subscriber final {
private:
	CODEPP_STATIC std::vector<core::base*> children;
	CODEPP_STATIC iterator* it;
private:
	subscriber() = delete;
	~subscriber() = delete;
public:
	CODEPP_STATIC void init() CODEPP_NTHROW {
		(*it) = reinterpret_cast<linb::any*>(&children);
	}

	CODEPP_STATIC void add(core::base* child) CODEPP_NTHROW {
		children.push_back(child);
	}

	CODEPP_STATIC void remove(core::base* child) CODEPP_NTHROW {
		for (int i = it->begin(); i < it->end(); i++) {
			if (children[i] == child) {
				children[i] = nullptr;
				break;
			}
		}
	}
};

}}


#endif /* CODE_PP_INCLUDE_EVENTS_SUBSCRIBER_H */
