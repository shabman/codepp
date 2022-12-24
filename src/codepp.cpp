// Copyright   : Copyright (c) 2022 Mustafa Malik (@shabman)

#include "../include/config.h"
#include "../include/core/runnable.h"
#include "../include/ui/layout/freelayer.h"

int main() {
    _setup_dir();
	codepp::core::runnable r(900, 500, APPLICATION_TITLE);
	Color colour = RED;
	r.add_renderable([] () -> void {
		ClearBackground(WHITE);
	});
    r.add_renderable([&] () -> void {
        DrawRectangle(0, 0, r.get_window_width() / 4,  r.get_window_height(), TOP_PANEL_COLOUR);
    });
    r.add_renderable([&] () -> void {
       DrawRectangle(100, 100, 40, 40, _darken_colour(&colour));
    });
	r.loop();
    Color col = _darken_colour(&colour);
    std::cout << col.r << col.g << col.b << col.a << std::endl;
}
