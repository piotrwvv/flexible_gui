//
#pragma once

#include "../event/event_dispatcher_winapi.h"

struct HWND__;
using HWND = HWND__*;

namespace flexible_gui {

	class Window_Impl {
	public:
		using Wnd_Impl = Window_Impl;

		explicit Window_Impl();
		Window_Impl(const Wnd_Impl&) = delete;
		Window_Impl(Wnd_Impl&&) = delete;
		~Window_Impl() noexcept;

		Wnd_Impl& operator=(const Wnd_Impl&) = delete;
		Wnd_Impl& operator=(Wnd_Impl&&) = delete;
	private:
		bool create_window() noexcept;
		bool destroy_window() noexcept;

		HWND hwnd{nullptr};										//WinAPI window handler
		Event_Dispatcher ev_disp{};								//WinAPI window procedure
	};

	bool register_wnd_class() noexcept;
}
//