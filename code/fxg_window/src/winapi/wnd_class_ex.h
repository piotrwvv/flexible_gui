//##############################################################################################
#pragma once

#include "fxg_graphic/include/brush.h"
#include "fxg_graphic/include/icon.h"
#include "fxg_graphic/include/cursor.h"

namespace flexible_gui { namespace window {

	class Wnd_Class_Ex {
	public:
		virtual ~Wnd_Class_Ex() {}

		virtual bool is_registered() const noexcept = 0;
		virtual void set_registered() noexcept = 0;
		void register_wcx();
	private:
		virtual const wchar_t* name() const noexcept = 0;
		virtual const int style() const noexcept = 0;
		virtual HBRUSH background_brush_h() const noexcept = 0;
		virtual HICON large_icon_h() const noexcept = 0;
		virtual HICON mouse_cursor_h() const noexcept = 0;
	};
//--------------------------------------------------------------
	class Dynamic_Window_WCx : public Wnd_Class_Ex {
	public:
		explicit Dynamic_Window_WCx() noexcept;

		bool is_registered() const noexcept override;
		void set_registered() noexcept override;
	private:
		const wchar_t* name() const noexcept override;
		const int style() const noexcept override;
		HBRUSH background_brush_h() const noexcept override;
		HICON large_icon_h() const noexcept override;
		HICON mouse_cursor_h() const noexcept override;

		static bool registered;
		graphic::Stock_Brush background{graphic::Stock_Brush_Color::dark_gray};
		graphic::OS_Icon large_icon{graphic::OS_Icon_Image::application};
		graphic::OS_Cursor mouse_cursor{graphic::OS_Cursor_Image::cross};
	};
}}
//##############################################################################################