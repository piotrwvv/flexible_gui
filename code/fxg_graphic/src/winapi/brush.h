//##############################################################################################
#pragma once

using HBRUSH = struct HBRUSH__*;

namespace flexible_gui { namespace graphic {

	enum class Stock_Brush_Color {
		white, light_gray, gray, dark_gray, black
	};

	class Stock_Brush {
	public:
		explicit Stock_Brush(Stock_Brush_Color color);

		HBRUSH brush_h() const noexcept;
	private:
		const int convert_to_os(Stock_Brush_Color color) const;
		void create(const int os_value);

		HBRUSH hbrush{nullptr};
	};
}}
//##############################################################################################