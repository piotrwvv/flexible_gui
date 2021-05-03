//##############################################################################################
// Temporary code, excluded from build.
//
//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--
//------//------//------//------//------//------//------//------
//--------------//--------------//--------------//--------------
//------------------------------//------------------------------
//--------------------------------------------------------------

#ifndef WIN32_LEAN_AND_MEAN
#error WIN32_LEAN_AND_MEAN not defined.
#endif

namespace flexible_gui {}
namespace fxg = flexible_gui;
using namespace flexible_gui;
using flexible_gui::register_wnd_class;
using char_ptr = char*;

//	default constructor, copy constructor, move constructor, destructor, copy assignment, move assignment

	HINSTANCE hinst{nullptr};
	if ((hinst = GetModuleHandle(nullptr)) == nullptr) return 1;

	HINSTANCE hinst{GetModuleHandle(nullptr)};
	if (hinst == nullptr) return 1;



	DWORD style{};
	switch (f_style) {
	case Window_Style::dynamic_float: {
		style = WS_OVERLAPPEDWINDOW;							//OVERLAPPED+BORDER+DLGFRAME+THICKFRAME+SYSMENU+MINIMIZEBOX+MAXIMIZEBOX
		break;
	}
//	case Window_Style::dynamic_dock: {
//		style = WS_TILED | WS_THICKFRAME;						//OVERLAPPED
//		break;
//	}
//	case Window_Style::static_float: {
//		style = WS_TILED | WS_DLGFRAME;							//OVERLAPPED
//		break;
//	}
//	case Window_Style::static_dock: {
//		style = WS_TILED | WS_BORDER;							//OVERLAPPED
//		break;
//	}
//	case Window_Style::panel: {
//		style = WS_TILED | WS_BORDER;							//OVERLAPPED
//		break;
//	}
	}

void Platform_Window::set_parent(HWND parent) {
	std::cout << "set_parent()\n";

//	std::cout << GetWindowLongPtr(hwnd, GWLP_HWNDPARENT) << "\n";

//	SetLastError(0);
//	SetWindowLongPtr(hwnd, GWLP_HWNDPARENT, reinterpret_cast<LONG_PTR>(parent));
//	if (GetLastError() != 0) throw std::runtime_error{"SetWindowLongPtr()"};

//	SetLastError(0);
//	if (SetParent(hwnd, parent) == nullptr) {
//		if (GetLastError() != 0) throw std::runtime_error{"SetParent()"};
//	}

//	std::cout << GetWindowLongPtr(hwnd, GWLP_HWNDPARENT) << "\n";
	return;
}

void Platform_Window::clear_parent(HWND parent) {
	std::cout << "clear_parent()\n";

//	std::cout << GetWindowLongPtr(hwnd, GWLP_HWNDPARENT) << "\n";

//	SetLastError(0);
//	SetWindowLongPtr(hwnd, GWLP_HWNDPARENT, reinterpret_cast<LONG_PTR>(parent));
//	if (GetLastError() != 0) throw std::runtime_error{"SetWindowLongPtr()"};

//	SetLastError(0);
//	if (SetParent(hwnd, parent) == nullptr) {
//		if (GetLastError() != 0) throw std::runtime_error{"SetParent()"};
//	}

//	std::cout << GetWindowLongPtr(hwnd, GWLP_HWNDPARENT) << "\n";
	return;
}

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
/*



*/
//##############################################################################################