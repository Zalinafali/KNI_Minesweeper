#pragma once

#include <iostream>

class area {
private:
	bool mine;			// czy jest mina
	bool checked_area;	// czy pole zostalo odkryte
	bool flag;			// oflagowanie pola
	//bool is_active;		// czy styka sie z odkrytym polem
	int mines_nearby;	// miny dotykajace obszaru

public:
	area();

	bool place_mine();
	bool check_area();			// sprawdzenie danego obszaru
	bool checking_mine();
	int checking_mines_nearby();
	bool checking_flag();
	bool checking_area();
	void change_flag();
	bool check_flag();

	void add_mines_nearby();	// zwikszanie liczby sasiaduj¹cych min

	friend std::ostream& operator<<(std::ostream&, const area&);
};