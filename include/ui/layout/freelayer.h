// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)

#ifndef CODE_PP_INCLUDE_UI_LAYOUT_FREELAYER_H
#define CODE_PP_INCLUDE_UI_LAYOUT_FREELAYER_H

#include "../../config.h"
#include "../components/container.h"

namespace codepp {
namespace ui {
namespace layouts {

class freelayer final : public codepp::ui::comps::container {
private:
	std::vector<uiview> __renderable_children;
	bool static_sizing = false; // Makes the layout flexible to different resolutions
public:
	freelayer(const bool& = false);
	~freelayer() override;
public:
	void add(const uiview& child) const CODEPP_NTHROW;
	void remove(const uiview& child) const CODEPP_NTHROW;
};

}}}

#endif /* CODE_PP_INCLUDE_UI_LAYOUT_FREELAYER_H */
