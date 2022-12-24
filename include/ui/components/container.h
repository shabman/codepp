// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)

#ifndef CODE_PP_UI_COMPONENTS_CONTAINER_H
#define CODE_PP_UI_COMPONENTS_CONTAINER_H

#include "../../config.h"
#include "../../core/ext/iterable.h"
#include "../../core/runnable.h"

namespace codepp {
namespace ui {
namespace comps {

class container {
private:
	std::vector<uiview> __children;
	codepp::core::runnable __ctx;
private:
	void __add_if(const uiview&) CODEPP_NTHROW;
	void __remove_if(const uiview&) CODEPP_NTHROW;
	void __render_comps() CODEPP_NTHROW;
public:
	container(const codepp::core::runnable&);
	virtual ~container();
public:
	void add(const uiview&) CODEPP_NTHROW;
	void remove(const uiview&) CODEPP_NTHROW;
};

}}}

#endif /* CODE_PP_UI_COMPONENTS_CONTAINER_H */
