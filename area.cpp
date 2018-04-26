#include "area.h"

area::area() : mine(false), checked_area(false), flag(false), mines_nearby(0) {};

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

bool area::checking_mine() { 
	return mine;
}

int area::checking_mines_nearby(){return mines_nearby;}

bool area::checking_flag() { return flag;}

bool area::checking_area() { return checked_area; }

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
	if (source.checked_area == true) {		// jesli pole by�o sprawdzone
		if (source.mine == true) {			// bomba
			out << "B";
			return out;
		}
		out << source.mines_nearby;	
		return out;	
	}
	if (source.checked_area == false) {		// jesli pole nie by�o sprawdzone
		if (source.flag == true) {			// jesli jest ustawiona flaga
			out << "F";
			return out;
		}
		//if (source.is_active == true) {		// czy pole ma pokazywac
		//	out << source.mines_nearby;		// sasiednie miny
		//	return out;
		//}
		out << "#";							// w innym wypadku
		return out;
	}
	out << "!";								// b�ad
	return out;
}