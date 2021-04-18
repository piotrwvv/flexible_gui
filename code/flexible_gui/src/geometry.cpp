//
#include "geometry.h"

namespace fxg = flexible_gui;

fxg::Point::Point(short x, short y) noexcept
	: x_coordinate{x}, y_coordinate{y} {
	return;
}

inline void fxg::Point::set_x(short x) noexcept {
	x_coordinate = x;
	return;
}

inline void fxg::Point::set_y(short y) noexcept {
	y_coordinate = y;
	return;
}

inline void fxg::Point::set_x_y(short x, short y) noexcept {
	x_coordinate = x;
	y_coordinate = y;
	return;
}

inline short fxg::Point::x() const noexcept {
	return x_coordinate;
}

inline short fxg::Point::y() const noexcept {
	return y_coordinate;
}

fxg::Rectangle::Rectangle(short w, short h, Point pt) noexcept
	: width{w}, height{h}, top_left{pt} {
	if (w <= 0) width = 1;
	if (h <= 0) height = 1;
	return;
}

inline void fxg::Rectangle::set_w(short w) noexcept {
	width = w;
	return;
}

inline void fxg::Rectangle::set_h(short h) noexcept {
	height = h;
	return;
}

inline void fxg::Rectangle::set_w_h(short w, short h) noexcept {
	width = w;
	height = h;
	return;
}

void fxg::Rectangle::set_parameters(short w, short h, Point pt) {
	if (w <= 0) width = 1; else width = w;
	if (h <= 0) height = 1; else height = h;
	top_left.set_x_y(pt.x(), pt.y());
	return;
}

inline short fxg::Rectangle::w() const noexcept {
	return width;
}

inline short fxg::Rectangle::h() const noexcept {
	return height;
}

inline short fxg::Rectangle::x() const noexcept {
	return top_left.x();
}

inline short fxg::Rectangle::y() const noexcept {
	return top_left.y();
}
//