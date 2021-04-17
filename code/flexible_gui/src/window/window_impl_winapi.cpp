//
#include "window_impl_winapi.h"

#define WIN32_LEAN_AND_MEAN

#include <iostream>												//cin cout
#include <Windows.h>											//WinAPI

namespace fxg = flexible_gui;

fxg::Window_Impl::Window_Impl() {
	std::cout << "+ Window_Impl\n";
	if (register_wnd_class() == 1) throw std::runtime_error{"register_wnd_class()"};
	if (create_window() == 1) throw std::runtime_error{"create_window()"};
	return;
}

fxg::Window_Impl::~Window_Impl() noexcept {
	if (destroy_window() == 1) std::cerr << "ERROR: destroy_window()\n";
	std::cout << "- Window_Impl\n";
	return;
}

bool fxg::register_wnd_class() noexcept {
	static bool registered{false};								//WinAPI window class single registration state
	if (registered) return 0;

	HINSTANCE app{GetModuleHandle(nullptr)};					//file (exe) used to create the calling process
	if (app == nullptr) return 1;
	HGDIOBJ backg{GetStockObject(DKGRAY_BRUSH)};				//dark gray brush
	if (backg == nullptr) return 1;
	HICON icon{LoadIcon(nullptr, IDI_APPLICATION)};				//default application icon
	if (icon == nullptr) return 1;
	HCURSOR cursor{LoadCursor(nullptr, IDC_ARROW)};				//standard arrow
	if (cursor == nullptr) return 1;

	WNDCLASSEX wcx{};
	wcx.hInstance = app;										//module that contains the window event procedure
	wcx.lpszClassName = L"WND_CLASS";							//window class name
	wcx.lpfnWndProc = fxg::Event_Dispatcher::select_handler;	//window event procedure
	wcx.style = CS_HREDRAW | CS_VREDRAW;						//window style

	wcx.hbrBackground = static_cast<HBRUSH>(backg);				//window background brush
	wcx.hIcon = icon;											//window large icon
	wcx.hIconSm = nullptr;										//window small icon
	wcx.hCursor = cursor;										//window cursor

	wcx.lpszMenuName = nullptr;									//window menu resource
	wcx.cbClsExtra = 0;											//extra bytes following the class structure
	wcx.cbWndExtra = 0;											//extra bytes following the window instance
	wcx.cbSize = sizeof(WNDCLASSEX);							//size in bytes of this structure

	if (RegisterClassEx(&wcx) == 0) return 1;
	registered = true;
	return 0;
}

bool fxg::Window_Impl::create_window() noexcept {
	HINSTANCE app{GetModuleHandle(nullptr)};					//file (exe) used to create the calling process
	if (app == nullptr) return 1;

	hwnd = CreateWindowEx(
		0,														//window extended style
		L"WND_CLASS",											//window class name
		L"Default",												//window title
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,						//window style, OVERLAPPED+BORDER+DLGFRAME+THICKFRAME+SYSMENU+MINIMIZEBOX+MAXIMIZEBOX
		50, 50,													//window position (coordinates)(x, y)
		500, 500,												//window size (dimensions)(w, h)
		nullptr,												//window parent or owner
		nullptr,												//window menu or child identifier
		app,													//module to be associated with the window
		&ev_disp												//pointer of type void*, to be passed to the window by WM_NCCREATE message
	);
	if (hwnd == nullptr) return 1;
	return 0;
}

bool fxg::Window_Impl::destroy_window() noexcept {
	if (hwnd == nullptr) return 0;
	if (DestroyWindow(hwnd) == 0) return 1;
	hwnd = nullptr;
	return 0;
}
//