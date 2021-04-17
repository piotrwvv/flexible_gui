//
#pragma once

#include "window.h"

namespace flexible_gui {

	class Dynamic_Window : public Window {
	public:
		using Dn_Wnd = Dynamic_Window;

		explicit Dynamic_Window();								//default constructor
		Dynamic_Window(const Dn_Wnd&) = delete;					//copy constructor
		Dynamic_Window(Dn_Wnd&&) = delete;						//move constructor
		~Dynamic_Window() noexcept;								//destructor

		Dn_Wnd& operator=(const Dn_Wnd&) = delete;				//copy assignment
		Dn_Wnd& operator=(Dn_Wnd&&) = delete;					//move assignment
	private:

	};
}
//