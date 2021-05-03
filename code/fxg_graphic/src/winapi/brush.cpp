//##############################################################################################
#include "brush.h"

#define WIN32_LEAN_AND_MEAN

#include <stdexcept>											//standard exceptions
#include <Windows.h>											//WinAPI

using namespace flexible_gui::graphic;
//--------------------------------------------------------------
// Stock_Brush class.
//--------------------------------------------------------------
Stock_Brush::Stock_Brush(Stock_Brush_Color color) {
	create(convert_to_os(color));
	return;
}

HBRUSH Stock_Brush::brush_h() const noexcept {
	return hbrush;
}

const int Stock_Brush::convert_to_os(Stock_Brush_Color color) const {
	switch (color) {
	case Stock_Brush_Color::white:
		return WHITE_BRUSH;
	case Stock_Brush_Color::light_gray:
		return LTGRAY_BRUSH;
	case Stock_Brush_Color::gray:
		return GRAY_BRUSH;
	case Stock_Brush_Color::dark_gray:
		return DKGRAY_BRUSH;
	case Stock_Brush_Color::black:
		return BLACK_BRUSH;
	}
	throw std::runtime_error{"Stock_Brush::convert_to_os()::switch()"};
}

void Stock_Brush::create(const int os_value) {
	hbrush = static_cast<HBRUSH>(GetStockObject(os_value));
	if (hbrush == nullptr) throw std::runtime_error{"Stock_Brush::create()::GetStockObject()"};
	return;
}
//##############################################################################################