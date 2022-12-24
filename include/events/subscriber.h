// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)

#ifndef CODE_PP_INCLUDE_EVENTS_SUBSCRIBER_H
#define CODE_PP_INCLUDE_EVENTS_SUBSCRIBER_H

#include "../config.h"
#include "../core/ext/iterable.h"

namespace codepp {
namespace events {

enum class event_codes {
	NEW_PROJ,
	OPEN_PROJ,
	SAVE_FILE,

};

class subscriber final {
private:
	CODEPP_STATIC std::vector<base<codepp::events::event_codes>*> children;
public:
	subscriber() = default;
	~subscriber() = default;

	CODEPP_STATIC subscriber* init() CODEPP_NTHROW {
		return new subscriber();
	}

	CODEPP_STATIC void add(base<codepp::events::event_codes>* child) CODEPP_NTHROW {
		children.push_back(child);
	}

	CODEPP_STATIC void remove(base<codepp::events::event_codes>* child) CODEPP_NTHROW {
		for (int i = 0; i < children.size(); i++) {
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
	void fire_event(const event_codes& name, void* data) CODEPP_NTHROW {
		if (children.empty())
			return;
		for (int i = 0; i < children.size(); i++) {
			children[i]->on_event(name, data);
		}
	}

	void fire_event_single(base<codepp::events::event_codes>* target, const event_codes& name, void* data) CODEPP_NTHROW {
		target->on_event(name, data);
	}
};

}}


#endif /* CODE_PP_INCLUDE_EVENTS_SUBSCRIBER_H */
