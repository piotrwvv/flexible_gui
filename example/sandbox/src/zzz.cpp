// Temporary code, excluded from build.

#ifndef WIN32_LEAN_AND_MEAN
#error WIN32_LEAN_AND_MEAN not defined.
#endif

namespace fxg = flexible_gui;
using namespace flexible_gui;
using flexible_gui::register_wnd_class;
using char_ptr = char*;

	HINSTANCE hinst{nullptr};
	if ((hinst = GetModuleHandle(nullptr)) == nullptr) return 1;

	HINSTANCE hinst{GetModuleHandle(nullptr)};
	if (hinst == nullptr) return 1;

//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--
//------//------//------//------//------//------//------//------
//--------------//--------------//--------------//--------------
//------------------------------//------------------------------
//--------------------------------------------------------------

bool Button::create_window() noexcept {
	HINSTANCE app {GetModuleHandle(nullptr)};					//file (exe) used to create the calling process
	if (app == nullptr) return 1;

	hwnd = CreateWindowEx(
		0,														//window extended style
		L"BUTTON",												//window class name
		L"Default",												//window title
		WS_VISIBLE,												//window style
		500, 500,												//window position (coordinates)(x, y)
		50, 50,													//window size (dimensions)(w, h)
		nullptr,												//window parent or owner
		reinterpret_cast<HMENU>(1),								//window menu or child identifier
		app,													//module to be associated with the window
		this													//pointer of type void* (this), to be passed to the window by WM_NCCREATE message
	);
	if (hwnd == nullptr) return 1;
	return 0;
}

// simple - complex
// basic - advanced

//