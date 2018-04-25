#include "area.h"

area::area() : mine(false), show_area(false), flag(false), is_active(false), mines_nearby(0) {};

bool area::check_area() {
	if (show_area == true)
		return false;
	show_area = true;
	return true;
}

void area::add_mines_nearby() { mines_nearby++; }

bool area::place_mine() {
	if (mine == true)
		return false;
	mine = true;
	return true;
}

void area::change_flag() {
	if (flag == true)
		flag = false;
	else
		flag = true;
}

bool area::check_flag()
{
	return flag;
}

std::ostream& operator<<(std::ostream& out, const area& source) {
	if (source.show_area == false) {
		if (source.flag == true) {
			out << "F";
			return out;
		}
		if (source.is_active) {
			out << source.mines_nearby;
			return out;
		}
		out << "o";
		return out;
	}
	out << "x";
	return out;
}