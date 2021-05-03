//##############################################################################################
#pragma once

using UINT = unsigned int;
using WPARAM = unsigned __int64;
using LPARAM = __int64;
using HWND = struct HWND__*;

namespace flexible_gui { namespace event {

	class Message_Translator {
	public:
		Message_Translator() = delete;

		static bool receive_message();
		static __int64 __stdcall message_to_event(HWND hwnd, UINT msg, WPARAM wpar, LPARAM lpar);
	private:
		static bool save_generator_ptr(HWND hwnd, LPARAM lpar);
		static class Event_Generator* generator_ptr(HWND hwnd);

		static void dbg_msg(const char* ch, HWND proc_wnd, HWND cl_wnd, int msg);
	};
}}
//##############################################################################################