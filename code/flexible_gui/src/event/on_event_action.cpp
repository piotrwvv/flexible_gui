//
#include "on_event_action.h"

#include <iostream>												//cin cout

namespace fxg = flexible_gui;

fxg::On_Event_Action_I::On_Event_Action_I() {
	std::cout << "+ On_Event_Action_I {\n";
	std::cout << "+ On_Event_Action_I }\n";
	return;
}

fxg::On_Event_Action_I::~On_Event_Action_I() noexcept {
	std::cout << "- On_Event_Action_I {\n";
	std::cout << "- On_Event_Action_I }\n";
	return;
}

//fxg::Mouse_Event_Handler::Mouse_Event_Handler() {
//	std::cout << "+ Mouse_Event_Handler\n";
//	return;
//}

//fxg::Mouse_Event_Handler::~Mouse_Event_Handler() noexcept {
//	std::cout << "- Mouse_Event_Handler\n";
//	return;
//}
//