//##############################################################################################
#pragma once

#include "on_event_action.h"

#include <memory>

namespace flexible_gui { namespace event {

	class Event_Generator {
	public:
		explicit Event_Generator();
		Event_Generator(const Event_Generator&) = delete;
		Event_Generator(Event_Generator&&) = delete;
		~Event_Generator() noexcept;

		Event_Generator& operator=(const Event_Generator&) = delete;
		Event_Generator& operator=(Event_Generator&&) = delete;

		void set_action(std::unique_ptr<On_Layout_Action_I> act);
		void set_action(std::unique_ptr<On_Mouse_Action_I> act);
		void set_action(std::unique_ptr<On_Keyboard_Action_I> act);

		void generate_on_mouse(graphic::Point pos);
	private:
		std::unique_ptr<On_Layout_Action_I> on_layout{};
		std::unique_ptr<On_Mouse_Action_I> on_mouse{};
		std::unique_ptr<On_Keyboard_Action_I> on_keyboard{};
	};
}}
//##############################################################################################