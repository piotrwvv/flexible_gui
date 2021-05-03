//##############################################################################################
#include "window.h"

#include "winapi/wnd_class_ex.h"

#include <stdexcept>											//standard exceptions
#include <iostream>												//cin cout

using namespace flexible_gui::window;
//--------------------------------------------------------------
// Window class.
//--------------------------------------------------------------
Window::Window() {
	std::cout << "+ Window {\n";

	wcx = new Dynamic_Window_WCx{};

	std::cout << "+ Window }\n";
	return;
}

Window::~Window() noexcept {
	std::cout << "- Window {\n";

	delete wcx;

	std::cout << "- Window }\n";
	return;
}
//##############################################################################################