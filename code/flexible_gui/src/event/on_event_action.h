//
#pragma once

namespace flexible_gui {

	class On_Event_Action_I {
	public:
		explicit On_Event_Action_I();
		virtual ~On_Event_Action_I() noexcept;
		virtual void execute() = 0;
	};

//	class Mouse_Event_Handler : public On_Event_Action_I {
//	public:
//		explicit Mouse_Event_Handler();
//		virtual ~Mouse_Event_Handler() noexcept;
//		virtual void execute();
//	};
}
//