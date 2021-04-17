//
#include "event_handler.h"

#include <iostream>												//cin cout

namespace fxg = flexible_gui;

fxg::Event_Handler_I::Event_Handler_I() {
	std::cout << "+ Event_Handler_I\n";
	return;
}

fxg::Event_Handler_I::~Event_Handler_I() noexcept {
	std::cout << "- Event_Handler_I\n";
	return;
}

fxg::Mouse_Event_Handler::Mouse_Event_Handler() {
	std::cout << "+ Mouse_Event_Handler\n";
	return;
}

fxg::Mouse_Event_Handler::~Mouse_Event_Handler() noexcept {
	std::cout << "- Mouse_Event_Handler\n";
	return;
}
//