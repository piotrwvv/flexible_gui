//
#pragma once

namespace flexible_gui {

	class Point;
	class Window_Impl;

	class Window {
	public:
		using Wnd = Window;

		explicit Window();
		Window(const Wnd&) = delete;
		Window(Wnd&&) = delete;
		~Window() noexcept;	//virtual?

		Wnd& operator=(const Wnd&) = delete;
		Wnd& operator=(Wnd&&) = delete;

		void move_to(Point pt);
	private:
		Window_Impl* wnd_impl{nullptr};	//unique_ptr?			//platform dependent window implementation
	};

	bool work();
}
//