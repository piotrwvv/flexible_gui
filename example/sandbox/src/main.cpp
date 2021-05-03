//
//#include "event/on_event_action.h"

//#include "flexible_gui/include/flexible_gui.h"					//library user interfece

#include <exception>
#include <iostream>												//cin cout
//#include <memory>
#include <chrono>
#include <thread>

//using namespace sandbox;
//namespace fxg = flexible_gui;

int main() {
	std::cout << "Hello World!\n";
	try {
//		fxg::window::Window main_wnd{};

//		std::unique_ptr<fxg::On_Mouse_Action_I> act{new Main_Wnd_On_Mouse};
//		main_wnd.set_action(std::move(act));

//		main_wnd.add(&child1_wnd);

//		main_wnd.show();

		while (true) {
//			if (fxg::platform_work() == 1) break;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		std::cout << "Close.\n";
	}
	catch (std::exception& err) {
		std::cerr << "ERROR: " << err.what() << '\n';
	}
	catch (...) {
		std::cerr << "ERROR: unknown" << '\n';
	}
	std::cout << "Exit.\n";
	return 0;
}
//