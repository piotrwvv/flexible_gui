//
#pragma once

namespace flexible_gui {

	class Platform_Window;
	class On_Event_Action_I;
	class Point;

	class Base_Window {
	public:
		explicit Base_Window();
		Base_Window(const Base_Window&) = delete;
		Base_Window(Base_Window&&) = delete;
		~Base_Window() noexcept;	//virtual?

		Base_Window& operator=(const Base_Window&) = delete;
		Base_Window& operator=(Base_Window&&) = delete;

		void register_action(On_Event_Action_I* ev_act);
		void move_to(Point pt);
	private:
		Platform_Window* pl_wnd{nullptr};	//unique_ptr?		//platform dependent window
	};

	bool work();
}
//