//##############################################################################################
#include "cursor.h"

#define WIN32_LEAN_AND_MEAN

#include <stdexcept>											//standard exceptions
#include <Windows.h>											//WinAPI

using namespace flexible_gui::graphic;
//--------------------------------------------------------------
// OS_Cursor class.
//--------------------------------------------------------------
OS_Cursor::OS_Cursor(OS_Cursor_Image image) {
	create(convert_to_os(image));
	return;
}

HICON OS_Cursor::cursor_h() const noexcept {
	return hcursor;
}

const wchar_t* OS_Cursor::convert_to_os(OS_Cursor_Image image) const {
	switch (image) {
	case OS_Cursor_Image::arrow:
		return IDC_ARROW;
	case OS_Cursor_Image::cross:
		return IDC_CROSS;
	case OS_Cursor_Image::hand:
		return IDC_HAND;
	}
	throw std::runtime_error{"OS_Cursor::convert_to_os()::switch()"};
}

void OS_Cursor::create(const wchar_t* os_value) {
	hcursor = LoadCursor(nullptr, os_value);
	if (hcursor == nullptr) throw std::runtime_error{"OS_Cursor::create()::LoadCursor()"};
	return;
}
//##############################################################################################