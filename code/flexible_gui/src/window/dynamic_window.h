//
#pragma once

#include "base_window.h"

namespace flexible_gui {

	class Dynamic_Window : public Base_Window {
	public:
		explicit Dynamic_Window();
		Dynamic_Window(const Dynamic_Window&) = delete;
		Dynamic_Window(Dynamic_Window&&) = delete;
		~Dynamic_Window() noexcept;

		Dynamic_Window& operator=(const Dynamic_Window&) = delete;
		Dynamic_Window& operator=(Dynamic_Window&&) = delete;
	private:
	};
}
//