//##############################################################################################
#include "message_translator.h"

#include "../event_generator.h"

#include "fxg_graphic/include/geometry.h"

#define WIN32_LEAN_AND_MEAN

#include <stdexcept>											//standard exceptions
#include <iostream>												//cin cout
#include <string>												//for debug
#include <Windows.h>											//WinAPI
#include <Windowsx.h>											//WinAPI definitions

using namespace flexible_gui::event;
//--------------------------------------------------------------
// Message_Translator class.
//--------------------------------------------------------------
bool Message_Translator::receive_message() {
	MSG msg{};
	while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE) != 0) {
		if (msg.message == WM_QUIT) {
			if (msg.wParam != 0) return 1;						//closing the application with error
			return 1;											//closing the application without error
		}
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
	return 0;
}

LRESULT CALLBACK Message_Translator::message_to_event(HWND hwnd, UINT msg, WPARAM wpar, LPARAM lpar) {

	dbg_msg("hwnd, nullptr, msg", hwnd, nullptr, msg);

	Event_Generator* gen{generator_ptr(hwnd)};
	if (gen == nullptr) {
		if (msg != WM_NCCREATE) {
			return DefWindowProc(hwnd, msg, wpar, lpar);		//default processing without event generator
		}
	}
	switch (msg) {
	case WM_NCCREATE: {
		if (save_generator_ptr(hwnd, lpar) == 1) return 0;		//return FALSE - CreateWindowEx function will return nullptr handle
		break;
	}
	case WM_LBUTTONDOWN: {
		gen->generate_on_mouse(graphic::Point {GET_X_LPARAM(lpar),GET_Y_LPARAM(lpar)});
		break;
	}
	case WM_CLOSE: {
		PostQuitMessage(0);										//send WM_QUIT with wpar = OK
		return 0;												//message processed
	}
	}
	return DefWindowProc(hwnd, msg, wpar, lpar);				//continue with default message processing
}

bool Message_Translator::save_generator_ptr(HWND hwnd, LPARAM lpar) {
	CREATESTRUCT* cs{reinterpret_cast<CREATESTRUCT*>(lpar)};									//pointer to structure that contains parameters of the CreateWindowEx function
	Event_Generator* gen{reinterpret_cast<Event_Generator*>(cs->lpCreateParams)};				//passed pointer, to the event generator of the created window
	SetLastError(0);
	SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(gen));						//store the event generator pointer in user data associated with the window
	if (GetLastError() != 0) return 1;															//error
	return 0;
}

inline Event_Generator* Message_Translator::generator_ptr(HWND hwnd) {
	return reinterpret_cast<Event_Generator*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));			//get the event generator pointer from user data associated with the window
}

void Message_Translator::dbg_msg(const char* ch, HWND proc_wnd, HWND cl_wnd, int msg) {
	static long t1{0}, t2{0}, dt{0};
	t2 = clock();
	std::string s1{ch}, s2{"> "};
	s2 = s2 + std::to_string(t2-t1) + "\t" + std::to_string(dt) + "\t" + s1;
	if (s1.size() < 8)	s2 += "\t\t\t\t";
	else
	if (s1.size() < 16)	s2 += "\t\t\t";
	else
	if (s1.size() < 24)	s2 += "\t\t";
	else				s2 += "\t";
	s2 = s2 + std::to_string(reinterpret_cast<UINT_PTR>(proc_wnd)) + "\t";
	s2 = s2 + std::to_string(reinterpret_cast<UINT_PTR>(cl_wnd)) + "\t\t";
	switch (msg) {
	case WM_NULL: s2 = s2 + "WM_NULL";  break;
	case WM_CREATE: s2 = s2 + "WM_CREATE";  break;
	case WM_DESTROY: s2 = s2 + "WM_DESTROY";  break;
	case WM_MOVE: s2 = s2 + "WM_MOVE";  break;
	case WM_SIZE: s2 = s2 + "WM_SIZE";  break;
	case WM_ACTIVATE: s2 = s2 + "WM_ACTIVATE";  break;
	case WM_SETFOCUS: s2 = s2 + "WM_SETFOCUS";  break;
	case WM_KILLFOCUS: s2 = s2 + "WM_KILLFOCUS";  break;
	case WM_PAINT: s2 = s2 + "WM_PAINT";  break;
	case WM_CLOSE: s2 = s2 + "WM_CLOSE";  break;
	case WM_QUIT: s2 = s2 + "WM_QUIT";  break;
	case WM_ERASEBKGND: s2 = s2 + "WM_ERASEBKGND";  break;
	case WM_SHOWWINDOW: s2 = s2 + "WM_SHOWWINDOW";  break;
	case WM_ACTIVATEAPP: s2 = s2 + "WM_ACTIVATEAPP";  break;
	case WM_SETCURSOR: s2 = s2 + "WM_SETCURSOR";  break;
	case WM_MOUSEACTIVATE: s2 = s2 + "WM_MOUSEACTIVATE";  break;
	case WM_CHILDACTIVATE: s2 = s2 + "WM_CHILDACTIVATE";  break;
	case WM_GETMINMAXINFO: s2 = s2 + "WM_GETMINMAXINFO";  break;
	case WM_WINDOWPOSCHANGING: s2 = s2 + "WM_WINDOWPOSCHANGING";  break;
	case WM_WINDOWPOSCHANGED: s2 = s2 + "WM_WINDOWPOSCHANGED";  break;
	case WM_CONTEXTMENU: s2 = s2 + "WM_CONTEXTMENU";  break;
	case WM_GETICON: s2 = s2 + "WM_GETICON";  break;
	case WM_NCCREATE: s2 = s2 + "WM_NCCREATE";  break;
	case WM_NCDESTROY: s2 = s2 + "WM_NCDESTROY";  break;
	case WM_NCCALCSIZE: s2 = s2 + "WM_NCCALCSIZE";  break;
	case WM_NCHITTEST: s2 = s2 + "WM_NCHITTEST";  break;
	case WM_NCPAINT: s2 = s2 + "WM_NCPAINT";  break;
	case WM_NCACTIVATE: s2 = s2 + "WM_NCACTIVATE";  break;
	case 0x0090: s2 = s2 + "WM_UAHDESTROYWINDOW";  break;
	case 0x0091: s2 = s2 + "WM_UAHDRAWMENU";  break;
	case 0x0092: s2 = s2 + "WM_UAHDRAWMENUITEM";  break;
	case 0x0093: s2 = s2 + "WM_UAHINITMENU";  break;
	case 0x0094: s2 = s2 + "WM_UAHMEASUREMENUITEM";  break;
	case 0x0095: s2 = s2 + "WM_UAHNCPAINTMENUPOPUP";  break;
	case 0x0096: s2 = s2 + "WM_UAHUPDATE";  break;
	case WM_NCMOUSEMOVE: s2 = s2 + "WM_NCMOUSEMOVE";  break;
	case WM_NCLBUTTONDOWN: s2 = s2 + "WM_NCLBUTTONDOWN";  break;
	case WM_NCLBUTTONUP: s2 = s2 + "WM_NCLBUTTONUP";  break;
	case WM_COMMAND: s2 = s2 + "WM_COMMAND";  break;
	case WM_SYSCOMMAND: s2 = s2 + "WM_SYSCOMMAND";  break;
	case WM_CTLCOLOREDIT: s2 = s2 + "WM_CTLCOLOREDIT";  break;
	case WM_MOUSEMOVE: s2 = s2 + "WM_MOUSEMOVE";  break;
	case WM_LBUTTONDOWN: s2 = s2 + "WM_LBUTTONDOWN";  break;
	case WM_LBUTTONUP: s2 = s2 + "WM_LBUTTONUP";  break;
	case WM_PARENTNOTIFY: s2 = s2 + "WM_PARENTNOTIFY";  break;
	case WM_SIZING: s2 = s2 + "WM_SIZING";  break;
	case WM_CAPTURECHANGED: s2 = s2 + "WM_CAPTURECHANGED";  break;
	case WM_MOVING: s2 = s2 + "WM_MOVING";  break;
	case WM_POWERBROADCAST: s2 = s2 + "WM_POWERBROADCAST";  break;
	case WM_ENTERSIZEMOVE: s2 = s2 + "WM_ENTERSIZEMOVE";  break;
	case WM_EXITSIZEMOVE: s2 = s2 + "WM_EXITSIZEMOVE";  break;
	case WM_IME_SETCONTEXT: s2 = s2 + "WM_IME_SETCONTEXT";  break;
	case WM_IME_NOTIFY: s2 = s2 + "WM_IME_NOTIFY";  break;
	case WM_NCMOUSELEAVE: s2 = s2 + "WM_NCMOUSELEAVE";  break;
	case WM_DWMNCRENDERINGCHANGED: s2 = s2 + "WM_DWMNCRENDERINGCHANGED";  break;
	default: s2 = s2 + std::to_string(msg);
	}
	s2 += "\n";
	std::cout << s2.c_str();
	t1 = clock();
	dt = t1 - t2;
	return;
}
//##############################################################################################