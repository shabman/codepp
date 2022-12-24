// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)

#ifndef CODE_PP_INCLUDE_UI_SLIDER_H
#define CODE_PP_INCLUDE_UI_SLIDER_H

#include "../config.h"
#include "../events/subscriber.h"

class slider : public base<codepp::events::event_codes*> {
private:
	//
public:
	slider() = default;
	~slider() override = default;
};

#endif /* CODE_PP_INCLUDE_UI_SLIDER_H */
