// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)

#include "../../include/ui/components/container.h"

using namespace codepp::ui::comps;

container::container(const codepp::core::runnable& ctx) : __ctx(ctx) {}

container::~container() { }

// private

void container::__add_if(const uiview& child) CODEPP_NTHROW {
	bool exists = _iterate_v_exists<uiview>(this->__children, child, this->__children.size());
	if (!exists) {
		__children.push_back(child);
	}
}

void container::__remove_if(const uiview& child) CODEPP_NTHROW {
	cuint index = _iterate_get_index<uiview>(__children, child);
	if (index < __children.size()) {
		__children[index] = nullptr;
	}
	for (int i = 0; i < __children[index].draw_calls.size(); i++) {
		__ctx.remove_renderable(__children[index].draw_calls[i]);
	}
}

void container::__render_comps() CODEPP_NTHROW {
	for (int i = 0; i < __children.size(); i++) {
		for (int k = 0; i < __children[i].draw_calls.size(); k++) {
			__ctx.add_renderable(__children[i].draw_calls[k]);
		}
	}
}

// public

void container::add(const uiview& child) CODEPP_NTHROW {
	__add_if(child);
}

void container::remove(const uiview& child) CODEPP_NTHROW {
	__remove_if(child);
}
