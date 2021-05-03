//
#pragma once

namespace sandbox {

	class Main_Wnd_On_Mouse : public flexible_gui::On_Mouse_Action_I {
	public:
		explicit Main_Wnd_On_Mouse() noexcept;
		~Main_Wnd_On_Mouse() noexcept;

		void execute(flexible_gui::Point pos) override;
	private:
	};
}
//