//
#include "window.h"
#include "../geometry.h"
#include "window_impl_winapi.h"

#include <iostream>												//cin cout

namespace fxg = flexible_gui;

fxg::Window::Window()
	: wnd_impl{new Window_Impl{}} {
	std::cout << "+ Window\n";
	return;
}

fxg::Window::~Window() noexcept {
	if (wnd_impl) delete wnd_impl;
	std::cout << "- Window\n";
	return;
}

void fxg::Window::move_to(Point pt) {
	return;
}

bool fxg::work() {
	return fxg::dispatch_message();
}
//