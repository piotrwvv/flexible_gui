//
#pragma once

namespace flexible_gui {

	class On_Event_Action_I;

	class Event_Generator {
	public:
	private:
		On_Event_Action_I* body_ev_handler{nullptr};
		On_Event_Action_I* mouse_ev_handler{nullptr};
		On_Event_Action_I* keyboard_ev_handler{nullptr};
		//
	};

	class Child_Action {
	public:
	private:
		//
		On_Event_Action_I* mouse_ev_handler{nullptr};
		On_Event_Action_I* keyboard_ev_handler{nullptr};;
	};
}
//