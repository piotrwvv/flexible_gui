//##############################################################################################
#include "event_generator.h"

#include "fxg_graphic/include/geometry.h"

#include <iostream>												//cin cout

using namespace flexible_gui::event;
//--------------------------------------------------------------
// Message_Translator class.
//--------------------------------------------------------------
Event_Generator::Event_Generator() {
	std::cout << "+ Event_Generator {\n";
	std::cout << "+ Event_Generator }\n";
	return;
}

Event_Generator::~Event_Generator() noexcept {
	std::cout << "- Event_Generator {\n";
	std::cout << "- Event_Generator }\n";
	return;
}

void Event_Generator::set_action(std::unique_ptr<On_Mouse_Action_I> act) {
	on_mouse = std::move(act);
	return;
}

void Event_Generator::generate_on_mouse(graphic::Point pos) {
	if (on_mouse) on_mouse->execute(pos);
	return;
}
//##############################################################################################