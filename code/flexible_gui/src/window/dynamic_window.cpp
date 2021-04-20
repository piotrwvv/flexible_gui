//
#include "dynamic_window.h"

#include <iostream>												//cin cout

namespace fxg = flexible_gui;

fxg::Dynamic_Window::Dynamic_Window()
	: Base_Window{} {
	std::cout << "+ Dynamic_Window {\n";
	std::cout << "+ Dynamic_Window }\n";
	return;
}

fxg::Dynamic_Window::~Dynamic_Window() noexcept {
	std::cout << "- Dynamic_Window {\n";
	std::cout << "- Dynamic_Window }\n";
	return;
}
//