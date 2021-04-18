//
#include "flexible_gui/include/flexible_gui.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

namespace fxg = flexible_gui;

int main() {
	std::cout << "Hello World!\n";
	try {
		fxg::Dynamic_Window main_wnd{};
		main_wnd.move_to(fxg::Point{1000,500});

		while (true) {
			if (fxg::work() == 1) break;
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