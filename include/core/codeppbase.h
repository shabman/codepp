//============================================================================
// Name        : codepp.cpp
// Author      : Mustafa Malik
// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)
//============================================================================

#ifndef CODE_PP_INCLUDE_CORE_CODEPPBASE_H
#define CODE_PP_INCLUDE_CORE_CODEPPBASE_H

#include "../config.h"

namespace codepp {
namespace core {

class base {
public:
	virtual ~base();
	virtual void on_event(const std::string&, void*) const noexcept;
};

}}

#endif /* CODE_PP_INCLUDE_CORE_CODEPPBASE_H */
