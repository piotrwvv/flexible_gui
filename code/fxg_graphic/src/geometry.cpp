//##############################################################################################
#include "geometry.h"

using namespace flexible_gui::graphic;
//--------------------------------------------------------------
// Point class.
//--------------------------------------------------------------
Point::Point(short x, short y) noexcept
	: x_coordinate{x}, y_coordinate{y} {
	return;
}

inline void Point::set_x(short x) noexcept {
	x_coordinate = x;
	return;
}

inline void Point::set_y(short y) noexcept {
	y_coordinate = y;
	return;
}

inline void Point::set_x_y(short x, short y) noexcept {
	x_coordinate = x;
	y_coordinate = y;
	return;
}

inline short Point::x() const noexcept {
	return x_coordinate;
}

inline short Point::y() const noexcept {
	return y_coordinate;
}
//--------------------------------------------------------------
// Rectangle class.
//--------------------------------------------------------------
Rectangle::Rectangle(short w, short h, Point pt) noexcept
	: width{w}, height{h}, top_left{pt} {
	if (w <= 0) width = 1;
	if (h <= 0) height = 1;
	return;
}

inline void Rectangle::set_w(short w) noexcept {
	width = w;
	return;
}

inline void Rectangle::set_h(short h) noexcept {
	height = h;
	return;
}

inline void Rectangle::set_w_h(short w, short h) noexcept {
	width = w;
	height = h;
	return;
}

void Rectangle::set_parameters(short w, short h, Point pt) noexcept {
	if (w <= 0) width = 1; else width = w;
	if (h <= 0) height = 1; else height = h;
	top_left.set_x_y(pt.x(), pt.y());
	return;
}

inline short Rectangle::w() const noexcept {
	return width;
}

inline short Rectangle::h() const noexcept {
	return height;
}

inline short Rectangle::x() const noexcept {
	return top_left.x();
}

inline short Rectangle::y() const noexcept {
	return top_left.y();
}
//##############################################################################################