//
#pragma once

namespace flexible_gui {

	class Window_Impl;

	class Window {
	public:
		using Wnd = Window;

		explicit Window();										//default constructor
		Window(const Wnd&) = delete;							//copy constructor
		Window(Wnd&&) = delete;									//move constructor
		~Window() noexcept;//virtual?							//destructor

		Wnd& operator=(const Wnd&) = delete;					//copy assignment
		Wnd& operator=(Wnd&&) = delete;							//move assignment

//		void set_size(short w, short h);
//		void set_position(short x, short y);
//		void set_size_position(short w, short h, short x, short y);
	private:
		Window_Impl* wnd_impl{nullptr};//unique_ptr?			//platform dependent window implementation
	};

	bool work();
}
//