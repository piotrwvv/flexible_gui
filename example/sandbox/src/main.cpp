//
#include "flexible_gui/include/flexible_gui.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

int main() {
	std::cout << "Hello World!\n";
	try {
		flexible_gui::Dynamic_Window main_wnd{};
//		main_wnd.set_position();

//		temp_lib::Button one_btt{};

		while (true) {
			if (flexible_gui::work() == 1) break;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
	catch (std::exception& err) {
		std::cerr << "ERROR: " << err.what() << '\n';
	}
	catch (...) {

	}
	std::cout << "Exit.\n";
	return 0;
}
//