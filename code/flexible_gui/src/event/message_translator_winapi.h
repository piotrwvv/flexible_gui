//
#pragma once

struct HWND__;
using HWND = HWND__*;
using LRESULT = __int64;
using UINT = unsigned int;
using WPARAM = unsigned __int64;
using LPARAM = __int64;

namespace flexible_gui {

	class Event_Generator;

	class Message_Translator {
	public:
		static bool receive_message();
		static LRESULT __stdcall message_to_event(HWND hwnd, UINT msg, WPARAM wpar, LPARAM lpar);
	private:
		static bool save_generator_ptr(HWND hwnd, LPARAM lpar);
		static Event_Generator* generator_ptr(HWND hwnd);
		static void dbg_msg(const char* ch, HWND proc_wnd, HWND cl_wnd, int msg);
	};
}
//