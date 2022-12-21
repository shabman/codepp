//============================================================================
// Name        : codepp.cpp
// Author      : Mustafa Malik
// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)
//============================================================================

#include "../include/config.h"
#include "../include/core/runnable.h"
//#include "../include/core/runnable.h"
//#include "../include/events/subscriber.h"

int main() {
	//SetExitKey(KEY_NULL);
	codepp::core::runnable r(900, 500, "test");
	r.add_renderable([] () -> void {
		ClearBackground(BLACK);
	});
	r.loop();
	return 0;
}
