#include "area.h"

area::area() : mine(false), checked_area(false), flag(false), is_active(false), mines_nearby(0) {};

bool area::check_area() {
	if (checked_area == true)
		return false;
	checked_area = true;
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

std::ostream& operator<<(std::ostream& out, const area& source) {
	//if (source.mine) {		// do sprawdzania
	//	out << "B";
	//	return out;
	//}

	if (source.checked_area == true) {		// je�li pole by�o
		out << "x";							// sprawdzone, wy�wietla
		return out;							// x w tablicy
	}
	if (source.checked_area == false) {		// jesli pole nie by�o sprawdzone
		if (source.flag == true) {			// je�li jest ustawiona flaga
			out << "F";
			return out;
		}
		if (source.is_active == true) {		// czy pole ma pokazywa�
			out << source.mines_nearby;		// sasiednie miny
			return out;
		}
		out << "#";							// w innym wypadku
		return out;
	}
	out << "!";								// b��d
	return out;
}