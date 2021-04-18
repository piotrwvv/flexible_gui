//
#pragma once

namespace flexible_gui {

	class Event_Handler_I {
	public:
		explicit Event_Handler_I();
		virtual ~Event_Handler_I() noexcept;
		virtual void execute() = 0;
	};

	class Mouse_Event_Handler : public Event_Handler_I {
	public:
		explicit Mouse_Event_Handler();
		virtual ~Mouse_Event_Handler() noexcept;
		virtual void execute();
	};
}
//