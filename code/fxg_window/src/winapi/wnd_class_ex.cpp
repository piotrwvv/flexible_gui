//##############################################################################################
#include "wnd_class_ex.h"

#include "fxg_event/include/message_translator.h"

#define WIN32_LEAN_AND_MEAN

#include <stdexcept>											//standard exceptions
#include <Windows.h>											//WinAPI

using namespace flexible_gui::window;
//--------------------------------------------------------------
// Wnd_Class_Ex class.
//--------------------------------------------------------------
void Wnd_Class_Ex::register_wcx() {
	HINSTANCE app{GetModuleHandle(nullptr)};					//file (exe) used to create the calling process
	if (app == nullptr) throw std::runtime_error{"GetModuleHandle()"};

	WNDCLASSEX wcx{};
	wcx.hInstance = app;										//module that contains the window event procedure
	wcx.lpszClassName = name();									//window class name
	wcx.lpfnWndProc = event::Message_Translator::message_to_event;//window event procedure
	wcx.style = style();										//window style

	wcx.hbrBackground = background_brush_h();					//window background brush
	wcx.hIcon = large_icon_h();									//window large icon
	wcx.hIconSm = nullptr;										//window small icon
	wcx.hCursor = mouse_cursor_h();								//window mouse cursor

	wcx.lpszMenuName = nullptr;									//window menu resource
	wcx.cbClsExtra = 0;											//extra bytes following the class structure
	wcx.cbWndExtra = 0;											//extra bytes following the window instance
	wcx.cbSize = sizeof(WNDCLASSEX);							//size in bytes of this structure

	if (RegisterClassEx(&wcx) == 0) throw std::runtime_error{"Wnd_Class_Ex::register_wcx()::RegisterClassEx()"};
	return;
}
//--------------------------------------------------------------
// Dynamic_Window_WCx class.
//--------------------------------------------------------------
bool Dynamic_Window_WCx::registered{false};

Dynamic_Window_WCx::Dynamic_Window_WCx() noexcept {
	return;
}

bool Dynamic_Window_WCx::is_registered() const noexcept {
	return registered;
}

void Dynamic_Window_WCx::set_registered() noexcept {
	registered = true;
	return;
}

const wchar_t* Dynamic_Window_WCx::name() const noexcept {
	return L"DYNAMIC";
}

const int Dynamic_Window_WCx::style() const noexcept {
	return CS_HREDRAW | CS_VREDRAW;
}

HBRUSH Dynamic_Window_WCx::background_brush_h() const noexcept {
	return background.brush_h();
}

HICON Dynamic_Window_WCx::large_icon_h() const noexcept {
	return large_icon.icon_h();
}

HICON Dynamic_Window_WCx::mouse_cursor_h() const noexcept {
	return mouse_cursor.cursor_h();
}
//##############################################################################################