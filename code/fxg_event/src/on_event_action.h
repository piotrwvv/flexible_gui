//##############################################################################################
#pragma once

namespace flexible_gui { namespace graphic { class Point; }}

namespace flexible_gui { namespace event {

	class On_Layout_Action_I {
	public:
		virtual ~On_Layout_Action_I() {}

		virtual void execute() = 0;
	};
//--------------------------------------------------------------
	class On_Mouse_Action_I {
	public:
		virtual ~On_Mouse_Action_I() {}

		virtual void execute(graphic::Point pos) = 0;
	};
//--------------------------------------------------------------
	class On_Keyboard_Action_I {
	public:
		virtual ~On_Keyboard_Action_I() {}

		virtual void execute() = 0;
	};
}}
//##############################################################################################