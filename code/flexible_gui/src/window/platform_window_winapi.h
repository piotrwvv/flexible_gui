//
#pragma once

#include "../event/event_generator.h"

struct HWND__;
using HWND = HWND__*;

namespace flexible_gui {

	class Platform_Window {
	public:
		explicit Platform_Window();
		Platform_Window(const Platform_Window&) = delete;
		Platform_Window(Platform_Window&&) = delete;
		~Platform_Window() noexcept;

		Platform_Window& operator=(const Platform_Window&) = delete;
		Platform_Window& operator=(Platform_Window&&) = delete;
	private:
		bool register_wnd_class() noexcept;
		bool create_window() noexcept;
		bool destroy_window() noexcept;

		HWND hwnd{nullptr};										//WinAPI window handler
		Event_Generator ev_gen{};								//Generates events by executing proper On_Event_Action
	};

	bool platform_work();
}
//