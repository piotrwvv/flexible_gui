//
#include "base_window.h"

#include "platform_window_winapi.h"
#include "../geometry.h"

#include <iostream>												//cin cout

namespace fxg = flexible_gui;

fxg::Base_Window::Base_Window()
	: pl_wnd{new Platform_Window{}} {
	std::cout << "+ Base_Window {\n";
	std::cout << "+ Base_Window }\n";
	return;
}

fxg::Base_Window::~Base_Window() noexcept {
	std::cout << "- Base_Window {\n";
	if (pl_wnd) delete pl_wnd;
	std::cout << "- Base_Window }\n";
	return;
}

void fxg::Base_Window::register_action(fxg::On_Event_Action_I* f_ev_hr) {
	return;
}

void fxg::Base_Window::move_to(Point pt) {
	return;
}

bool flexible_gui::work() {
	return fxg::platform_work();
}
//