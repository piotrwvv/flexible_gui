//##############################################################################################
#pragma once

namespace flexible_gui { namespace graphic {

	class Point {
	public:
		explicit Point(short x, short y) noexcept;

		void set_x(short x) noexcept;
		void set_y(short y) noexcept;
		void set_x_y(short x, short y) noexcept;

		short x() const noexcept;
		short y() const noexcept;
	private:
		short x_coordinate{0}, y_coordinate{0};
	};
//--------------------------------------------------------------
	class Rectangle {
	public:
		explicit Rectangle(short w, short h, Point pt) noexcept;

		void set_w(short w) noexcept;
		void set_h(short h) noexcept;
		void set_w_h(short w, short h) noexcept;
		void set_parameters(short w, short h, Point pt) noexcept;

		short w() const noexcept;
		short h() const noexcept;
		short x() const noexcept;
		short y() const noexcept;
	private:
		short width{0}, height{0};
		Point top_left{0,0};									//corner of the rectangle
	};
}}
//##############################################################################################