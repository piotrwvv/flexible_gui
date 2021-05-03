//##############################################################################################
#pragma once

using HICON = struct HICON__*;

namespace flexible_gui { namespace graphic {

	enum class OS_Cursor_Image {
		arrow, cross, hand
	};

	class OS_Cursor {
	public:
		explicit OS_Cursor(OS_Cursor_Image image);

		HICON cursor_h() const noexcept;
	private:
		const wchar_t* convert_to_os(OS_Cursor_Image image) const;
		void create(const wchar_t* os_value);

		HICON hcursor{nullptr};
	};
}}
//##############################################################################################