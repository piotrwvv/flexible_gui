//
#pragma once

#include "../event/event_dispatcher_winapi.h"

struct HWND__;
using HWND = HWND__*;

namespace flexible_gui {

	class Window_Impl {
	public:
		using Wnd_Impl = Window_Impl;

		explicit Window_Impl();									//default constructor
		Window_Impl(const Wnd_Impl&) = delete;					//copy constructor
		Window_Impl(Wnd_Impl&&) = delete;						//move constructor
		~Window_Impl() noexcept;								//destructor

		Wnd_Impl& operator=(const Wnd_Impl&) = delete;			//copy assignment
		Wnd_Impl& operator=(Wnd_Impl&&) = delete;				//move assignment	private:
	private:
		bool create_window() noexcept;
		bool destroy_window() noexcept;

		HWND hwnd{nullptr};										//WinAPI window handler
		Event_Dispatcher ev_disp{};								//WinAPI window procedure
	};

	bool register_wnd_class() noexcept;
}
//