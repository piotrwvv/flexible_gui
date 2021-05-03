//##############################################################################################
#pragma once

using HICON = struct HICON__*;

namespace flexible_gui { namespace graphic {

	enum class OS_Icon_Image {
		application, question, information, error
	};

	class OS_Icon {
	public:
		explicit OS_Icon(OS_Icon_Image image);

		HICON icon_h() const noexcept;
	private:
		const wchar_t* convert_to_os(OS_Icon_Image image) const;
		void create(const wchar_t* os_value);

		HICON hicon{nullptr};
	};
}}
//##############################################################################################