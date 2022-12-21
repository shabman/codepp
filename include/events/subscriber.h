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

	CODEPP_STATIC void flush() CODEPP_NTHROW {
		_iterate_clr(reinterpret_cast<linb::any*>(&children), children.size());
	}
public:
	CODEPP_STATIC void fire_event(const std::string name, void* data) CODEPP_NTHROW {
		for (int i = it->begin(); i < it->end(); i++) {
			children[i]->on_event(name, data);
		}
	}

	CODEPP_STATIC void fire_event_single(core::base* target, std::string name, void* data) CODEPP_NTHROW {
		target->on_event(name, data);
	}
};

}}


#endif /* CODE_PP_INCLUDE_EVENTS_SUBSCRIBER_H */
