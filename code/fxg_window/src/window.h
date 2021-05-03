//##############################################################################################
#pragma once

#include "fxg_event/include/event_generator.h"

namespace flexible_gui { namespace window {

	class Window {
	public:
		explicit Window();
		Window(const Window&) = delete;
		Window(Window&&) = delete;
		~Window() noexcept;

		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;

	private:
		class Wnd_Class_Ex* wcx{nullptr};
		event::Event_Generator ev_gen{};						//generates events by executing proper On_Event_Action
	};
}}
//##############################################################################################