//
#pragma once

#include "window.h"

namespace flexible_gui {

	class Dynamic_Window : public Window {
	public:
		using Dn_Wnd = Dynamic_Window;

		explicit Dynamic_Window();
		Dynamic_Window(const Dn_Wnd&) = delete;
		Dynamic_Window(Dn_Wnd&&) = delete;
		~Dynamic_Window() noexcept;

		Dn_Wnd& operator=(const Dn_Wnd&) = delete;
		Dn_Wnd& operator=(Dn_Wnd&&) = delete;
	private:

	};
}
//