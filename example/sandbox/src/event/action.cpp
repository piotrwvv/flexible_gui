//
#include "action.h"

#include <iostream>												//cin cout

namespace sbx = sandbox;
namespace fxg = flexible_gui;

sbx::Main_Wnd_On_Mouse::Main_Wnd_On_Mouse() noexcept {
	std::cout << "+ Main_Wnd_On_Mouse {\n";
	std::cout << "+ Main_Wnd_On_Mouse }\n";
	return;
}

sbx::Main_Wnd_On_Mouse::~Main_Wnd_On_Mouse() noexcept {
	std::cout << "- Main_Wnd_On_Mouse {\n";
	std::cout << "- Main_Wnd_On_Mouse }\n";
	return;
}

void sbx::Main_Wnd_On_Mouse::execute(fxg::Point pos) {
	std::cout << "Mouse (x,y) = " << pos.x() << "," << pos.y() << "\n";
	return;
}
//