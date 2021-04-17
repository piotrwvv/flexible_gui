//
#include "window.h"
#include "window_impl_winapi.h"

#include <iostream>												//cin cout

namespace fxg = flexible_gui;

fxg::Window::Window() : wnd_impl{new Window_Impl{}} {
	std::cout << "+ Window\n";
	return;
}

fxg::Window::~Window() noexcept {
	if (wnd_impl) delete wnd_impl;
	std::cout << "- Window\n";
	return;
}

bool fxg::work() {
	return fxg::dispatch_message();
}
//