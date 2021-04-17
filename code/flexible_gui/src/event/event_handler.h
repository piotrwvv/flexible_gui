//
#pragma once

namespace flexible_gui {

	class Event_Handler_I {
	public:
		explicit Event_Handler_I();								//default constructor
		virtual ~Event_Handler_I() noexcept;					//destructor
		virtual void execute() = 0;
	};

	class Mouse_Event_Handler : public Event_Handler_I {
	public:
		explicit Mouse_Event_Handler();							//default constructor
		virtual ~Mouse_Event_Handler() noexcept;				//destructor
		virtual void execute();
	};
}
//