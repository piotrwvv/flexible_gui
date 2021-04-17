//
#pragma once

struct HWND__;
using HWND = HWND__*;
using LRESULT = __int64;
using UINT = unsigned int;
using WPARAM = unsigned __int64;
using LPARAM = __int64;

namespace flexible_gui {

	class Event_Handler_I;

	class Event_Dispatcher {
	public:
		using Ev_Disp = Event_Dispatcher;

		static LRESULT __stdcall select_handler(HWND hwnd, UINT msg, WPARAM wpar, LPARAM lpar);
	private:
		Event_Handler_I* mouse_ev_handler{nullptr};

	};

	bool dispatch_message();
	void msg_dbg(const char* ch, HWND proc_wnd, HWND cl_wnd, int msg);
}
//