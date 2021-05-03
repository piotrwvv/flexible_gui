//##############################################################################################
#include "icon.h"

#define WIN32_LEAN_AND_MEAN

#include <stdexcept>											//standard exceptions
#include <Windows.h>											//WinAPI

using namespace flexible_gui::graphic;
//--------------------------------------------------------------
// OS_Icon class.
//--------------------------------------------------------------
OS_Icon::OS_Icon(OS_Icon_Image image) {
	create(convert_to_os(image));
	return;
}

HICON OS_Icon::icon_h() const noexcept {
	return hicon;
}

const wchar_t* OS_Icon::convert_to_os(OS_Icon_Image image) const {
	switch (image) {
	case OS_Icon_Image::application:
		return IDI_APPLICATION;
	case OS_Icon_Image::question:
		return IDI_QUESTION;
	case OS_Icon_Image::information:
		return IDI_INFORMATION;
	case OS_Icon_Image::error:
		return IDI_ERROR;
	}
	throw std::runtime_error{"OS_Icon::convert_to_os()::switch()"};
}

void OS_Icon::create(const wchar_t* os_value) {
	hicon = LoadIcon(nullptr, os_value);
	if (hicon == nullptr) throw std::runtime_error{"OS_Icon::create()::LoadIcon()"};
	return;
}
//##############################################################################################